#define pinSensorHumedadSuelo A2

void configurarSensorHumedadDelSuelo(){
    pinMode(pinSensorHumedadSuelo, INPUT);
}

int medirHumedadDelSuelo() {
  	/*Se hace la lectura analoga del pin A0 (sensor) y se pasa por la funcion map() para ajustar los valores leidos a los porcentajes que queremos utilizar*/
	int valorHumedadDelSuelo = 0;
 Serial.println(analogRead(pinSensorHumedadSuelo));
	valorHumedadDelSuelo = map(analogRead(pinSensorHumedadSuelo), 0, 1023, 100, 0);
 Serial.println(analogRead(pinSensorHumedadSuelo));
	Serial.print("Humedad suelo: ");
	Serial.print(valorHumedadDelSuelo);
	Serial.println("%");
	return valorHumedadDelSuelo;
}


	
