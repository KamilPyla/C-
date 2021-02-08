/* Do napisania jest prosta struktura będąca kontenerem na napis.
 * Kontener ten powinien pozwalać na rozszerzanie i usuwanie fragmentów.
 * 
 * W zadaniu są dwa problematyczne miejsca:
 * - funkcja erase  - usuwanie tekstu w środku 
 *   (dla ambitnych: rozwiązanie da się zapisać w jednej linijce, 
 *   tj jeden średnik, bez żadnych dodatkowych funkcji);
 * 
 * - funkcja modify - modyfikuje cały napis używając przekazanego 
 *   WSKAŹNIKA do funkcji (uwaga - funkcje std::tolower/std::toupper 
 *   wcale nie działają na typie char!)
 * 
 * Oczywiście nie można używać gotowych rozwiązań. 
 * Kontenery z biblioteki standardowej są zabronione. 
 */


#include <iostream>
#include <cstring>
#include <cmath>

// Zabezpieczenie przed użyciem gotowego rozwiązania
namespace std {
    struct string{};
    struct vector{};
}
#include "MyText.h"

void proba_wypisania(const char * text)
{
    std::cout << "Proba wypisania <" << text << ">" << std::endl;
}

int main()
{  
    std::cout << "Na rozgrzewke:" << std::endl;
    
    char a = 'a', b = 'B';

    std::cout << "a = " << a << ", b = " << b << std::endl;
    a = std::toupper(a);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    b = std::tolower(b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    a = my_uptolow_lowtoup(a);
    b = my_uptolow_lowtoup(b);
    std::cout << "a = " << a << ", b = " << b << std::endl;


    std::cout << "\n***********************************\n" << std::endl;

    MyText * ttt = initMyText("ttt");
    if( empty(ttt) )
    {
        std::cout << "ttt jest puste. Ale sprobujmy go wypisac:" << std::endl;
        proba_wypisania( getCString(ttt) );
    }
    
    
    std::cout << "\n***********************************\n" << std::endl;
    
    append(ttt, "Ala"); 
    proba_wypisania( getCString(ttt) );
    nicePrint(ttt);
    std::cout << "size(ttt) = " << size(ttt) << std::endl;
    
    append(append(ttt, " ma"), " kota");
    nicePrint(ttt);
    std::cout << "size(ttt) = " << size(ttt) << std::endl;
    
    setChar(ttt, 0, 'O');
    nicePrint(ttt);
    std::cout << "size(ttt) = " << size(ttt) << std::endl;

    erase(ttt, 4, 7);  // Usuwa trzy znaki: od 4 (włącznie) do 7 (bez 7)
    nicePrint(ttt);
    std::cout << "size(ttt) = " << size(ttt) << std::endl;
        
    
    std::cout << "\n***********************************\n" << std::endl;
    
    MyText * copy = initMyText("copy", ttt);
    nicePrint(copy);
    modify(copy, std::toupper);
    nicePrint(copy);
    modify(copy, std::tolower);
    nicePrint(copy);
    
    std::cout << "\nttt tez chce sie zmienic!" << std::endl;
    nicePrint(ttt);
    modify(ttt, my_uptolow_lowtoup);
    nicePrint(ttt);

    std::cout << "\n***********************************\n" << std::endl;

    clear(ttt);
    clear(copy);
    std::cout << "I jeszcze raz... Dla pewnosci." << std::endl;
    clear(ttt);
    std::cout<<"tutaj";
    free(ttt);
    free(copy);

    return 0;
}

/************************* OUTPUT *************************
Na rozgrzewke:
a = a, b = B
a = A, b = B
a = A, b = b
a = a, b = B

***********************************

ttt jest puste. Ale sprobujmy go wypisac:
Proba wypisania <>

***********************************

Proba wypisania <Ala>
ttt = <Ala>
size(ttt) = 3
ttt = <Ala ma kota>
size(ttt) = 11
ttt = <Ola ma kota>
size(ttt) = 11
ttt = <Ola kota>
size(ttt) = 8

***********************************

copy = <Ola kota>
copy = <OLA KOTA>
copy = <ola kota>

ttt tez chce sie zmienic!
ttt = <Ola kota>
ttt = <oLA KOTA>

***********************************

I jeszcze raz... Dla pewnosci.
**********************************************************/
