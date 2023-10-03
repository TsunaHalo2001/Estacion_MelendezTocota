#define pinSensorDeRadiacionSolar A0   
 
float medirRadiacionSolar() {
  float respuestaDelSensorDeRadiacionSolar = analogRead(pinSensorDeRadiacionSolar)*3.3/1023; 
  float valorDeRadiacionSolar=respuestaDelSensorDeRadiacionSolar*1800/3.3; // SE ENTREGA LA LECTURA EN LAS UNIDADES DE W/M2
  //Serial.print("Radiación: ");
  //Serial.println(valorDeRadiacionSolar);
  return valorDeRadiacionSolar;
}
