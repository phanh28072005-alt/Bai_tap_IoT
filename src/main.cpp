#include <Arduino.h>
#include <OneButton.h>

const int BUTTON_PIN = 2;
const int LED1_PIN = 13;
const int LED2_PIN = 4;

OneButton button(BUTTON_PIN, true);

int activeLed = 1;

bool led1State = false;
bool led2State = false;

bool isBlinking1 = false;
bool isBlinking2 = false;

unsigned long lastBlinkTime1 = 0;
unsigned long lastBlinkTime2 = 0;
const long blinkInterval = 200;

void handleClick() {
  if (activeLed == 1) {
    isBlinking1 = false;
    led1State = !led1State;
    digitalWrite(LED1_PIN, led1State ? HIGH : LOW);
  } else {
    isBlinking2 = false;
    led2State = !led2State;
    digitalWrite(LED2_PIN, led2State ? HIGH : LOW);
  }
}

void handleDoubleClick() {
  if (activeLed == 1) {
    activeLed = 2;
  } else {
    activeLed = 1;
  }
}

void handleLongPressStart() {
  if (activeLed == 1) {
    isBlinking1 = !isBlinking1;
    if (!isBlinking1) {
      led1State = false;
      digitalWrite(LED1_PIN, LOW);
    }
  } else {
    isBlinking2 = !isBlinking2;
    if (!isBlinking2) {
      led2State = false;
      digitalWrite(LED2_PIN, LOW);
    }
  }
}

void setup() {
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);

  button.attachClick(handleClick);
  button.attachDoubleClick(handleDoubleClick);
  button.attachLongPressStart(handleLongPressStart);

  button.setClickMs(250);
  button.setPressMs(800);
}

void loop() {
  button.tick();

  unsigned long currentMillis = millis();

  if (isBlinking1) {
    if (currentMillis - lastBlinkTime1 >= blinkInterval) {
      lastBlinkTime1 = currentMillis;
      led1State = !led1State;
      digitalWrite(LED1_PIN, led1State ? HIGH : LOW);
    }
  }

  if (isBlinking2) {
    if (currentMillis - lastBlinkTime2 >= blinkInterval) {
      lastBlinkTime2 = currentMillis;
      led2State = !led2State;
      digitalWrite(LED2_PIN, led2State ? HIGH : LOW);
    }
  }
}