#include <SPI.h>
#include <RF24.h>
#include <RF24Network.h>
#include <Wire.h>
#include <Sodaq_DS3231.h>
#include <SD.h>

RF24 radio(9, 10);

RF24Network network(radio); 
const uint16_t user = 00;
const uint16_t uav = 01;                                                     // Address of our node in Octal format
const uint16_t ground_station_1 = 011;                                                          // Address of the other node in Octal format
const uint16_t ground_station_2 = 021;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
