int sensorPin = A0; //bc using <analog> 0 pin
int sensorValue = 0; //in the beginning
int ledPin = 9; //number in gnd/ground

void setup() {
  Serial.begin (9600);
  for (int thisReading = 0; thisReading < numReadings; thisReading ++){
    readings[thisReading] =0;
  } //initialize all readings to be 0

}

void loop() {
  total = total - readings [readIndex]; 
  readings[readIndex] = analogRead(inputPin);//read from the sensor
  total = total + readings[readIndex]; //add reading to total
  readIndex = readIndex +1;

  if (readIndex >= numReadings){
    readIndex = 0;
  }

  average = total / numReadings;
  Serial.println (average);
  delay(1);

}
