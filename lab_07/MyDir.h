#pragma once
#include <string>

struct MyDir {
  std::string name;
  MyDir ** children;
  int size;
};

void initDir (MyDir &,const std::string &);

void printDir (MyDir &);
 
MyDir * addDir (MyDir & ,const std::string &);
void addDir (MyDir &, MyDir&);

void clearDir (MyDir &);