
int numberOfSensors = 4;

void setup(){
    Serial.begin(9600);
    while (!Serial) {
      ; // wait for serial port to connect. Needed for Leonardo only
    }
}

void loop(){
  for (int i = 0; i < numberOfSensors; i++){
    Serial.print(analogRead(i));
    Serial.print(" * ");
  }
  Serial.println();
}
