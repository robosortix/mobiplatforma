
#include <Wire.h>

#define SERVO_ADDRESS 0x02
#define SERVO_CONTROLLER_ENABLE 0x25
#define SERVO_POSITION 0x2E

void tetrixServoEnable(TwoWire& i2c);
void setServoPosition(TwoWire& i2c, int servo_num, int angle);
void setServoPositionSmooth(TwoWire& i2c, int servo_num, int angle);

