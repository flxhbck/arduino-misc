#define BARGRAPH 1
#define SENSOR A0        // select the input pin for the potentiometer

int sensorValue = 0;     // variable to store the value coming from the sensor


void setup() {
    Serial.begin(9600);
    pinMode(SENSOR, INPUT);
}

void loop()
{
    sensorValue = analogRead(SENSOR);
    
    if (BARGRAPH){
        for(int i = 0; i < sensorValue/10; i++){
            Serial.print("|");
        }
        Serial.println();
    } else {
        Serial.println(analogRead(SENSOR));
    }
}










