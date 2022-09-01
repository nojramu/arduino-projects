#include <Servo.h>
Servo myservo1;
Servo myservo2;
#define echoPin 6
#define trigPin 5
boolean up = false;
long duration;
int pos = 90;
int val1;
int val2;
int val3;
int lim;
int i = 0;

void setup(){
  myservo1.attach(9);// rotation
  myservo2.attach(10);// finger
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(trigPin, OUTPUT);// left
  pinMode(echoPin, INPUT);// right
  Serial.begin(9600);
}
   
void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  val1 = analogRead(A0);
  val2 = analogRead(A1);
  val1 = map(val1, 0, 525, 0, 5);
  val2 = map(val2, 60, 600, 0, 5);
  val3 = (duration/2)/74;
  Serial.print("left "); 
  Serial.println(val1);
  Serial.print("right  "); 
  Serial.println(val2);
  Serial.print("x degree "); 
  Serial.println(pos);
  Serial.print("distance ");
  Serial.println(val3);
  Serial.print("boolean ");
  Serial.println(up);
  Serial.print("y degree ");
  Serial.println(i);
  
   if (up == true && val3 > 5){
    for (i=180;i>=0;i-=10){
        myservo2.write(i);
    }
    up = false;
    }
   else if (up == false && val3 < 5){
    for (i=0;i<=180;i+=10){
        myservo2.write(i);
    }
    up = true;
    }
   if (val1 > val2){
     pos = pos + 5;
     myservo1.write(pos);
    }
   else if (val1 < val2){
     pos = pos - 5;
     myservo1.write(pos); 
    }
    lim=pos;
   if(lim <= 0){
     pos=0;
    }
   else if(lim >= 180){
     pos=180;
    }
    
  delay(15);
}
