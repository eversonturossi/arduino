#include <DallasTemperature.h>
DallasTemperature tempSensor;
float temperatura;

void setup(void) {
  Serial.begin(9600);
  tempSensor.begin(12); // link DS18B20 to NO.12 pin of digital I/O port
  pinMode(13, OUTPUT);  
}

void loop(void) {
  // test temperature weather working normally
  switch(tempSensor.isValid())
  {
  case 1:
    Serial.println("Invalid CRC");
    tempSensor.reset(); // reset temperature sensor
    return;
  case 2:
    Serial.println("Not a valid device");
    tempSensor.reset(); // reset temperature sensor             
    return;
  }
  // read temperature data from DS18B20
  temperatura = tempSensor.getTemperature();
  Serial.print(round(trunc(temperatura)));
  if (temperatura >= 30) {
    digitalWrite(13, HIGH); 
  } 
  else {
    digitalWrite(13, LOW); 
  }
  Serial.print("C");
  Serial.println();
}




