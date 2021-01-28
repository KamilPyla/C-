/* Zadanie 14: Tablica bitów
 * 
 * Celem zadania jest napisanie klasy opakowującej tablicę bitów: BitArray.
 * Bity mają być złożone w tablicy "unsigned char" o odpowienim rozmiarze
 * zaalokowanym przy konstrukcji, tak dużym aby wszystkie bity się zmieściły.
 * Tablica ta ma być alokowana dynamicznie (można użyć std::vector<unsigned int>).
 *
 * UWAGA: Alokacja pamięci musi być optymalna (np 7 bitów zmieści się na jednym
 * bajcie, a 20 bitów potrzebują 3 bajtów). Rozwiązanie, w którym każdy bit 
 * trzymany jest w osobnym bajcie (np. tablica unsigned char[20] dla 20 bitów)
 * jest oceniana jako zadanie nie na temat.
 * 
 * 
 * Kluczowym elementem zadania jest przeładowanie operatora [], który 
 * umożliwi wygodny dostęp do poszczególnych bitów. Problemem jest to, 
 * że w języku C++ nie można uzyskać adresu dla pojedyńczego bitu.
 * 
 * Aby rozwiązać problem, należy zwracać pomocniczą strukturę np BitPos.
 * Taka struktura będzie trzymać adres do obietku BitArray oraz numer
 * bitu który chemy ewentualnie modyfikować. Dla takiej struktury trzeba 
 * trzeba przeładować dwa operatory: rzutowania na bool i operator
 * przypisania = (przyjmujący bool), który wywoła getBit/setBit.
 * 
 * 
 * UWAGA: Trzeba napisać dwa operatory []: const i nie const. Operator 
 * const jest dużo prostszy...
 * 
 * Dla ułatwienia, funkcje ustawiające i zwracające pojedyńczy bit oraz
 * funkcja inkrementująca są gotowe, można z nich swobodnie korzystać 
 * w implementacjach operatorów (i modyfikować w razie potrzeby).
*/


#include "BitArray.h"
#include <iostream>


int main() {
    std::cout << "Rozpoczynamy zadanie 14: Tablica bitów!\n" << std::endl;
    
	BitArray ba(35);         // miejsce na 35 bitow indeksowanych od 0 do 34, 
                             // wszystkie sa ustawione na 0 (false)
	BitArray bb(35, true);   // jw tylko ze wszystkie sa 1 (true)

	// zmiana wartosci bitow
    ba.setBit(1, true); 

	ba[3] = true;                 
	bb[3] = false;                

	bool v1 = ba[3];
	bool v2 = ba[4];
	std::cout << "Bity: " << v1 << " " << v2 << std::endl << std::endl;

    // wypisujemy od konca!
	std::cout << "ba: " << ba << std::endl;
	std::cout << "bb: " << bb << std::endl;

	bb[7] = false;
	bb[8] = false;
    std::cout << "bb: " << bb << std::endl;

	// Test na duzym obiekcie:
	BitArray large(64);
	large[12] = true;
	large[13] = true;
	large[32] = true;
	std::cout << std::endl << "large: " << large << std::endl << std::endl;

	// Test na stalym obiekcie:
	const BitArray cb(4, true);
    std::cout << "cb: " << cb << std::endl;
	std::cout << "pojedyncze bity: ";
	for( int i = 3; i>=0 ; --i) {
		std::cout << cb[i] << ",";
	}
	std::cout << std::endl << std::endl;

    // Dla utrwalenia: operatory inkrementacji
    // Bez konstruktora kopiujacego sie nie obejdzie... 
    std::cout << "ba: " <<   ba   << std::endl;
    std::cout << "ba: " << ++ba   << std::endl;
    std::cout << "ba: " <<   ba   << std::endl;
    std::cout << "ba: " <<   ba++ << std::endl;
    std::cout << "ba: " <<   ba   << std::endl;
}

/************************* OUTPUT *************************
Rozpoczynamy zadanie 14: Tablica bitów!

Bity: 1 0

ba: 000 <-32 00000000 <-24 00000000 <-16 00000000 <-8 00001010 <-0 
bb: 111 <-32 11111111 <-24 11111111 <-16 11111111 <-8 11110111 <-0 
bb: 111 <-32 11111111 <-24 11111111 <-16 11111110 <-8 01110111 <-0 

large: 00000000 <-56 00000000 <-48 00000000 <-40 00000001 <-32 00000000 <-24 00000000 <-16 00110000 <-8 00000000 <-0 

cb: 1111 <-0 
pojedyncze bity: 1,1,1,1,

ba: 000 <-32 00000000 <-24 00000000 <-16 00000000 <-8 00001010 <-0 
ba: 000 <-32 00000000 <-24 00000000 <-16 00000000 <-8 00001011 <-0 
ba: 000 <-32 00000000 <-24 00000000 <-16 00000000 <-8 00001011 <-0 
ba: 000 <-32 00000000 <-24 00000000 <-16 00000000 <-8 00001011 <-0 
ba: 000 <-32 00000000 <-24 00000000 <-16 00000000 <-8 00001100 <-0 
**********************************************************/
