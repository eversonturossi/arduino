int ledPin = 13;
int switchPin = 2;
int value = 0;

void setup() {                
  pinMode(ledPin,OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {
  value = digitalRead(switchPin);
  if (HIGH == value) {
    digitalWrite(ledPin,HIGH);
  } 
  else {
    digitalWrite(ledPin, LOW);
  }
}

