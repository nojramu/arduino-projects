# define a1 11
# define a2 10
# define a3 9
# define a4 6
# define a5 5
# define a6 3
# define str 12
int brightness = 0;   

void setup()
{

pinMode(a1, OUTPUT);
pinMode(a2, OUTPUT);
pinMode(a3, OUTPUT);
pinMode(a4, OUTPUT);
pinMode(a5, OUTPUT);
pinMode(a6, OUTPUT);
pinMode(str, OUTPUT);

}
 void loop()
{
// star 1a
  digitalWrite(str, HIGH);

// right to left
  digitalWrite(a1, HIGH);
  delay(300);
  digitalWrite(a1, LOW);
  digitalWrite(a2, HIGH);
  delay(300);
  digitalWrite(a2, LOW);
  digitalWrite(a3, HIGH);
  delay(300);
  digitalWrite(a3, LOW);
  digitalWrite(a4, HIGH);
  delay(300);
  digitalWrite(a4, LOW);
  digitalWrite(a5, HIGH);
  delay(300);
  digitalWrite(a5, LOW);
  digitalWrite(a6, HIGH);
  delay(300);
  digitalWrite(a6, LOW);
  delay(200);
  
// star 1b
  digitalWrite(str, LOW);
  delay(500);
  digitalWrite(str, HIGH);
  
// left to right
  digitalWrite(a6, HIGH);
  delay(300);
  digitalWrite(a6, LOW);
  digitalWrite(a5, HIGH);
  delay(300);
  digitalWrite(a5, LOW);
  digitalWrite(a4, HIGH);
  delay(300);
  digitalWrite(a4, LOW);
  digitalWrite(a3, HIGH);
  delay(300);
  digitalWrite(a3, LOW);
  digitalWrite(a2, HIGH);
  delay(300);
  digitalWrite(a2, LOW);
  digitalWrite(a1, HIGH);
  delay(300);
  digitalWrite(a1, LOW);
  delay(500);
  
 // star 1c
  digitalWrite(str, LOW);
  delay(500);
  digitalWrite(str, HIGH);
  
  // blink
  digitalWrite(a1, HIGH);
  digitalWrite(a2, HIGH);
  digitalWrite(a3, HIGH);
  digitalWrite(a4, HIGH);
  digitalWrite(a5, HIGH);
  digitalWrite(a6, HIGH);
  delay(500);
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(a3, LOW);
  digitalWrite(a4, LOW);
  digitalWrite(a5, LOW);
  digitalWrite(a6, LOW);
  delay(500);
  digitalWrite(a1, HIGH);
  digitalWrite(a2, HIGH);
  digitalWrite(a3, HIGH);
  digitalWrite(a4, HIGH);
  digitalWrite(a5, HIGH);
  digitalWrite(a6, HIGH);
  delay(500);
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(a3, LOW);
  digitalWrite(a4, LOW);
  digitalWrite(a5, LOW);
  digitalWrite(a6, LOW);
  delay(500);
  digitalWrite(a1, HIGH);
  digitalWrite(a2, HIGH);
  digitalWrite(a3, HIGH);
  digitalWrite(a4, HIGH);
  digitalWrite(a5, HIGH);
  digitalWrite(a6, HIGH);
  delay(500);
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(a3, LOW);
  digitalWrite(a4, LOW);
  digitalWrite(a5, LOW);
  digitalWrite(a6, LOW);
  delay(500);
    
 // star 1d
  digitalWrite(str, LOW);
  delay(500);
  digitalWrite(str, HIGH);
  
    // triad
  digitalWrite(a1, HIGH);
  digitalWrite(a2, HIGH);
  digitalWrite(a3, HIGH);
  delay(500);
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(a3, LOW);
  digitalWrite(a4, HIGH);
  digitalWrite(a5, HIGH);
  digitalWrite(a6, HIGH);
  delay(500);
  digitalWrite(a1, HIGH);
  digitalWrite(a2, HIGH);
  digitalWrite(a3, HIGH);
  digitalWrite(a4, LOW);
  digitalWrite(a5, LOW);
  digitalWrite(a6, LOW);
  delay(500);
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(a3, LOW);
  digitalWrite(a4, HIGH);
  digitalWrite(a5, HIGH);
  digitalWrite(a6, HIGH);
  delay(500);
  digitalWrite(a1, HIGH);
  digitalWrite(a2, HIGH);
  digitalWrite(a3, HIGH);
  digitalWrite(a4, LOW);
  digitalWrite(a5, LOW);
  digitalWrite(a6, LOW);
  delay(500);
  digitalWrite(a1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(a3, LOW);
  delay(500);
    
 // star 1e
  digitalWrite(str, LOW);
  delay(500);
  digitalWrite(str, HIGH);
  
  // collide and seperate
  digitalWrite(a1, HIGH);
  delay(300);
  digitalWrite(a1, LOW);
  digitalWrite(a2, HIGH);
  digitalWrite(a6, HIGH);
  delay(300);
  digitalWrite(a2, LOW);
  digitalWrite(a6, LOW);
  digitalWrite(a3, HIGH);
  digitalWrite(a5, HIGH);
  delay(300);
  digitalWrite(a3, LOW);
  digitalWrite(a5, LOW);
  digitalWrite(a4, HIGH);
  delay(300);
  digitalWrite(a4, LOW);
  delay(300);
  digitalWrite(a4, HIGH);
  delay(300);
  digitalWrite(a4, LOW);
  digitalWrite(a3, HIGH);
  digitalWrite(a5, HIGH);
  delay(300);
  digitalWrite(a3, LOW);
  digitalWrite(a5, LOW);
  digitalWrite(a2, HIGH);
  digitalWrite(a6, HIGH);
  delay(300);
  digitalWrite(a2, LOW);
  digitalWrite(a6, LOW);
  delay(1000);
  
 // star 1f
  digitalWrite(str, LOW);
  delay(500);
  digitalWrite(str, HIGH);
  
  // faded
  for (brightness = 0; brightness <= 225; brightness += 5) {
    analogWrite(a1, brightness);
    analogWrite(a2, brightness);
    analogWrite(a3, brightness);
    analogWrite(a4, brightness);
    analogWrite(a5, brightness); 
    analogWrite(a6, brightness); 
    
    delay(30); 
  }
  for (brightness = 225; brightness >= 0; brightness -= 5) {
    analogWrite(a1, brightness);
    analogWrite(a2, brightness);
    analogWrite(a3, brightness);
    analogWrite(a4, brightness);    
    analogWrite(a5, brightness);
    analogWrite(a6, brightness); 
    
    delay(30);
  }
   for (brightness = 0; brightness <= 225; brightness += 5) {
    analogWrite(a1, brightness);
    analogWrite(a2, brightness);
    analogWrite(a3, brightness);
    analogWrite(a4, brightness);
    analogWrite(a5, brightness); 
    analogWrite(a6, brightness); 
    
    delay(30); 
  }
  for (brightness = 225; brightness >= 0; brightness -= 5) {
    analogWrite(a1, brightness);
    analogWrite(a2, brightness);
    analogWrite(a3, brightness);
    analogWrite(a4, brightness);    
    analogWrite(a5, brightness);
    analogWrite(a6, brightness); 
    
    delay(30);
  }
    
 // star 1g
  digitalWrite(str, LOW);
  delay(500);
  digitalWrite(str, HIGH);
  
  // switch
  digitalWrite(a1, HIGH);
  digitalWrite(a3, HIGH);
  digitalWrite(a5, HIGH);
  delay(200);
  digitalWrite(a1, LOW);
  digitalWrite(a2, HIGH);
  digitalWrite(a3, LOW);
  digitalWrite(a4, HIGH);
  digitalWrite(a5, LOW);
  digitalWrite(a6, HIGH);
  delay(200);
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  digitalWrite(a3, HIGH);
  digitalWrite(a4, LOW);
  digitalWrite(a5, HIGH);
  digitalWrite(a6, LOW);
  delay(200);
  digitalWrite(a1, LOW);
  digitalWrite(a2, HIGH);
  digitalWrite(a3, LOW);
  digitalWrite(a4, HIGH);
  digitalWrite(a5, LOW);
  digitalWrite(a6, HIGH);
  delay(200);
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  digitalWrite(a3, HIGH);
  digitalWrite(a4, LOW);
  digitalWrite(a5, HIGH);
  digitalWrite(a6, LOW);
  delay(200);
  digitalWrite(a1, LOW);
  digitalWrite(a2, HIGH);
  digitalWrite(a3, LOW);
  digitalWrite(a4, HIGH);
  digitalWrite(a5, LOW);
  digitalWrite(a6, HIGH);
  delay(200);
  digitalWrite(a1, HIGH);
  digitalWrite(a2, LOW);
  digitalWrite(a3, HIGH);
  digitalWrite(a4, LOW);
  digitalWrite(a5, HIGH);
  digitalWrite(a6, LOW);
  delay(200);
  digitalWrite(a1, LOW);
  digitalWrite(a3, LOW);
  digitalWrite(a5, LOW);
  delay(500);
    
 // star 1h
  digitalWrite(str, LOW);
  delay(500);
  digitalWrite(str, HIGH);
  
    // faded
  for (brightness = 0; brightness <= 225; brightness += 5) {
    analogWrite(a1, brightness);
    analogWrite(a3, brightness);
    analogWrite(a5, brightness); 
    
    delay(30); 
  }
  for (brightness = 225; brightness >= 0; brightness -= 5) {
    analogWrite(a1, brightness);
    analogWrite(a3, brightness);  
    analogWrite(a5, brightness);
    
    delay(30);
  }
   for (brightness = 0; brightness <= 225; brightness += 5) {
    analogWrite(a2, brightness);
    analogWrite(a4, brightness);
    analogWrite(a6, brightness); 
    
    delay(30); 
  }
  for (brightness = 225; brightness >= 0; brightness -= 5) {
    analogWrite(a2, brightness);
    analogWrite(a4, brightness); 
    analogWrite(a6, brightness); 
    
    delay(30);
  }
    
 // star 1i
  digitalWrite(str, LOW);
  
  }
