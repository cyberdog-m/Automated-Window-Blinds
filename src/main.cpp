#include <Arduino.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>

#include<HallEffect.h>
#include<MotorDriver.h>

// I/O Pin Defnitions
int ioPin = 4;
int clkPin = 5;
int cePin = 6;

// Motor Pins
int motor_in_1 = 27;
int motor_in_2 = 26;
int motor_pwm = 25;

// Hall Effect sensor Pins
int sensor_1 = 12;
int sensor_2 = 33;

int blindOpenTime = 9;
int blindCloseTime = 16;

int data1,data2;

MotorDriver motor(motor_in_1, motor_in_2, motor_pwm);
HallEffect hallEffect(sensor_1, sensor_2);

void moveUp(){
  // Rotate the motor if the curtain is not at TOP 
  while (hallEffect.checkPosition() != "top"){
    motor.rotateCW(100);
    Serial.println("Moving Blind UP");
    delay(100);
  }
}

void moveDown(){
  // Rotate the motor if the curtain is not at TOP 
  while (hallEffect.checkPosition() != "bottom"){
    motor.rotateCCW(100);
    Serial.println("Moving Blind Down");
    delay(100);
  }
}

void setup() {
  Serial.begin(115200);
}

void loop() {
  // data1 = analogRead(sensor_1);
  // data2 = analogRead(sensor_2);

  // Serial.print("Sensor1:");
  // Serial.println(data1);
  // Serial.print("Sensor2:");
  // Serial.println(data2);

  Serial.println(hallEffect.checkPosition());
  moveUp();
  delay(300);
}