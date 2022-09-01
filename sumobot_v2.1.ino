//Colegio de Montalban, Rodriguez, Rizal, Phil. - BSCpE 2018-2022
#include <NewPing.h>
//(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE)
NewPing sonar1(A2,A3,60);//A
NewPing sonar2(A4,A5,60);//B
int disa,disb;
//IR SENSORS
int irfront = 0;//A0
int irback = 0;//A1
//MOTOR ANALOG PWM PINS 
const int ina = 5;
const int inb = 6;
const int inc = 9;
const int ind = 10;
const int lim = 15;

void setup() {//run once
  Serial.begin(9600);
  delay(4500);
  analogWrite(ina,255);
  analogWrite(inb,0);
  analogWrite(inc,0);
  analogWrite(ind,255);
  Serial.println("forward");
  delay(1000);
  analogWrite(ina,0);
  analogWrite(inb,0);
  analogWrite(inc,0);
  analogWrite(ind,0);
}

void stage() {
  irfront = digitalRead(A0);
  irback = digitalRead(A1);
  if (irfront == LOW && irback == LOW){//All black
    disa = sonar1.ping_cm();
    disb = sonar2.ping_cm();
    delay(10);
    if (disa > 0 || disb > 0){// found something
      while (disa < lim && disb < lim){
        forward();
        disa = sonar1.ping_cm();
        disb = sonar2.ping_cm();
        delay(10);
        irfront = digitalRead(A0);
        irback = digitalRead(A1);
        if (irfront == HIGH || irback == HIGH){
          pause();
          break;
        }
      }
      while (disa > lim && disb < lim){
        left();
        disa = sonar1.ping_cm();
        disb = sonar2.ping_cm();
        delay(10);
        irfront = digitalRead(A0);
        irback = digitalRead(A1);
        if (irfront == HIGH || irback == HIGH){
          pause();
          break;
        }
      }
      while (disa < lim && disb > lim){
        right();
        disa = sonar1.ping_cm();
        disb = sonar2.ping_cm();
        delay(10);
        irfront = digitalRead(A0);
        irback = digitalRead(A1);
        if (irfront == HIGH || irback == HIGH){
          pause();
          break;
        }
      }
    }
    else{// found nothing
      rotate();
      delay(100);
      pause();
      delay(10);
    }
  }
  else if (irfront == HIGH && irback == HIGH){//All white
      rotate();
      delay(1000);
      drift();
      delay(1000);
      pause();
      Serial.println("error1");
  }
  else if (irfront == HIGH && irback == LOW){
    reverse();
    delay(1000);
    pause();
    Serial.println("error2");
  }
  else if (irfront == LOW && irback == HIGH){
      disa = sonar1.ping_cm();
      disb = sonar2.ping_cm();
      delay(10);
    if (disa > 0 || disb > 0){// found something
      rotate();
      delay(1000);
      drift();
      delay(1000);
      pause();
      Serial.println("error3");
    }
    else{// found nothing
      forward();
      delay(1000);
      pause();
    }
  }
}
  
void forward() {
  analogWrite(ina,255);
  analogWrite(inb,0);
  analogWrite(inc,0);
  analogWrite(ind,255);
  Serial.println("forward");
}
void rotate(){
  analogWrite(ina,255);
  analogWrite(inb,0);
  analogWrite(inc,255);
  analogWrite(ind,0);
  Serial.println("rotate");
}
void left(){
  analogWrite(ina,0);
  analogWrite(inb,0);
  analogWrite(inc,0);
  analogWrite(ind,255);
  Serial.println("left");
}
void right(){
  analogWrite(ina,255);
  analogWrite(inb,0);
  analogWrite(inc,0);
  analogWrite(ind,0);
  Serial.println("right");
}
void reverse() {
  analogWrite(ina,0);
  analogWrite(inb,255);
  analogWrite(inc,255);
  analogWrite(ind,0);
  Serial.println("reverse");
}
void pause(){
  analogWrite(ina,0);
  analogWrite(inb,0);
  analogWrite(inc,0);
  analogWrite(ind,0);
  Serial.println("pause");
}
void drift(){
  analogWrite(ina,0);
  analogWrite(inb,100);
  analogWrite(inc,255);
  analogWrite(ind,0);
  Serial.println("drift");
}

void loop() {
  stage();
}
