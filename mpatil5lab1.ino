// Mallika Patil - 660213398
// YouTube Link: https://youtu.be/BYkzbkLLTwo
// Lab 1 - Get started with Arduino
// Description - Have a cycle of LEDs, in the order of the onboard LED, the red LED, 
// and then a green LED, without using delay. 
// Assumptions: 
// 1. LOW - means that the LED is off
// 2. Resistors do not have polarity
// 3. millis() - a function to keep time, used from reference of BlinkyWithoutDelay
// 4. Used cloud based version of Arduino IDE, downloading only the Arduino Agent, for ease of use 
// References: 
// millis(): https://www.arduino.cc/reference/en/language/functions/time/millis/
// BlinkyWithoutDelay: https://www.arduino.cc/en/tutorial/BlinkWithoutDelay
// Download: https://www.arduino.cc/en/Main/Software
// Set Up: https://www.arduino.cc/en/Guide/HomePage
// TutorialBlink: http://arduino.cc/en/Tutorial/Blink


// Constant Variables
const int yellowPin =  13;  // red LED pin
const int redPin =  12;     // yellow LED pin
const int greenPin =  11;   // green LED pin
// Variables
long start = 0;         // start time
long period = 9000;     // total time period for loop, which is 9 secs

void setup() {
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop()
{
  unsigned long current = millis();
  // When past time is equal to period, set start to current
  if (current - start == period) { 
    start = current;
  }
  // Turn on yellow LED for 3 seconds 
  if (current - start < 3000) {
    yellow();
  }
  // Turn on red LED for 3 seconds 
  else if (current - start > 3000 && current - start < 6000 ) {
    red();
  }
  // Turn on green LED for 3 seconds
  else if (current - start > 6000 ) {
    green();
  }
}

// Function to turn on yellow LED
void yellow(){
  digitalWrite(yellowPin, HIGH);  // yellow LED on
  digitalWrite(redPin, LOW);      // red LED off
  digitalWrite(greenPin, LOW);    // green LED off
}

// Function to turn on red LED
void red(){
  digitalWrite(yellowPin, LOW);  // yellow LED off
  digitalWrite(redPin, HIGH);    // red LED on
  digitalWrite(greenPin, LOW);   // green LED off
}

// Function to turn on green LED
void green(){
  digitalWrite(yellowPin, LOW);  // yellow LED off
  digitalWrite(redPin, LOW);     // red LED off
  digitalWrite(greenPin, HIGH);  // green LED on
}