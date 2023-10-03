char caracterRespuestaSerialSim900,respuestaSerialSim900[500];

//extrae los caracteres contenidos en la respuesta del serial 
void obterRespuestaSerialSim900(){
  int i = 0;
  while(Serial1.available()!=0){
    caracterRespuestaSerialSim900 = Serial1.read();
    Serial.print(caracterRespuestaSerialSim900);
    respuestaSerialSim900[i] = caracterRespuestaSerialSim900;
    i++;
  }
}