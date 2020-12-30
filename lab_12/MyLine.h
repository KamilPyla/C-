#pragma once
#include <iostream>


class MyLine {
friend class MyPoem;
public:
  //konstruktor domyślmy ustawia pusty wiersz
  MyLine (): _line(""){};
  //konstruktor konwertujący
  MyLine (const char * line);
  //konwerter
  operator const char * () const;

private:
//pole przechowujęce wiersz
  std::string _line;

};