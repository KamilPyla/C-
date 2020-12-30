#include <iostream>
#include "MyGrade.h"

using std::cout;
using std::endl;

int MyGrade::_ID = 0;

  MyGrade::MyGrade(double grade, int ID ) {
    _grade = grade;
    if (ID == 0){
      _ID++;
      _num = _ID;
    }
    else {
      _num = ID;
    }
  }


  MyGrade::~MyGrade(){
    cout<<"Delete grade with id "<<_num<<endl;
  }


  void MyGrade::print(){
    cout<<"["<<_ID<<": "<<_grade<<"]  ";
  }

