#include "MyDir.h"
#include <iostream>
#include <cstring>
#include <string>

void initDir (MyDir & newDir, const std::string & NewName){
  newDir.name = NewName;
  newDir.children = NULL;
  newDir.size = 0;
}

void printDir (MyDir & dir){
  if (dir.children != NULL)
  {
    std::cout<<"---";
    for(int i = 0; i < dir.size; i++)
    printDir(*dir.children[i]);
  }
  else
  {
    
  }
    
  }
  


 
MyDir * addDir (MyDir & dir,const std::string & name_)
{
  if (name_.length() > 25){
    std::cout<<"Too long name:  "<<name_<<std::endl;
    return NULL;
  }
  else{
    MyDir * newDir = new MyDir;
    MyDir ** temp = dir.children;
    
    dir.children = new  MyDir* [dir.size +1]; 
    for (int i = 0; i < dir.size; i++){
      dir.children[i] = temp[i];
    }
    dir.children[dir.size] = newDir;
    dir.size ++;
    delete[] temp;
    initDir(*newDir,name_);
    return newDir;
  }
}

void addDir (MyDir & root, MyDir & dir)
{
  MyDir ** temp = dir.children;
    
    root.children = new  MyDir* [root.size +1]; 
    for (int i = 0; i < dir.size; i++){
      dir.children[i] = temp[i];
    }
    root.children[dir.size] = &dir;
    root.size ++;
    delete[] temp;
}

void clearDir (MyDir & root)
{
  if(root.children != NULL)
  {
    for(int i = 0; i < root.size; i++)
    clearDir(*root.children[i]);
    delete[] root.children;
    delete [] &root;
  }
  else{
    delete &root;
  }

}