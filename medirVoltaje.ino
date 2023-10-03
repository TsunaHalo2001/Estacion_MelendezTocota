#define pinSensorDeVoltaje A15   // pin para leer el voltaje de la bateria
#define GND 48
//#define VCC 47
void configurarSensorDeVoltaje(){
  pinMode(pinSensorDeVoltaje,INPUT);
  pinMode(GND,INPUT); 
  digitalWrite(GND,LOW);
  //pinMode(VCC,INPUT); 
  //digitalWrite(VCC,HIGH);
} 

float medirVoltaje(int numeroDeMuestras){ 
  float valorVoltajeBateria = 0;  
  for (int i = 0; i < numeroDeMuestras; i++){        
    float respuestaSensorDevoltage = analogRead(pinSensorDeVoltaje)*(4.9)/1023;
    valorVoltajeBateria = valorVoltajeBateria+2.90*respuestaSensorDevoltage+0.85;
  }
  valorVoltajeBateria = valorVoltajeBateria/(numeroDeMuestras+1);
  Serial.println(valorVoltajeBateria);
  return valorVoltajeBateria;
}
