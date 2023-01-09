#include <Arduino.h>
#include "solarcharge.h"
#include "logger.h"

int GPIO1 = 4;
int p_PWM_Freq = 5000;
int p_PWM_Res = 8;

Solar solar01;

void setup()
{
  ledcAttachPin(GPIO1, 0);
  ledcSetup(0, p_PWM_Freq, p_PWM_Res);
  Serial.println("solar charge output set");
}

void loop() {
  // put your main code here, to run repeatedly:
  Solar::update(float voltage, float current, int dT)
}