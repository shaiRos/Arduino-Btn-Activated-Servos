#include <Servo.h>

int buttonPin = 9;
int buttonOld = LOW;
int buttonNew;

bool on = false;

Servo ser1;
Servo ser2;
int serPin = 12;
int ser2Pin = 13;
int serPos = 0;

void setup() {

  //serail is a connection with your pc, this is mostly for debugging
  //the number is connection speed, here I'm using 9600 band. THey are pre-defined.
  Serial.begin(9600);

  //set the button pin as an input
  pinMode(buttonPin, INPUT);

  //indicate which pit set should be linked to
  ser1.attach(serPin);
  ser2.attach(ser2Pin);

  //sert initial pos for servos
  ser1.write(serPos);
  ser2.write(serPos);
}
void loop() { // loops run repeatedly
  delay(1000);

  // update position of servos
  ser1.write(serPos);
  ser2.write(serPos);

  // button click detection will switch the boolean on variable
  
  buttonNew = digitalRead(buttonPin);
  if (buttonOld == LOW && buttonNew == HIGH) {
     on = !on;
  }

  // turned on with a button press
  // may have to hold for 1-3s for it to turn off/on
  if (on == true) {
    // change how the servos rotate here
    if (serPos == 0) 
        serPos = 250;
    else
       serPos = 0;
  }

  buttonOld = buttonNew;


}
