#define pinSensorDeCorriente A4 // pin para leer la corriente del circuito

float medirCorriente(int numeroMuestras){
  float valorDeCorriente = 0;
  float valorSalidaDelSensorDeCorriente;
  for(int i=0;i<numeroMuestras;i++){
    valorSalidaDelSensorDeCorriente = analogRead(pinSensorDeCorriente)*(5 / 1023.0);
    valorDeCorriente=valorDeCorriente-10.17*valorSalidaDelSensorDeCorriente+25.32; //Ecuación  para obtener la corriente 
  }
  if(valorDeCorriente < 0)
    valorDeCorriente = 0;
  else
    valorDeCorriente=valorDeCorriente/numeroMuestras;
  return valorDeCorriente;
}
