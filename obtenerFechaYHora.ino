#define VCC 46
#define GND 47

#include <stdio.h>
#include <DS1302.h>

namespace 
{
  const int kCePin   = 38;  // Chip Enable
  const int kIoPin   = 40;  // Input/Output
  const int kSclkPin = 42;  // Serial Clock
  String year, mes, dia, hora, minuto, segundo;
  // Create a DS1302 object.
  DS1302 rtc(kCePin, kIoPin, kSclkPin);
  String dayAsString(const Time::Day day) {
    switch (day) {
      case Time::kSunday: return "Sunday";
      case Time::kMonday: return "Monday";
      case Time::kTuesday: return "Tuesday";
      case Time::kWednesday: return "Wednesday";
      case Time::kThursday: return "Thursday";
      case Time::kFriday: return "Friday";
      case Time::kSaturday: return "Saturday";
    }
    return "(unknown day)";
  }
  void obtenerFecha() {
    // Get the current time and date from the chip.
    Time t = rtc.time();
    // Name the day of the week.
    const String day = dayAsString(t.day);
    // Format the time and date and insert into the temporary buffer.
    char buf[50];
    snprintf(buf, sizeof(buf), "%s %04d-%02d-%02d %02d:%02d:%02d",
             day.c_str(),
             t.yr, t.mon, t.date,
             t.hr, t.min, t.sec);
    // Print the formatted string to serial so we can see the time.
    //Serial.println(buf);
        //snprintf(year, sizeof(year), "%04d",t.yr);
        year = t.yr;
        Serial.print("Año: ");
        Serial.println(year);
        //snprintf(mes, sizeof(mes), "%02d",t.mon);
        mes = t.mon;
        Serial.print("mes: ");
        Serial.println(mes);
        //snprintf(dia, sizeof(dia), "%02d",t.date);
        dia = t.date;
        Serial.print("dia: ");
        Serial.println(dia);
        //snprintf(hora, sizeof(hora), "%02d",t.hr);
        hora = t.hr;
        Serial.print("hora: ");
        Serial.println(hora);
        //snprintf(minuto, sizeof(minuto), "%02d",t.min);
        minuto = t.min;
        Serial.print("min: ");
        Serial.println(minuto);
        //snprintf(segundo, sizeof(segundo), "%02d",t.sec);
        segundo = t.sec;
        Serial.println(segundo);    
        delay(100);  
  }
}  // namespace

void configurarRelojRTC() {
  //pines de alimentación
  pinMode(VCC, OUTPUT);
  digitalWrite(VCC,HIGH);
  pinMode(GND, OUTPUT);
  digitalWrite(GND,LOW);
  // Initialize a new chip by turning off write protection and clearing the
  // clock halt flag. These methods needn't always be called. See the DS1302
  // datasheet for details.
  rtc.writeProtect(false);
  rtc.halt(false);
  // Make a new time object to set the date and time.
  // Sunday, September 22, 2013 at 01:38:50.
  Time t(2023, 9, 3, 2, 24, 00, Time::kSunday);
  // Set the time and date on the chip.
  //rtc.time(t);
}

// Loop and print the time every second.
void obtenerFechaYHora() {
  obtenerFecha();
}
