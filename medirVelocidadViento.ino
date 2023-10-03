long tiempoCero = 0;
long tiempoPasado, tiempoPresente, tiempo= 0,Periodo;

void configurarSensorVelocidadViento(){  
   //CONFIGURACION DE INTERRUPCION EXTERNA, ACCIONADA POR EL ANEMOMETRO
   pinMode(3, INPUT_PULLUP);
   attachInterrupt( digitalPinToInterrupt(3), contacto, RISING); 
}

float medirVelocidadViento(){
    float velocidadViento = 0;
   //ESTA RUTINA ES UN FRECUENCIMETRO
   tiempoPresente = tiempoCero; 
   Periodo = tiempoPresente-tiempoPasado;
   if (Periodo == 0)
       velocidadViento=velocidadViento;
   else
       velocidadViento=2.4/(Periodo*0.001);
    tiempoPasado = tiempoPresente;
   Serial.print("velovidad viento: ");
   Serial.println(velocidadViento);
   Serial.println(Periodo*0.001);
   Serial.println(tiempo);
   return velocidadViento;
}

void contacto() {    
    if ( millis() > tiempoCero  + 250){  
            tiempo++ ;
            tiempoCero = millis();
        }    
}
