#include <Stepper.h>
#include <Joystick.h>

#define STEPS 32

#define IN1 11
#define IN2 10
#define IN3 9
#define IN4 8

Stepper stepper(STEPS, IN4, IN2,  IN3, IN1); //use 9-12V 

#define X_pin A0
#define Y_pin A1

void setup() {

}

void loop() {    
  int x = analogRead(X_pin);
  int y = analogRead(Y_pin); //not used

  if (x > 500 &&
    x < 523)
  { 
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }      
  else
  {
    while (x >= 523)
    {
      int speed = map(x, 523, 1023, 5, 500);
      stepper.setSpeed(speed);

      stepper.step(1);
 
      x = analogRead(X_pin);
    }
 
    while (x <= 500)
    {
      int speed = map(x, 500, 0, 5, 500);
      stepper.setSpeed(speed);

      stepper.step(-1);
 
      x = analogRead(X_pin);
    }
  }      
}