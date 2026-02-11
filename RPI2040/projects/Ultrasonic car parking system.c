#define TRIG1 6
#define ECHO1 7
#define TRIG2 17
#define ECHO2 18
#define LED   4

void setup() {
  Serial.begin(115200);

  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);

  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);

  pinMode(LED, OUTPUT);

  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(16, OUTPUT);

  digitalWrite(5, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(16, HIGH);
  digitalWrite(19, LOW);
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
  delay(50);   // small gap to avoid interference

  float distance2 = readUltrasonic(TRIG2, ECHO2);

  Serial.print("SLOT 1: ");
  Serial.print(distance1);
  Serial.print(" cm   ");

  Serial.print("SLOT 2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  if (distance1 <= 5 || distance2 <= 5) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

  delay(200);
}
