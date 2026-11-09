/*
  Bonezegei_BH1750 Library
  BH1750 I2C Digital Light Sensor Driver
  Author: Bonezegei (Jofel Batutay)
  Date: November 9, 2026
*/

#include "Bonezegei_BH1750.h"

Bonezegei_BH1750::Bonezegei_BH1750(uint8_t address) {
    _address = address;
}

bool Bonezegei_BH1750::begin() {
    Wire.begin();
    
    // Send continuous high-resolution measurement command
    Wire.beginTransmission(_address);
    Wire.write(BH1750_CONTINUOUS_HIGH_RES_MODE);
    if (Wire.endTransmission() != 0) {
        return false; // Connection failed or sensor not found
    }
    
    delay(10);
    return true;
}

float Bonezegei_BH1750::readLux() {
    // Request 2 bytes of data from sensor
    Wire.requestFrom((int)_address, 2);
    
    if (Wire.available() == 2) {
        uint8_t msb = Wire.read();
        uint8_t lsb = Wire.read();
        
        uint16_t raw = ((uint16_t)msb << 8) | lsb;
        
        // Convert raw digital count to Lux (Divided by standard factor 1.2)
        return (float)raw / 1.2f;
    }
    
    return -1.0f; // Return error value if sensor reading fails
}