#include <SPI.h>
#include <RF24.h>
#include <RF24Network.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

RF24 radio(9, 10);

RF24Network network(radio);
const uint16_t user = 00;
const uint16_t uav = 01;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
