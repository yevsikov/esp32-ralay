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
  int startMicros = micros();
  digitalWrite(RELAY_PIN, HIGH);
  while (digitalRead(CONTACT_PIN) == LOW)
  {
      delay(1);
  }
  int result = micros() - startMicros ;

  Serial.print("ON: ");
  Serial.print(result);
  Serial.println(" mcs");
  delay(RELAY_SET_MS);




  digitalWrite(RELAY_PIN, LOW);
  Serial.print("OFF");
  delay(RELAY_SET_MS);
  Serial.println('_');

}

