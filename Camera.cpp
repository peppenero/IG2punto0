#include"Camera.h"

#include<iostream>
#include<math.h>

using namespace std;

Camera::Camera()
{
	Xangle=0.0;
	Yangle=0.0;
	
	this->Xpos=0.0;
	Ypos=0.0;
	Zpos=0.0;
	directionX=0.0;
	directionY=0.0;
	directionZ=0.0;
}

void Camera::setPosition(float angle, float xPos, float yPos, float zPos)
{
	xPos = Xpos;
	zPos = Zpos;
	yPos = Ypos;

	//compute instead of set based on angle
	Yangle = angle;
	this->directionX = sin(Yangle);
	this->directionZ = -cos(Yangle);

}

float Camera::getAngleY()
{
	return Yangle;
}
void Camera::setAngleY(float p)
{
	Yangle=p;
}

float Camera::getAngleX()
{
	return Xangle;
}
void Camera::setAngleX(float p)
{
	Xangle=p;
}

void Camera::setDirectionX(float d)
{
	directionX=d;
}
void Camera::setDirectionY(float d)
{
	directionY=d;
}
void Camera::setDirectionZ(float d)
{
	directionZ=d;
}
float Camera::getDirectionX()
{
	return directionX;
}
float Camera::getDirectionY()
{
	return directionY;
}
float Camera::getDirectionZ()
{
	return directionZ;
}

float Camera::getXpos()
{
	return Xpos;
}
float Camera::getYpos()
{
	return Ypos;
}
float Camera::getZpos()
{
	return Zpos;
}
void  Camera::setXpos(float p)
{
	Xpos=p;
}
void  Camera::setYpos(float p)
{
	Ypos=p;
}
void  Camera::setZpos(float p)
{
	Zpos=p;
}

Camera::~Camera(void)
{

}
