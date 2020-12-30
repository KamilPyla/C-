#pragma once
// Klasa służąca do wypisywania linii oddzielających wraz z numerem porządkowym wypisywanje linii
class MyPrint 
{
public:
//metoda inicjująca obiekt klasy MyPrint jako argument przyjmuje int, który oznacza ilość gwiazdek przed numerem porządkowym linii
  void init(int n);

//Metoda wypisująca etaOne.toRad() < thetaTwo.toRad() ? thetaOne : thetaTwo;linię
  void printLine();

// Destruktor
  ~MyPrint();

private:

//Atrybut mówiący o ilości gwiazdek
  int number_stars;

//Atrybut mówiący o numerze wypisywanej linii
  int number_line;
};
