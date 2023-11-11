#include <Arduino.h>

#include "EinkDisplay.h"
#define LED_BUILTIN 2

// put function declarations here:
EinkDisplay* display;

void setup()
{
  display = new EinkDisplay(34, 35, CELSIUS);
}

float randomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

void loop()
{
  float a = randomFloat(-9.9, 199.9);
  float b = randomFloat(-9.9, 199.9);
  display->setBluetoothIndicator(true);
  display->setNumbers(a, b);
  display->loop();
  delay(5000);
}

