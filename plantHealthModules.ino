#include <Wire.h>
#include <Adafruit_BME280.h>
#include <BH1750.h>

Adafruit_BME280 bme;
BH1750 light;

#define soilPin A0
#define waterLEDPin 16
#define sunLEDPin 17

void setup() {
  // put your setup code here, to run once:
  //should I add an LCD?
  Wire.begin(); //defaults for the SDA and SCL
  bme.begin(0x76); //address for the BME280
  light.begin(); //initialize the BH1750 sensor
  //initialize LED pins as output pins
  pinMode(waterLEDPin, OUTPUT);
  pinMode(sunLEDPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float soilValue = analogRead(soilPin);
  float lux = light.readLightLevel();
  float humidity = bme.readHumidity();

  //will adjust these values
  if (soilValue < 1500) {
    digitalWrite(LED_WATER, HIGH);  // Needs water
  } else {
    digitalWrite(LED_WATER, LOW);
  }

  if (lux < 1000) {
    digitalWrite(LED_SUN, HIGH);    // Needs more sunlight
  } else {
    digitalWrite(LED_SUN, LOW);
  }

  delay(2000);
}
