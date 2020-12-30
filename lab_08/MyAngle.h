#pragma once


//Klasa wykonyjąca podstawowe operacjie na kątach
class MyAngle 
{

public:

// metoda ustawiająca wartość kąta w radianach
  void setRadians(double r);

// Metoda ustawianąca wartość kąta w stopniach
  void setDegrees(double d);

//procedura zamieniająca radiany na stopnie
  double toDeg();

//procedura zamieniająca stopnie na radiany
  double toRad();


//metoda ustawiająca wartość kąta na podstawie isniejącego obiektu
  void setAngle(MyAngle & ang);

// metoda dodająca do siebie dwie wartości kątów pochodzące z różnych obiektów
  void addAngle(MyAngle & ang);

	~MyAngle();


private:
//wartość liczbowa kąta
  double angle_deg;

  double angle_rad;
};

// metoda liczyąca różnicę wartości kątów dwóch obiektów
MyAngle distance(MyAngle &, MyAngle &);
