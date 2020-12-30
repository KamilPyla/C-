  #include "MyPoem.h"
	#include "MyLine.h"
	#include <iostream>
  MyPoem::MyPoem(int n) {
    _numLine = n;
    _lines = new MyLine [n]; 
  }

  MyPoem::MyPoem (const MyPoem & cpy){
    _numLine = cpy._numLine;
    _lines = new MyLine [_numLine];
    for (int i = 0; i < _numLine; i++) {
      _lines[i] = cpy._lines[i];
    }
  }

  MyPoem::MyPoem(MyPoem && move){
  
    _lines = move._lines;
    _numLine = move._numLine;
    move._lines = nullptr;
    move._numLine = 0;
  }
 
  MyPoem::~MyPoem(){
    delete [] _lines;
  }

  void  MyPoem::setLine(int n, const MyLine & line){
    if (n < _numLine){
      _lines[n] = line;
    }
  }

  void MyPoem::print() const{
    for (int i = 0; i < _numLine; i++){
      std::cout << _lines[i] << std::endl;
    }
  }

