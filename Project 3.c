const int led1 = 2;
const int led2 = 3;
const int led3 = 4;
const int echoPin = 7;
const int trigPin = 9;
const int buzzer = 16;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
}

void loop()
{
  // establish variables for duration of the ping, 
  // and the dist ance result in inches and centimeters:
  long duration, inches, cm;

  //VCC
  pinMode(A0, OUTPUT);
  digitalWrite(A0, HIGH);
  //LED1
  pinMode(led1, OUTPUT);
  digitalWrite(led1, HIGH);
  //LED2
  pinMode(led2, OUTPUT);
  digitalWrite(led2, HIGH);
  //LED3
  pinMode(led3, OUTPUT);
  digitalWrite(led3, HIGH);

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
   delay(20);
  inches = microsecondsToInches(duration);
  
  Serial.print(inches);
  Serial.print(" in, ");
  Serial.println();
  
  delay(30);

  pinMode(buzzer, OUTPUT);
  if(inches < 1)
  {
    digitalWrite(buzzer, HIGH);
    digitalWrite(led1, LOW);
    delay(10);
    digitalWrite(led1, HIGH);
    digitalWrite(buzzer, LOW);  
  }
}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}