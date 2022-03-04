
//declare variables
const int buttonPin = 2;
const int ledPin = 13;

int buttonState = 0;


void setup() {
  pinMode (buttonPin, INPUT);
  pinMode (ledPin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
//digital read and digital write)

  if(buttonState == HIGH){
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW); //LOW means turn off
  }

}
