/* Zadanie 8: Radiany i stopnie
 * 
 * Zadanie polega na napisaniu klasy MyAngle. Będzie ona służyła do 
 * operacji na kątach. Głównym zadaniem klasy będzie przeliczanie
 * stopni na radiany i odwrotnie. 
 * 
 * Wszystkie kąty mniejsze od zera lub większe od 2PI można utożsamić
 * z kątem z przedziału [0, 2PI]. Dlatego drugim ważnym zadaniem klasy
 * jest przesuwanie kąta do zakresu [0, 2PI] poprzez dodanie/odjęcie 
 * wielokrotności 2PI.
 * 
 * Proszę zdefiniować pi jako 3.14159265358979323846.
 * Ta wartość powinna pojawić się tylko w jednym miejscu w kodzie.
 * 
 * Uzupełnieniem zadania jest klasa MyPrint, która rozdziela poszczególne
 * części zadania wypisując na ekran linie z numerem porządkowym. 
 * 
 * Zadanie jest bardzo proste, dlatego proszę zadbać o jakość kodu: 
 * przesyłanie przez referencję, czytelność etc.
 */

#include "MyAngle.h"
#include "MyPrint.h"

#include <iostream>
#include <iomanip>

int main()
{  
    std::cout << "Rozpoczynamy zadanie 8: Radiany i stopnie!" << std::endl;
    
    // Ustawienie precyzji wypisania
    std::cout << std::fixed << std::setprecision(2); 
    
    // Ustawienie printera - 25 oznacza połowę liczby gwiazdek w lini
    MyPrint printer;
    printer.init(25);
    printer.printLine();
    
    // Właściwy początek zadania
    MyAngle phi, eta;
    phi.setRadians(11.45);
    eta.setDegrees( -715);
    
    double realPhi = phi.toRad();
    double realEta = eta.toRad();
    std::cout << "Katy w radianach: phi = " << std::setw(8) << realPhi 
                              << ", eta = " << std::setw(8) << realEta << std::endl;
    std::cout << "Katy w stopniach: phi = " << std::setw(8) << phi.toDeg()
                              << ", eta = " << std::setw(8) << eta.toDeg() << std::endl;

    printer.printLine();
    
    // Trzeci kąt
    MyAngle alpha;
    alpha.setAngle(phi);
    alpha.addAngle(eta);
    std::cout << "Suma katow = " << alpha.toDeg() << std::endl;

    printer.printLine();

    // Funkcja zewnętrzna
    std::cout << "Roznica nie moze byc wieksza od 180 deg, prawda?" << std::endl;
    std::cout << "distance(phi, eta) = " << std::setw(8) 
              << distance(phi, eta).toDeg() << std::endl;
    std::cout << "distance(eta, phi) = " << std::setw(8) 
              << distance(eta, phi).toDeg() << std::endl;

    return 0;
}

/************************* OUTPUT *************************
Rozpoczynamy zadanie 8: Radiany i stopnie!

************************* 1 *************************
Katy w radianach: phi =     5.17, eta =     0.09
Katy w stopniach: phi =   296.04, eta =     5.00

************************* 2 *************************
Suma katow = 301.04

************************* 3 *************************
Roznica nie moze byc wieksza od 180 deg, prawda?
distance(phi, eta) =    68.96
distance(eta, phi) =    68.96
**********************************************************/
