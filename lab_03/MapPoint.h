#pragma once

struct MapPoint
{
  double latitude;
  double longitude;
  char * name;
};

//Funkcja tworząca punkty na mapie
struct MapPoint constructMP(const char *, const double, const double);
//Funkcja zwracająca dystans pomiędzy dwama punktami
double distance(struct MapPoint, struct MapPoint);
//Procedura wypisująca punkty na mapie
void print(struct MapPoint);
//Procedura przesuwająca punkty
void movePoint (struct MapPoint& , double, double);
//Funkcja wyznaczająca środek między punktami
struct MapPoint inTheMiddle (struct MapPoint, struct MapPoint, const char*);
//Funkcje zwalniające pamięć
void clear (struct MapPoint);
void clear (int ,struct MapPoint**);