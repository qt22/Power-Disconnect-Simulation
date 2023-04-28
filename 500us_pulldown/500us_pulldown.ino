const int outputPin = 2;       // Declare a constant integer variable named outputPin and assign the value 2 to it
const int buttonPin = 3;       // Declare a constant integer variable named buttonPin and assign the value 3 to it
volatile bool pullUpFlag = false;  // Declare a boolean variable named pullUpFlag and assign the value false to it. The "volatile" keyword tells the compiler that the value of this variable can change at any time, so it should not optimize the code that uses it.

void setup() {                  // Define the setup function which runs once when the Arduino is powered on or reset
  pinMode(outputPin, OUTPUT);   // Configure the outputPin as an output pin using the pinMode() function
}

void loop() {                   // Define the loop function which runs repeatedly as long as the Arduino is powered on or reset

  digitalWrite(outputPin, HIGH);  // Turn on the outputPin by setting it to HIGH

  bool buttonState = digitalRead(buttonPin);  // Read the current state of the buttonPin and store it in a boolean variable named buttonState

  if (buttonState) {            // If the button is currently pressed (i.e., if buttonState is true)
    pullUpFlag = false;         // Set pullUpFlag to false
    delay(1000);                // Wait for 1 second (1000 milliseconds)
  }

  long startTime = micros();    // Get the current time in microseconds and store it in a long integer variable named startTime

  if (!pullUpFlag) {            // If pullUpFlag is currently false (i.e., if the button was recently pressed)
    while(micros() - startTime < 500) {  // Loop until 500 microseconds have elapsed since the startTime
      digitalWrite(outputPin, LOW);      // Set the outputPin to LOW (i.e., turn it off)
    }
    pullUpFlag = true;          // Set pullUpFlag to true (i.e., indicate that the outputPin should now be turned back on)
  }

  digitalWrite(outputPin, HIGH); // Turn on the outputPin by setting it to HIGH
}
