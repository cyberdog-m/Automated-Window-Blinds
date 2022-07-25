#include <Arduino.h>

class MotorDriver{
    int _MOTOR_IN_1;
    int _MOTOR_IN_2;
    int _MOTOR_PWM;

    public:
        // Initilize the motor driver pins
        MotorDriver(int motor_in_1, int motor_in_2, int motor_pwm){
            _MOTOR_IN_1 = motor_in_1;
            _MOTOR_IN_2 = motor_in_2;
            _MOTOR_PWM = motor_pwm;

            pinMode(_MOTOR_IN_1, OUTPUT);
            pinMode(_MOTOR_IN_2, OUTPUT);
            pinMode(_MOTOR_PWM, OUTPUT);
        }

        // Rotates the motor in Clockwise direction at a specific speed
        void rotateCW(int motorSpeed){
            digitalWrite(_MOTOR_IN_1, 1);
            digitalWrite(_MOTOR_IN_2, 0);
            // Control the motor speed using pwm
            analogWrite(_MOTOR_PWM, motorSpeed);
        }

        // Rotates the motor in Counter Clockwise direction at a specific speed
        void rotateCCW(int motorSpeed){
            digitalWrite(_MOTOR_IN_1, 0);
            digitalWrite(_MOTOR_IN_2, 1);
            // Control the motor speed using pwm
            analogWrite(_MOTOR_PWM, motorSpeed);
        }

        // Brake the motor; Bring the motor to a halt
        void brake(){
            digitalWrite(_MOTOR_IN_1, 0);
            digitalWrite(_MOTOR_IN_2, 0);
        }
};