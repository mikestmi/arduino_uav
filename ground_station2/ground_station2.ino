#include <SPI.h>
#include <RF24.h>
#include <RF24Network.h>

RF24 radio(9, 10);

RF24Network network(radio);
const uint16_t ground_station_2 = 021;
const uint16_t uav = 01;

int moistPin = A0;
int moistValue = 0;

void setup() {
  SPI.begin();
  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
  network.begin(108, ground_station_2);

}

void loop() {
  network.update();

  moistValue = analogRead(moistPin);

  while ( network.available() ) {
    RF24NetworkHeader header;
    char c;
    network.read(header, &c, sizeof(c));
  }
}
