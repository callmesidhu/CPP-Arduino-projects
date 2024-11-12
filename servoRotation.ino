#include <Servo.h>

Servo myServo;  

void setup() {
  myServo.attach(9);  
}

void loop() {

  myServo.write(10);
  delay(700);    
  myServo.write(20);
  delay(700);  
  myServo.write(30);
  delay(700);    
  myServo.write(40);
  delay(700);
  myServo.write(50);
  delay(700);    
  myServo.write(60);
  delay(700);
  myServo.write(70);
  delay(700);    
  myServo.write(80);
  delay(700);
  myServo.write(90);
  delay(700);    
  myServo.write(180);
  delay(700);
}
