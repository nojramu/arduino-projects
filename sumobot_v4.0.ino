//Colegio de Montalban, Rodriguez, Rizal, Phil. - BSCpE 2018-2022
#include <NewPing.h>
//(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE)
NewPing sonar1(A2,A3,60);//A
int disa;
//IR SENSORS
int irfront = 0;//A0
int irback = 0;//A1
//MOTOR ANALOG PWM PINS 
const int ina = 5;//dir1
const int inb = 6;//pwm1
const int inc = 9;//dir2
const int ind = 10;//pwm2
//PHYSICS
int marker = 0;//tactics to find enemy
const int lim = 20;//is enemy near?
const int spd = 225;//max speed
const int slw = 150;//slower speed
const int fdly = 100;//faster delay, less strength
const int sdly = 500;//slower delay, more strength


void setup() {//run once
  Serial.begin(9600);
  delay(4500);
  digitalWrite(ina,HIGH);
  analogWrite(inb,spd);
  digitalWrite(inc,HIGH);
  analogWrite(ind,spd);
  Serial.println("forward");
  delay(sdly);
  digitalWrite(ina,LOW);
  analogWrite(inb,0);
  digitalWrite(inc,LOW);
  analogWrite(ind,0);
}

void stage() {
  irfront = digitalRead(A0);
  irback = digitalRead(A1);
  if (irfront == LOW && irback == LOW){//All black
    disa = sonar1.ping_cm();
    delay(10);
    if (disa > 0){// found something
      marker = 2;
      while (disa < lim){//enemy near
        forward();
        disa = sonar1.ping_cm();
        delay(sdly);
        irfront = digitalRead(A0);
        irback = digitalRead(A1);
        if (irfront == HIGH || irback == HIGH){
          pause();
          break;
        }
      }
       while (disa < lim){//enemy far
        forward();
        disa = sonar1.ping_cm();
        delay(fdly);
        irfront = digitalRead(A0);
        irback = digitalRead(A1);
        if (irfront == HIGH || irback == HIGH){
          pause();
          break;
        }
      }
    }
    else{// found nothing
      if (marker == 0){
        forward();
        delay(fdly);
        pause();
        delay(10);
      }
      else if (marker == 1){
        drift();
        delay(fdly);
        pause();
        delay(10);
      }
      else if (marker == 2){
        left();
        delay(fdly);
        pause();
        delay(10);
      }
      else if (marker == 3){
        right();
        delay(fdly);
        pause();
        delay(10);
      }
    }
  }
  else if (irfront == HIGH && irback == HIGH){//All white
      Serial.println("error1");
      marker = 2;
      rotate();
      delay(sdly);
      pause();
  }
  else if (irfront == HIGH && irback == LOW){
    Serial.println("error2");
    marker = 1;
    reverse();
    delay(sdly);
    pause();
  }
  else if (irfront == LOW && irback == HIGH){
      Serial.println("error3");
      disa = sonar1.ping_cm();
      delay(10);
    if (disa < lim){// found something
      marker = 3;
      forward();
      delay(sdly);
      drift();
      delay(sdly);
      pause();
    }
    else{// found nothing
      marker = 0;
      forward();
      delay(sdly);
      pause();
    }
  }
}
//dir1,pwm1,dir2,pwm2
void forward() {
  digitalWrite(ina,HIGH);
  analogWrite(inb,spd);
  digitalWrite(inc,HIGH);
  analogWrite(ind,spd);
  Serial.println("forward");
}
void rotate(){
  digitalWrite(ina,LOW);
  analogWrite(inb,spd);
  digitalWrite(inc,HIGH);
  analogWrite(ind,spd);
  Serial.println("rotate");
}
void left(){
  digitalWrite(ina,HIGH);
  analogWrite(inb,slw);
  digitalWrite(inc,HIGH);
  analogWrite(ind,spd);
  Serial.println("left");
}
void right(){
  digitalWrite(ina,HIGH);
  analogWrite(inb,spd);
  digitalWrite(inc,HIGH);
  analogWrite(ind,slw);
  Serial.println("right");
}
void reverse() {
  digitalWrite(ina,LOW);
  analogWrite(inb,spd);
  digitalWrite(inc,LOW);
  analogWrite(ind,spd);
  Serial.println("reverse");
}
void pause(){
  digitalWrite(ina,LOW);
  analogWrite(inb,0);
  digitalWrite(inc,LOW);
  analogWrite(ind,0);
  Serial.println("pause");
}
void drift(){
  digitalWrite(ina,LOW);
  analogWrite(inb,spd);
  digitalWrite(inc,LOW);
  analogWrite(ind,slw);
  Serial.println("drift");
}

void loop() {
  stage();
}
