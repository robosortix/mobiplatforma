#include <Arduino.h>
#include "dcmotor_i2c.h"

void tetrixMotorEnable(TwoWire& i2c) {
  i2c.beginTransmission(MOTOR_ADDRESS);
  i2c.write(MOTOR_CONTROLLER_ENABLE);
  i2c.endTransmission();
}

// Sets the power level for motor
void setMotorPower(TwoWire& i2c, int motor_num, int power) {
  // входные параметры функции: 
  // i2c - ссылка на объект класса TwoWire
  // motor_num - мотор, который нужно включить на определенную мощность
  // power - мощность в пpоцентах (-100...100)
  i2c.beginTransmission(MOTOR_ADDRESS);
  i2c.write(MOTOR_POWER+motor_num);
  i2c.write(power);
  i2c.endTransmission();
}

// Sets motor speed parameter (in units of degrees per second)
void setMotorSpeed(TwoWire& i2c, int motor_num, int speed) {
  // входные параметры функции: 
  // i2c - ссылка на объект класса TwoWire
  // motor_num - мотор, для которого нужно установить параметр скорости
  // speed = -32768...32767
  i2c.beginTransmission(MOTOR_ADDRESS);
  i2c.write(MOTOR_SPEED+motor_num);
  i2c.write(highByte(speed));
  i2c.write(lowByte(speed));
  i2c.endTransmission();
}

// Sets motor to invert or non-invert mode
void setMotorInvert(TwoWire& i2c, int motor_num, int invert) {
  // входные параметры функции: 
  // i2c - ссылка на объект класса TwoWire
  // motor_num - мотор, который нужно запустить в противоположную сторону
  // invert = 1: invert mode, 0 = non-invert mode
  i2c.beginTransmission(MOTOR_ADDRESS);
  i2c.write(MOTOR_INVERT+motor_num);
  i2c.write(invert);
  i2c.endTransmission();
}
