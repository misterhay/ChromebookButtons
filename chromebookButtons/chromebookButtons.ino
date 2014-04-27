// send a email and password when button is pressed
String email = "example@example.com";
String password = "thisisaweakpassword";
const int enrolButton = 2;
const int loginButton = 3;
const int enrolLED = 11;
const int loginLED = 13;

void setup() {
  pinMode(enrolButton, INPUT_PULLUP); // consider debouncing these
  pinMode(loginButton, INPUT_PULLUP);
  pinMode(enrolLED, OUTPUT);
  pinMode(loginLED, OUTPUT);
  digitalWrite(enrolLED, HIGH);
  digitalWrite(loginLED, HIGH);
}

void loop() {
  if(digitalRead(enrolButton)==LOW){
    enrol();
  }
  if(digitalRead(loginButton)==LOW){
    login();
  }
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
  Keyboard.releaseAll();
  Keyboard.end();
  digitalWrite(enrolLED, LOW);
}

void login() {
  Keyboard.begin();
  Keyboard.print(email);
  Keyboard.print(KEY_TAB); //tab to get to the password field
  Keyboard.print(password);
  Keyboard.end();
  digitalWrite(loginLED, LOW);
}
