#include<Servo.h>

int TRIG = 2;
int ECO = 3;
int LED = 6;
int DURACION;
int DISTANCIA;
Servo MOTOR;
int SERVO = 5;

void setup()
{
  MOTOR.attach(SERVO);
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(LED, OUTPUT);
}
void loop()
{
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECO, HIGH);
  DISTANCIA = DURACION / 58.2;
  delay(400);
  if (DISTANCIA <= 20 && DISTANCIA >= 0)
  {
    AbrirPuerta();
    delay(10000);
    CerrarPuerta();
  }
}
void AbrirPuerta() {
  for (int i = 0; i <= 13; i++) {
    MOTOR.write(i * 10);
    delay(500);
  }
}
void CerrarPuerta() {
  for (int i = 13; i >= 0; i--) {
    MOTOR.write(i * 10);
    delay(500);
  }

  digitalWrite(LED, HIGH);
  delay(10000);
  digitalWrite(LED, LOW);
}
