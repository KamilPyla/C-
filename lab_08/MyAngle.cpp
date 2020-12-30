#include "MyAngle.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

void MyAngle::setRadians(double r)
{
  while(r<0)
    r = r + 2*M_PI;

  while (r > 2*M_PI)
    r = r - 2*M_PI;

  angle_rad = r;

  angle_deg = (angle_rad * 180)/M_PI;
}

///////////////////////////////////////////////////////////////////////
void MyAngle::setDegrees(double d)
{
  while (d < 0)
    d = d + 360;

  while (d > 360)
    d = d - 360;

  angle_deg = d;

  angle_rad = (M_PI*angle_deg)/180;
}

//////////////////////////////////////////////////////////////////////////
double MyAngle::toRad() 
{
  return angle_rad;
}

///////////////////////////////////////////////////////////////////////
double MyAngle::toDeg() 
{
  return angle_deg; 
}

/////////////////////////////////////////////////////////////////
void MyAngle::setAngle(MyAngle & ang)
{
  angle_deg = ang.angle_deg;

  angle_rad = angle_rad;
}

///////////////////////////////////////////////////////////
void MyAngle::addAngle(MyAngle & a)
{
  this->setDegrees(angle_deg + a.angle_deg );
}

////////////////////////////////////////////////////////////
MyAngle::~MyAngle()
{
	cout<<"Zamykamy kąt: "<<angle_deg<<endl;
}

/////////////////////////////////////////////////////////
MyAngle distance (MyAngle & a,MyAngle & b)
{

  MyAngle result;

  double new_angle = (a.toDeg() - b.toDeg());

  if (new_angle > 180)
    new_angle = fabs(new_angle - 360);

  result.setDegrees(new_angle);

  return result;
}
