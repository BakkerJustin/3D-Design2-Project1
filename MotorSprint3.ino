//https://www.instructables.com/Servo-Motor-Arduino/
 
 #include <Servo.h>;

 int led = 5;
 
 // pushbutton pin
 const int buttonPin = 8;

 // servo pin
 const int servoPin = 3;
 Servo servo;


//create a variable to store a counter and set it to 0
int counter = 0;
void setup()


{
  pinMode(led, OUTPUT);
  servo.attach (servoPin);
  
  // Set up the pushbutton pins to be an input:
  pinMode(buttonPin, INPUT);
}


void loop()


{
  digitalWrite(led, HIGH);
 // local variable to hold the pushbutton states
  int buttonState;  

  //read the digital state of buttonPin with digitalRead() function and store the           //value in buttonState variable
  buttonState = digitalRead(buttonPin);

  //if the button is pressed increment counter and wait a tiny bit to give us some          //time to release the button
  if (buttonState == LOW) // light the LED
  {
    counter++;
    delay(150);
  }

  if(counter == 0)
    servo.write (30);  // zero degrees
  else if(counter == 1)
    servo.write(130);

  //else reset the counter to 0 which resets thr servo to 0 degrees
  else
   counter = 0;
}
