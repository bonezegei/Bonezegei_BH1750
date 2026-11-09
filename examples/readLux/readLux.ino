#include <Bonezegei_BH1750.h>

// Create sensor instance (Default address 0x23)
Bonezegei_BH1750 lightSensor(BH1750_ADDR_LOW);

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("Initializing BH1750 Light Sensor...");

  if (!lightSensor.begin()) {
    Serial.println("Error: BH1750 sensor not found! Check I2C connections.");
    while (1);
  }

  Serial.println("BH1750 Initialized Successfully.");
}

void loop() {
  float lux = lightSensor.readLux();

  if (lux >= 0) {
    Serial.print("Light Intensity: ");
    Serial.print(lux);
    Serial.println(" lx");
  } else {
    Serial.println("Failed to read sensor data.");
  }

  delay(500);
}