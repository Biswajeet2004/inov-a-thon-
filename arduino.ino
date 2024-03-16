#include <IRremote.h>


const int IR1_PIN = 2;
const int IR2_PIN = 3; 


const int LED_PIN = 4; 


IRrecv irrecv1(IR1_PIN);
IRrecv irrecv2(IR2_PIN);


int peopleInside = 0;

void setup() {

  Serial.begin(9600);


  irrecv1.enableIRIn();
  irrecv2.enableIRIn();

 
  pinMode(LED_PIN, OUTPUT);


  digitalWrite(LED_PIN, LOW);
}

void loop() {

  if (irrecv1.decode()) {
    
    peopleInside += (peopleInside >= 0) ? 1 : -1;
    
    Serial.print("Total people inside: ");
    Serial.println(peopleInside);
   
    irrecv1.resume();
  }

 
  if (irrecv2.decode()) {
   
    peopleInside += (peopleInside <= 0) ? 1 : -1;
   
    Serial.print("Total people inside: ");
    Serial.println(peopleInside);
    
    irrecv2.resume();
  }

  
  digitalWrite(LED_PIN, peopleInside > 0 ? HIGH : LOW);
}
