#include <Servo.h>

Servo doorServo;

const int pirPin = 7;      
const int servoPin = 8;    
const int ledPin = 9;     // LED connected to GP13


void setup() {
  Serial.begin(9600);

  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(4, OUTPUT);


  doorServo.attach(servoPin);
  doorServo.write(0);   // Door closed

  digitalWrite(ledPin, LOW);  // LED OFF
  Serial.println("System Ready...");
}

void loop() {
  bool motion = digitalRead(pirPin);

  if (motion == 1 ) {
    Serial.println("Motion Detected → Opening Door");
    
    doorServo.write(90);        // Open door
    digitalWrite(ledPin, HIGH); // LED ON
    digitalWrite(4, HIGH); // LED ON
    
    
    delay(3000);
  }
else{

    Serial.println("Closing Door");
    
    doorServo.write(0);         // Close door
    digitalWrite(ledPin, LOW);  // LED OFF
    digitalWrite(4, LOW); 
    
    delay(2000);
  }
}
