/* Do napisania jest struktura obrazująca drzewo folderów w systemie.
 * Każdy folder może trzymać podfoldery.
 * Podfoldery trzeba alokować dynamicznie za pomocą new i delete. 
 * Do obsługi drzewa najłatwiej używać funkcje rekurencyjne.
 * 
 * Użycie kontenerów z biblioteki standardowej w tym celu jest zakazane!
 * 
 * Aby ładnie wypisać strukurę drzewa, funkcja print powinna otrzymywać
 * ilość kresek do wypisania.
 * 
 * Dla uproszczenia, maksymalny rozmiar nazwy to 10 znaków. 
 * Można zatem używać tablicy statycznej (tradycyjnej albo std::array).
 * Można też użyć tablicy dynamicznej (odradzam, bo braknie czasu),
 * albo std::string (jeszcze prosztsze rozwiązanie niż tablica statyczna).
 * 
 * Przykłady użycia podano w pliku test.cpp. 
 */

#include "MyDir.h"
#include <string>
#include <iostream>

// Zabezpieczenie przed użyciem gotowego rozwiązania
namespace std {
    struct vector{};
}

int main()
{  
    std::cout << "Rozpoczynamy zadanie 7: drzewo plikow!\n" << std::endl;
        
    MyDir root;
    initDir(root, "root");
    printDir(root);
    std::cout << std::endl;

    MyDir * home = addDir(root, "home");
    addDir(*home, "Kasia");
    addDir(*home, "Zosia");
    addDir(*home, "Tosia");
    printDir(root);
    std::cout << std::endl;
       
    // Za długa nazwa:
    addDir(*home, "Konstantynopolitanczykowianeczka");
    std::cout << std::endl;
        
    MyDir data;
    initDir(data, "data");
    addDir( *addDir(data, "oceny"), "tajemnica");
    printDir(data);
    std::cout << std::endl;
    
    // Dodawanie całego katalogu z podkatalogami
    addDir(root, data);
    printDir(root);
    std::cout << std::endl;
    
    // Czyszczenie katalogów
    //clearDir(root);
    
    //printDir(data);
    //clearDir(data);
    
    return 0;
}

/************************* OUTPUT *************************
Rozpoczynamy zadanie 7: drzewo plikow!

> root

> root/
---> home/
------> Kasia
------> Zosia
------> Tosia

Too long name: Konstantynopolitanczykowianeczka

> data/
---> oceny

> root/
---> home/
------> Kasia
------> Zosia
------> Tosia
---> data/
------> oceny

> data/
---> oceny
**********************************************************/
