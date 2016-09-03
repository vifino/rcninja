/*
 * RCNinja: Crowd-controllable RC Car with live video feed.
 * 
 * This is the code that will control the Servo for steering and the motor
 * controller. It will accept two numbers, for steering and motor, respectively.
 * 
 * Pins: The motor controller is on port 5, the steering servo is on port 6.
 */

#include <Servo.h>

// Initialize servos.
Servo motor;
Servo steering;

// Start values
int motor_throttle = 0;
int steering_value = 80;

// Strings
int char_newline = 10;
int char_space = 32;

void setup() {
  Serial.begin(9600);
  motor.attach(5);
  steering.attach(6);

  // Indicate that we are actually alive.
  pinMode(13, OUTPUT);
  digitalWrite(13, true);
}

String read_buffer = "";

int read_num_until(int stopchar) {
  read_buffer = "";
  while (Serial.available() > 0) {
    int inp_byte = Serial.read();
    if (inp_byte == stopchar)
      return read_buffer.toInt();
    else {
      read_buffer += (char)inp_byte;
    }
  }
}


void loop() {
  while (Serial.available() > 0) {
    motor_throttle = read_num_until(char_space);
    steering_value = read_num_until(char_newline);
    Serial.write("Motor: ");
    Serial.print(motor_throttle);
    Serial.write("\nSteering: ");
    Serial.print(steering_value);
    Serial.write("\n");
  }
  motor.write(motor_throttle);
  steering.write(steering_value);
}
