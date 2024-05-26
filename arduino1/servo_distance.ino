
#include <Servo.h>

const int triggerPin = 8;
const int echoPin1 = 9;
const int echoPin2 = 10;
const int echoPin3 = 11;
const Servo myservo;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(13);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  Serial.begin(9600);
}

void loop() {

  
  long duration1, distance1, duration2, distance2, duration3, distance3;

  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1 / 2) / 29.1;

  delay(60);
  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2 / 2) / 29.1;

  delay(60);
  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = (duration3 / 2) / 29.1;

  delay(60);

  if (distance1 < 34 &&  distance2 > 34) {

    // Serial.println(distance1);

    // Serial.println(distance2);

    // Serial.println(distance3);

    // Serial.print('\n');
    // Serial.print('\n');


    myservo.write(140);

  }

  else if (distance1 < 34 && distance2 < 34) {

    // Serial.println(distance1);

    // Serial.println(distance2);

    // Serial.println(distance3);

    // Serial.print('\n');
    // Serial.print('\n');


    myservo.write(115);
  }

  else if (distance1 > 34 && distance2 < 34 && distance3 > 34) {

    // Serial.println(distance1);

    // Serial.println(distance2);

    // Serial.println(distance3);

    // Serial.print('\n');
    // Serial.print('\n');


    myservo.write(90);
  }

  else if (distance2 < 34 && distance3 < 34) {

    // Serial.println(distance1);

    // Serial.println(distance2);

    // Serial.println(distance3);

    // Serial.print('\n');
    // Serial.print('\n');


    myservo.write(60);
  }

  else if (distance3 < 34 && distance2 > 34) {

    // Serial.println(distance1);

    // Serial.println(distance2);

    // Serial.println(distance3);

    // Serial.print('\n');
    // Serial.print('\n');


    myservo.write(40);
  }

  delay(100);
}
