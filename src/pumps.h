#include <Arduino.h>

#define motor_1 3
#define motor_2 4
#define motor_3 5
#define motor_4 6
#define motor_5 7

void pumpsSetup()
{
    pinMode(motor_1, OUTPUT);
    pinMode(motor_2, OUTPUT);
    pinMode(motor_3, OUTPUT);
    pinMode(motor_4, OUTPUT);
    pinMode(motor_5, OUTPUT);
}