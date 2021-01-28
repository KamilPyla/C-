#pragma once
#include<string>

class InfoClass {

public:

//konstrukor domyślny ustawia _name jako ""
InfoClass ();

//ustawia _name jako name
InfoClass (std::string name);

//Destruktor wyświetla komunikat o zwalnianym obiekcie, wypisuje jego zawartość
~InfoClass();

//wzraca pole _name
std::string getInfo()const ;

//zmienia zawartość pola _name na name
void setInfo(std::string name);

private:

//pole przechowujące nazwę obiektu
std::string _name;

};