/* Zadanie 9: Dziennik ocen
 * 
 * Zadanie polega na napisaniu klasy MyRegister, przechowujący oceny 
 * MyGrade. Maksymalny rozmiar dziennika jest określony jako parametr 
 * konstruktora. 
 * 
 * Każda ocena posiada swój własny numer ID, który jest nadawany 
 * w momencie jej tworzenia. Unikalny numer ID można uzyskać za pomocą 
 * zmiennej statycznej.
 * 
 * MyRegister pozwala na wykonanie kopi zapasowej. Kopia ta jest głęboką
 * kopią - czyli każda ocena jest skopiowana. Kopia ma być zabezpieczeniem,
 * więc nie może być modyfikowana (dlatego zwracamy ją jako STAŁY wskaźnik).
 */

#include "MyGrade.h"
#include "MyRegister.h"
#include "MyGrade.h"

#include <iostream>
#include <iomanip>

int main()
{  
    std::cout << "Rozpoczynamy zadanie 9: Dziennik ocen!" << std::endl;
    
    // Ustawienie precyzji wypisania - dzięki temu oceny będą 
    // w studenckim formacie: 3.0, 4.5 etc
    std::cout << std::fixed << std::setprecision(1); 
    
    std::cout << "\n************* + WARM-UP + ***********" << std::endl;
    { 
        MyGrade gr( 2.0 );
        gr.print();
        std::cout << std::endl;
    }  
    
    std::cout << "\n*************  REGISTERS  ***********" << std::endl;
    
    MyRegister reg(5);
    reg.addGrade(new MyGrade(2.0));
    reg.addGrade(new MyGrade(4.5));
    reg.addGrade(new MyGrade(3.5));
    reg.showRegister();
    
    std::cout << "\n************* REG BACKUP  ***********" << std::endl;
    
    const MyRegister * backup = reg.backup();
    reg.addGrade(new MyGrade(4.0));

    reg.showRegister();
    backup->showRegister();
    
    std::cout << "\n************* PROBLEMS... ***********" << std::endl;

    // Za dużo ocen!
    reg.addGrade(new MyGrade(2.0));    
    reg.addGrade(new MyGrade(5.0));  
    
    // Nie można dodawać ocen do stałej kopii zapasowej!
    //backup->addGrade(new MyGrade(5.0));
    
    std::cout << "\n************* DESTRUCTORS ***********" << std::endl;

    reg.clearRegister();
    reg.showRegister();
    
    backup->showRegister();

    std::cout << std::endl;    
    delete backup;    
    
    return 0;
}

/************************* OUTPUT *************************
Rozpoczynamy zadanie 9: Dziennik ocen!

************* + WARM-UP + ***********
[1: 2.0]
Delete grade with id 1

*************  REGISTERS  ***********
Create register with maximum size 5
Register 3/5: [2: 2.0] [3: 4.5] [4: 3.5] 

************* REG BACKUP  ***********
Create register with maximum size 3
Register 4/5: [2: 2.0] [3: 4.5] [4: 3.5] [5: 4.0] 
Register 3/3: [2: 2.0] [3: 4.5] [4: 3.5] 

************* PROBLEMS... ***********
The limit of 5 grades has been reached!
Delete grade with id 7
Const register cannot be modyfied!
Delete grade with id 8

************* DESTRUCTORS ***********
Delete grade with id 2
Delete grade with id 3
Delete grade with id 4
Delete grade with id 5
Delete grade with id 6
Register 0/5: 
Register 3/3: [2: 2.0] [3: 4.5] [4: 3.5] 

Delete register with 3/3 grades
Delete grade with id 2
Delete grade with id 3
Delete grade with id 4
Delete register with 0/5 grades
**********************************************************/
