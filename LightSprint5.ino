// Code sourced from https://create.arduino.cc/projecthub/guruashishchoudhary29/turn-led-on-and-off-through-ldr-fe5738

int ldr=A0;//Set A0(Analog Input) for LDR.
int value=0;
void setup() {
Serial.begin(9600);
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
}

void loop() {
value=analogRead(ldr);//Reads the Value of LDR(light).
Serial.println("LDR value is :");//Prints the value of LDR to Serial Monitor.
Serial.println(value);
if(value<50)
  {
    digitalWrite(3,HIGH);//Makes the LED glow in Dark.
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
  }
  else
  {
    digitalWrite(3,LOW);//Turns the LED OFF in Light.
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
  }
}
