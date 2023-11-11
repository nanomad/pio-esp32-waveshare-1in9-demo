#include <Wire.h>
#include "EinkDisplay.h"

#include "utils.h"

EinkDisplay::EinkDisplay(uint8_t gpio_busy_pin, uint8_t gpio_rst_pin, unsigned char degreesTypeInit)
    : image{
          0x00,
          0x00,
          0x00,
          0x00,
          0x00,
          0x00,
          0x00,
          0x00,
          0x00,
          0x00,
          0x00,
          0x00,
          0x00,
          0x00,
          0x00}
{
    Serial.begin(115200);
    Wire.begin();

    degreesType = degreesTypeInit;
    image[13] = degreesType;

    GPIOInit(gpio_busy_pin, gpio_rst_pin);
    EPD_1in9_init();

    // Set type of updating
    EPD_1in9_lut_DU_WB();

    // Clear screen
    EPD_1in9_Write_Screen(DSPNUM_9in1_off);
}

void EinkDisplay::loop()
{
    if (needUpdate)
    {
        EPD_1in9_lut_DU_WB();
        delay(300);
        EPD_1in9_Write_Screen(image);

        needUpdate = false;
    }
    EPD_1in9_sleep();
}

void EinkDisplay::setData(unsigned char new_image[IMAGE_SIZE])
{
    for (int i = 0; i < IMAGE_SIZE; i++)
    {
        if (new_image[i] != image[i])
        {
            image[i] = new_image[i];
            needUpdate = true;
        }
    }
}

void EinkDisplay::setNumbers(float first, float second)
{
    boolean first_positive = first > 0;
    boolean second_positive = second > 0;
    parseNumber(first_positive ? first : -1.0 * first, temperature_digits, 4);
    parseNumber(second_positive ? second : -1.0 * second, humidity_digits, 3);

    unsigned char new_image[] = {
        getPixel(temperature_digits[0], 1),
        first_positive ? getPixel(temperature_digits[1], 0) : MINUS_SIGN[0],
        first_positive ? getPixel(temperature_digits[1], 1) : MINUS_SIGN[1],
        getPixel(temperature_digits[2], 0),
        getPixel(temperature_digits[2], 1),
        second_positive ? getPixel(humidity_digits[0], 0) : MINUS_SIGN[0],
        second_positive ? getPixel(humidity_digits[0], 1) : MINUS_SIGN[1],
        getPixel(humidity_digits[1], 0),
        getPixel(humidity_digits[1], 1),
        getPixel(humidity_digits[2], 0),
        getPixel(humidity_digits[2], 1),
        getPixel(temperature_digits[3], 0),
        getPixel(temperature_digits[3], 1),
        degreesType, // С°/F°/power/bluetooth
        image[14]};

    new_image[4] |= DOT;      // set top dot
    new_image[8] |= DOT;      // set bottom dot
    new_image[10] |= PERCENT; // set percent symbol

    setData(new_image);
}

void EinkDisplay::setLowPowerIndicator(bool isLowPower)
{
    if (isLowPower)
    {
        degreesType |= LOW_POWER_ON;
    }
    else
    {
        degreesType &= LOW_POWER_OFF;
    }
}

void EinkDisplay::setBluetoothIndicator(bool isBluetooth)
{
    if (isBluetooth)
    {
        degreesType |= BT_ON;
    }
    else
    {
        degreesType &= BT_OFF;
    }
}


EinkDisplay::~EinkDisplay()
{
    EPD_1in9_sleep();
    delay(2000);
    Wire.end();
    Serial.end();
}