// send a email and password when button is pressed

String email = "example@example.com";
String password = "thisisaweakpassword";
const int enrolButton = 2;
const int loginButton = 3;
const int enrolLED = 11;
const int loginLED = 13;

#include <Bounce.h>
Bounce button1 = Bounce(enrolButton, 10); // 10 ms debouce
Bounce button2 = Bounce(loginButton, 10);
void setup() {
  pinMode(enrolButton, INPUT_PULLUP);
  pinMode(loginButton, INPUT_PULLUP);
  pinMode(enrolLED, OUTPUT);
  pinMode(loginLED, OUTPUT);
  digitalWrite(enrolLED, HIGH);
  digitalWrite(loginLED, HIGH);
}

void loop() {
  button1.update();
  button2.update();
  if(button1.fallingEdge()) {enrol();}
  if(button2.fallingEdge()) {login();}
}

void enrol() {
  // key sequence to select the keyboard type, press enter,
  // then ctrl-alt-e to enrol
  // then enter twice (with delays) to accept the agreements
  Keyboard.begin();
  //Keyboard.print(KEY_ENTER);
  //Keyboard.print(KEY_DOWN);
  //Keyboard.print(KEY_TAB);
  //delay(1000);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('e');
  delay(50);
  Keyboard.releaseAll();
  Keyboard.end();
  digitalWrite(enrolLED, LOW);
  delay(1000);
}

void login() {
  Keyboard.begin();
  Keyboard.print(email);
  Keyboard.press(KEY_TAB); //tab to get to the password field
  delay(50);
  Keyboard.releaseAll();
  Keyboard.print(password);
  Keyboard.press(KEY_ENTER);
  delay(50);
  Keyboard.releaseAll();
  Keyboard.end();
  digitalWrite(loginLED, LOW);
  delay(1000);
}
