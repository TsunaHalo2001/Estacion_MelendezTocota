long tiempoEspera = 0;
long contadorDePrecipitacion = 0;

void configurarSensorDePrecipitacion(){  
  /*CONFIGURACION DE INTERRUPCION EXTERNA, ACCIONADA POR EL BUCKET*/
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),contador,RISING);
}

void contador(){
 /*ESTA RUTINA ES UN CONTADOR ACUMULADOR*/
  if ( millis() > tiempoEspera  + 250){ //RETARDO DE 250 mS USANDO LA FUNCION MILLIS
    contadorDePrecipitacion++;
    tiempoEspera = millis();
  }
}

float medirPrecipitacion(){
  float valorDePrecipitacion=contadorDePrecipitacion*0.2794;
  Serial.print("Precipitación: "); 
  Serial.println(valorDePrecipitacion);
  return valorDePrecipitacion;
}
