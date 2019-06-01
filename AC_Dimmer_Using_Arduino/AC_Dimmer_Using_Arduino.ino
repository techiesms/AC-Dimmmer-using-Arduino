/*
 * This is the code for AC Dimmer using Arduino Board.
 * 
 * To watch it's full tutorial video, head on to my YouTube Channel
 * 
 * http://www.youtube.com/techiesms
 * 
 */


#define triacPulse 10
#define SW 7
#define ZVC 2

int x = 0;
void setup() {
  Serial.begin(115200);
  pinMode(ZVC, INPUT_PULLUP);
  //digitalWrite(2, INPUT_PULLUP); // pull up
  pinMode(A0, INPUT);
  pinMode(triacPulse, OUTPUT);
  pinMode(SW, INPUT);
  digitalWrite(SW, INPUT_PULLUP);
}

void loop() {

  //if (!digitalRead(SW)) 
  { // When the switch is closed
   int y = analogRead(A0);
    x= map(y,0,1024, 200,7200);
    
   Serial.println(digitalRead(ZVC));
    attachInterrupt(0, acon, FALLING); // attach Interrupt at PIN2
  }
  //else if (digitalRead(SW)) {
    //detachInterrupt(0); // Detach Interrupt
  //}
}

void acon()
{
  // Serial.println("REad");
   
  delayMicroseconds(x); // read AD0
  digitalWrite(triacPulse, HIGH);
  
  // Serial.println(digitalRead(triacPulse));
  
  delayMicroseconds(50);  //delay 50 uSec on output pulse to turn on triac
  digitalWrite(triacPulse, LOW);
  
  // Serial.println(digitalRead(triacPulse));
}
