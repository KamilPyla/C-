#include "InfoClass.h"
#include <iostream>

InfoClass::InfoClass (){

  _name = "";
  std::cout<<"++ Tworze obiekt InfoClass: "<<_name<<std::endl;

}

InfoClass::InfoClass (std::string name){

  _name = name;
  std::cout<<"++ Tworze obiekt InfoClass: "<<_name<<std::endl;

}

InfoClass::~InfoClass(){

  std::cout<<"-- Usuwam obiekt InfoClass: "<<_name<<std::endl;

}

///////////////////////////////////////////////////////////////////

std::string InfoClass::getInfo()const{

  return _name;

}

void InfoClass::setInfo(std::string name){

  _name = name;

}

