#include<iostream>
#include "MyRegister.h"
#include "MyGrade.h"

using std::cout;
using std::endl;


  MyRegister::MyRegister(int size){
    _maxsize = size;
    _number = 0;
    _ArrayGrades = new MyGrade * [size];

  }
  MyRegister::~MyRegister(){
    cout<<"Delete register with "<<_number<<"/"<<_maxsize<<" grades"<<endl;
    this->clearRegister();
    delete[] _ArrayGrades;
  }

  void MyRegister::addGrade(MyGrade * new_grade){
    if (_number < _maxsize){
      _ArrayGrades[_number] = new_grade;
      _number ++;
    }
    else{
      cout<<"The limit of "<<_maxsize<<" has been reached!"<<endl;
      delete new_grade;
    }
  }
  void MyRegister::showRegister() const{
    cout<<"Register "<<_number<<"/"<<_maxsize<<":";
    for (int i = 0; i < _number; i++)
      _ArrayGrades[i]->print();
    cout<<endl;

  }
  const MyRegister * MyRegister::backup() const{
    MyRegister * backup = new MyRegister(_number);
    for (int i = 0; i < _number; i++){
      backup->addGrade(new MyGrade(_ArrayGrades[i]->_grade,_ArrayGrades[i]->_num));
    }
    return backup;
    
  }
  void MyRegister::clearRegister(){
    for (int i = 0; i < _number; i++)
    delete _ArrayGrades[i];
    _number = 0;
    
  }


