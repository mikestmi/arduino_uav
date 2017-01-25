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

DateTime dt(2017, 01, 02, 20, 26, 00, 2);

int CSpin = 8;
File data;

String getTime() {

  String time;
  String hour;
  String minute;
  String second;

  DateTime now = rtc.now();
  hour = String(now.hour(), DEC);
  minute = String(now.minute(), DEC);
  second = String(now.second(), DEC);

  time = hour + ":" + minute + ":" + second;
  return time;
}

void saveToSD(String Entry) {

  data = SD.open("LOGDATA.txt", FILE_WRITE);

  if (data) {
    data.print(Entry);
    data.close();
  }
}

void setup() {
  Wire.begin();
  SD.begin(CSpin);
  rtc.begin();
  SPI.begin();
  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
  network.begin(108, uav);
  //rtc.setDateTime(dt);
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

  if ( network.available() ) {
    RF24NetworkHeader header;
    char msg[32] = {0};
    network.read(header, &msg, sizeof(msg));

    String Time = getTime();
    String Entry = Time + " " + msg;

    saveToSD(Entry + "\n");

    int EntryLen = Entry.length() + 1;
    char txt[EntryLen];
    Entry.toCharArray(txt, EntryLen);
    RF24NetworkHeader header1(user);
    network.write(header1, &txt, sizeof(txt));
  }
}
