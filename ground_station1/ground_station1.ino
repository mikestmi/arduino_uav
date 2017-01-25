#include <SPI.h>
#include <RF24.h>
#include <RF24Network.h>
#include <dht.h>

RF24 radio(9, 10);

RF24Network network(radio);
const uint16_t ground_station_1 = 011;
const uint16_t uav = 01;

#define DHT11_PIN 3
dht DHT;

String temperature;
String humidity;

void setup() {
  SPI.begin();
  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
  network.begin(108, ground_station_1);
}

void loop() {
  network.update();

  while ( network.available() ) {
    RF24NetworkHeader header;
    char c;
    network.read(header, &c, sizeof(c));

    DHT.read11(DHT11_PIN);
    humidity = String(DHT.humidity, 0);
    temperature = String(DHT.temperature, 0);
    String Entry = temperature + "C," + humidity + "%";

    int EntryLen = Entry.length() + 1;
    char msg[EntryLen];
    Entry.toCharArray(msg, EntryLen);
    RF24NetworkHeader header1(uav);
    bool ok = network.write(header1, &msg, sizeof(msg));
  }
}
