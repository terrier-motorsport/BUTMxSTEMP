// Terrier Motorsport x STEM Pathways
  // Code written by Michael Waetzman, mwae@bu.edu
  // Intended for adaptation by members
  // FULL CODE

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

  Arduino code is essentially C++ code, but with some added functions like digitalRead and pinMode. If
  you're unfamiliar with C or C++, don't worry! Any grey code (like this) is a comment, it describes what's 
  going on in a given section. You don't need to add anything to this code to make it work, but you will need 
  to uncomment some sections based on the sensor your team chooses to use! Read through the code line-by-line 
  and ask for help if you need any!

*/

// ================================================================================================
// SECTION 1: HEADER

// This is the "header section"
  // We add libraries here, like adding "stdio" or "math" in proper C++ code
  // We also define global variables here
  // Typically, global variables are Arduino pins, max/min values, and other stuff that doesn't change

// #include <Arduino_FreeRTOS.h>   // Library for parallel processing, if you'd like to use it
  // https://github.com/feilipu/Arduino_FreeRTOS_Library
  
#define BAUD_RATE 115200

#define LEFT_MOTOR_PIN 5      // PWM enabled pin, meaning we can write any values between 0V and 5V
#define RIGHT_MOTOR_PIN 6     // ^^^

#define LEFT_IR_PIN  14       // Pin A0, Using ANALOG IN pins, as we're reading analog sensor values
#define RIGHT_IR_PIN 15       // Pin A1, ^^^

#define LEFT_ULTRASONIC_TRIG_PIN 16   // Pin A2
#define LEFT_ULTRASONIC_ECHO_PIN 17   // Pin A3
#define RIGHT_ULTRASONIC_TRIG_PIN 18   // Pin A4
#define RIGHT_ULTRASONIC_ECHO_PIN 19   // Pin A5

#define LED_PIN   4           // Non-PWM, used for on/off display so we don't need variable values
#define LED_DELAY 1000        // 1000ms --> 2.5 second delay

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
  pinMode(LEFT_MOTOR_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN, OUTPUT);

  pinMode(LEFT_IR_PIN, INPUT);
  pinMode(RIGHT_IR_PIN, INPUT);

  // Setting up ultrasonic sensor's communication pins
  pinMode(LEFT_ULTRASONIC_TRIG_PIN, OUTPUT);
  pinMode(LEFT_ULTRASONIC_ECHO_PIN, INPUT);
  pinMode(RIGHT_ULTRASONIC_TRIG_PIN, OUTPUT);
  pinMode(RIGHT_ULTRASONIC_ECHO_PIN, INPUT);

  pinMode(LED_PIN, OUTPUT);


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

    // xTaskCreate(
    //   run_motors
    //   ,  "Run motors"
    //   ,  128
    //   ,  NULL
    //   ,  0              // Highest priority, we don't want the motors to "wait" for anything else!
    //   ,  NULL );

    // xTaskCreate(
    //   read_sensor_left
    //   ,  "Read right sensor"
    //   ,  128
    //   ,  NULL
    //   ,  1              // High priority, but less than the motor priority. What would this be on a self-driving car?
    //   ,  NULL );

    // xTaskCreate(
    //   read_sensor_right
    //   ,  "Read right sensor"
    //   ,  128
    //   ,  NULL
    //   ,  1
    //   ,  NULL );


}


// This code gets repeted forever! Think of it like an infinite while loop.
  // If we used FreeRTOS and parallel processing, we wouldn't need this loop!
  // Note: this loop runs in series, one function after another --> using the Serial Monitor, see how long each function takes
void loop() {
  // led_flash();   // uncomment this to flash the LED, but comment it out when racing! why?
  read_sensors();
  run_motors();
}

// ================================================================================================
// SECTION 4: YOUR FUNCTIONS

// Flash the pin 4 LED on and off
static void led_flash(void){
  digitalWrite(LED_PIN, HIGH);  // Output 5V to the LED_PIN
  Serial.println("LED ON");  // Print on the serial monitor, make sure it's set to the correct baud rate!
  delay(LED_DELAY);             // Time in ms, declared in the header section
  
  digitalWrite(LED_PIN, LOW);   // Output 0V to the LED_PIN
  Serial.println("LED OFF");
  delay(LED_DELAY);
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
  //   left_motor_value = map(left_distance, 0, 10, 255, 200);
  // } else {
  //   left_motor_value = 200;
  // }

  // if(right_distance < 10) {
  //   right_motor_value = map(right_distance, 0, 10, 255, 200);
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
  left_motor_value = constrain(left_motor_value, 0, 255);     // constrains the PWM_value a range of 0->255
  right_motor_value = constrain(right_motor_value, 0, 255);   // ^^^

  // Set motor "power" values
  analogWrite(LEFT_MOTOR_PIN, left_motor_value);
  analogWrite(RIGHT_MOTOR_PIN, right_motor_value);

  // Print motor values on Serial monitor
  Serial.println("MOTOR VALUES");
  Serial.print(  "  Left:  "); Serial.println(left_motor_value);
  Serial.print(  "  Right: "); Serial.println(right_motor_value);
  Serial.println(" ");

}




