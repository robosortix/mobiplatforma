
#include <Wire.h>

#define MOTOR_ADDRESS 0x01
#define MOTOR_CONTROLLER_ENABLE 0x25
#define MOTOR_POWER 0x3F
#define MOTOR_SPEED 0x42
#define MOTOR_INVERT 0x50


void tetrixMotorEnable(TwoWire& i2c);
void setMotorPower(TwoWire& i2c, int motor_num, int power);
void setMotorSpeed(TwoWire& i2c, int motor_num, int speed);
void setMotorInvert(TwoWire& i2c, int motor_num, int invert);


