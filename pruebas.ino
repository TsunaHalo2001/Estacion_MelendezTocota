
void pruebas(){
     String datos = "CAUDAL=96&FECHA=11-10-2018&HORA=12:51&voltaje=0";
     Serial1.println("AT+CGDCONT=1,\"IP\",\"internet.movistar.com.co\""); //Define el contexto PDP el cual es usado en la transferencia de datos en las comunicaciones via GPRS
     delay(1500);
     printSerialData();

     Serial1.println("AT+CIPSHUT");
     delay(1500);
     printSerialData();

     Serial1.println("AT+CSTT=\"internet.movistar.com.co\",\"movistar\",\"movistar\""); //Configuración de APN, usuario y contraseña, el cual es definido por el proveedor de servicio
     delay(1500);
     printSerialData();
     
     Serial1.println("AT+CIICR");//Inicia la conexión inalámbrica con el servicio de GPRS
     delay(1500);
     printSerialData();
     
     Serial1.println("AT+CIFSR"); //Obtiene la dirección IP del modulo GSM
     delay(1500);
     printSerialData();
     
     Serial1.println("AT+CIPSTART=\"TCP\",\"45.5.164.43\",\"80\"");//Inicia la conexión donde se define el protocolo y la dirección IP del servidor con su respectivo puerto
     delay(1500);
     printSerialData();
     delay(1500);
  
     Serial1.println("AT+CIPSEND");//Envía los datos al servidor
     delay(1500);
     printSerialData();
      
     Serial1.print("GET /arduino/caudal/agregar.php?");//ruta en el servidor con el dato que se quiere enviar.
     Serial1.println(datos);            // envia el valor de la distancia por el puerto Serial1
     Serial1.println((char)26); // Codigo ASCII para el caracter Sustituir (Ctrl+z)
     printSerialData();
     delay(100);  
}

void printSerialData()
{
 while(Serial1.available()!=0)
 Serial.write(Serial1.read());
}
