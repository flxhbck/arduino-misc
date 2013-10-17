#include <TinyWireM.h>                  // I2C Master lib for ATTinys which use USI

#define SLAVEADDRESS    38              // 7 bit I2C address for DS1621 temperature sensor
#define LED_PIN         13              // ATtiny Pin 3

void setup(){
  pinMode(LED_PIN,OUTPUT);
  
  TinyWireM.begin();                    // initialize I2C lib
  Init_Temp();                          // Setup DS1621
  delay (3000);
}


void loop(){
  Get_Temp();
  Blink(LED_PIN,1);
}


void Init_Temp(){ // Setup the DS1621 for one-shot mode
  TinyWireM.beginTransmission(SLAVEADDRESS);
  TinyWireM.send(0xAC);                 // Access Command Register
  //TinyWireM.send(B00000001);            // Using one-shot mode for battery savings
  TinyWireM.send(B00000000);            // if setting continious mode for fast reads
  TinyWireM.endTransmission();          // Send to the slave
}


void Get_Temp(){  // Get the temperature from a DS1621
  
  TinyWireM.beginTransmission(SLAVEADDRESS);
  TinyWireM.send(0xEE);                 // if one-shot, start conversions now
  TinyWireM.endTransmission();          // Send 1 byte to the slave

  
  TinyWireM.beginTransmission(SLAVEADDRESS);
  TinyWireM.send(0xAA);                 // read temperature (for either mode)
  TinyWireM.endTransmission();          // Send 1 byte to the slave
  

  TinyWireM.requestFrom(SLAVEADDRESS,1); // Request 1 byte from slave
  tempC = TinyWireM.receive();          // get the temperature
  
  Blink(LED_PIN,1);

}


void Blink(byte led, byte times){ // poor man's GUI
  for (byte i=0; i< times; i++){
    digitalWrite(led,HIGH);
    delay (400);
    digitalWrite(led,LOW);
    delay (175);
  }
}

