#include <TrinketKeyboard.h>
 
int LED = 1;
int redButton = 0;
int blackButton = 2;
 
void setup() {
  pinMode(redButton, INPUT_PULLUP); // button pins as inputs with internal pullup resistors
  pinMode(blackButton, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  TrinketKeyboard.begin(); // start USB keyboard
}

void redButtonFunction() {
  digitalWrite(LED, HIGH);
  TrinketKeyboard.pressKey(KEYCODE_MOD_LEFT_SHIFT, KEYCODE_A);
  TrinketKeyboard.pressKey(0, 0);
  delay(100);
}

void blackButtonFunction() {
  digitalWrite(LED, HIGH);
  TrinketKeyboard.print("Hello World!");
}

void loop() {
  TrinketKeyboard.poll(); // the poll function must be called at least once every 10 ms
  delay(5); // to help debounce the inputs
  if (digitalRead(redButton) == LOW) {redButtonFunction();} // if pressed call the firstButton function
  if (digitalRead(blackButton) == LOW) {blackButtonFunction();}
  digitalWrite(LED, LOW);
}
