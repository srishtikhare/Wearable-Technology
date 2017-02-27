const int trigPin = 2;  Trigger pin set to pin 2 of microcontroller
const int echoPin = 5;  Echo pin set to pin 2 of microcontroller
const int buzzer = 15;  Buzzer input pin set to pin 2 of microcontroller

void setup() {
}

void loop()
{
   establish variables for duration of the ping, 
   and the distance result in inches and centimeters
  long duration, inches, cm;

   The sensor is triggered by a HIGH pulse of 10 or more microseconds.
   Give a short LOW pulse beforehand to ensure a clean HIGH pulse
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

   Read the signal from the sensor a HIGH pulse whose
   duration is the time (in microseconds) from the sending
   of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

   convert the time into a distance
  inches = microsecondsToInches(duration);

  pinMode(buzzer, OUTPUT);
  if(inches = 14)
  {
    digitalWrite(buzzer, HIGH);
    delay(10);
    digitalWrite(buzzer, LOW);
    delay(10);
    digitalWrite(buzzer, HIGH);
    delay(10);
    digitalWrite(buzzer, LOW);
    delay(10);   
  }
}

long microsecondsToInches(long microseconds)
{
   According to Parallax's datasheet for the PING))), there are
   73.746 microseconds per inch (i.e. sound travels at 1130 feet per
   second).  This gives the distance travelled by the ping, outbound
   and return, so we divide by 2 to get the distance of the obstacle.
   See httpwww.parallax.comdldocsprodacc28015-PING-v1.3.pdf
  return microseconds  74  2;
}
