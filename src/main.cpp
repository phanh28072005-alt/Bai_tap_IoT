#include <Arduino.h>
#include <OneButton.h>


const int BUTTON_PIN = 2; 
const int LED_PIN = 13;    
OneButton button(BUTTON_PIN, true);
bool ledState = false;      
bool isBlinking = false;    
unsigned long lastBlinkTime = 0;
const long blinkInterval = 500; 


void handleClick() {
  isBlinking = false;       
  ledState = !ledState;    
  digitalWrite(LED_PIN, ledState ? HIGH : LOW);
}


void handleDoubleClick() {
  isBlinking = !isBlinking; 
  if (!isBlinking) {
    ledState = false;
    digitalWrite(LED_PIN, LOW);
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  button.attachClick(handleClick);
  button.attachDoubleClick(handleDoubleClick);
  button.setClickMs(300);
}

void loop() {
 
  button.tick();
  if (isBlinking) {
    unsigned long currentMillis = millis();
    if (currentMillis - lastBlinkTime >= blinkInterval) {
      lastBlinkTime = currentMillis;
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState ? HIGH : LOW);
    }
  }
}