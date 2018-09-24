#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const byte news[6] = "00001";

RF24 radio(9,10);

void setup() {
  Serial.begin(115200);

  radio.begin();
  radio.openReadingPipe(0, news);

  radio.startListening();
}

void loop() {
  if(radio.available()) {
     Serial.println("Hello World!");

     delay(1000);
  }

}

