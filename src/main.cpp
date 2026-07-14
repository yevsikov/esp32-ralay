#include <Arduino.h>

#define RELAY_PIN 5
#define CONTACT_PIN 18

#define RELAY_SET_MS 1000



void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  pinMode(CONTACT_PIN, INPUT_PULLDOWN);

  Serial.println("=== Relay Actuation Time Test ===");
  delay(RELAY_SET_MS);
}

void loop() {
  // read CONTACT_PIN state
  int contactState = digitalRead(CONTACT_PIN);
  Serial.print("Relay state: ");
  Serial.println(contactState);
  delay(RELAY_SET_MS);
  
}

