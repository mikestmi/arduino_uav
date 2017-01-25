#include <SPI.h>
#include <RF24.h>
#include <RF24Network.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

RF24 radio(9, 10);

RF24Network network(radio);
const uint16_t user = 00;
const uint16_t uav = 01;

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  lcd.begin(16, 2);
  lcd.print("User device");
  delay(1500);
  lcd.clear();

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

    lcd.print(msg);
    delay(1500);
    lcd.clear();
  }
}
