/**
 * @overview Uses a rgb led and a button. If button is pressed, the color changes
 * @author Lukas 'derbl4ck' Berwanger
 * @copyright (c) derbl4ck
 */

// set rgb led & button pins on the microcontroller
int r_pin = 9;
int g_pin = 11;
int b_pin = 10;
int button_pin = 7;

// set start color (in this case it will be red)
int r_val = 0;
int g_val = 255;
int b_val = 255;

// set default runmode and buttonstate
int runmode = 0;
int buttonstate = 0;

void setup() {

  // define that rgb pins will be used as output & button as input
  pinMode(r_pin, OUTPUT);
  pinMode(g_pin, OUTPUT);
  pinMode(b_pin, OUTPUT);
  pinMode(button_pin, INPUT);

  Serial.begin(9600);
}

void loop() {

  // get current button state
  buttonstate = digitalRead(button_pin);

  // change runmode with each button press & reset if its higher that our available modes
  if (buttonstate == HIGH) {
   if (runmode < 4) {
     runmode++;
   } else {
     runmode = 0;
   }
   delay(200);
  }

  // set the color for each mode
  if (runmode == 0){
    // red
    digitalWrite(r_pin, LOW);
    digitalWrite(g_pin, HIGH);
    digitalWrite(b_pin, HIGH);
  }else if(runmode == 1) {
    // green
    digitalWrite(r_pin, HIGH);
    digitalWrite(g_pin, LOW);
    digitalWrite(b_pin, HIGH);
  }else if(runmode == 2) {
    // blue
    digitalWrite(r_pin, HIGH);
    digitalWrite(g_pin, HIGH);
    digitalWrite(b_pin, LOW);
  }else if(runmode == 3) {
    // lightblue
    digitalWrite(r_pin, HIGH);
    digitalWrite(g_pin, LOW);
    digitalWrite(b_pin, LOW);
  }else if(runmode == 4) {
    // orange
    analogWrite(r_pin, 0);
    analogWrite(g_pin, 100);
    analogWrite(b_pin, 255);
  }
}
