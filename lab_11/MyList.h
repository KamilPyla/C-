#pragma once
#include<iostream>
#include<initializer_list>


class MyNode;

class MyList{
public:

/*Konstruktory*/

//domyślny: ustawia _head oraz _tail na nullpt _size na 0
MyList();

//jednoargumentowy, dodaje do listy liczny od zera do n-1
MyList(int n);

//z listą inicjalizacyjną, dodaje kolejne elementy z listy inicjalizacyjnej
MyList(std::initializer_list<int> l);

//kopiujący, tworzy nowy obiekt na podstawie podanego,
//nowy obiekt jest jego twardą kopią
MyList(const MyList & cpy );


//konstruktor przenoszący, wykorzystuje funkcję std::move
MyList(MyList && cpy);


//konstruktor korzystający z fukcji generującej kolejne wyrazy
//przyjmuje referencję do funkcji generującej oraz ilość elementów które dodaje
MyList(int (&f)(MyNode *), int n);

///////////////////////////////////////////////////

//destruktor zwalnia pamięc po wskaźnikach *MyNode
~MyList();

/*Metody*/

//dodaje elementy na koniec listy
void add(int num);


//sprawdza czy w liscie znajdują sie elementy
//zwraca true jeżeli lista jest pusta
bool empty() const;

//wypisuje zawartość listy
void print() const;

//zwraca ilość elementów znajdujących się w liście
int size() const;


//zwalnia elementy list, nie niszcząc listy, można ją ponwnie wykorzystać
void clear();


private:

//przechowuje ilość elementów w liście
int _size;

//wskaźnik na pierwszt element
MyNode * _head;

//wskaźnik na ostatni element
MyNode * _tail;

};



class MyNode{
//dekalracja przyjaźni
friend class MyList;
public:

//konstruktor ustawia wartość przechowywaną przez element
//ustawia na nullptr wskaźniki na poprzedni element oraz następny
MyNode(int val);

//zwraca wartość elementu
int val();

//zwraca wskaźnik na poprzedni element
MyNode * prev();


private:
//przechowywana wartość
int _value;
//wskaznik na następny element
MyNode * _next;

//wskaznik na poprzedni element
MyNode * _prev;
};