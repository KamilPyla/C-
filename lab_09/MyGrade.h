#pragma once

class MyRegister;

class MyGrade
{
  double _grade;
  static int _ID;
  int _num;

public:
  MyGrade(double grade, int ID = 0 );
  ~MyGrade();
  friend class MyRegister;
  void print();

};