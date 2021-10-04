//PROJECT NOTES

//servo attack angles are 175 - 156



#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial BTserial(2, 3);  // 2 is RX, 3 is TX
Servo servo;
int angle = 175;
int arcLighter = 10;
int servoPin = 4;
char c;

void setup()
{
  BTserial.begin(9600);
  servo.attach(servoPin);
  servo.write(angle);
  pinMode(arcLighter, OUTPUT);
  pinMode(arcLighter, OUTPUT);
  digitalWrite(arcLighter, HIGH);
}


void loop() 
{
  
  if (BTserial.available()) // turn this boolean variable to true when we recieve the bluetooth signal 
  {
    c = BTserial.read(); // stores the character received
    if(c == 'p') {    // if we received the start command

        //  Trigger to push butane
        for(angle = 175; angle > 155; angle--)
        {
          servo.write(angle);
        }
        delay(300);
        digitalWrite(arcLighter, LOW);  // write arclighter low to ground bias base of BJT
        delay(300);
        digitalWrite(arcLighter, HIGH); // bring up bias of BJT again
        delay(2250);
        // pull away from butane
        for(angle = 156; angle < 176; angle++)
        {
          servo.write(angle);
        }
    }
//    if(c == 'p') {    // if we received the start command
//
//   
//        digitalWrite(arcLighter, LOW);  // write arclighter low to ground bias base of BJT
//        delay(200);
//        digitalWrite(arcLighter, HIGH); // bring up bias of BJT again
//    }

  }
  
//  digitalWrite(10, LOW);
//  delay(500);
//  digitalWrite(10, HIGH);
//  delay(3000);
  

}
