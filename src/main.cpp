#include <Arduino.h>

// Пины
const int CAR_RED = 23;
const int CAR_YELLOW = 22;
const int CAR_GREEN = 21;
const int BUTTON =    13;

const int red_time = 5000;
const int green_time = 3000;
const int blinking_time = 500;
const int AutoModeDuration = red_time + green_time + 4*(blinking_time * 4); 

unsigned long currentTime = millis();

void setup()
{
  Serial.begin(115200);
  pinMode(CAR_RED, OUTPUT);
  pinMode(CAR_YELLOW, OUTPUT);
  pinMode(CAR_GREEN, OUTPUT);

  digitalWrite(CAR_RED, HIGH);
  digitalWrite(CAR_YELLOW, LOW);
  digitalWrite(CAR_GREEN, LOW);

  Serial.println(AutoModeDuration);
}

void loop()
{
  digitalWrite(CAR_RED, HIGH);
  delay(red_time);
  digitalWrite(CAR_RED, LOW);

  digitalWrite(CAR_YELLOW, HIGH);  // жёлтый сигнал
  delay(blinking_time * 4);
  digitalWrite(CAR_YELLOW, LOW);

  digitalWrite(CAR_GREEN, HIGH);   // машины едут
  delay(green_time);
  for(int i = 0; i <= 3; i++){     // мигает зелёный сигнал машинам
    digitalWrite(CAR_GREEN, HIGH);
    delay(blinking_time);
    digitalWrite(CAR_GREEN, LOW);
    delay(blinking_time);
  }

  digitalWrite(CAR_YELLOW, HIGH);  // жёлтый сигнал
  delay(blinking_time * 4);
  digitalWrite(CAR_YELLOW, LOW);

  Serial.println(currentTime);
}