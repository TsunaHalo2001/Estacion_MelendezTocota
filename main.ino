/*
 *    ||||||||   || |||||| ||||||
 *       ||      || ||  ||   ||
 *       ||      || ||||||   ||
 *    |||||   ||||| ||  ||   ||
 *  Author: Jaime Jjat 
 *  Date: marzo de 2019
 *  e-mail: jaimen.aza@correounivalle.edu.co 
 *  Youtube: https://www.youtube.com/channel/UC_SdV1G11_uYdfCDWrbLVWg/videos?view_as=subscriber
 */
bool resetSIM900 = true;

void setup() {
    Serial.begin(19200);
    Serial.println("Iniciando...");
    configurarSim900();
    //configuracion inicial de los sensores
    configurarSensorHumedadDelSuelo(); 
    configurarSensorDePrecipitacion(); 
    configurarSensorDePresion(); 
    configurarSensorDeVoltaje();    
    configurarSensorTemeperaturaYHumedadAmbiente(); 
    configurarSensorTemperaturaSuelo();
    configurarSensorVelocidadViento(); 
    configurarRelojRTC(); // configuración sensor  hora y fecha
}

void loop() {
    //Serial.println("[1]");
    //obtenerDireccionDelViento();       
    //Serial.println("[2]");
    //medirVelocidadViento();  
    //Serial.println("[3]");
    //medirHumedadDelSuelo();
    //Serial.println("[4]");
    //medirPrecipitacion();  
    //Serial.println("[5]");
    //medirRadiacionSolar();
    //Serial.println("[6]");
    //obtenerTemperaturaAmbiente(); // sensor temperatura y humedad del aire
    //Serial.println("[6]");
    //obtenerHumedadAmbiente();
    //Serial.println("[7]");
    //obtenerTemperaturaSuelo();obtenerFechaYHora();
    //Serial.println("[8]");
    //medirPresion(); 
    //Serial.println("[9]");
    //medirCorriente(10);
    //Serial.println("[10]");
    //medirVoltaje(10);
    //Serial.println("[12]");
    //Serial.println("[13]");
    Serial.println(" ");    
    enviarAlServidor();
    //sendSMS();
    //pruebas();
    delay(25000);
    Serial.println(" ");
}
