//by NOJRAMU
//Led
const int a = 2;
const int b = 3;
const int c = 4;
const int d = 5;
const int e = 6;
const int f = 8;
const int g = 9;
//Buttons
const int b1 = A0;//Increment
const int b2 = A1;//Decrement
const int b3 = A2;//Stop
const int b4 = A3;//Go
//Availability Marker
int m1,m2,m3,m4;
//Variables
int value;
bool dir = true;
bool mov = false;

void setup() {
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(b4, INPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  Serial.begin(9600);
}

void disp(int i){
 if(i !=1 && i != 4 && i != 11 && i != 13)
 digitalWrite(a,HIGH);

 if(i != 5 && i != 6 && i != 11 && i != 12 && i != 14 && i != 15)
 digitalWrite(b,HIGH);
 
 if(i != 2 && i != 12 && i != 14 && i != 15)
 digitalWrite(c,HIGH);
 
 if(i != 1 && i != 4 && i != 7 && i != 10 && i != 15)
 digitalWrite(d,HIGH);
 
 if(i != 1 && i != 3 && i != 4 && i != 5 && i != 7 && i != 9)
 digitalWrite(e,HIGH);
 
 if(i != 1 && i != 2 && i != 3 && i != 7 && i != 13)
 digitalWrite(f,HIGH);
 
 if (i != 0 && i != 1 && i != 7 && i != 12)
 digitalWrite(g,HIGH);
}

void off()
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

void loop() {
  Serial.print("value ");
  Serial.println(value);
  Serial.print("direction ");
  Serial.println(dir);
  Serial.print("movement ");
  Serial.println(mov);
  m1 = digitalRead(b1);
  m2 = digitalRead(b2);
  m3 = digitalRead(b3);
  m4 = digitalRead(b4);
  if (m1 == HIGH){
    dir = true;
    mov = true;
  }
  if (m2 == HIGH){
    dir = false;
    mov = true;
  }
  if (m3 == HIGH){
    mov = false;
  }
  if (m4 == HIGH){
    mov = true;
  }
  if (dir == true && mov == true){
    value++;
  }
  if (dir == false && mov == true){
    value--;
  }
  if (value > 15){
    value = 0;
  }
  if (value < 0){
    value = 15;
  }
  disp(value);
  delay(1000);
  off();
}
