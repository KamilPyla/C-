#include <iostream>
#include "MyString.h"
#include <cstring>



mystring::MyString::MyString(){
  _string = new char[1];
  *_string = '\0';
  _size = 0;
}



mystring::MyString::MyString(const char * str){
   _size = strlen(str) + 1;
  _string = new char[_size];
  strcpy(_string,str);
 
}


mystring::MyString::MyString(const MyString & cpy){
  _size = strlen(cpy._string) + 1;
  _string = new char[_size];
  strcpy(_string,cpy._string);
 
}



mystring::MyString::~MyString()
{
  delete [] _string;
}



mystring::MyString::operator char*()const{
  return _string;
}




bool mystring::MyString::operator ==(const char * str)const{
  return strcmp(_string,str) ? false:true;
}


bool mystring::MyString::operator ==(const MyString & str)const{
  return strcmp(_string,str._string) ? false:true;
}


mystring::MyString mystring::MyString::operator +(const MyString & str)const{
  MyString nstring;
  nstring._size = _size + strlen(str._string);
  delete [] nstring._string;
  nstring._string = new char [nstring._size];
  strcpy(nstring._string, _string);
  strcat(nstring._string, str._string);
  return nstring;
}


mystring::MyString mystring::MyString::operator +(const char * str)const{
  MyString nstring;
  nstring._size = _size + strlen(str);
  delete [] nstring._string;
  nstring._string = new char [nstring._size];
  strcpy(nstring._string, _string);
  strcat(nstring._string, str);
  return nstring;
}


mystring::MyString mystring::MyString::operator +(char sig)const{
  MyString nstring;
  nstring._size = _size + 1;
  delete [] nstring._string;
  nstring._string = new char [nstring._size];
  strcpy(nstring._string, _string);
  strcat(nstring._string, &sig);
  return nstring;
}


mystring::MyString mystring::MyString::operator =(const MyString & str)
{
  _size = str._size;
  delete [] _string;
  _string = new char[_size];
  strcpy(_string, str._string);
  return *this;
}

mystring::MyString mystring::MyString::operator =(const char * str){
  _size = strlen(str) + 1;
  delete [] _string;
  _string = new char[_size];
  strcpy(_string,str);
  return *this;
}


void mystring::MyString::print(const char * beg)const{
  std::cout<<beg<<*this<<std::endl;
}


char * mystring::MyString::getString()const {
  return _string;
}

mystring::MyString mystring::operator *(int num,const MyString & str){
  MyString nstring;
  nstring._size = num * strlen(str._string) + 1;
  delete [] nstring._string;
  nstring._string = new char [nstring._size];
  strcpy(nstring._string,str._string);
  for (int i = 0; i < num -1; i++)
    strcat(nstring._string,str._string);
  return nstring;


}
