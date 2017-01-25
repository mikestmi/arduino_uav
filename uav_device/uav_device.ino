#include <SPI.h>
#include <RF24.h>
#include <RF24Network.h>
#include <Wire.h>
#include <Sodaq_DS3231.h>
#include <SD.h>

RF24 radio(9, 10);

RF24Network network(radio);
const uint16_t user = 00;
const uint16_t uav = 01;                                                     
const uint16_t ground_station_1 = 011;                                                          
const uint16_t ground_station_2 = 021;

const unsigned long interval = 5000;                                            
unsigned long last_sent;

void setup() {
  SPI.begin();
  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
  network.begin(108, uav);

}

void loop() {
  network.update();

  unsigned long now = millis();
  if ( now - last_sent >= interval  )
  {
    last_sent = now;

    char c = 'A';
    RF24NetworkHeader header(ground_station_1);
    bool ok = network.multicast(header, c, sizeof(c), 2);
  }
}
