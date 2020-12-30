#include "MyPrint.h"
#include <iostream>

using std::cout;
using std::endl;

void MyPrint::init (int n)
{
  number_stars = n;
  number_line = 0;
} 

void MyPrint::printLine() 
{
  cout<<endl;
  for (int i = 0; i < number_stars; i++)
  {
    cout<<'*';
  }
  cout<<++number_line;
    for (int i = 0; i < number_stars; i++)
  {
    cout<<'*';
  }
  cout<<endl;
}
MyPrint::~MyPrint ()
{
	cout<<"No to kończyny z wypisywaniem, żegnam!"<<endl;
}

