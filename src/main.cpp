#include <Arduino.h>

// Пины
const int CAR_RED = 23;
const int CAR_YELLOW = 22;
const int CAR_GREEN = 21;
const int PED_RED =   17;
const int PED_GREEN = 16;
const int BUTTON =    13;




void setup()
{
  Serial.begin(115200);
  pinMode(CAR_RED, OUTPUT);
  pinMode(CAR_YELLOW, OUTPUT);
  pinMode(CAR_GREEN, OUTPUT);
  pinMode(PED_RED, OUTPUT);
  pinMode(PED_GREEN, OUTPUT);

  digitalWrite(CAR_RED, HIGH);
  digitalWrite(CAR_YELLOW, LOW);
  digitalWrite(CAR_GREEN, LOW);
}

void loop()
{
  digitalWrite(CAR_RED, HIGH);
  delay(2000);                     // машины стоят, пешеходы идут
  digitalWrite(PED_RED, LOW);
  digitalWrite(PED_GREEN, HIGH);
  delay(4000);
  for(int i = 0; i <= 3; i++){     // мигает зелёный сигнал пешеходам
    delay(500);
    digitalWrite(PED_GREEN, HIGH);
    delay(500);
    digitalWrite(PED_GREEN, LOW);
  }
  digitalWrite(PED_RED, HIGH);
  delay(2000);                     // пешеходы встали

  digitalWrite(CAR_RED, LOW);

  digitalWrite(CAR_YELLOW, HIGH);  // жёлтый сигнал
  delay(1000);
  digitalWrite(CAR_YELLOW, LOW);

  digitalWrite(CAR_GREEN, HIGH);   // машины едут, пешеходы стоят
  delay(4000);
  for(int i = 0; i <= 3; i++){     // мигает зелёный сигнал машинам
    delay(500);
    digitalWrite(CAR_GREEN, HIGH);
    delay(500);
    digitalWrite(CAR_GREEN, LOW);
  }

  digitalWrite(CAR_YELLOW, HIGH);  // жёлтый сигнал
  delay(1000);
  digitalWrite(CAR_YELLOW, LOW);
}