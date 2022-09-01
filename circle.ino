const int a = 4;
const int b = 5;
const int c = 6;
const int d = 7;
const int e = 8;
const int f = 9;
const int g = 10;
const int h = 11;
const int btn1 = 3;
const int btn2 = 2;
bool run = true;
int val1 = 0;
int val2 = 0;
int i = 0;
int r = 0;

void setup()
{
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(h, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
}

void range(){
    if(r==8){
    i=0;}
}

void slice(int s)
{
 if(s==0 || s ==7)
    digitalWrite(a,HIGH);
 if(s==1 || s ==0)
    digitalWrite(b,HIGH);
 if(s==2 || s ==1)
    digitalWrite(c,HIGH);
 if(s==3 || s ==2)
    digitalWrite(d,HIGH);
 if(s==4 || s ==3)
    digitalWrite(e,HIGH);
 if(s==5 || s ==4)
    digitalWrite(f,HIGH);
 if(s==6 || s ==5)
    digitalWrite(g,HIGH);
 if(s==7 || s ==6)
    digitalWrite(h,HIGH);
    
}

void turnOff()
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  digitalWrite(h,LOW);
}

void loop()
{
  val1 = digitalRead(btn1);
  val2 = digitalRead(btn2);
    
if(val1 == HIGH){
    run=true;
    }
else if(val2 == HIGH){
    run=false;
    }
    
if(run==true){
    slice(i);
    delay(25);
    i++;
    r=(i);
    turnOff();
    range();
    }
 else if(run==false){
    slice(i);
 }
}
