//LED Assignments
#define LED1 13
#define LED2 12
#define LED3 14
#define LED4 27
#define LED5 26
#define LED6 25
#define LED7 33
#define LED8 32
//Switch Assignments
#define SW1 35
#define SW2 34
#define SW3 39
#define SW4 36

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);
  Serial.begin(9600);
}

//for turning off LEDs to refresh the HIGH outputs
void refresh() {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
  digitalWrite(LED7, LOW);
  digitalWrite(LED8, LOW);
}

void switchCheck() {
  //Switch State
  int SWST1 = digitalRead(SW1);
  int SWST2 = digitalRead(SW2);
  int SWST3 = digitalRead(SW3);
  int SWST4 = digitalRead(SW4);

  //Print the output of sensors
  Serial.println("Switch states: " + String(SWST1) + " " + String(SWST2) + " " + String(SWST3) + " " + String(SWST4));

  if (SWST1 == 1 && SWST2 == 0 && SWST3 == 0 && SWST4 == 0) {
    Serial.println("movement 1");
    refresh();
    ledMovement(1);
  } else if (SWST1 == 0 && SWST2 == 1 && SWST3 == 0 && SWST4 == 0) {
    Serial.println("movement 2");
    refresh();
    ledMovement(2);
  } else if (SWST1 == 0 && SWST2 == 0 && SWST3 == 1 && SWST4 == 0) {
    Serial.println("movement 3");
    refresh();
    ledMovement(3);
  } else if (SWST1 == 0 && SWST2 == 0 && SWST3 == 0 && SWST4 == 1) {
    Serial.println("movement 4");
    refresh();
    ledMovement(4);
  } else {
    refresh();
    Serial.println("no movement");
  }
}

//The various option on changing led movement using switches
void ledMovement(int option) {
  //Adjust speed of switching of leds here
  int speed = 100;

  if (option == 1) {
    digitalWrite(LED8, LOW);
    digitalWrite(LED4, HIGH);
    delay(speed);
    digitalWrite(LED4, LOW);
    digitalWrite(LED3, HIGH);
    delay(speed);
    digitalWrite(LED3, LOW);
    digitalWrite(LED2, HIGH);
    delay(speed);
    digitalWrite(LED2, LOW);
    digitalWrite(LED1, HIGH);
    delay(speed);
    digitalWrite(LED1, LOW);
    digitalWrite(LED5, HIGH);
    delay(speed);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, HIGH);
    delay(speed);
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, HIGH);
    delay(speed);
    digitalWrite(LED7, LOW);
    digitalWrite(LED8, HIGH);
    delay(speed);
  } else if (option == 2) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED8, LOW);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
    delay(speed);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED6, HIGH);
    delay(speed);
    digitalWrite(LED3, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED7, HIGH);
    delay(speed);
    digitalWrite(LED2, LOW);
    digitalWrite(LED7, LOW);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED8, HIGH);
    delay(speed);
  } else if (option == 3) {
    digitalWrite(LED2, LOW);
    digitalWrite(LED1, HIGH);
    delay(speed);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    delay(speed);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    delay(speed);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);
    delay(speed);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, HIGH);
    delay(speed);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, HIGH);
    delay(speed);
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, HIGH);
    delay(speed);
    digitalWrite(LED7, LOW);
    digitalWrite(LED8, HIGH);
    delay(speed);
    digitalWrite(LED8, LOW);
    digitalWrite(LED7, HIGH);
    delay(speed);
    digitalWrite(LED7, LOW);
    digitalWrite(LED6, HIGH);
    delay(speed);
    digitalWrite(LED6, LOW);
    digitalWrite(LED5, HIGH);
    delay(speed);
    digitalWrite(LED5, LOW);
    digitalWrite(LED4, HIGH);
    delay(speed);
    digitalWrite(LED4, LOW);
    digitalWrite(LED3, HIGH);
    delay(speed);
    digitalWrite(LED3, LOW);
    digitalWrite(LED2, HIGH);
    delay(speed);
  } else if (option == 4) {
    digitalWrite(LED2, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED8, LOW);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED7, HIGH);
    delay(speed * 2);
    digitalWrite(LED1, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED7, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED6, HIGH);
    digitalWrite(LED8, HIGH);
    delay(speed * 2);
  }
}

void loop() {
  switchCheck();
}