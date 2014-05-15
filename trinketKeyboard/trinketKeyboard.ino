#include <TrinketKeyboard.h>
 
int LED = 1;
int button1 = 0;
int button2 = 2;
 
void setup() {
  pinMode(button1, INPUT_PULLUP); // button pins as inputs with internal pullup resistors
  pinMode(button2, INPUT_PULLUP);
  TrinketKeyboard.begin(); // start USB keyboard
}

void firstButton() {
  TrinketKeyboard.pressKey(KEYCODE_MOD_LEFT_SHIFT, KEYCODE_A);
  TrinketKeyboard.pressKey(0, 0);
  delay(100);
}

void secondButton() {
  TrinketKeyboard.print("Hello World!");
}

void loop() {
  TrinketKeyboard.poll(); // the poll function must be called at least once every 10 ms
  delay(5); // to help debounce the inputs
  if (digitalRead(button1) == LOW) {firstButton();} // if pressed call the firstButton function
  if (digitalRead(button2) == LOW) {secondButton();}
}
