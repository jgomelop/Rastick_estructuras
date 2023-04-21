/*
  Ultrasonic Sensor HC-SR04 and Arduino Tutorial

  by Dejan Nedelkovski,
  www.HowToMechatronics.com

*/
// defines pins numbers
const int trigPin1 = 9;
const int echoPin1 = 10;

const int trigPin2 = 5;
const int echoPin2 = 6;
// defines variables
long duration1;
int distance1;

long duration2;
int distance2;

const int MIN_DISTANCE = 55;


void setup() {
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}

long getDuration(int trigPin, int echoPin){
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void printingDistances(int d1, int d2 ){
  if (d1 <= MIN_DISTANCE || d2 <= MIN_DISTANCE){
    Serial.println("OBSTÁCULO");
  } 
  else {
    Serial.print("Distance1: ");
    Serial.print(d1);
    Serial.print(" Distance2: ");
    Serial.println(d2);
  }
}

void print(int d1, int d2){
  Serial.print("Distance1: ");
  Serial.print(d1);
  Serial.print(" Distance2: ");
  Serial.println(d2);
}

void loop() {

  // Calculating the distance
  distance1 = getDuration(trigPin1, echoPin1) * 0.034 / 2;
  delayMicroseconds(10);
  distance2 = getDuration(trigPin2, echoPin2) * 0.034 / 2;

  // Prints the distance on the Serial Monitor
  //printingDistances(distance1, distance2);
  print(distance1, distance2);

  // Wait for 1 sec until next measurement.
  delay(100);
}