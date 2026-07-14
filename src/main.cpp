#include <Arduino.h>

#define RELAY_PIN 5
#define CONTACT_PIN 18

#define RELAY_SET_MS 1000
#define MEASUREMENTS_COUNT 10
#define WAIT_TIMEOUT_US 1000000UL // safety timeout for one edge, 1s

long counter = 0;
long summ = 0;
long average = 0;

// shared between ISR and loop()
volatile unsigned long toggleStartTime = 0;
volatile unsigned long reactionTime = 0;
volatile bool edgeDetected = false;

IRAM_ATTR unsigned long getCurrentTime() {
  return millis();
  // return micros();
}

// Interrupt handler: fires on any change of the relay contact pin.
// It measures the time elapsed since the relay pin was last toggled.
void IRAM_ATTR onContactChange() {
  reactionTime = getCurrentTime() - toggleStartTime;
  edgeDetected = true;
}

void setup() {
  Serial.begin(115200);
  delay(2000);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  pinMode(CONTACT_PIN, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(CONTACT_PIN), onContactChange, CHANGE);

  Serial.println("=== Relay Actuation Time Test ===");
  delay(RELAY_SET_MS);
}

// Toggles the relay to newState and waits (via interrupt) for the contact
// pin to react. Returns the measured reaction time in microseconds, or -1
// on timeout.
long toggleAndMeasure(int newState) {
  edgeDetected = false;
  toggleStartTime = getCurrentTime();
  digitalWrite(RELAY_PIN, newState);

  while (!edgeDetected) {
    if (getCurrentTime() - toggleStartTime > WAIT_TIMEOUT_US) {
      return -1;
    }
    yield();
  }

  return (long)reactionTime;
}

void loop() {
  counter++;

  long result = toggleAndMeasure(HIGH);
  Serial.print("ON: ");
  Serial.print(result);
  Serial.println(" ms");
  delay(RELAY_SET_MS);
  summ += result;

  result = toggleAndMeasure(LOW);
  Serial.print("OFF: ");
  Serial.print(result);
  Serial.println(" ms");
  delay(RELAY_SET_MS);
  summ += result;

  Serial.println('_');

  if (counter == MEASUREMENTS_COUNT) {
    average = summ / (counter * 2);
    Serial.print("Average: ");
    Serial.print(average);
    Serial.println(" ms");
    counter = 0;
    summ = 0;
  }
}

