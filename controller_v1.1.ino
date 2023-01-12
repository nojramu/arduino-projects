  //by NOJRAMU
const int ina = 5;
const int inb = 6;
const int inc = 9;
const int ind = 10;
int spd = 255;
int dly = 100;//delay
char mov;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()){
    mov = Serial.read();
    Serial.println(mov);
  }
  if (mov == '8'){//forward
    analogWrite(ina,spd);
    analogWrite(inb,0);
    analogWrite(inc,0);
    analogWrite(ind,spd);
  }
  else if (mov == '4'){//left
    analogWrite(ina,0);
    analogWrite(inb,spd);
    analogWrite(inc,0);
    analogWrite(ind,spd);
  }
  else if (mov == '2'){//backward
    analogWrite(ina,0);
    analogWrite(inb,spd);
    analogWrite(inc,spd);
    analogWrite(ind,0);
  }
  else if (mov == '6'){//right
    analogWrite(ina,spd);
    analogWrite(inb,0);
    analogWrite(inc,spd);
    analogWrite(ind,0);
  }
  else if (mov == '5'){//stop
    analogWrite(ina,0);
    analogWrite(inb,0);
    analogWrite(inc,0);
    analogWrite(ind,0);
  }
  else if (mov == '9'){//forward right
    analogWrite(ina,spd);
    analogWrite(inb,0);
    analogWrite(inc,0);
    analogWrite(ind,spd-100);
  }
  else if (mov == '7'){//forward left
    analogWrite(ina,spd-100);
    analogWrite(inb,0);
    analogWrite(inc,0);
    analogWrite(ind,spd);
  }
  else if (mov == '1'){//backward right
    analogWrite(ina,0);
    analogWrite(inb,spd-100);
    analogWrite(inc,spd);
    analogWrite(ind,0);
  }
  else if (mov == '3'){//backward left
    analogWrite(ina,0);
    analogWrite(inb,spd);
    analogWrite(inc,spd-100);
    analogWrite(ind,0);
  }
  else if (mov == '+'){//adjust speed faster
    analogWrite(ina,0);
    analogWrite(inb,0);
    analogWrite(inc,0);
    analogWrite(ind,0);
    spd = 255;
  }
  else if (mov == '-'){//adjust speed slower
    analogWrite(ina,0);
    analogWrite(inb,0);
    analogWrite(inc,0);
    analogWrite(ind,0);
    spd = 150;
  }
  delay(dly);
}
