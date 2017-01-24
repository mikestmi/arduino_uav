#include <SPI.h>
#include <RF24.h>
#include <RF24Network.h>
#include <dht.h>

RF24 radio(9, 10);

RF24Network network(radio);
const uint16_t ground_station_1 = 011;                                                       // Address of ground station 1 node in Octal format
const uint16_t uav = 01;

void setup() {
  SPI.begin();
  radio.begin();
  radio.setDataRate(RF24_250KBPS);                                                    // Set radio data rate to 250 KBPS
  radio.setPALevel(RF24_PA_MAX);                                                      // Set power amplifier lever to maximum (-18 dBm)
  network.begin(108, ground_station_1);

}

void loop() {
  // put your main code here, to run repeatedly:

}
