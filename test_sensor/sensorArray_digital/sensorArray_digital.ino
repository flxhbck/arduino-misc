int numberOfSensors = 13;

void setup(){
    Serial.begin(9600);
    for (int i = 0; i < numberOfSensors; i++){
      pinMode(i, INPUT);
    }
}

void loop(){
  for (int i = 0; i < numberOfSensors; i++){
    Serial.print(digitalRead(i));
    Serial.print(" * ");
  }
  Serial.println();
}
