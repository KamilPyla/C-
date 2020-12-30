#include "MyLine.h"

  
  MyLine::operator const char * () const 
  {
    return (const char *)(&_line[0]);
  }
  MyLine::MyLine (const char * line) {
    _line = line;
  }

  
