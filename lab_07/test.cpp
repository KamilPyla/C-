/* Przykład pokazujący cztery sposoby przechowywania i obsługi napisu:
 * - tablica statyczna
 * - tablica dynamiczna
 * - std::array<char, X>
 * - std::string
 */
 
// Proszę wybrać jeden, przeczytać go dokładnie i konsekwentnie stosować!
// Niektóre spsoby pozwalają przesyłać i kopiować dane w różny sposób.
// Tradycyjny cstring można zawsze wyciągnąć z użytych struktur:
// std::array<char, 11>  std_arr -> std_arr.data(); 
// std::string           std_str -> std_str.c_str(); 

// Przechowujemy 10 liter,
// ale trzeba jeszcze pamiętać o znaku końca stringa!

#include <array>
#include <string>
#include <cstring>
#include <iostream>

struct MyTest {
    char                  sta_tab[11];
    std::array<char, 11>  std_arr;
    char *                dyn_tab;
    std::string           std_str;   
};


//*********************  tablica statyczna  *********************//

void copy_sta_tab(MyTest & t, const char * str)
{
    std::strcpy(t.sta_tab, str);
    
    std::cout << "sta_tab 1 = " << t.sta_tab << std::endl;
}


//*********************  tablica dynamiczna  *********************//

void copy_dyn_tab(MyTest & t, const char * str)
{
    // Zakładając że dyn_tab jest puste, 
    // w przeciwnym razie trzeba zwolnić starą pamięć:
    // if(dyn_tab) free(dyn_tab);
    
    // można od razu przyjąć 11, 
    // ale po co wtedy robić to dynamiczne
    unsigned int len = std::strlen(str) + 1; 
    
    t.dyn_tab = new char[len];
    std::strcpy(t.dyn_tab, str);
    
    std::cout << "dyn_tab 1 = " << t.dyn_tab << std::endl;
}


//*********************  std::array<char, X>  *********************//

void copy_std_arr(MyTest & t, const char * str)
{
    std::strcpy(t.std_arr.data(), str);
    
    std::cout << "std_arr 1 = " << t.std_arr.data() << std::endl;
}

void copy_std_arr(MyTest & t, const std::array<char, 11> & str)
{
    // Trzeba pamiętać o referencji i const!!!
    t.std_arr = str;
    
    std::cout << "std_arr 2 = " << t.std_arr.data() << std::endl;
}


//*********************  std::string  *********************//

// Zdefiniowanie funkcji przyjmującej const char * str jest niepotrzebne
// ponieważ const char * str może być skonwertowane na std::string
// 
// void copy_std_str(MyTest & t, const char * str)
// {
//     t.std_str = str;
//    
//    std::cout << "std_str 1 = " << t.std_str << std::endl;
// }

void copy_std_str(MyTest & t, const std::string & str)
{
    // Trzeba pamiętać o referencji i const!!!
    t.std_str = str;
    
    std::cout << "std_str 2 = " << t.std_str << std::endl;
}


//**************************************************//
//*********************  TEST  *********************//
//**************************************************//


int main()
{
    MyTest ttt;
    
    copy_sta_tab(ttt, "Test str");
    
    copy_std_arr(ttt, "Test str");
    copy_std_arr(ttt, std::array<char,11>{"Test str"});
    
    copy_dyn_tab(ttt, "Test str");
    
    // Obie funkcje wywołują to samo
    // bo const char * można skonwertować na std::string
    copy_std_str(ttt, "Test str");
    copy_std_str(ttt, std::string{"Test str"});
}


