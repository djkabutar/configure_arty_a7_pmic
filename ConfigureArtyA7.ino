// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

#define I2C_DEV_ADDR 0x58

void setup() {
  Wire.begin(1, 2); // join I2C bus (address optional for master)

  delay(2000);

  // LDO2
  sendI2CCommand(0xAA, 0x14); // Voltage set to 1.8V
  delay(10);
  sendI2CCommand(0x27, 0x01); // Enable LDO2
  delay(10);

  // Buck1 & Buck2
  sendI2CCommand(0xA4, 0x46); // Voltage set Buck1
  delay(10);
  sendI2CCommand(0xA3, 0x69); // Voltage set Buck2
  delay(10);
  sendI2CCommand(0x9C, 0x66); // Current Limit Buck1 & Buck2
  delay(10);

  sendI2CCommand(0x21, 0x01); // Enable Buck1
  delay(10);
  sendI2CCommand(0x20, 0x01); // Enable Buck2
  delay(10);

  // Buck3
  sendI2CCommand(0x9A, 0x00); // Current set to 2A
  delay(10);
  sendI2CCommand(0xA7, 0x7D); // Voltage set to 3.3V
  delay(10);
  sendI2CCommand(0x24, 0x01); // Enable Buck3
  delay(10);

  // Buck4
  sendI2CCommand(0xA5, 0x7F); // Voltage set to 1.8V
  delay(10);
  sendI2CCommand(0x9B, 0x08); // Current set to 1.5A
  delay(10);
  sendI2CCommand(0x22, 0x01); // Enable Buck4
  delay(500);
}

void loop() {
  
}

void sendI2CCommand(uint8_t r_address, uint8_t value) {
  Wire.beginTransmission(I2C_DEV_ADDR);  
  Wire.write(r_address);
  Wire.write(value);
  Wire.endTransmission();    // stop transmitting
}
