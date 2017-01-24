#include <SPI.h>
#include <RF24.h>
#include <RF24Network.h>

RF24 radio(9, 10);

RF24Network network(radio);
const uint16_t ground_station_2 = 021;                             // Address of ground station 2 node in Octal format
const uint16_t uav = 01;  

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
