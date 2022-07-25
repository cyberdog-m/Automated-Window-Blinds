#include <Arduino.h>

class HallEffect{
    int _SENSOR_1;
    int _SENSOR_2;

    public:
        // Initialize the Hall Effect sensors
        HallEffect(int sensor_1, int sensor_2){
            _SENSOR_1 = sensor_1;
            _SENSOR_2 = sensor_2;

            pinMode(_SENSOR_1, INPUT);
            pinMode(_SENSOR_2, INPUT);
        };

        // Check for the position of the curtain
        String checkPosition(){
            // Check if sensor is active
            if (isActive(_SENSOR_1)){
                return "top";
            }
            // Check if sensor 2 is active
            else if (isActive(_SENSOR_2)){
                return "bottom";
            }
            // Both sensors not active
            else {
                return "middle";
            }
        }

    private:
        // Check whether the sensor is active
        bool isActive(int sensor){
            int sensorValue = analogRead(sensor);
            // Serial.println(sensorValue);
            int threshold = 10;

            if (sensorValue <= threshold){
                return true;
            }
            return false;
        }
};
