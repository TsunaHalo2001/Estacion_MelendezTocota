#include <SFE_BMP180.h>
#include <Wire.h>

SFE_BMP180 bmp180;

void configurarSensorDePresion() {
  if (bmp180.begin())//iniciar barómetro
    Serial.println("BMP180 iniciado correctamenten");
  else
    Serial.println("Error al iniciar el BMP180");
}

double medirPresion() {
  double valorDePresion = 0;
  char respuestaSensorDePresion;
  double valorTemperatura;
  respuestaSensorDePresion = bmp180.startTemperature();//Inicio de lectura de temperatura
  if (respuestaSensorDePresion != 0){   
    delay(respuestaSensorDePresion); //Pausa para que finalice la lectura
    respuestaSensorDePresion = bmp180.getTemperature(valorTemperatura); //Obtener la temperatura
    if (respuestaSensorDePresion != 0){
      respuestaSensorDePresion = bmp180.startPressure(3); //Inicio lectura de presión
      if (respuestaSensorDePresion != 0){        
        delay(respuestaSensorDePresion);//Pausa para que finalice la lectura        
        respuestaSensorDePresion = bmp180.getPressure(valorDePresion,valorTemperatura); //Obtenemos la presión
        //Ejemplo:
        /*if (respuestaSensorDePresion != 0)
        {                  
          Serial.print("Temperatura: ");
          Serial.print(valorTemperatura,2);
          Serial.print(" *C , ");
          Serial.print("Presion: ");
          Serial.print(valorDePresion,2);
          Serial.println(" mb");          
        }*/
        return valorDePresion;
      }      
    }   
  } 
}
