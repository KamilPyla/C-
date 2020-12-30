// Lista jest jednym z podstawowych kontenerów,
// dlatego będzie często używana jako temat zadań z programowania.
//
// W liście jednokierunkowej, każdy obiekt poza ostatnim wskazuje
// na kolejny element listy. Następnik dla ostatniego elementu jest 
// ustawiany na NULL (nullptr), co umożliwia sprawdzenie końca listy.
//
// Zadanie najłatwiej rozwiązać tworząc dwie struktury: Node (węzeł)
// oraz właściwą strukturę MyList, trzymajacą wskaźnik na pierwszy węzeł.
//
// W zadaniu proszę napisać listę połączoną jednokierunkowo, 
// służącą do przechowywania napisów (łańcuchów znaków).
//
// Napisy muszą być kopiowane do alokowanej pamięci. 
// Należy zadbać o zwolnienie pamięci przy czyszczeniu listy.
//
// Niektóre z funkcji nie zmieniają listy (np. dump)
// i z tego powodu powinny odbierać stały wskaźnik do struktury MyList.

#include "MyList.h"
#include "MyList.h"
#include <cstring>
#include <iostream>

int main() {
    std::cout << "---> Pierwsza lista <---" << std::endl;
    MyList testList;
    prepare(&testList);
    
    ////////////////////////////////////////////////
    char buffer[100];
    strcpy(buffer, "Ala");
    add(&testList, buffer);
    strcpy(buffer, "ma");
    add(&testList, buffer);
    
    add(&testList, "kota");

    MyList* lptr = &testList;

    std::cout << lptr->head->data << std::endl;
    std::cout << lptr->head->next->data << std::endl;
  
    ////////////////////////////////////////////////
    std::cout << "Czy lista jest pusta? " 
              << std::boolalpha << empty(lptr) << std::endl;
    std::cout << "Wypiszmy ja!" << std::endl;
    dump(lptr);

    ////////////////////////////////////////////////
    std::cout << "\n---> Druga lista <---" << std::endl;
    MyList drugaLista;
    prepare(&drugaLista);
    strcpy(buffer, "Maraton to");
    add(&drugaLista, buffer);
    strcpy(buffer, "wyczyn");
    add(&drugaLista, buffer);
    dump(&drugaLista);

    ////////////////////////////////////////////////
    std::cout << "\n---> Teraz czyszczenie <---" << std::endl;
    clear(&testList);
    std::cout << "Czy teraz lista jest pusta? " 
              << std::boolalpha << empty(&testList) << std::endl;
              
    std::cout << "Co sie stanie, jak bedziemy chciec "
              << " wypisac pusta liste?" << std::endl;
    dump(lptr);
    
    ////////////////////////////////////////////////
    dump(&drugaLista);
    clear(&drugaLista);
    clear(&drugaLista);
}

/************************* OUTPUT *************************
---> Pierwsza lista <---
Ala
ma
Czy lista jest pusta? false
Wypiszmy ja!
Ala ma kota.

---> Druga lista <---
Maraton to wyczyn.

---> Teraz czyszczenie <---
Czy teraz lista jest pusta? true
Co sie stanie, jak bedziemy chciec  wypisac pusta liste?

Maraton to wyczyn.
**********************************************************/
