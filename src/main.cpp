#include <Arduino.h>

#define RELAY_PIN 5
#define CONTACT_PIN 18

#define RELAY_SET_MS 1000



void setup() {
  Serial.begin(115200);
  delay(2000);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  pinMode(CONTACT_PIN, INPUT_PULLDOWN);

  Serial.println("=== Relay Actuation Time Test ===");
  delay(RELAY_SET_MS);
}

void loop() {
  int startMillis = millis();
  digitalWrite(RELAY_PIN, HIGH);
  
  int contactState = digitalRead(CONTACT_PIN);
  Serial.print("Relay state: ");
  Serial.println(contactState);
  int resultMillis = millis() - startMillis;
  Serial.println(resultMillis);
  delay(RELAY_SET_MS);

  startMillis = millis();
  digitalWrite(RELAY_PIN, LOW);
  contactState = digitalRead(CONTACT_PIN);
  Serial.print("Relay state: ");
  Serial.println(contactState);
  resultMillis = millis() - startMillis;
  Serial.println(resultMillis);
  delay(RELAY_SET_MS);

   Serial.println('_');

}

