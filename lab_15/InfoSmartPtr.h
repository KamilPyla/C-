#pragma once

#include "InfoClass.h"


class InfoSmartPtr {
public:


//konstruktor przyjmujący wskaźnik na InfoClass, ustawia wskaźnik _shareptr na wskaźnik podamy w argumencie
InfoSmartPtr(InfoClass* ptr);

//konstruktor kopiujący czyści pamięć po wcześniejszych wskaźnikach jeżeli obiekt jest jedynym obiektek który przechowuje wskaźnik do InfoClass
//wziększa cout o jeden przypisuje ten wskaźnik z obiektu cpy
InfoSmartPtr(const InfoSmartPtr& cpy);


//destruktor czyści pamięć po wskaźnikach do InfoClass oraz count jeżeli dany obiekt jest ostatnij obiektem przechowującym wskaźnik do InfoClass, jeżeli nie jest ostatnim, zmniejsza wartość count o jeden
~InfoSmartPtr();

//wzraca obiekt na który wskazuje wskaźnik _share
const InfoClass & operator*() const;

//wzraca obiekt na który wskazuje wzkaźnik _share
InfoClass & operator*();

void equal(const InfoSmartPtr & eq);

//operator przypisania, jeżeli dany obiekt jest ostatnik obiektem przechowującym wskaźnik na wcześniejsze InfoClass to zwalnia po nim pamięć
// jeżeli nie jest ostatnim, to zmniejsza count o jeden
// nastepnie przekazuje wskaźnik z obiektu eq oraz zwiększa cout o jeden
void operator=(const InfoSmartPtr & eq);

//wzraca wskaźnik _share
const InfoClass* operator->()const;
//wzraca wskaźnik _share
InfoClass* operator->();

private:

//pole przechowujące wskaźnik;
InfoClass * _shareptr;

//pole przechowujące licznik ile jest obiektów przechowujących dany wskaźnik.
mutable int * _count;

};