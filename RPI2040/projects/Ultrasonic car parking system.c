#define TRIG2 5
#define ECHO2 6
#define TRIG1 7
#define ECHO1 8
#define TRIG4 9
#define ECHO4 10
#define TRIG5 11
#define ECHO5 14
#define TRIG6 28
#define ECHO6 29
#define TRIG3 26
#define ECHO3 27

void setup() {
  Serial.begin(115200);

  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);

  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);

  pinMode(TRIG3, OUTPUT);
  pinMode(ECHO3, INPUT);

  pinMode(TRIG4, OUTPUT);
  pinMode(ECHO4, INPUT);

    pinMode(TRIG5, OUTPUT);
  pinMode(ECHO5, INPUT);

  pinMode(TRIG6, OUTPUT);
  pinMode(ECHO6, INPUT);

  
}

float readUltrasonic(int trigPin, int echoPin) {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  float distance = duration * 0.0343 / 2;

  return distance;
}

void loop() {

  float distance1 = readUltrasonic(TRIG1, ECHO1);
  (distance1<=10)?Serial.print("SLOT 1:PARKED   "):Serial.print("SLOT 1:FREE  ");
  delay(50);   // small gap to avoid interference

  float distance2 = readUltrasonic(TRIG2, ECHO2);
  (distance2<=10)?Serial.print("SLOT 2:PARKED  "):Serial.print("SLOT 2:FREE  ");
  delay(50);
  float distance3 = readUltrasonic(TRIG3, ECHO3);
  (distance3<=10)?Serial.print("SLOT 2:PARKED   "):Serial.print("SLOT 3:FREE   ");
  delay(50);   // small gap to avoid interference

  float distance4 = readUltrasonic(TRIG4, ECHO4);
  (distance4<=10)?Serial.print("SLOT 4:PARKED  "):Serial.print("SLOT 4:FREE   ");
   delay(50);
  float distance5 = readUltrasonic(TRIG5, ECHO5);
  (distance5<=10)?Serial.print("SLOT 5:PARKED   "):Serial.print("SLOT 5:FREE  ");
  delay(50);   // small gap to avoid interference5
  float distance6 = readUltrasonic(TRIG6, ECHO6);

  (distance6<=10)?Serial.print("SLOT 6:PARKED   "):Serial.print("SLOT 6:FREE   ");
  delay(50); 
  Serial.println();
  
delay(500);

}
