/*
  Bonezegei_BH1750 Library
  BH1750 I2C Digital Light Sensor Driver
  Author: Bonezegei (Jofel Batutay)
  Date: November 9, 2026
*/

#ifndef _BONEZEGEI_BH1750_H_
#define _BONEZEGEI_BH1750_H_

#include <Arduino.h>
#include <Wire.h>

// BH1750 I2C Default Addresses
#define BH1750_ADDR_LOW  0x23  // ADDR pin connected to GND (Default)
#define BH1750_ADDR_HIGH 0x5C  // ADDR pin connected to VCC

// Operational Modes (Continuous High Resolution)
#define BH1750_CONTINUOUS_HIGH_RES_MODE 0x10

class Bonezegei_BH1750 {
public:
    Bonezegei_BH1750(uint8_t address = BH1750_ADDR_LOW);
    
    // Initialize I2C and sensor
    bool begin();
    
    // Read illuminance value in Lux
    float readLux();

private:
    uint8_t _address;
};

#endif