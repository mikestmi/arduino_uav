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
  SPI.begin();
  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
  network.begin(108, user);

}

void loop() {
  network.update();

  while ( network.available() ) {
    RF24NetworkHeader header;
    char msg[32] = {0};
    network.read(header, &msg, sizeof(msg));
  }
}
