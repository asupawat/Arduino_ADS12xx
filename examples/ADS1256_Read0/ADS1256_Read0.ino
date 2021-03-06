#include "ADS1256.h"

// Pin configuration for Arduino UNO
#define ADS1256_PIN_CS      (10)
#define ADS1256_PIN_DRDY    (9)
#define ADS1256_PIN_RST     (8)


ADS1256 adc = ADS1256(ADS1256_PIN_CS, ADS1256_PIN_DRDY, ADS1256_PIN_RST);

void setup()
{
    // Setup serial
    Serial.begin(115200);

    Serial.println("Initializing...");

    // Setup pins and initialize the ADS1256 chip
    adc.begin();

    // Configure reading between AIN0 and AINCOM
    adc.SetMux(ADS1256_MUX_AIN0);

    Serial.println("Complete!");
}

void loop()
{
    int32_t value = 0;
    adc.ReadData(&value);
    Serial.println(value);

    delay(100);
}
