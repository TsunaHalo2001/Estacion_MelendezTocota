
bool palabraEncontrada = true;

bool buscarEnLaRespuestaDeSerialSim900(char* palabra){
     if(strstr(respuestaSerialSim900,palabra)!=NULL) {
       palabraEncontrada = true;
       delay(100);
     } 
     else if (strstr(respuestaSerialSim900,"ERR")!=NULL)  {
       palabraEncontrada = false;
       delay(100);
     }
     else
      palabraEncontrada = false;
  return palabraEncontrada;
}
