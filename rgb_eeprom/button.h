//reference: https://www.e-tinkers.com/2021/05/the-simplest-button-debounce-solution/
#ifndef button_h
#define button_h

#include "Arduino.h" // Include the Arduino core library

class Button // Define a Button class
{
  private:
    uint8_t btn; // Variable to store the button pin number
    uint16_t state; // Variable to store the button state for debouncing
  public:
    // Function to initialize the button
    void begin(uint8_t button) {
      btn = button; // Set the button pin number
      state = 0; // Initialize the state to 0
      pinMode(btn, INPUT_PULLUP); // Set the button pin as input with pull-up resistor
    }

    // Function to debounce the button press
    bool debounce() {
      state = (state << 1) | digitalRead(btn) | 0xfe00; // Shift the state, read the button pin, and apply debounce logic
      return (state == 0xff00); // Return true if the button press is confirmed after debouncing
    }
};

#endif // End of the button_h header guard