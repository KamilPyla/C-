#pragma once

class MyGrade;

class MyRegister
{
  int _maxsize;
  int _number;
  MyGrade ** _ArrayGrades;

public:
  MyRegister(int size);
  ~MyRegister();
  void addGrade(MyGrade * new_grade);
  void showRegister() const;
  const MyRegister * backup() const;
  void clearRegister();



};