#define Veleta A1     

float obtenerDireccionDelViento()
{
  float anguloDireccionDelViento = 0;  
  float respuestaSensorDireccionViento = analogRead(Veleta);
  respuestaSensorDireccionViento = respuestaSensorDireccionViento*5;
  respuestaSensorDireccionViento = respuestaSensorDireccionViento/1023; // LECTURA ANALAGICA DE LA VELETA POR EL PUERTO A1
  Serial.println(respuestaSensorDireccionViento);
  /*DE ACUUERDO AL INTERVALO DE VOLTAJE, SE ESTABLECE LA DIRECCION DEL VIENTO*/
  //tocota
  if (respuestaSensorDireccionViento>4.82 && respuestaSensorDireccionViento<4.84 ){anguloDireccionDelViento=0;} 
  if (respuestaSensorDireccionViento>4.27 && respuestaSensorDireccionViento<4.29 ){anguloDireccionDelViento=22.5;} 
  if (respuestaSensorDireccionViento>4.39 && respuestaSensorDireccionViento<4.41 ){anguloDireccionDelViento=45;}
  if (respuestaSensorDireccionViento>2.22 && respuestaSensorDireccionViento<2.24 ){anguloDireccionDelViento=67.5;} 
  if (respuestaSensorDireccionViento>2.37 && respuestaSensorDireccionViento<2.39 ){anguloDireccionDelViento=90;}
  if (respuestaSensorDireccionViento>1.91 && respuestaSensorDireccionViento<1.93 ){anguloDireccionDelViento=112.5;}
  if (respuestaSensorDireccionViento>3.32 && respuestaSensorDireccionViento<3.34 ){anguloDireccionDelViento=135;}
  if (respuestaSensorDireccionViento>2.79 && respuestaSensorDireccionViento<2.81 ){anguloDireccionDelViento=157.5;}
  if (respuestaSensorDireccionViento>3.89 && respuestaSensorDireccionViento<3.91 ){anguloDireccionDelViento=180;} 
  if (respuestaSensorDireccionViento>3.69 && respuestaSensorDireccionViento<3.71 ){anguloDireccionDelViento=202.5;}
  if (respuestaSensorDireccionViento>4.66 && respuestaSensorDireccionViento<4.68 ){anguloDireccionDelViento=225;} 
  if (respuestaSensorDireccionViento>4.62 && respuestaSensorDireccionViento<4.64 ){anguloDireccionDelViento=247.5;} 
  if (respuestaSensorDireccionViento>4.94 && respuestaSensorDireccionViento<4.96 ){anguloDireccionDelViento=270;} 
  if (respuestaSensorDireccionViento>4.86 && respuestaSensorDireccionViento<4.88 ){anguloDireccionDelViento=292.5;}
  if (respuestaSensorDireccionViento>4.90 && respuestaSensorDireccionViento<4.92 ){anguloDireccionDelViento=315;}
  if (respuestaSensorDireccionViento>4.75 && respuestaSensorDireccionViento<4.77 ){anguloDireccionDelViento=337.5;}
  //melendez
  /*if (respuestaSensorDireccionViento>3.83 && respuestaSensorDireccionViento<3.85 ){anguloDireccionDelViento=0;} 
  if (respuestaSensorDireccionViento>1.97 && respuestaSensorDireccionViento<1.99 ){anguloDireccionDelViento=22.5;} 
  if (respuestaSensorDireccionViento>2.24 && respuestaSensorDireccionViento<2.26 ){anguloDireccionDelViento=45;}
  if (respuestaSensorDireccionViento>0.40 && respuestaSensorDireccionViento<0.42 ){anguloDireccionDelViento=67.5;} 
  if (respuestaSensorDireccionViento>0.44 && respuestaSensorDireccionViento<0.46 ){anguloDireccionDelViento=90;}
  if (respuestaSensorDireccionViento>0.31 && respuestaSensorDireccionViento<0.33 ){anguloDireccionDelViento=112.5;}
  if (respuestaSensorDireccionViento>0.89 && respuestaSensorDireccionViento<0.91 ){anguloDireccionDelViento=135;}
  if (respuestaSensorDireccionViento>0.61 && respuestaSensorDireccionViento<0.63 ){anguloDireccionDelViento=157.5;}
  if (respuestaSensorDireccionViento>1.39 && respuestaSensorDireccionViento<1.41 ){anguloDireccionDelViento=180;} 
  if (respuestaSensorDireccionViento>1.18 && respuestaSensorDireccionViento<1.20 ){anguloDireccionDelViento=202.5;}
  if (respuestaSensorDireccionViento>3.07 && respuestaSensorDireccionViento<3.09 ){anguloDireccionDelViento=225;} 
  if (respuestaSensorDireccionViento>2.92 && respuestaSensorDireccionViento<2.94 ){anguloDireccionDelViento=247.5;} 
  if (respuestaSensorDireccionViento>4.61 && respuestaSensorDireccionViento<4.63 ){anguloDireccionDelViento=270;} 
  if (respuestaSensorDireccionViento>4.03 && respuestaSensorDireccionViento<4.05 ){anguloDireccionDelViento=292.5;}
  if (respuestaSensorDireccionViento>4.77 && respuestaSensorDireccionViento<4.79 ){anguloDireccionDelViento=315;}
  if (respuestaSensorDireccionViento>3.42 && respuestaSensorDireccionViento<3.44 ){anguloDireccionDelViento=337.5;}    
  */
  Serial.print("dirección viento: ");
  Serial.println(anguloDireccionDelViento);    
  return anguloDireccionDelViento;
}
