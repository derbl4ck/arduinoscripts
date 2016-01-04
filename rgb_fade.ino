/**
 * @overview Uses a rgb led and fades between all colors
 * @author Lukas 'derbl4ck' Berwanger
 * @copyright (c) derbl4ck
 */

// set rgb led pins on the microcontroller
int g_pin = 11;
int b_pin = 10;
int r_pin = 9;

// set start color (in this case it will be red)
int r_val = 0;
int g_val = 255;
int b_val = 255;

void setup() {

  // define that rgb pins will be used as output
  pinMode(r_pin, OUTPUT);
  pinMode(g_pin, OUTPUT);
  pinMode(b_pin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

    //
    // for each color fade a loop
    //

    while (r_val != 255) {
      analogWrite(r_pin, r_val);
      analogWrite(g_pin, g_val);

      r_val++;
      g_val--;

      delay(20);
    }

    while (g_val != 255) {
      analogWrite(g_pin, g_val);
      analogWrite(b_pin, b_val);

      g_val++;
      b_val--;

      delay(20);
    }

    while (b_val != 255) {
      analogWrite(b_pin, b_val);
      analogWrite(r_pin, r_val);

      b_val++;
      r_val--;

      delay(20);
    }

}
