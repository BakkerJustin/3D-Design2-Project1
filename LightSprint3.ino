/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/

int led = 9;           // the PWM pin the LED is attached to
int led1 = 6;           // the PWM pin the LED is attached to
int led2 = 3;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int brightness1 = 5;    // how bright the LED is
int brightness2 = 1;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int fadeAmount1 = 5;    // how many points to fade the LED by
int fadeAmount2 = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(led, brightness);
  analogWrite(led1, brightness1);
  analogWrite(led2, brightness2);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;
  brightness1 = brightness1 + fadeAmount1;
  brightness2 = brightness2 + fadeAmount2;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  if (brightness1 <= 0 || brightness1 >= 127) {
    fadeAmount1 = -fadeAmount1;
  }

  if (brightness2 <= 0 || brightness2 >= 50) {
    fadeAmount2 = -fadeAmount2;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
