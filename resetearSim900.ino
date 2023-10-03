#define pinResetSim900 9  // pin del arduino asignado para el power key del shield, sirve para reconectar automáticamente

void resetearSim900()
{
    digitalWrite(pinResetSim900,LOW);
    delay(100);
    digitalWrite(pinResetSim900,HIGH);
    delay(2200);
    digitalWrite(pinResetSim900,LOW);
    delay(1000);
    digitalWrite(pinResetSim900,HIGH);  
}
