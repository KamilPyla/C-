#include <iostream>
#include "MyList.h"
#include <cstring>

void prepare (struct MyList * first)
{
  first->head = NULL;
}

//procedura dodająca elementy do listy
void add (struct MyList * first, char * val)
{
  if (first->head == NULL)
  {
    struct node * el = NULL;
    el = (struct node *)malloc(sizeof(struct node));
    first->head = el;
    int len = strlen(val) + 1;
    el->data = (char*)malloc(len);
    strcpy(el->data,val);
    el->next = NULL;
  }
  else
  {
    struct node * str = first->head;
    while (str->next != NULL)
    {
      str=str->next;
    }
    struct node * el = NULL;
    el = (struct node *)malloc(sizeof(struct node));
    str->next = el;
    int len = strlen(val) + 1;
    el->data = (char*)malloc(len);
    strcpy(el->data,val);
    el->next = NULL;
  }
}

//funkcja sprawdzająca czy lista jest pusta
bool empty (struct MyList * test)
{
  if (test->head)
    return false;
  else
    return true;
}

//procedura wypisująca listę
void dump (struct MyList * first)
{
  if(first->head)
  {
    struct node * str = first->head;
    while(str->next)
    {
      std::cout<<str->data<<" ";
      str = str->next;
    }
    std::cout<<str->data;
    std::cout<<".\n"; 
  }
  else 
    std::cout<<"\n";
}

//Procedura zwalniająca listę
void clear (struct MyList * first)
{
  if(first->head)
  {
    struct node * str = first->head;
    struct node * str1 = str;
    while(str->next)
    {
      free(str->data);
      str1 = str;
      str = str->next;
      free(str1);
    }
    free(str->data);
    free(str);
    first->head = NULL;
  }
}