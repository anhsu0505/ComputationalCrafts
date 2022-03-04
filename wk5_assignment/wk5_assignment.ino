int sensorPin = A0;
int sensorValue = 0;
int LEDpin = 9;
int newSensorValue;

const int numReadings = 20;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int inputPin = A0;

void setup() {
  // configure pins
  pinMode(sensorPin, INPUT);
  pinMode(LEDpin, OUTPUT);

  // initialize serial communication with computer:
  Serial.begin(9600);

  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
  // read raw data to compare
  sensorValue = analogRead(sensorPin);
  Serial.print("Raw = ");
  Serial.print(sensorValue);
  Serial.print("\t\t");

  // start smoothing
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(sensorPin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
  Serial.print("Average = ");
  Serial.print(average);
  Serial.print("\t\t");

  //map the range from your average values to the range of
  //an LED output
  newSensorValue = map(average, 180, 400, 0, 255);

  //constrain the input range to LED output values
  newSensorValue = constrain(newSensorValue, 0, 255);

  Serial.print("New = ");
  Serial.println(newSensorValue);

  analogWrite(LEDpin, newSensorValue);

  delay(1);

}
