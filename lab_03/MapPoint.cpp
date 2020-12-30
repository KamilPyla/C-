#include "MapPoint.h"
#include <iostream>
#include <cstring>
#include <cmath>

void print(struct MapPoint x)
{
  std::cout<< "Punkt na mapie <"<<x.name<<"> ma wspolrzedne [ ";
  if(x.latitude >= 0)
    std::cout<<x.latitude<<" N, ";
  else
    std::cout<<fabs(x.latitude)<<" S, ";
  if(x.longitude >= 0)
    std::cout<<x.longitude<<" E ]"<<std::endl;
  else
    std::cout<< (-1)*x.longitude<<" W ]"<<std::endl;
}

struct MapPoint constructMP(const char *str, const double lati, const double longi)
{
  MapPoint point;
  point.latitude = lati;
  point.longitude = longi;
  point.name = (char *)malloc(strlen(str)+1);
  strcpy(point.name,str);
  return point;
}

double distance(struct MapPoint a, struct MapPoint b)
{
  double x = fabs(a.latitude - b.latitude);
  double y = fabs(a.longitude - b.longitude);
  return sqrt(x*x+y*y);
}

void movePoint (struct MapPoint& a, double x, double y)
{
  a.latitude = a.latitude + x;
  a.longitude = a.longitude + y;
}

struct MapPoint inTheMiddle (struct MapPoint a, struct MapPoint b , const char* middle)
{
  MapPoint midl;
  midl.latitude = (a.latitude + b.latitude)/2;
  midl.longitude = (a.longitude + b.longitude)/2;
  midl.name = (char *)malloc(strlen(middle)+1);
  strcpy(midl.name,middle);
  return midl;
}

void clear (struct MapPoint a)
{
  free(a.name);
}
void clear (int size ,struct MapPoint** tab)
{
  for (int i = 0; i < size; i++)
  {
    free(tab[i]->name);
  }
}