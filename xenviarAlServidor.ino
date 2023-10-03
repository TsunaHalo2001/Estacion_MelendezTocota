void enviarAlServidor(){
    
    String direccionViento = String(obtenerDireccionDelViento());
    String velocidadViento = String(medirVelocidadViento());
    String radiacionSolar = String(medirRadiacionSolar());
    String temperaturaAmbiente = String(obtenerTemperaturaAmbiente());
    String precipitacion = String(medirPrecipitacion());
    String humedadAmbiente = String(obtenerHumedadAmbiente());
    String temperaturaSuelo = String(obtenerTemperaturaSuelo());
    String humedadDelSuelo = String(medirHumedadDelSuelo());      
    String presion = String(medirPresion());
    String corriente = String(medirCorriente(10));
    String voltaje = String(medirVoltaje(10));
    String porcentajeBateria = String(porcentajeCargaBateria(medirVoltaje(10)));
    String consumo = String(medirVoltaje(10)*medirCorriente(10));
    obtenerFechaYHora();
            
    //reinicia la cantidad de precipitacion cuando sea un nuevo dia
    if ((hora.toInt() == 0) && (minuto.toInt() == 0) )
      contadorDePrecipitacion = 0;
    /*
    Serial.println(minuto.toInt());
    Serial.println("op1");
    Serial.print("direccionViento: ");
    Serial.println(direccionViento);
    Serial.print("velocidadViento: ");
    Serial.println(velocidadViento);
    Serial.print("radiacionSolar: ");
    Serial.println(radiacionSolar);
    Serial.print("temperaturaAmbiente: ");
    Serial.println(temperaturaAmbiente);
    Serial.print("precipitacion: ");
    Serial.println(precipitacion);
    Serial.print("humedadAmbiente: ");
    Serial.println(humedadAmbiente);
    Serial.print("temperaturaSuelo: ");
    Serial.println(temperaturaSuelo);
    Serial.print("humedadDelSuelo: ");
    Serial.println(humedadDelSuelo);
    Serial.print("yr: ");
    Serial.println(year);
    Serial.print("mes: ");
    Serial.println(mes);
    Serial.print("dia: ");
    Serial.println(dia);
    Serial.print("hora: ");
    Serial.println(hora);
    Serial.print("minu: ");
    Serial.println(minuto);
    Serial.print("presión: ");
    Serial.println(presion);
    Serial.print("corriente: ");
    Serial.println(corriente);
    Serial.print("voltaje: ");
    Serial.println(voltaje);
    Serial.print("estado Batería: ");
    Serial.println(porcentajeBateria);
    Serial.print("consumo: ");
    Serial.println(consumo);*/
   
    //NUEVO LINK: http://45.5.164.43/arduino/meteorologia/agregar.php?fecha=2019-01-01&hora=10:20:00&direc_viento=20&vel_viento=30&rad_solar=700&temp_amb=30&precipitacion=5&hum_amb=30&temp_suelo=45&hum_suelo=90&presion=23&bateria=67&consumo=89&equipo=equipo1";
   String datos = "fecha="+year+"-"+mes+"-"+dia+"&hora="+hora+":"+minuto+"&direc_viento="+direccionViento+"&vel_viento="+velocidadViento+"&rad_solar="+radiacionSolar+"&temp_amb="+temperaturaAmbiente+"&precipitacion="+precipitacion+"&hum_amb="+humedadAmbiente+"&temp_suelo="+temperaturaSuelo+"&hum_suelo="+humedadDelSuelo+"&presion="+presion+"&bateria="+porcentajeBateria+"&consumo="+consumo+"&equipo=equipo1";
   //String datos = "fecha=2023-02-08&hora=04:39&direc_viento="+direccionViento+"&vel_viento="+velocidadViento+"&rad_solar="+radiacionSolar+"&temp_amb="+temperaturaAmbiente+"&precipitacion="+precipitacion+"&hum_amb="+humedadAmbiente+"&temp_suelo="+temperaturaSuelo+"&hum_suelo="+humedadDelSuelo+"&presion="+presion+"&bateria="+porcentajeBateria+"&consumo="+consumo+"&equipo=equipo1";
   
   Serial.println(datos);
   conectarGPRS();
   iniciarConexionInalambrica();
   enviarDatosAlSerividor(datos);
   delay(500);
} 
