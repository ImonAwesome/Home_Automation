#include "DHT.h"

#define LEDPIN D1
#define FANPIN D2
#define DHTPIN D3
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(FANPIN, OUTPUT);

  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  delay(450);
  // Wait a few seconds between measurements.

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  if (t <= 35) {
    digitalWrite(LEDPIN, HIGH);
  } else {
    digitalWrite(FANPIN, HIGH);
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("*C  Fahrenheit: "));
  Serial.print(f);
  Serial.println(F("*F"));
  delay(200);


}
