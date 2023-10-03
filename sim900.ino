int Reintentarenvio = 0; 

void configurarSim900(){
    Serial1.begin(19200);
}

void conectarGPRS(){
     //Serial1.println("AT+CGDCONT=1,\"IP\",\"internet.comcel.com.co\""); //Define el contexto PDP el cual es usado en la transferencia de datos en las comunicaciones via GPRS
     Serial1.println("AT+CGDCONT=1,\"IP\",\"internet.movistar.com.co\"");
     //Serial1.println("AT+CGDCONT=1,\"IP\",\"web.colombiamovil.com.co\""); //Define el contexto PDP el cual es usado en la transferencia de datos en las comunicaciones via GPRS
     delay(1500);
     imprimirRespuestaSerial1();
     Serial1.println("AT+CIPSHUT");
     delay(1500);
     imprimirRespuestaSerial1();
     //Serial1.println("AT+CSTT=\"internet.comcel.com.co\",\"comcel\",\"comcel\""); //Configuración de APN, usuario y contraseña, el cual es definido por el proveedor de servicio
     Serial1.println("AT+CSTT=\"internet.movistar.com.co\",\"movistar\",\"movistar\"");
     //Serial1.println("AT+CSTT=\"web.colombiamovil.com.co\""); //Configuración de APN, usuario y contraseña, el cual es definido por el proveedor de servicio
     delay(1500);
     imprimirRespuestaSerial1();
}

void iniciarConexionInalambrica(){
    Serial1.println("AT+CIICR");//Inicia la conexión inalámbrica con el servicio de GPRS
     delay(2000);
     imprimirRespuestaSerial1();
     
     Serial1.println("AT+CIFSR"); //Obtiene la dirección IP del modulo GSM
     delay(3000);
     obterRespuestaSerialSim900();
}

void enviarDatosAlSerividor(String datos){     
    if (!buscarEnLaRespuestaDeSerialSim900("1")){
       resetSIM900 = false;
       Serial.println("ERROR");
       delay(10);
       Serial.println("RECONNECTING.......");
       delay(10);
       resetearSim900();
       if (((minuto.toInt() == 0)||(minuto.toInt() == 10)||(minuto.toInt() == 20)||(minuto.toInt() == 30)||(minuto.toInt() == 40)||(minuto.toInt() == 50)))
       {
        Reintentarenvio = 1;
        Serial.println("Reintento pendiente"); 
       }
       delay(45000); 
    }
    else if(buscarEnLaRespuestaDeSerialSim900("1")){
        Serial.println("SUCCESSFUL CONNECTION");
//        if (((minuto.toInt() == 0)||(minuto.toInt() == 10)||(minuto.toInt() == 20)||(minuto.toInt() == 30)||(minuto.toInt() == 40)||(minuto.toInt() == 50)) || Reintentarenvio == 1)
        if ((minuto.toInt() == 0)||(minuto.toInt() == 5)||(minuto.toInt() == 10)||(minuto.toInt() == 15)||(minuto.toInt() == 20)||(minuto.toInt() == 25)||(minuto.toInt() == 30)||(minuto.toInt() == 35)||(minuto.toInt() == 40)||(minuto.toInt() == 45)||(minuto.toInt() == 50))
            enviarParametrosAlServidor(datos);
           
    }
    else{
        Serial.println("CONNECTING... ");   
        if(resetSIM900){
           resetearSim900();
           delay(45000); 
           resetSIM900 = false;
        }  
    } 
}

void enviarParametrosAlServidor(String datos){
   Serial1.println("AT+CIPSTART=\"TCP\",\"45.5.164.43\",\"5434\"");//Inicia la conexión donde se define el protocolo y la dirección IP del servidor con su respectivo puerto
   delay(1500);
   obterRespuestaSerialSim900();
   if(!buscarEnLaRespuestaDeSerialSim900("CONNECT OK")){        
      Serial.print("ERROR DE CONEXIÓN CON IP");
      resetearSim900();
      Reintentarenvio = 1;
      Serial.println("Reintento pendiente");  
      delay(45000);
   }
   else if(buscarEnLaRespuestaDeSerialSim900("CONNECT OK")){        
      Reintentarenvio = 0;    
   }  
   Serial1.println("AT+CIPSEND");//Envía los datos al servidor
   delay(1500);
   imprimirRespuestaSerial1();
   Serial1.print("GET /arduino/meteorologia_tocota/agregar.php?");//ruta en el servidor con el dato que se quiere enviar.
   Serial1.println(datos);            // envia el valor de la distancia por el puerto Serial1   
   Serial1.println((char)26); // Codigo ASCII para el caracter Sustituir (Ctrl+z)  
   delay(50000);  
   imprimirRespuestaSerial1();    
   
}
