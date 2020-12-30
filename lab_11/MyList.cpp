#include "MyList.h"
#include <iostream>
using namespace std;

/////////////    Konstruktory     ////////////////////

MyList::MyList()
{

  cout << "KONST: Domyslny" << endl;

  _size = 0;
  _head = nullptr;
  _tail = nullptr;

}

MyList::MyList(int n): MyList() 
{

  cout<<"KONST: Jednoargumentowy" << endl;

  for (int i = 0; i < n; i++)
    this -> add(i) ;

}

MyList::MyList(std::initializer_list<int> l): MyList()
{

  cout<<"KONST: std::initializer_list"<<endl;

  for(unsigned int i = 0; i < l.size(); i++)
    this->add(l.begin()[i]);

}

MyList::MyList(int (&f)(MyNode *), int n)
{

  cout<<"KONST: funkcja generujaca"<<endl;

    for(int i = 0; i < n; i++)
    this -> add(f(_tail));

}

MyList::MyList(const MyList & cpy ): MyList()
{

  cout<<"KONST: Kopiujacy"<<endl;

  MyNode * ptr = cpy._head;

  for(int i = 0; i < cpy._size; i++){

    this->add(ptr->val());
    ptr = ptr -> _next;

  }
}

MyList::MyList(MyList && cpy): _size(std::move(cpy._size)), _head(std::move(cpy._head)), _tail(std::move(cpy._tail))
{

  cout<<"KONST: przenoszacy"<<endl;
  cpy._size = 0;
}

//////////    Destruktor    ////////////////

MyList::~MyList()
{

  cout << "DESRUKTOR (rozmiar = " << _size << ")" << endl;

    this->clear();
}

////////////    Metody    ////////////////////


void MyList::add(int num)
{

  MyNode* _node = new MyNode(num);

  if (!_head)
  {

    _head = _node;
    _tail = _node;
    _size++;

  }
  else
  {

    _tail->_next = _node;
    _node->_prev = _tail;MyNode * prev();
    _tail = _node;
    _size++;

  }
}


bool MyList::empty() const
{
  return _size ? false : true;
}


int MyList::size() const
{
  return _size;
}


void MyList::print() const
{
  MyNode * prt = _head;

  cout<<"[";
  if (_size)
  {

    for(int i = 0; i < _size-1; i++)
    {

      cout<<prt->val()<<", ";
      prt = prt->_next;

    }
    cout<<_tail->val();

  }

  cout<<"] "<<endl;

}


void MyList::clear()
{

  MyNode * ptr = _head;

  if (ptr)
  {
    for(int i = 0; i < _size; i++){

      ptr = ptr->_next;
      delete _head;
      _head = ptr;

    }
  }

  _head = nullptr;
  _tail = nullptr;
  _size = 0;

}

///////////   MyNode    ///////////

MyNode::MyNode(int val): _value(val), _next(nullptr), _prev(nullptr){}

int MyNode::val()
{
  return _value;
}

MyNode * MyNode::prev()
{
  return _prev;
} 