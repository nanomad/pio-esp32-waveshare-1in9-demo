#ifndef EinkDisplay_h
#define EinkDisplay_h
#include "EPD_1in9.h"

#define IMAGE_SIZE 15

#define CELSIUS 0x05
#define FAHRENHEIT 0x06
#define DOT 0b0000000000100000
#define PERCENT 0b0000000000100000
#define LOW_POWER_ON 0b0000000000010000
#define LOW_POWER_OFF 0b1111111111101111

#define BT_ON 0b0000000000001000
#define BT_OFF 0b1111111111110111

class EinkDisplay
{
  bool needUpdate = false;
  unsigned char degreesType = CELSIUS;
  unsigned char image[IMAGE_SIZE];
  int temperature_digits[4] = {-1, -1, -1, -1};
  int humidity_digits[3] = {-1, -1, -1};

  void setData(unsigned char new_image[IMAGE_SIZE]);

public:
  /**
   * @param degreesType CELSIUS || FAHRENHEIT
   */
  EinkDisplay(uint8_t gpio_busy_pin, uint8_t gpio_rst_pin, unsigned char degreesTypeInit = CELSIUS);
  ~EinkDisplay();
  virtual void loop();

  void setNumbers(float first, float second);
  void setLowPowerIndicator(bool isLowPower);
  void setBluetoothIndicator(bool isBluetooth);
};

#endif