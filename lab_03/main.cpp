// Proszę napisać strukturę MapPoint, ktore reprezentuje punkt na
// mapie skladajacy sie z nazwy, dlugosci (longitude) i szerokosci
// (latitude) geograficznej. Zachodnia i południowa półkula mają 
// odpowiednią współrzędną ujemną.

// Funkcja inTheMiddle powinna tworzyć nowy punkt na mapie o zadanej
// nazwie i połozeniu, ktore jest srednią arytmetyczna z polozeń
// podanych punktów czyli x = (x_1 + x_2)/2. 

// UWAGA: Trzeba zaakolować miejsce na tablice znaków! Funkcja clean
// powinna zwalniać pamieć zaalokowaną dla danego punktu / tablicy punktów.
// Proszę pamiętać o zaalokowaniu pamięci także dla znaku końca stringu '\0'.

#include "MapPoint.h"
#include "MapPoint.h"
#include <iostream>
#include <string>

int main() {
    const double latitude  = 50.061389;
    const double longitude = 19.938333;
        
    MapPoint krk = constructMP("Krakow", latitude, longitude);
    print(krk);
    MapPoint nyc = constructMP("NYC", 40.7127, -74.0059 );
    print(nyc);
    
    char tabChar[] = "Irkutsk";
    MapPoint irk = constructMP(tabChar,  52.283333, 104.283333);
    print(irk);

    // Na pewno skopiowano?
    tabChar[0] = 'X';
    print(irk);


    std::cout << "Odleglosc pomiedzy " << krk.name << " a " << nyc.name <<
                 " = " << distance(krk, nyc) << std::endl;

    // Funkcja print nie modyfikuje obiektu. Zatem powinna być...?
    const MapPoint& siberiaCapital = irk;
    print(siberiaCapital);

    const double longitudeShift = 4.1234;
    const double latitudeShift  = -25.987;
    movePoint(irk, latitudeShift, longitudeShift);
    print(siberiaCapital);

    const char * somewhere = "Gdzies, lecz nie wiadomo gdzie...";
    MapPoint mp = inTheMiddle(krk, siberiaCapital, somewhere);
    print(mp);

    // Sprzątanie - pojedyńczy punkt ....
    clear(mp);  

    // ... i tablica punktów
    MapPoint* tab[] = { &krk, &nyc, &irk };
    int rozmiar = sizeof(tab)/sizeof(MapPoint*);
    clear(rozmiar, tab);  
}

/************************* OUTPUT *************************
Punkt na mapie <Krakow> ma wspolrzedne [ 50.0614 N, 19.9383 E ]
Punkt na mapie <NYC> ma wspolrzedne [ 40.7127 N, 74.0059 W ]
Punkt na mapie <Irkutsk> ma wspolrzedne [ 52.2833 N, 104.283 E ]
Punkt na mapie <Irkutsk> ma wspolrzedne [ 52.2833 N, 104.283 E ]
Odleglosc pomiedzy Krakow a NYC = 94.4082
Punkt na mapie <Irkutsk> ma wspolrzedne [ 52.2833 N, 104.283 E ]
Punkt na mapie <Irkutsk> ma wspolrzedne [ 26.2963 N, 108.407 E ]
Punkt na mapie <Gdzies, lecz nie wiadomo gdzie...> ma wspolrzedne [ 38.1789 N, 64.1725 E ]
**********************************************************/
