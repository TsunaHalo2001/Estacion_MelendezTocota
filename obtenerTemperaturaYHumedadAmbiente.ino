#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

/*Digital pin connected to the DHT sensor 
Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
Pin 15 can work but DHT must be disconnected during program upload.*/
#define DHTPIN 5
#define DHTTYPE DHT22 // DHT 22 (AM2302), #define DHTTYPE DHT21 // DHT 21 (AM2301)
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

void configurarSensorTemeperaturaYHumedadAmbiente() {
  dht.begin(); // Initialize device.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  // Serial.println(F("------------------------------------"));
  // Serial.println(F("Temperature Sensor"));
  // Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  // Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  // Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  // Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
  // Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
  // Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C"));
  // Serial.println(F("------------------------------------"));
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  // Serial.println(F("Humidity Sensor"));
  // Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  // Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  // Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  // Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("%"));
  // Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("%"));
  // Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("%"));
  // Serial.println(F("------------------------------------"));
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;
}

float obtenerTemperaturaAmbiente() {
  float temperaturaAmbiente = 0; 
  delay(delayMS); // Delay between measurements.
  sensors_event_t event; // Get temperature event and print its value.
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature))
    temperaturaAmbiente = 0;
  else
    temperaturaAmbiente = event.temperature;
  return temperaturaAmbiente;
}

float obtenerHumedadAmbiente(){
  float humedadAmbiente = 0;
  delay(delayMS); // Delay between measurements.
  sensors_event_t event; // Get temperature event and print its value.
  dht.humidity().getEvent(&event);// Get humidity event and print its value.
  if (isnan(event.relative_humidity))
    humedadAmbiente = 0;
  else
    humedadAmbiente = event.relative_humidity;
  return humedadAmbiente;
}