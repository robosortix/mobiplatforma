
#include "servo_i2c.h"
#include "dcmotor_i2c.h"

TwoWire i2cwire;

void setup() {
  Serial.begin(9600);
  i2cEnable(i2cwire);
  tetrixServoEnable(i2cwire);
  tetrixMotorEnable(i2cwire);
}

void loop() {
  char buf[50];
  String recStr = "";
  int num1, num2, value1, value2;
  char symbol;
  char device[10], action[10];
  char what[10], how[10];
  String command_str = "";
  //"servo 1,0:slow -90,0"
  //"motor 1,2:power 20,20"
  //"motor 1,2:power 0,0"
  //"motor 1,2:invert 0,0"
  //"motor 1,2:speed 1000,0"
  
  do {
    symbol = Serial.read();
    if (symbol != '\xFF') {
      if (symbol == '\x0A') {
        //Serial.println("received: " + recStr);
        break;
      } else {
        recStr += symbol;
      }       
    }
  } while (1);

  recStr.toCharArray(buf, 50);
  sscanf(buf, "%s%s", &what, &how);

  String what_to_do = String(what);
  String how_fast = String(how);

  if (what_to_do == "forward") {
    
    if (how_fast == "slow") {
      command_str = "motor 1,2:invert 1,0";
      command_str.toCharArray(buf, 50);
      sscanf(buf, "%s%d,%d:%s%d,%d", &device, &num1, &num2, &action, &value1, &value2);
      execMotorCommand(i2cwire, num1, num2, action, value1, value2);
      delay(100);
      command_str = "motor 1,2:power 20,20";
      command_str.toCharArray(buf, 50);
      sscanf(buf, "%s%d,%d:%s%d,%d", &device, &num1, &num2, &action, &value1, &value2);
      execMotorCommand(i2cwire, num1, num2, action, value1, value2);
      
   } else  if (how_fast == "med") {
      command_str = "motor 1,2:invert 1,0";
      command_str.toCharArray(buf, 50);
      sscanf(buf, "%s%d,%d:%s%d,%d", &device, &num1, &num2, &action, &value1, &value2);
      execMotorCommand(i2cwire, num1, num2, action, value1, value2);
      delay(100);
      command_str = "motor 1,2:power 50,50";
      command_str.toCharArray(buf, 50);
      sscanf(buf, "%s%d,%d:%s%d,%d", &device, &num1, &num2, &action, &value1, &value2);
      execMotorCommand(i2cwire, num1, num2, action, value1, value2);
      
    } else { // fast
      command_str = "motor 1,2:invert 1,0";
      command_str.toCharArray(buf, 50);
      sscanf(buf, "%s%d,%d:%s%d,%d", &device, &num1, &num2, &action, &value1, &value2);
      execMotorCommand(i2cwire, num1, num2, action, value1, value2);
      delay(100);
      command_str = "motor 1,2:power 80,80";
      command_str.toCharArray(buf, 50);
      sscanf(buf, "%s%d,%d:%s%d,%d", &device, &num1, &num2, &action, &value1, &value2);
      execMotorCommand(i2cwire, num1, num2, action, value1, value2);
    }
    
  } else if (what_to_do == "back") {

    if (how_fast == "slow") {
      command_str = "motor 1,2:invert 0,1";
      command_str.toCharArray(buf, 50);
      sscanf(buf, "%s%d,%d:%s%d,%d", &device, &num1, &num2, &action, &value1, &value2);
      execMotorCommand(i2cwire, num1, num2, action, value1, value2);
      delay(100);
      command_str = "motor 1,2:power 20,20";
      command_str.toCharArray(buf, 50);
      sscanf(buf, "%s%d,%d:%s%d,%d", &device, &num1, &num2, &action, &value1, &value2);
      execMotorCommand(i2cwire, num1, num2, action, value1, value2);
      
    } else  if (how_fast == "med") {
      command_str = "motor 1,2:invert 0,1";
      command_str.toCharArray(buf, 50);
      sscanf(buf, "%s%d,%d:%s%d,%d", &device, &num1, &num2, &action, &value1, &value2);
      execMotorCommand(i2cwire, num1, num2, action, value1, value2);
      delay(100);
      command_str = "motor 1,2:power 50,50";
      command_str.toCharArray(buf, 50);
      sscanf(buf, "%s%d,%d:%s%d,%d", &device, &num1, &num2, &action, &value1, &value2);
      execMotorCommand(i2cwire, num1, num2, action, value1, value2);
      
    } else { // fast
      command_str = "motor 1,2:invert 0,1";
      command_str.toCharArray(buf, 50);
      sscanf(buf, "%s%d,%d:%s%d,%d", &device, &num1, &num2, &action, &value1, &value2);
      execMotorCommand(i2cwire, num1, num2, action, value1, value2);
      delay(100);
      command_str = "motor 1,2:power 80,80";
      command_str.toCharArray(buf, 50);
      sscanf(buf, "%s%d,%d:%s%d,%d", &device, &num1, &num2, &action, &value1, &value2);
      execMotorCommand(i2cwire, num1, num2, action, value1, value2);
    }
    
  } else if (what_to_do == "left") {
    
    int how_long = how_fast.toInt();
   
    command_str = "motor 1,2:power 0,0";
    command_str.toCharArray(buf, 50);
    sscanf(buf, "%s%d,%d:%s%d,%d", &device, &num1, &num2, &action, &value1, &value2);
    execMotorCommand(i2cwire, num1, num2, action, value1, value2);

    delay(100);

    command_str = "motor 1,2:invert 1,0";
    command_str.toCharArray(buf, 50);
    sscanf(buf, "%s%d,%d:%s%d,%d", &device, &num1, &num2, &action, &value1, &value2);
    execMotorCommand(i2cwire, num1, num2, action, value1, value2);

    delay(50);

    command_str = "motor 1,2:power -50,40";
    command_str.toCharArray(buf, 50);
    sscanf(buf, "%s%d,%d:%s%d,%d", &device, &num1, &num2, &action, &value1, &value2);
    execMotorCommand(i2cwire, num1, num2, action, value1, value2);

    delay(how_long*1000);

    command_str = "motor 1,2:power 0,0";
    command_str.toCharArray(buf, 50);
    sscanf(buf, "%s%d,%d:%s%d,%d", &device, &num1, &num2, &action, &value1, &value2);
    execMotorCommand(i2cwire, num1, num2, action, value1, value2);

  } else if (what_to_do == "right") {

    int how_long = how_fast.toInt();
   
    command_str = "motor 1,2:power 0,0";
    command_str.toCharArray(buf, 50);
    sscanf(buf, "%s%d,%d:%s%d,%d", &device, &num1, &num2, &action, &value1, &value2);
    execMotorCommand(i2cwire, num1, num2, action, value1, value2);

    delay(100);

    command_str = "motor 1,2:invert 1,0";
    command_str.toCharArray(buf, 50);
    sscanf(buf, "%s%d,%d:%s%d,%d", &device, &num1, &num2, &action, &value1, &value2);
    execMotorCommand(i2cwire, num1, num2, action, value1, value2);

    delay(50);

    command_str = "motor 1,2:power 50,-50";
    command_str.toCharArray(buf, 50);
    sscanf(buf, "%s%d,%d:%s%d,%d", &device, &num1, &num2, &action, &value1, &value2);
    execMotorCommand(i2cwire, num1, num2, action, value1, value2);

    delay(how_long*1000);

    command_str = "motor 1,2:power 0,0";
    command_str.toCharArray(buf, 50);
    sscanf(buf, "%s%d,%d:%s%d,%d", &device, &num1, &num2, &action, &value1, &value2);
    execMotorCommand(i2cwire, num1, num2, action, value1, value2);
    
  } else { // stop
    command_str = "motor 1,2:power 0,0";
    command_str.toCharArray(buf, 50);
    sscanf(buf, "%s%d,%d:%s%d,%d", &device, &num1, &num2, &action, &value1, &value2);
    execMotorCommand(i2cwire, num1, num2, action, value1, value2);
  }
  
  delay(500);
  
  /*setServoPosition(i2cwire, 1, 0);
  delay(1000);
  setServoPosition(i2cwire, 1, 90);
  delay(1000);
  setServoPositionSmooth(i2cwire, 1, -90);
  delay(1000);
  setServoPositionSmooth(i2cwire, 1, 90);
  delay(1000);*/
}

void i2cEnable(TwoWire& i2c) {
  i2c.begin();
}

void execServoCommand(TwoWire& i2c, int num, char *action, int value) {
  String act = String(action);
  
  if (act == "fast") {
    setServoPosition(i2c, num, abs(value));
  } else {
    setServoPositionSmooth(i2c, num, value);
  }
}

void execMotorCommand(TwoWire& i2c, int num1, int num2, char *action, int value1, int value2) {
  String act = String(action);
  
  if (act == "power") {
    setMotorPower(i2c, num1, value1);
    if (num2 != 0) {
       setMotorPower(i2c, num2, value2);
    } 
  } else if (act == "invert") {
    setMotorInvert(i2c, num1, abs(value1));
    if (num2 != 0) {
       setMotorInvert(i2c, num2, abs(value2));
    }
  } else if (act == "speed") {
    setMotorSpeed(i2c, num1, abs(value1));
    if (num2 != 0) {
       setMotorSpeed(i2c, num2, abs(value2));
    }
  }
}
