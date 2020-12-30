#include "MyString.h"
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

  MyString::MyString(){
    _string = new char;
    *_string = '\0';
    cout<<"CTOR(def) = <"<<_string<<">"<<endl;
  }

  MyString::MyString (const char * name){

    _string = new char[strlen(name) +1];
    strcpy(_string, name);
    std::cout<<"CTOR(cstr) = <"<<_string<<">"<<endl;
  }

  MyString::MyString(  const MyString & cpy){
  
    _string = new char[strlen(cpy._string)+1];
    strcpy(_string, cpy._string);
    cout<<"CTOR( copy ) = <"<<_string<<">"<<endl;
  }


  MyString::~MyString(){
    cout<<"Destruktor = <"<<_string<<">"<<endl;
    delete [] _string;
  }

  MyString::MyString(const MyStringProxy & cpy){
    int len = cpy._end - cpy._beg;
    _string = new char[cpy._end - cpy._beg +1];
    char * ptr = cpy._beg;
    int i = 0;
    while(ptr != cpy._end){
      _string[i] = *ptr;
      i++;
      ptr++;
    }
    _string[i] = '\0';

    cout<<"CTOR(proxy) = <"<<_string<<">"<<endl;
  }


  char * MyString::str() const {
    return _string;
  }

  MyStringProxy::MyStringProxy(char *beg, char*end){
    _beg = beg;
    _end = end;
  }

  MyStringProxy MyString::subStr(int a, int b) const{
    MyStringProxy proxy(_string + a,_string + b);
    return proxy;
  }

  MyStringProxy::~MyStringProxy(){}