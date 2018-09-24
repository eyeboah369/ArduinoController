#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const int SW_pin = 2; // digital pin connected to switch output
const int VRx_pin = 0; // analog pin connected to X output
const int VRy_pin = 1; // analog pin connected to Y output

const byte news[0] = "00001";

RF24 radio(9,10);

void setup() {
  radio.begin();
  radio.openWritingPipe(news);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  
    pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
 
  
}


void loop() {
  String hey = "Hello World!";

    Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(VRx_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(VRy_pin));
  Serial.print("\n\n");
  delay(500);

  
}

