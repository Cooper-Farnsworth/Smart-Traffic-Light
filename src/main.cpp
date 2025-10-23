#include <Arduino.h>

// Пины
const int CAR_RED = 23;
const int CAR_YELLOW = 22;
const int CAR_GREEN = 21;
const int BUTTON =    13;
bool cars_mode = true;

uint32_t current_time = 0;
uint32_t previous_time = 0;
uint32_t red_time = 5000;
uint32_t green_time = 3000;
uint32_t blinking_time = 500;
uint32_t AutoModeDuration = red_time + green_time + blinking_time*4; 

void setup()
{
  Serial.begin(115200);
  pinMode(CAR_RED, OUTPUT);
  pinMode(CAR_YELLOW, OUTPUT);
  pinMode(CAR_GREEN, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  digitalWrite(CAR_RED, LOW);
  digitalWrite(CAR_YELLOW, LOW);
  digitalWrite(CAR_GREEN, HIGH);

  Serial.println(AutoModeDuration);
}

void delay_func(uint32_t time) {
  uint32_t prev = millis();
  while(millis() - prev <= time);
}

bool handle_button() {
  if(digitalRead(BUTTON)) return true;
  return false;
}

void auto_traffic_mode() {
  digitalWrite(CAR_GREEN, HIGH);   // машины едут
  delay_func(green_time);
  digitalWrite(CAR_GREEN, LOW);

  digitalWrite(CAR_YELLOW, HIGH);  // жёлтый сигнал
  delay_func(blinking_time * 2);
  digitalWrite(CAR_YELLOW, LOW);

  digitalWrite(CAR_RED, HIGH); // машины встали
  delay_func(red_time);
  digitalWrite(CAR_RED, LOW);

  digitalWrite(CAR_YELLOW, HIGH);  // жёлтый сигнал
  delay_func(blinking_time * 2);
  digitalWrite(CAR_YELLOW, LOW);
}

void manual_traffic_mode() {
}

void loop()
{ 
  current_time = millis();
  if(cars_mode && (current_time - previous_time >= AutoModeDuration)) {
    previous_time = current_time;
    auto_traffic_mode();
  }
}