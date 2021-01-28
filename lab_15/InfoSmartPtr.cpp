#include <iostream>
#include "InfoSmartPtr.h"





InfoSmartPtr::InfoSmartPtr(InfoClass* ptr){

  _shareptr = ptr;
  _count = new int;
  *_count = 1;

}


InfoSmartPtr::InfoSmartPtr(const InfoSmartPtr& cpy){

	equal(cpy);
	
}


InfoSmartPtr::~InfoSmartPtr(){

  (*_count)--;

  if(*_count == 0){

    delete _shareptr;
    delete _count;

  }
  
}

//////////////////////////////////////////////////////////////////////////

const InfoClass & InfoSmartPtr::operator*() const{

  return *_shareptr;

}

InfoClass & InfoSmartPtr::operator*(){

  return *_shareptr;

}

void InfoSmartPtr::operator=(const InfoSmartPtr & eq){

  if(*_count == 1)
  {

    delete _shareptr;
    delete _count;

  }
  else{

    (*_count)--;
  }

  equal(eq);

}

const InfoClass* InfoSmartPtr::operator->()const{

  return _shareptr;

}


InfoClass* InfoSmartPtr::operator->(){

  return _shareptr;

}

void InfoSmartPtr::equal(const InfoSmartPtr & eq){

	(*eq._count)++;

  _count = eq._count;

  _shareptr = eq._shareptr;
}
