
int sensorPin = A0; //bc using <analog> 0 pin
int sensorValue = 0; //in the beginning
int ledPin = 9; //number in gnd/ground

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT); //define what is the role/mode for the pin
  pinMode(ledPin, OUTPUT);
  
  
}

void loop() {
  //Serial.println("hello world"); //ln means "in a line" so that its not horizontally forever
 
 sensorValue = analogRead (sensorPin); //to get data from the analog arduino
 Serial.print ("Sensor value = ");
 Serial.print (sensorValue);
 Serial.print("\t"); //split the line into two in serial monitor to see clearer


 int newSensorValue = map(sensorValue, 160, 300, 0, 255); 
 //map one range to another range, from 160-300 to 0-255

 newSensorValue = constrain (newSensorValue, 0, 255);
 
 Serial.print("new sensor value: ");
 Serial.println(newSensorValue);
 
 analogWrite(ledPin, newSensorValue); 
 //want the led to track the sensor, to change with
 
}
