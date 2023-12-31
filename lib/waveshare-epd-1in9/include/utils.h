#include <math.h>
#include <Arduino.h>

#ifndef UTILS_h
#define UTILS_h

const unsigned char EMPTY = 0x00;
const unsigned char MINUS_SIGN[2] = {
  0b01000100, 0b00000
};

const unsigned char DIGITS[][2] = {
    {0xbf, 0xff}, // 0
    {0x00, 0xff}, // 1
    {0xfd, 0x17}, // 2
    {0xf5, 0xff}, // 3
    {0x47, 0xff}, // 4
    {0xf7, 0x1d}, // 5
    {0xff, 0x1d}, // 6
    {0x21, 0xff}, // 7
    {0xff, 0xff}, // 8
    {0xf7, 0xff}, // 9
};

unsigned char getPixel(int number, int order)
{
  return number == -1 ? EMPTY : DIGITS[number][order];
}

bool isNaN(float a)
{
  return a != a;
}

void parseNumber(float number, int* digits, int digitsCount)
{
  for (int i = 0; i < digitsCount; i++)
  {
    if (isNaN(number))
    {
      digits[i] = -1;
    }
    else
    {
      digits[i] = (int)(number / pow(10, (digitsCount - i) - 2)) % 10;
      Serial.printf("loop[%d] = %d\n", i, digits[i]);

      if (digits[i] == 0 && (i == 0 || digits[i - 1] == -1))
      {
        digits[i] = -1;
      }
    }
  }

}

#endif