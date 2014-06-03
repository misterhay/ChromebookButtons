// For a Teensy, the red button is on pin 0 and the black is on pin 1
// the other side of the button should be connected to ground
// Edit the redButtonFunction and blackButtonFunction as you see fit
// For documentation, see https://www.pjrc.com/teensy/td_keyboard.html

const int redButton = 0;
const int blackButton = 1;
const int LED = 11;

void redButtonFunction() {
  Keyboard.begin();
  //Keyboard.print(KEY_ENTER);
  //Keyboard.print(KEY_DOWN);
  //Keyboard.print(KEY_TAB);
  //delay(1000);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_E);
  delay(50);
  Keyboard.releaseAll();
  delay(3000);
  Keyboard.print("example@email.com");
  Keyboard.press(KEY_TAB); //tab to get to the password field
  delay(50);
  Keyboard.releaseAll();
  Keyboard.print("thisisaweakpassword");
  Keyboard.press(KEY_ENTER);
  delay(50);
  Keyboard.releaseAll();
  Keyboard.end();
  digitalWrite(LED, LOW);
  delay(1000);
}

void blackButtonFunction() {
  Keyboard.begin();
  Keyboard.print("I'm testing this black button");
  Keyboard.releaseAll();
}

#include <Bounce.h>
Bounce redButtonDebounce = Bounce(redButton, 10); // 10 ms debouce
Bounce blackButtonDebounce = Bounce(blackButton, 10);

void setup() {
  pinMode(redButton, INPUT_PULLUP);
  pinMode(blackButton, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);  
  redButtonDebounce.update();
  blackButtonDebounce.update();
  if(redButtonDebounce.fallingEdge()) {redButtonFunction();}
  if(blackButtonDebounce.fallingEdge()) {blackButtonFunction();}
}
