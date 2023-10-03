
int porcentajeCargaBateria(float voltajeBateria){
  int porcentaje = 0;
  int porcentajeAuxiliar = 47*voltajeBateria-473;
  if (porcentajeAuxiliar > 100)
    porcentaje = 100;
  else if (porcentajeAuxiliar < 0)
    porcentaje = 0;
  else
    porcentaje = porcentajeAuxiliar;
  return porcentaje;
}
