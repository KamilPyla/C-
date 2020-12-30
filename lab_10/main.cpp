/* Zadanie 10: Kopiowalny MyString
 * 
 * Celem zadanie jest napisanie kopiowalnej klasy MyString.
 * Klasa MyString jest posiada także przydatną metodę subStr, 
 * która przymuje dwa indeksy i pozwala na stworzenie pod-napisu. 
 * 
 * Jednakże: zamiast wytwarzać nowy obiekt MyString, metoda subStr 
 * tworzy lekki obiekt: MyStringProxy, który przechowuje wskaźniki 
 * do źródłowego łańcucha (nie może kopiować tekstu!). Taki obiekt można
 * na przykład użyć jako argument konstruktora kopiującego 
 * (a w przyszłosci operatora przypisania).
 * 
 * W zadaniu wymagana jest dynamiczna alokacja pamięci. Nie można używać 
 * kontenerów z biblioteki standardowej (w tym std::string). 
 * Niespełnienie tego warunku będzie ocenione jako zadanie nie na temat
 * i zostanie przyznane 0 pkt.
 * 
 * Uwaga: Każdy konstruktor (jest ich w sumie 4) oraz destruktor klasy 
 * MyString jest głośny (tzn wypisuje na ekran odpowiedni komunikat).
 */

#include "MyString.h"
#include <iostream>

int main()
{  
    std::cout << "Rozpoczynamy zadanie 10: Kopiowalny MyString!\n" << std::endl;
    
    // Rozgrzewka
    MyString s1("Witaj");
    const MyString s2("swiecie!");
    
    std::cout << s1.str() << " " << s2.str() << std::endl << std::endl;
        
    // Kopiowanie
    {
        MyString obiekt_lokalny = s1;
        std::cout << s1.str() << " -> " << obiekt_lokalny.str() << std::endl;
    }
    std::cout << s1.str() << std::endl;

    // Substr (nie zwracamy MyString tylko MyStringProxy, 
    // żeby niepotrzebnie nie kopiować znaków )
    std::cout << "\nMozna tak: " << std::endl;
    MyString s3 = s1.subStr(2, 4);
    std::cout << s1.str() << " -> " << s3.str() << std::endl;
    
    std::cout << "... i mozna tak: " << std::endl;
    MyString s4{ s2.subStr(3, 6) };
    std::cout << s2.str() << " -> " << s4.str() << std::endl << std::endl;
        
    // A jak powstał obiekt tu poniżej? 
    MyString domyslny;
    std::cout << "Domyslny: [" << domyslny.str() << "]" << std::endl;
           
    std::cout << "\nWywolanie destruktorow" << std::endl;
    
    return 0;
}

/************************* OUTPUT *************************
Rozpoczynamy zadanie 10: Kopiowalny MyString!

CTOR(cstr) = <Witaj>
CTOR(cstr) = <swiecie!>
Witaj swiecie!

CTOR(copy) = <Witaj>
Witaj -> Witaj
DESTRUCTOR = <Witaj>
Witaj

Mozna tak: 
CTOR(proxy) = <ta>
Witaj -> ta
... i mozna tak: 
CTOR(proxy) = <eci>
swiecie! -> eci

CTOR(def) = <>
Domyslny: []

Wywolanie destruktorow
DESTRUCTOR = <>
DESTRUCTOR = <eci>
DESTRUCTOR = <ta>
DESTRUCTOR = <swiecie!>
DESTRUCTOR = <Witaj>
**********************************************************/
