#include <Arduino.h>
#include "solarcharge.h"

Solar solar01;

void setup() {
  ledcAttachPin(GPIO, 0);
  ledcSetup(0, p_PWM_Freq, p_PWM_Res);
  Serial.println("solar charge output set");
}

void loop() {
  // put your main code here, to run repeatedly:
}