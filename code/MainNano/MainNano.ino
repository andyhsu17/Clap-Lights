#include <SoftwareSerial.h>

int sound_sensor = 4;
int lampRelay = 5;
int rgbRelay =7;
int sidenanoStopMusic = 6;
int sidenanoStartMusic = 8;

int clap = 0;
long detection_range_start = 0;
long detection_range = 0;
boolean sexy_mode = false;

SoftwareSerial BTserial(2,3); // Rx and Tx

void setup() {
  pinMode(sound_sensor, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  pinMode(lampRelay, OUTPUT);
  pinMode(rgbRelay, OUTPUT);
  digitalWrite(lampRelay, HIGH);
  digitalWrite(rgbRelay, LOW);
  pinMode(sidenanoStartMusic, OUTPUT);
  pinMode(sidenanoStopMusic, OUTPUT);
  digitalWrite(sidenanoStartMusic, LOW); // digital trigger side nano to start music
  digitalWrite(sidenanoStopMusic, LOW); // digital trigger side nano to start music
  BTserial.begin(9600);
}

void loop() {
  
    int status_sensor = digitalRead(sound_sensor);
    if (status_sensor == 0) { // trigerred
      
      if (clap == 0)  { // first clap 
        
        detection_range_start = detection_range = millis();
        clap++;
 
      }
      else if (clap > 0 && millis()-detection_range >= 50) {
        
        detection_range = millis();
        clap++;
      }
    }
    
    if (millis()-detection_range_start >= 400)
    {

      if (clap == 2) {

        if (!sexy_mode) {

          sexy_mode = true; // turn on sexy mode
          
          digitalWrite(lampRelay, LOW); // Turn off Lamp

          digitalWrite(rgbRelay, HIGH); // Turn on rgb

          digitalWrite(sidenanoStartMusic, HIGH); // digital trigger side nano to start music
          delay(50);
          digitalWrite(sidenanoStartMusic, LOW);

          BTserial.write('p');        // bluetooth trigger to start candle

        }
        else if (sexy_mode) {

          sexy_mode = false;  // turn off sexy mode
          
          digitalWrite(lampRelay, HIGH); // Turn on Lamp

          digitalWrite(rgbRelay, LOW); // Turn off rgb

          digitalWrite(sidenanoStopMusic, HIGH); // digital trigger nano to stop music
          delay(50);
          digitalWrite(sidenanoStopMusic, LOW);
        
        }
          delay(500);
      }
      
      clap = 0;
    }
  
}
