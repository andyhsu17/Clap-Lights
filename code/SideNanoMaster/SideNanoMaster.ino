#include <SoftwareSerial.h>

SoftwareSerial BTserial(2,3); // Rx and Tx
int sidenanoStopMusic = 6;
int sidenanoStartMusic = 8;

int previousStartState = LOW;
int previousStopState = LOW;
int startState = LOW;
int stopState = LOW;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.write("serial connected");
  BTserial.begin(9600);
  pinMode(sidenanoStartMusic, INPUT);
  pinMode(sidenanoStopMusic, INPUT);

}

void loop() {

  //if (BTserial.available()) {

  //  Serial.write(BTserial.read());
//  }
  
  //if (Serial.available()) {
    //Serial.write(Serial.read());
//    BTserial.write(Serial.read());
 // }
    startState = digitalRead(sidenanoStartMusic);
    stopState = digitalRead(sidenanoStopMusic);
    
    if(startState == HIGH) {
        if(previousStartState == LOW) {
              BTserial.write('p');
              BTserial.flush();
        }
    }
    previousStartState = startState;
    
    if(stopState == HIGH) {
        if(previousStopState == LOW) {
            BTserial.write('s');
            BTserial.flush();
        }
    }
