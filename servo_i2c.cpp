#include <Arduino.h>
#include "servo_i2c.h"

void tetrixServoEnable(TwoWire& i2c) {
  i2c.beginTransmission(SERVO_ADDRESS);
  i2c.write(SERVO_CONTROLLER_ENABLE);
  i2c.endTransmission();
}

// функция, отвечающая за поворот сервопривода
void setServoPosition(TwoWire& i2c, int servo_num, int angle) {
  // входные параметры функции: 
  // i2c - ссылка на объект класса TwoWire
  // servo_num - сервопривод, который нужно повернуть на определенный угол
  // angle - угол поворота сервопривод
  i2c.beginTransmission(SERVO_ADDRESS);
  i2c.write(SERVO_POSITION+servo_num);
  i2c.write(angle);
  i2c.endTransmission();
}

// функция, отвечающая за плавный поворот сервопривода
void setServoPositionSmooth(TwoWire& i2c, int servo_num, int angle) { 
  // входные параметры функции: 
  // i2c - ссылка на объект класса TwoWire
  // servo_num - сервопривод, который нужно повернуть на определенный угол
  // angle - угол поворота сервопривод

   int step;
   int i = 0;

   if (angle < 0) { // если угол поворота отрицательный
     step = -1; // шаг поворота = -1 град
     i = abs(angle);
     do {
      i += step;
      // плавно поворачиваем сервопривод с шагом -1 град.
      setServoPosition(i2c, servo_num, i);
      delay(25);
     } while (i != 0);
     
   } else { // если угол поворота положительный
     step = 1; // шаг поворота = 1 град
     do {
      i += step;
      // плавно поворачиваем сервопривод с шагом +1 град.
      setServoPosition(i2c, servo_num, i);
      delay(25);
     } while (i != angle);
   }
}
