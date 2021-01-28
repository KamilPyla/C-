#pragma once

namespace mystring {

class MyString {

public:

friend MyString operator*(int num, const MyString &str);

MyString();

MyString(const char * str);

MyString(const MyString & cpy);

~MyString();


operator char*()const;


bool operator ==(const char * str) const;

bool operator ==(const MyString & str) const;

MyString operator +(const MyString & str)const;

MyString operator +(const char * str)const;

MyString operator +(char sig)const;

MyString operator =(const MyString & str);
MyString operator =(const char * str);





void print(const char * beg) const;

char * getString()const;

private:

int _size;

char * _string;

};

MyString operator *(int num, const MyString & str);

}