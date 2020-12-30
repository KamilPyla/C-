#pragma once



class MyLine;

class MyPoem {

  public:
  //konstruktor ustawia liczbę możliwych wierszy oraz alokuje potrzebną na nie pamięć
  explicit MyPoem (int n);

  //konstruktor kopiujący, przyjmuje obiekt, dokonuje jego głębokiej kopii
  MyPoem (const MyPoem & cpy);
  
  //konstruktor przenoszący
  MyPoem(MyPoem && move);

  //destruktor zwalnia pamięć po alokacji
  ~MyPoem();

  //wpisuje wiersz line na n-te miejsce w MyPoem
  void setLine(int n,const MyLine & line);

  //wypisuje zawartość MyPoem wiersz po wierszu
  void print() const;

  private:
  //maksymalna liczba wierszy
  int _numLine;
  //tablica przechowyjąca wiersze
  MyLine * _lines;

};