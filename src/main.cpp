#include <Arduino.h>

#define RELAY_PIN 5
#define CONTACT_PIN 18

#define RELAY_SET_MS 1000

int counter = 0;
int summ = 0;
int average = 0;
volatile int contactStatus = LOW;

int getCurrentTime() {
  // return millis();
  return micros();
}

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
  contactStatus = digitalRead(CONTACT_PIN);
  counter++;
  int startTime = getCurrentTime();
  digitalWrite(RELAY_PIN, HIGH);
  while (contactStatus == LOW)
  {
      delay(1);
      contactStatus = digitalRead(CONTACT_PIN);
  }
  int result = getCurrentTime() - startTime ;

  Serial.print("ON: ");
  Serial.print(result);
  Serial.println(" mcs");
  delay(RELAY_SET_MS);

  summ += result;


  startTime = getCurrentTime();
  digitalWrite(RELAY_PIN, LOW);
    while (contactStatus == HIGH)
  {
      delay(1);
      contactStatus = digitalRead(CONTACT_PIN);
  }
  result = getCurrentTime() - startTime ;
  Serial.print("OFF: ");
  Serial.print(result);
  Serial.println(" mcs");
  delay(RELAY_SET_MS);

  summ += result;


  Serial.println('_');

  if (counter == 10)
  {
    average = summ / counter;
    Serial.print("Average: ");
    Serial.print(average);
    Serial.println(" mcs");
    counter = 0;
    summ = 0;
  }

}

