// Terrier Motorsport x STEM Pathways
  // Code written by Michael Waetzman, mwae@bu.edu
  // Intended for adaptation by members
  // PARTIAL CODE

// Modified HC_SR04 code by Isaac100 on the Arduno Project Hub
  // https://projecthub.arduino.cc/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-7cabe1

// ================================================================================================
// SECTION 0: INFORMATION

/* This code is broken up into 5 sections (including this one)
    0) Information: info about the code
    1) Header: definitions and libraries
    2) Function/Variable Declarations
    3) Arduino Functions
    4) Your Functions

  There are multiple places within this file that have blanks, marked as XXXXX. Some areas have been left
  blank, with a simple description for what *should* go there. If you are unsure about your code or what you
  need to put there, just ask! You can also look at the FULL code and compare.

*/

// ================================================================================================
// SECTION 1: HEADER

// This is the "header section"
  // We add libraries here, like adding "stdio" or "math" in proper C++ code
  // We also define global variables here
  // Typically, global variables are Arduino pins, max/min values, and other stuff that doesn't change

// #include <Arduino_FreeRTOS.h>   // Library for parallel processing, if you'd like to use it
  // I had issues getting FreeRTOS to properly run multiple tasks on the Uno, but feel free to try it out!
  // The GitHub page for it is linked below, and I've left smaple declarations in the setup()
  // https://github.com/feilipu/Arduino_FreeRTOS_Library
  
#define BAUD_RATE XXXXX       // Fill these in!

// Arduino Uno Pin Map
  // If using the analog pins (like A0 or A1), it's best to use the int equivelent
  // For example, if you're using pin A4 assign that to 18
  // https://content.arduino.cc/assets/A000066-full-pinout.pdf

#define LEFT_MOTOR_PIN  XXXXX     // PWM enabled pin, meaning we can write any values between 0V and 5V
#define RIGHT_MOTOR_PIN XXXXX     // ^^^

// IR Pin Definitions
#define LEFT_IR_PIN  XXXXX       // Pin A0, Using ANALOG IN pins, as we're reading analog sensor values
#define RIGHT_IR_PIN XXXXX       // Pin A1, ^^^

// Ultrasonic Pin Definitions
#define LEFT_ULTRASONIC_TRIG_PIN  XXXXX   // Use either digital or analog pins
#define LEFT_ULTRASONIC_ECHO_PIN  XXXXX   // ^^^
#define RIGHT_ULTRASONIC_TRIG_PIN XXXXX   // ^^^
#define RIGHT_ULTRASONIC_ECHO_PIN XXXXX   // ^^^

#define LED_PIN   XXXXX           // Non-PWM, used for on/off display so we don't need variable values
#define LED_DELAY XXXXX           // 1000ms --> 2.5 second delay

// ================================================================================================
// SECTION 2: FUNCTION & VARIABLE DECLARATIONS

// In C++, you need to declare both variables and functions *before* they're used
  // To improve readability, we use shorter function declarations
  // This code says "hey this function exists, look somewhere else for it's content"
static void led_flash(void);
static int read_sensors(void);
static void run_motors(void);

// Here, we declare out global variables (those used throughout the program)
  // Double click on these to highlight where they're used throughout the code!
  // Note 1: all variables initialized to 0, but the code will change these once running
  // Note 2: typically, it's not a good idea to use global variables (you'll learn why in any CS or CompE course)

// Motor "power" values, minimum of 0 and maximum of 255 (do you know why?)
int left_motor_value = 0;
int right_motor_value = 0;

// IR Sensor values -->  over 500 if NOT triggered, under 50 if triggered
int left_sensor_val = 0;
int right_sensor_val = 0;

// ================================================================================================
// SECTION 3: ARDUINO FUNCTIONS

// This is the set-up code, it's only run once. Think of it like an initialiation function.
  // Note: we declare global variables OUTSIDE of this function (above)
void setup() {
  Serial.begin(BAUD_RATE);   // This will be useful for debugging!

  // Declare pins as INPUT or OUTPUT
  pinMode(LEFT_MOTOR_PIN,  XXXXX);
  pinMode(RIGHT_MOTOR_PIN, XXXXX);

  pinMode(LEFT_IR_PIN,  XXXXX);
  pinMode(RIGHT_IR_PIN, XXXXX);

  // Setting up ultrasonic sensor's communication pins
  pinMode(LEFT_ULTRASONIC_TRIG_PIN,  XXXXX);
  pinMode(LEFT_ULTRASONIC_ECHO_PIN,  XXXXX);
  pinMode(RIGHT_ULTRASONIC_TRIG_PIN, XXXXX);
  pinMode(RIGHT_ULTRASONIC_ECHO_PIN, XXXXX);

  pinMode(LED_PIN, XXXXX);


  // Setting up an RTOS "tasks"
    // This code has been commented out, as there was an issue with RTOS and the Serial monitor
    // Feel free to try and implement it!

  // xTaskCreate(
  //   led_flash           // Function Name
  //   ,  "LED ON Flash"   // A name just for humans
  //   ,  128              // This stack size can be checked & adjusted by reading the Stack Highwater, leave alone
  //   ,  NULL             //Parameters for the task, leave NULL
  //   ,  0                // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
  //   ,  NULL );          //Task Handle, leave NULL
}


// This code gets repeted forever! Think of it like an infinite while loop.
  // If we used FreeRTOS and parallel processing, we wouldn't need this loop!
  // Note: this loop runs in series, one function after another --> using the Serial Monitor, see how long each function takes
void loop() {
  // CALL FUNCTIONS HERE
  XXXXX

}

// ================================================================================================
// SECTION 4: YOUR FUNCTIONS

// Flash the pin 4 LED on and off
static void led_flash(void){
  // ADD CODE HERE
  XXXXX
}

// Read the left-hand sensor
static int read_sensors(void) {

  // === IF USING IR ===
    // uncomment this section, highlight all and use ctrl+/
  
  // // Read data
  // left_sensor_val = analogRead(LEFT_IR_PIN);
  // right_sensor_val = analogRead(RIGHT_IR_PIN);

  // // Set left motor value
  // if (left_sensor_val > 200) {
  //   left_motor_value = 255;
  // } else {
  //   left_motor_value = 200;
  // }

  // // Set right motor value
  // if (right_sensor_val > 200) {
  //   right_motor_value = 255;
  // } else {
  //   right_motor_value = 200;
  // }


  // === IF USING ULTRASONIC ===
    // uncomment this section, highlight all and use ctrl+/

  // Duration is used for the distance calculation
    // Note: distance is in cm. Can you convert it to inches?
  // float left_duration, right_duration, left_distance, right_distance;
  
  // // Read left side data
  // digitalWrite(LEFT_ULTRASONIC_TRIG_PIN, LOW);
  // delayMicroseconds(2);
  // digitalWrite(LEFT_ULTRASONIC_TRIG_PIN, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(LEFT_ULTRASONIC_TRIG_PIN, LOW);
  // left_duration = pulseIn(LEFT_ULTRASONIC_ECHO_PIN, HIGH);
  // left_distance = (left_duration*.0343)/2;

  // // Read right side data
  // digitalWrite(RIGHT_ULTRASONIC_TRIG_PIN, LOW);
  // delayMicroseconds(2);
  // digitalWrite(RIGHT_ULTRASONIC_TRIG_PIN, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(RIGHT_ULTRASONIC_TRIG_PIN, LOW);
  // right_duration = pulseIn(RIGHT_ULTRASONIC_ECHO_PIN, HIGH);
  // right_distance = (right_duration*.0343)/2;

  // // Map ultrasonic distance to sensor data
  //   // Only mapping if the wall/barrier is within 10cm
  //   // See https://www.arduino.cc/reference/en/language/functions/math/map/
  // if(left_distance < 10) {
  //   // Map the value of left_distance to left_motor_value using the built-in map function
  //      // What are the min an max distances within this block?
  //      // For the motor values, try reversing their order!
  //   XXXXXX
  // } else {
  //   left_motor_value = 200;
  // }
  
  // Add mapping code, just like you did above
  // if(right_distance < 10) {
  //   XXXXXX
  // } else {
  //   right_motor_value = 200;
  // }

  // // Print motor values on Serial monitor
  // Serial.println("ULTRASONIC DISTANCES");
  // Serial.print(  "  Left:  "); Serial.println(left_distance);
  // Serial.print(  "  Right: "); Serial.println(right_distance);
  // Serial.println(" ");
  
}

// Verify motor values are valid (within 0-255), then set motors to that values
static void run_motors(void) {
  // Constrain BOTH motor values on the range 0 to 255
    // Use the built-in Arduino function "constrain"
    // https://www.arduino.cc/reference/en/language/functions/math/constrain/
  XXXXX

  // Set motor "power" values
    // Write teh ANALOG values to BOTH motor pins
  XXXXX

  // Print motor values on Serial monitor
  Serial.println("MOTOR VALUES");
  Serial.print(  "  Left:  "); Serial.println(left_motor_value);
  Serial.print(  "  Right: "); Serial.println(right_motor_value);
  Serial.println(" ");

}




