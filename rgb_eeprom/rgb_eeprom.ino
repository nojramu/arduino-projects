#include <EEPROM.h> // Include the EEPROM library for reading and writing to EEPROM
#include "button.h" // Include the button library for button handling

#define PIN_RED 14 // Define the pin for the red LED
#define PIN_GREEN 27 // Define the pin for the green LED
#define PIN_BLUE 26 // Define the pin for the blue LED
Button BTN; // Create a button object

const int colorAddress = 0; // Define the starting address in EEPROM for storing color values
uint8_t colorArray[3]; // Array to store color values for RGB LEDs

void setup() {
  Serial.begin(115200); // Initialize serial communication at 115200 baud rate
  EEPROM.begin(sizeof(colorArray)); // Initialize EEPROM with the size of the color array
  randomSeed(analogRead(0)); // Seed the random number generator with an analog read

  BTN.begin(12); // Initialize the button on pin 12
  pinMode(PIN_RED, OUTPUT); // Set the red LED pin as an output
  pinMode(PIN_GREEN, OUTPUT); // Set the green LED pin as an output
  pinMode(PIN_BLUE, OUTPUT); // Set the blue LED pin as an output

  // Load color values from EEPROM on startup (data persistence)
  for (int i = 0; i < 3; i++) {
    colorArray[i] = EEPROM.read(colorAddress + i); // Read color values from EEPROM
  }
}

// Function to generate random color values
void randomizeColorArray(uint8_t colorArray[3]) {
  for (int i = 0; i < 3; i++) {
    colorArray[i] = random(256); // Generate a random number between 0 and 255 for each color
  }
}

// Function to display color values on serial monitor and LEDs
void displayColor(uint8_t colorArray[3]) {
  Serial.print("Random colors: "); // Print a message to the serial monitor
  for (int i = 0; i < 3; i++) {
    Serial.print(colorArray[i]); // Print each color value
    Serial.print(" "); // Print a space between color values
  }
  Serial.println(); // Print a newline character
  analogWrite(PIN_RED, colorArray[0]); // Set the red LED to the corresponding value
  analogWrite(PIN_GREEN, colorArray[1]); // Set the green LED to the corresponding value
  analogWrite(PIN_BLUE, colorArray[2]); // Set the blue LED to the corresponding value
}

// Function to save color array to EEPROM (called when button is pressed)
void saveColorToEEPROM(uint8_t colorArray[3]) {
  for (int i = 0; i < 3; i++) {
    EEPROM.write(colorAddress + i, colorArray[i]); // Write each color value to EEPROM
  }
  EEPROM.commit(); // Commit the changes to EEPROM
  Serial.println("Color saved to EEPROM!"); // Print a confirmation message to the serial monitor
}

void loop() {
  displayColor(colorArray); // Display the current color values

  if (BTN.debounce()) { // Check if the button is pressed and debounced
    randomizeColorArray(colorArray); // Generate new random color values
    saveColorToEEPROM(colorArray); // Save the new color values to EEPROM
  }
}