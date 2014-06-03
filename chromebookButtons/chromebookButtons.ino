const int redButton = 0;
const int blackButton = 1;
const int LED = 11;

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

void redButtonFunction() {
  // key sequence to select the keyboard type, press enter,
  // then ctrl-alt-e to enrol
  // then enter twice (with delays) to accept the agreements
  Keyboard.begin();
  //Keyboard.print(KEY_ENTER);
  //Keyboard.print(KEY_DOWN);
  //Keyboard.print(KEY_TAB);
  //delay(1000);
  /*Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('e');
  delay(50);
  Keyboard.releaseAll();
  delay(3000);//*/
  Keyboard.print("this is the red button");
  Keyboard.press(KEY_TAB); //tab to get to the password field
  delay(50);
  Keyboard.releaseAll();
  Keyboard.print("this is also a test");
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
  Keyboard.press(KEY_TAB); //tab to get to the password field
  delay(50);
  Keyboard.releaseAll();
  Keyboard.print("this is also a test");
  Keyboard.press(KEY_ENTER);
  delay(50);
  Keyboard.releaseAll();
  Keyboard.end();
  digitalWrite(LED, LOW);
  delay(1000);
  Keyboard.press(KEY_TAB);
  delay(50);
  Keyboard.releaseAll();
  Keyboard.press(KEY_DOWN);
  delay(50);
  Keyboard.releaseAll();
  Keyboard.press(KEY_TAB);
  delay(50);
  Keyboard.releaseAll();
  Keyboard.press(KEY_TAB);
  delay(50);
  Keyboard.releaseAll();
  Keyboard.press(KEY_ENTER);
  delay(50);
  Keyboard.releaseAll();
  delay(5000);
  Keyboard.press(KEY_SPACE);
  delay(50);
  Keyboard.releaseAll();
}
