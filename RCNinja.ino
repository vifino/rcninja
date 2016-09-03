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

void setup() {
  Serial.begin(11520);
  motor.attach(5);
  steering.attach(6);

  // Indicate that we are actually alive.
  pinMode(13, OUTPUT);
  digitalWrite(13, true);
}

int motor_throttle = 0;
int steering_value = 90;

void loop() {
  while (Serial.available() > 0) {
      motor_throttle = constrain(Serial.parseInt(), 0, 180);
      steering_value = constrain(Serial.parseInt(), 0, 180);
  }
  motor.write(motor_throttle);
  steering.write(motor_throttle);
}
