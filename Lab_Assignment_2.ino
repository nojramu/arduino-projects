#include <WiFi.h>

// LED Assignments
#define LED1 13
#define LED2 12
#define LED3 14
#define LED4 27
#define LED5 26
#define LED6 5
#define LED7 33
#define LED8 32
// Button Assignment
#define BTN 36
// Buzzer Assigment
#define BZR 4

const char* ssid = "SSID"; // Change based on router
const char* password = "password";

int BSTATE0;
int BSTATE1;
int BSTATE2;
int BSTATE3;
int BSTATE4;
int BSTATE5;

WiFiServer espServer(80); // Port number
String request; // Capture the incoming HTTP GET Request

void setup() {
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
  digitalWrite(LED7, LOW);
  digitalWrite(LED8, LOW);

  Serial.print("\n");
  Serial.print("Connecting to: ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print("*");
    delay(100);
  }

  Serial.print("\n");
  Serial.print("Connected to Wi-Fi: ");
  Serial.println(WiFi.SSID());
  delay(100);

  /* Assigning Static IP to ESP32 */
  // IPAddress ip(192,168,1,6);
  // IPAddress gateway(192,168,1,1);
  // IPAddress subnet(255,255,255,0);
  // WiFi.config(ip, gateway, subnet);

  delay(2000);
  Serial.print("\n");
  Serial.println("Starting ESP32 Web Server...");
  espServer.begin();
  Serial.println("ESP32 Web Server Started");
  Serial.print("\n");
  Serial.print("The URL of ESP32 Web Server is: ");
  Serial.print("http://");
  Serial.println(WiFi.localIP());
  Serial.print("\n");
  Serial.println("Use the above URL in your Browser to access ESP32 Web Server\n");
}

void playMelody(int melody[], int noteDurations[], int melodyLength) {
  for (int i = 0; i < melodyLength; i++) {
    int noteDuration = 1000 / noteDurations[i];
    tone(BZR, melody[i], noteDuration);
    delay(noteDuration * 1.30);
    noTone(BZR);
  }
}

void refreshState() {
  BSTATE0 = LOW;
  BSTATE1 = LOW;
  BSTATE2 = LOW;
  BSTATE3 = LOW;
  BSTATE4 = LOW;
  BSTATE5 = LOW;
}

void refreshLED() {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
  digitalWrite(LED7, LOW);
  digitalWrite(LED8, LOW);
}

void chooseLights(int option){
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
    delay(speed + speed);
    digitalWrite(LED1, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED7, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED6, HIGH);
    digitalWrite(LED8, HIGH);
    delay(speed + speed);
    digitalWrite(LED2, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED8, LOW);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED7, HIGH);
    delay(speed + speed);
    digitalWrite(LED1, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED7, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED6, HIGH);
    digitalWrite(LED8, HIGH);
    delay(speed + speed);
    digitalWrite(LED2, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED8, LOW);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED7, HIGH);
    delay(speed + speed);
    digitalWrite(LED1, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED7, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED6, HIGH);
    digitalWrite(LED8, HIGH);
    delay(speed + speed);
  } else if (option == 5) {
    for (int brightness = 0; brightness <= 255; brightness += 5) {
      analogWrite(LED1, brightness);
      analogWrite(LED2, brightness);
      analogWrite(LED3, brightness);
      analogWrite(LED4, brightness);
      analogWrite(LED5, brightness);
      analogWrite(LED6, brightness);
      analogWrite(LED7, brightness);
      analogWrite(LED8, brightness);
      delay(speed / 10);
    }
    for (int brightness = 255; brightness >= 0; brightness -= 5) {
      analogWrite(LED1, brightness);
      analogWrite(LED2, brightness);
      analogWrite(LED3, brightness);
      analogWrite(LED4, brightness);
      analogWrite(LED5, brightness);
      analogWrite(LED6, brightness);
      analogWrite(LED7, brightness);
      analogWrite(LED8, brightness);
      delay(speed / 10);
    }
    for (int brightness = 0; brightness <= 255; brightness += 5) {
      analogWrite(LED1, brightness);
      analogWrite(LED2, brightness);
      analogWrite(LED3, brightness);
      analogWrite(LED4, brightness);
      analogWrite(LED5, brightness);
      analogWrite(LED6, brightness);
      analogWrite(LED7, brightness);
      analogWrite(LED8, brightness);
      delay(speed / 10);
    }
    for (int brightness = 255; brightness >= 0; brightness -= 5) {
      analogWrite(LED1, brightness);
      analogWrite(LED2, brightness);
      analogWrite(LED3, brightness);
      analogWrite(LED4, brightness);
      analogWrite(LED5, brightness);
      analogWrite(LED6, brightness);
      analogWrite(LED7, brightness);
      analogWrite(LED8, brightness);
      delay(speed / 10);
    }
  }
}

void chooseMelody(int option){
  // Happy Birthday
  int hbMelody[] = {262, 262, 294, 262, 349, 330, 262, 262, 294, 262, 392, 349, 262, 262, 523, 440, 349, 330, 294, 466, 466, 440, 349, 392, 349};
  int hbDurations[] = {4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 2};

  // Twinkle Twinkle Little Star
  int ttMelody[] = {262, 262, 392, 392, 440, 440, 392, 349, 349, 330, 330, 294, 294, 262};
  int ttDurations[] = {4, 4, 4, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 2};

  // Jingle Bells
  int jbMelody[] = {330, 330, 330, 330, 330, 330, 330, 392, 262, 294, 330};
  int jbDurations[] = {4, 4, 2, 4, 4, 2, 4, 4, 4, 4, 4};

  // Ode to Joy
  int ojMelody[] = {330, 330, 349, 392, 392, 349, 330, 294, 262, 262, 294, 330, 330, 294, 294};
  int ojDurations[] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

  // Mary Had a Little Lamb
  int mlMelody[] = {330, 294, 262, 294, 330, 330, 330, 294, 294, 294, 330, 392, 392};
  int mlDurations[] = {4, 4, 4, 4, 4, 4, 2, 4, 4, 2, 4, 4, 2};

  // The Entertainer
  int teMelody[] = {262, 330, 392, 523, 392, 262, 330, 392, 523, 392, 330, 294, 349, 392};
  int teDurations[] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

  // Star Wars Theme
  int swMelody[] = {440, 440, 440, 349, 523, 440, 349, 523, 440};
  int swDurations[] = {4, 4, 4, 4, 4, 4, 4, 4, 4};

  // Beethoven's Fifth Symphony
  int bfMelody[] = {262, 262, 262, 349, 349, 349, 330, 294, 262};
  int bfDurations[] = {4, 4, 4, 4, 4, 4, 4, 4, 4};

  // Für Elise
  int feMelody[] = {330, 294, 262, 294, 330, 330, 330, 294, 294, 294, 330, 392, 392};
  int feDurations[] = {4, 4, 4, 4, 4, 4, 2, 4, 4, 2, 4, 4, 2};

  // Yankee Doodle
  int ydMelody[] = {262, 294, 330, 349, 392, 349, 330, 294, 262, 294, 330, 349, 392, 349, 330, 294, 262};
  int ydDurations[] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

  // Silent Night
  int snMelody[] = {262, 294, 330, 262, 262, 294, 330, 262, 330, 349, 392, 392, 330, 349, 392, 392, 440, 392, 349, 330, 294, 294, 330, 294, 262};
  int snDurations[] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

  // The Pink Panther Theme
  int ppMelody[] = {262, 330, 392, 262, 330, 392, 523, 523, 494, 523, 523, 494, 523, 523, 523, 523, 494, 523, 523, 494, 523, 523, 523, 523};
  int ppDurations[] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

  switch(option) {
    case 1:
    playMelody(hbMelody, hbDurations, sizeof(hbMelody) / sizeof(hbMelody[0]));
    //delay(2000);
    break;
    case 2:
    playMelody(ttMelody, ttDurations, sizeof(ttMelody) / sizeof(ttMelody[0]));
    //delay(2000);
    break;
    case 3:
    playMelody(jbMelody, jbDurations, sizeof(jbMelody) / sizeof(jbMelody[0]));
    //delay(2000);
    break;
    case 4:
    playMelody(ojMelody, ojDurations, sizeof(ojMelody) / sizeof(ojMelody[0]));
    //delay(2000);
    break;
    case 5:
    playMelody(mlMelody, mlDurations, sizeof(mlMelody) / sizeof(mlMelody[0]));
    //delay(2000);
    break;
  }
}


void loop() {
  WiFiClient client = espServer.available();
  if(!client) {
    return;
  }

  Serial.println("New Client!!!");
  boolean currentLineIsBlank = true;
  while (client.connected()) {
    if (client.available()) {
      char c = client.read();
      request += c;
      Serial.write(c);
      if (c == '\n' && currentLineIsBlank) {
        /* Based on the URL from the request, turn the LEDs ON or OFF */

        /* HTTP Response in the form of HTML Web Page */
        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println("Connection: close");
        client.println();

        client.println("<!DOCTYPE HTML>");
        client.println("<html>");
        client.println("<head>");
        client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
        client.println("<link rel=\"icon\" href=\"data:,\">");
        client.println("<style>");
        client.println("html { font-family: Courier New; display: inline-block; margin: 0px auto; text-align: center;}");
        client.println(".button {border: none; color: white; padding: 10px 20px; text-align: center;"); 
        client.println("text-decoration: none; font-size: 25px; margin: 2px; cursor: pointer;}"); 
        client.println(".button1 {background-color: #FF0000;}");
        client.println(".button2 {background-color: #00FF00;}");
        client.println("</style>");
        client.println("</head>");
        client.println("<body>");
        client.println("<h2>ESP32 Web Server</h2>");

        if (request.indexOf("/PLAY0") != -1) {
          refreshState();
          BSTATE0 = HIGH;
          Serial.println("PLAYING 0");
          chooseLights(0);
          refreshLED();
          chooseMelody(0);
          request = "";
        }
        if (request.indexOf("/PLAY1") != -1) {
          refreshState();
          BSTATE1 = HIGH;
          Serial.println("PLAYING 1");
          chooseLights(1);
          refreshLED();
          chooseMelody(1);
          chooseLights(1);
          refreshLED();
          request = "";
        }
        if (request.indexOf("/PLAY2") != -1) {
          refreshState();
          BSTATE2 = HIGH;
          Serial.println("PLAYING 2");
          chooseLights(2);
          refreshLED();
          chooseMelody(2);
          chooseLights(2);
          refreshLED();
          request = "";
        }
        if (request.indexOf("/PLAY3") != -1) {
          refreshState();
          BSTATE3 = HIGH;
          Serial.println("PLAYING 3");
          chooseLights(3);
          refreshLED();
          chooseMelody(3);
          chooseLights(3);
          refreshLED();
          request = "";
        }
        if (request.indexOf("/PLAY4") != -1) {
          refreshState();
          BSTATE4 = HIGH;
          Serial.println("PLAYING 4");
          chooseLights(4);
          refreshLED();
          chooseMelody(4);
          chooseLights(4);
          refreshLED();
          request = "";
        }
        if (request.indexOf("/PLAY5") != -1) {
          refreshState();
          BSTATE5 = HIGH;
          Serial.println("PLAYING 5");
          chooseLights(5);
          refreshLED();
          chooseMelody(5);
          chooseLights(5);
          refreshLED();
          request = "";
        }

        if(BSTATE1 == HIGH) {
          client.println("<p>Play Status: 1</p>");
          client.print("<p><a href=\"/PLAY0\"><button class=\"button button1\">STOP</button></a></p>");
          client.print("<p><a href=\"/PLAY1\"><button class=\"button button2\">PLAY 1</button></a></p>");
          client.print("<p><a href=\"/PLAY2\"><button class=\"button button1\">PLAY 2</button></a></p>");
          client.print("<p><a href=\"/PLAY3\"><button class=\"button button1\">PLAY 3</button></a></p>");
          client.print("<p><a href=\"/PLAY4\"><button class=\"button button1\">PLAY 4</button></a></p>");
          client.print("<p><a href=\"/PLAY5\"><button class=\"button button1\">PLAY 5</button></a></p>");
          request = "";
        }else if(BSTATE2 == HIGH) {
          client.println("<p>Play Status: 2</p>");
          client.print("<p><a href=\"/PLAY0\"><button class=\"button button1\">STOP</button></a></p>");
          client.print("<p><a href=\"/PLAY1\"><button class=\"button button1\">PLAY 1</button></a></p>");
          client.print("<p><a href=\"/PLAY2\"><button class=\"button button2\">PLAY 2</button></a></p>");
          client.print("<p><a href=\"/PLAY3\"><button class=\"button button1\">PLAY 3</button></a></p>");
          client.print("<p><a href=\"/PLAY4\"><button class=\"button button1\">PLAY 4</button></a></p>");
          client.print("<p><a href=\"/PLAY5\"><button class=\"button button1\">PLAY 5</button></a></p>");
          request = "";
        }else if(BSTATE3 == HIGH) {
          client.println("<p>Play Status: 3</p>");
          client.print("<p><a href=\"/PLAY0\"><button class=\"button button1\">STOP</button></a></p>");
          client.print("<p><a href=\"/PLAY1\"><button class=\"button button1\">PLAY 1</button></a></p>");
          client.print("<p><a href=\"/PLAY2\"><button class=\"button button1\">PLAY 2</button></a></p>");
          client.print("<p><a href=\"/PLAY3\"><button class=\"button button2\">PLAY 3</button></a></p>");
          client.print("<p><a href=\"/PLAY4\"><button class=\"button button1\">PLAY 4</button></a></p>");
          client.print("<p><a href=\"/PLAY5\"><button class=\"button button1\">PLAY 5</button></a></p>");
          request = "";
        }else if(BSTATE4 == HIGH) {
          client.println("<p>Play Status: 4</p>");
          client.print("<p><a href=\"/PLAY0\"><button class=\"button button1\">STOP</button></a></p>");
          client.print("<p><a href=\"/PLAY1\"><button class=\"button button1\">PLAY 1</button></a></p>");
          client.print("<p><a href=\"/PLAY2\"><button class=\"button button1\">PLAY 2</button></a></p>");
          client.print("<p><a href=\"/PLAY3\"><button class=\"button button1\">PLAY 3</button></a></p>");
          client.print("<p><a href=\"/PLAY4\"><button class=\"button button2\">PLAY 4</button></a></p>");
          client.print("<p><a href=\"/PLAY5\"><button class=\"button button1\">PLAY 5</button></a></p>");
          request = "";
        }else if(BSTATE5 == HIGH) {
          client.println("<p>Play Status: 5</p>");
          client.print("<p><a href=\"/PLAY0\"><button class=\"button button1\">STOP</button></a></p>");
          client.print("<p><a href=\"/PLAY1\"><button class=\"button button1\">PLAY 1</button></a></p>");
          client.print("<p><a href=\"/PLAY2\"><button class=\"button button1\">PLAY 2</button></a></p>");
          client.print("<p><a href=\"/PLAY3\"><button class=\"button button1\">PLAY 3</button></a></p>");
          client.print("<p><a href=\"/PLAY4\"><button class=\"button button1\">PLAY 4</button></a></p>");
          client.print("<p><a href=\"/PLAY5\"><button class=\"button button2\">PLAY 5</button></a></p>");
          request = "";
        }else {
          client.println("<p>Play Status: 1</p>");
          client.print("<p><a href=\"/PLAY0\"><button class=\"button button2\">STOP</button></a></p>");
          client.print("<p><a href=\"/PLAY1\"><button class=\"button button1\">PLAY 1</button></a></p>");
          client.print("<p><a href=\"/PLAY2\"><button class=\"button button1\">PLAY 2</button></a></p>");
          client.print("<p><a href=\"/PLAY3\"><button class=\"button button1\">PLAY 3</button></a></p>");
          client.print("<p><a href=\"/PLAY4\"><button class=\"button button1\">PLAY 4</button></a></p>");
          client.print("<p><a href=\"/PLAY5\"><button class=\"button button1\">PLAY 5</button></a></p>");
          request = "";
        }

        client.println("</body>");
        client.println("</html>");
        break;
      }
      if(c == '\n') {
        currentLineIsBlank = true;
      }
      else if(c != '\r') {
        currentLineIsBlank = false;
      }
    }
  }
  delay(1);
  request = "";
  client.flush();
  client.stop();
  Serial.println("Client disconnected");
  Serial.print("\n");
}
