#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(8);
  servo.write(angle);
}

void loop() 
{ 
 // scan from 0 to 180 degrees
  for(angle = 0; angle < 100; angle++)  
  {                                  
    servo.write(angle);               
    delay(15);                   
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 100; angle > 0; angle--)    
  {                                
    servo.write(angle);           
    delay(15);       
  } 
}
