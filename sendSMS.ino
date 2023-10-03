void sendSMS() {
  Serial1.println("AT+CMGF=1\r"); // AT command to set SIM900 to SMS mode
  delay(100);
  imprimirRespuestaSerial1();
  Serial1.println("AT + CMGS = \"+573245703139\"");  // Envia mensaje al número deseado
  delay(100);
  imprimirRespuestaSerial1();
  String text0 = "Hola Ing Jjat";
  Serial1.println(text0); 
  delay(100);
  imprimirRespuestaSerial1();
  Serial1.println((char)26); // End AT command with a ^Z, ASCII code 26
  delay(100);
  Serial1.println();
  delay(5000);// Give module time to send SMS
}
