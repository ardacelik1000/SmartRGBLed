#include <Arduino.h>
#include <MPU6050.h>
#include <Wire.h>

MPU6050 MPU;
int GyroX , GyroY , GyroZ;
int red = 11;
int green = 10;
int blue = 9;
int x = 0; 


void WithoutColor() { 
  analogWrite(red, 255);
  analogWrite(green, 255);
  analogWrite(blue, 255);
}
void WhiteColor() { 
  analogWrite(red, 0);
  analogWrite(green, 0);
  analogWrite(blue, 0);
}
void GreenColor() { 
  analogWrite(red, 255);
  analogWrite(green, 0);
  analogWrite(blue, 255);
}
void YellowColor() { 
  analogWrite(red, 0);
  analogWrite(green, 0);
  analogWrite(blue, 255);
}
void RedColor() { 
  analogWrite(red, 0);
  analogWrite(green, 255);
  analogWrite(blue, 255);
}
void setup() {
  Serial.begin(9600);
  Wire.begin();
  MPU.initialize();
  WithoutColor(); 
}

void loop()
{
  MPU.getRotation(&GyroX, &GyroY, &GyroZ);

  bool sensor_active = GyroX < -1000 || GyroX > 1000 || GyroY > 1000 || GyroY < -1000 || GyroZ > 1000 || GyroZ < -1000;

  
  if(sensor_active && x == 0)
  {
    delay(1000);
    x = 1;
    WithoutColor(); 
    return; 
  }
  if (sensor_active && x == 1)
  {
    delay(1000);
    x = 2;
    WhiteColor();
    return; 
  }
  if (sensor_active && x == 2)
  {
    delay(1000);
    x = 3;
    GreenColor();
    return; 
  }
  if (sensor_active && x == 3)
  {
    delay(1000);
    x = 4; 
    YellowColor();
    return; 
  }

  if (sensor_active && x == 4)
  {
    delay(1000);
    RedColor(); 
    x = 0;
    return; 
  }
}
