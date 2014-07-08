#include<iostream>


#ifndef CAMERA_H
#define CAMERA_H

class Camera
{

private:
  float Xangle;
  float Yangle;
  
  float directionX;
  float directionY;
  float directionZ;
  float Xpos;
  float Ypos;
  float Zpos;

public:

  Camera();

  void setPosition(float,float,float,float);
  float getAngleY();
  void setAngleY(float);
  float getAngleX();
  void setAngleX(float);
  void setDirectionX(float);
  void setDirectionY(float);
  void setDirectionZ(float);
  float getDirectionX();
  float getDirectionY();
  float getDirectionZ();
  float getXpos();
  float getYpos();
  float getZpos();
  void  setXpos(float);
  void  setYpos(float);
  void  setZpos(float);
  ~Camera(void);

};


#endif
