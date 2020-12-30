// Język C i arytmetyka wskaźników.
//
// Do napisania jest prosta struktura Delimited, która pomoże podzielić
// napis na części. Podział napisu ma się dokonywać bez używania 
// bibliotek C++ oraz bez dynamicznej alokacji pamięci. 
// 
// Funkcja chunk przygotowuje pomocniczą strukturę, 
// a funkcja next przesuwa ją na kolejny wyraz. Jeżeli jesteśmy już 
// na końcu, zamiast przesuwania zwraca false. 
//
// Wypisywanie napisu jest w osobnym pliku, który jest częścią zadania.
// Proszę zadbać o podział kodu na nagłówek i plik źródłowy, inaczej
// pojawią się problemy na etapie linkowania.
//
// Uwaga: Iterujemy jednocześnie po dwóch napisach! Dlatego
// zastosowanie zmiennych globalnych spowoduje błąd.
//
// Uwaga: Do zadania dostarczono generyczny makefile. 
// Prawdopodobnie nada się do każdego zadania w tym semestrze. 
// Tak długo aż nie przejdziemy na cmake. 

#include "Delimited.h"
#include "PrintHelper.h"
#include <iostream>

int main()
{
    Delimited delOne;
    Delimited delTwo;
    const char* textOne = "Ala ma kota    a sierotka Ma Rysia";
    const char* textTwo = "To proste zadanie, juz je zrobilem, "
                          "i sie bardzo ciesze ze sie udalo";

    chunk( textOne, &delOne, ' ' );
    chunk( textTwo, &delTwo, ',' );
    
    // Jeszcze nie przygotowano napisu, zatem jego długość to 0:
    std::cout << "Dlugosc = " << fragment_size( &delOne ) << std::endl;
    std::cout << std::endl;

    while ( next( &delOne ) and next( &delTwo ) ) 
    {
        help_me_print_this( &delOne );
        help_me_print_this( &delTwo );
        std::cout << std::endl;
    }

    std::cout << std::endl;

    rewind( &delOne );        // Powrót na poczatek;
    next( &delOne );          // dwa kroki w przód...
    next( &delOne );    
    std::cout << "Co jest na drugim miejscu?" << std::endl;
    help_me_print_this( &delOne );
    std::cout << std::endl << std::endl;
    
    
    prev( &delOne );          // ...i jeden krok w tył
    std::cout << "A troche wczesniej?" << std::endl;
    help_me_print_this( &delOne );
    std::cout << std::endl << std::endl;
    
    return 0;
}

/************************* OUTPUT *************************
Dlugosc = 0

 >Ala< >To proste zadanie<
 >ma< > juz je zrobilem<
 >kota< ** za duzo do wypisania ** 

Co jest na drugim miejscu?
 >ma<

A troche wczesniej?
 >Ala<

**********************************************************/
