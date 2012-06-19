int ledPin = 13;
int switchPin = 2;
int value = 0;

int BuzzerPin = 9;
int length = 15; // the number of notes
char notes[] = "ccggaagffeeddc "; // a space represents a rest
int beats[] = { 
  1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;
void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(BuzzerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(BuzzerPin, LOW);
    delayMicroseconds(tone);
  }
}
void playNote(char note, int duration) {
  char names[] = { 
    'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' , 'x','z'          };
  int tones[] = { 
    1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 , 500, 1000          };
  // play the tone corresponding to the note name
  for (int i = 0; i < 10; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}
void setup() {
  pinMode(BuzzerPin, OUTPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(switchPin, INPUT);
}
void loop() {
  value = digitalRead(switchPin);
  if (HIGH == value) {
    digitalWrite(ledPin,HIGH);
    //  for (int i = 0; i < length; i++) {
    //   if (notes[i] == ' ') {
    //    delay(beats[i] * tempo); // rest
    //  } +
    //   else {
    //    playNote(notes[i], beats[i] * tempo);
    //  }
    // }
    playNote('z', 2);
  } 
  else {
    digitalWrite(ledPin, LOW);
  }
} 





