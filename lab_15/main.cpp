/* Zadanie 15: Sprytny wskaźnik
 * 
 * Celem zadania jest napisanie klasy, będącej przykładem sprytnego wskaźnika.
 * Jest to klasa opakowująca wskaźnik w sposób, w którym liczona jest ilość
 * referencji do tego wkaźnika (wzorowany na std::shared_ptr). 
 * 
 * Podczas konstruowania takiego sprytnego wskaźnika przekazujemy do niego
 * wskaźnik do obiektu stworzonego operatorem new i startujemy licznik.
 * Każdy następny sprytny wskaźnik pokazujący na ten obiekt (stworzony z 
 * innego sprytnego wskaźnika) zwiększa ten licznik, a każde zniszczenie 
 * sprytnego wskaźnika (np przez wyjście poza zakres) zmniejsza licznik. 
 * Gdy licznik dochodzi do zera, pamięć należy zwolnić. 
 * 
 * Kluczową sprawą jest zapewnienie współdzielenia licznika pomiędzy różnymi
 * instancjami klasy sprytnego licznika. Poniważ mamy wiele wskaźników na
 * różne obiekty, to static nie jest rozwiązaniem. 
 * Najłatwiej jest to zrobić przez zaalokowanie pamięci na licznik 
 * dynamicznie (przez new int{1}) w zwykłym konstruktorze, a w konstruktorze 
 * kopiującym kopiować jego adres (i zwiększyć jego wartość o 1). 
 * 
 * Sprytny wskaźnik ma obslugiwać banalną klasę InfoClass, która nic nie 
 * robi, tylko dużo mówi (głośny konstruktor/destruktor, metoda info()).
 * 
 * Uwaga: przypominam że operatory dostępu przeładowuje się w dwóch 
 * wersjach: const i nie const!
 */

#include "InfoSmartPtr.h"
#include "InfoClass.h"
#include <iostream>

void printInfo(const InfoClass& info)
{
	std::cout << "** printInfo: " << info.getInfo() << std::endl;
}

void printInfoPtr(const InfoSmartPtr& infoPtr)
{
	std::cout << "** printInfoPtr: " << infoPtr->getInfo() << std::endl;
}

int main()
{
    std::cout << "Rozpoczynamy zadanie 15: Wspoldzielony wskaznik!\n" << std::endl;
    
	// -------------------------
	{
		const InfoClass info("InfoAAA");
		printInfo(info);
	}
	std::cout << std::endl;
	
	// -------------------------
	{
		InfoSmartPtr info( new InfoClass("InfoBBB") );
		printInfo(*info);
		printInfoPtr(info);
	}
	std::cout << std::endl;
	
	// -------------------------
    // Operator przypisania
	InfoSmartPtr infoOne( new InfoClass("InfoCCC") );
	InfoSmartPtr infoTwo( new InfoClass("InfoDDD") );
	infoTwo = infoOne;              // Kasowanie InfoDDD!!!
	std::cout << std::endl;
	
	// -------------------------
    // Wskaźnik jest naprawdę współdzielony!!!
	infoTwo->setInfo("InfoXXX"); 
	std::cout << "== " << infoOne->getInfo() << std::endl;
	std::cout << "== " << infoTwo->getInfo() << std::endl;
	std::cout << std::endl;	
	
	// -------------------------
    // Konstruktor kopiujący
	{
		const InfoSmartPtr infoThree = infoTwo;
		printInfo(*infoThree);		
        printInfoPtr(infoThree);
		std::cout << "== " << infoThree->getInfo() << std::endl;
	}
	std::cout << "== " << infoTwo->getInfo() << std::endl;
	std::cout << std::endl;
		
	return 0;
}

/************************* OUTPUT *************************
Rozpoczynamy zadanie 15: Wspoldzielony wskaznik!
++ Tworze obiekt InfoClass: InfoAAA
** printInfo: InfoAAA
++ Usuwam obiekt InfoClass: InfoAAA

++ Tworze obiekt InfoClass: InfoBBB
** printInfo: InfoBBB
** printInfoPtr: InfoBBB
++ Usuwam obiekt InfoClass: InfoBBB

++ Tworze obiekt InfoClass: InfoCCC
++ Tworze obiekt InfoClass: InfoDDD
++ Usuwam obiekt InfoClass: InfoDDD

== InfoXXX
== InfoXXX

** printInfo: InfoXXX
** printInfoPtr: InfoXXX
== InfoXXX
== InfoXXX

++ Usuwam obiekt InfoClass: InfoXXX
**********************************************************/
