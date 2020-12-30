#pragma once

class MyStringProxy
{
  public: 
  MyStringProxy (char * beg, char * end);
  ~MyStringProxy();
  friend class  MyString;
  private:
  char * _beg;
  char * _end;
};

class MyString {
public:
  MyString ();
  MyString (const char * name);
  MyString ( const MyString & cpy);
  MyString (const MyStringProxy & cpy);
  ~MyString();
  char * str() const;
  MyStringProxy subStr(int a, int b) const;
private:
  char * _string;

};
