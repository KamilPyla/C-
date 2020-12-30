#pragma once

//struktura listy

struct node
{
  char * data;
  struct node * next;
};

struct MyList
{
  struct node * head;
};


//Procedura inicjująca listę
void prepare (struct MyList *);

//procedura dodająca elementy do listy
void add (struct MyList *, char *);

//funkcja sprawdzająca czy lista jest pusta
bool empty (struct MyList *);

//procedura wypisująca listę
void dump (struct MyList *);

//Procedura zwalniająca listę
void clear (struct MyList *);



