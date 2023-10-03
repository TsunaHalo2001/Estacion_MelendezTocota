  #include <OneWire.h>
#include <DallasTemperature.h>

const byte pin_datos_DQ = 4;

OneWire one_wire_object(pin_datos_DQ);
DallasTemperature sensorDS18B20(&one_wire_object);

void configurarSensorTemperaturaSuelo() {
    sensorDS18B20.begin();
}

float obtenerTemperaturaSuelo() {
    sensorDS18B20.requestTemperatures();
    //Serial.print("Temperatura: ");
    float temperaturaSuelo = sensorDS18B20.getTempCByIndex(0);
    Serial.print("Temperatura suelo: ");
    Serial.print(temperaturaSuelo);
    Serial.println(" C");
    return temperaturaSuelo;
}
