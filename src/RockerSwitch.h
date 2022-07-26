#include<Arduino.h>

class RockerSwitch{
    int _SWITCH_1;
    int _SWITCH_2;

    public:
        // Initialize the Rocker Switch
        RockerSwitch(int switch_1, int switch_2){
            _SWITCH_1 = switch_1;
            _SWITCH_2 = switch_2;

            pinMode(_SWITCH_1, INPUT_PULLUP);
            pinMode(_SWITCH_2, INPUT_PULLUP);
        };

        String switchPos(){
            if (digitalRead(_SWITCH_1)==HIGH){
                return "up";
            }else if (digitalRead(_SWITCH_2)==HIGH){
                return "down";
            }
        }
};