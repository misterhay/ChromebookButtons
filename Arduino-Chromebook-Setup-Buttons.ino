
// send a username and password when button is pressed
var enrolButton = 2;
var loginButton = 3;
var enrolLED = 4;
var loginLED = 5;

void setup() {
  pinMode(enrolButton, INPUT_PULLUP); // consider debouncing these
  pinMode(loginButton, INPUT_PULLUP);
  pinMode(enrolLED, OUTPUT);
  pinMode(loginLED, OUTPUT);
  // do I need to add a delay here while the computer sets up?
  digitalWrite(enrolLED, HIGH);
  digitalWrite(loginLED, HIGH)
}

void loop() {
  if(digitalRead(enrolButton)==LOW_){
    i = enrol();
  }
  if(digitalRead(loginButton)==LOW_){
    i = login();
  }
}

void enrol() {
  // key sequence to select the keyboard type, press enter,
  // then ctrl-alt-e to enrol
  // then enter twice (with delays) to accept the agreements
  Keyboard.begin();
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('e');
  Keyboard.releaseAll();
  Keyboard.end();
  digitalWrite(enrolLED, LOW);
}

void login() {
  Keyboard.begin();
  Keyboard.print('example@example.com'); //the email address
  Keyboard.print(KEY_TAB); //tab to get to the password field
  Keyboard.print('thisisaweakpassword');
  Keyboard.end();
  digitalWrite(loginLED, LOW);
}
