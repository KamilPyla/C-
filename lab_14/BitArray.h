#pragma once
#include<iostream>

// Moje komentarze proszę usunąć przed oddaniem zadania.

// Deklaracja wyprzedzająca, może się przydać...
class BitPos;

class BitArray {
public: 
    // Miejsce na Twoje funkcje
    BitArray(int n);
    BitArray(int n, bool val);
    BitArray(BitArray & cpy);

    ~BitArray();


    bool operator[](unsigned i) const;
    BitPos operator[](unsigned i);

    BitArray operator++();
    BitArray operator++(int);

    unsigned int getBits() const {return m_bitsCount;}
    unsigned int getBajt() const {return m_cellCount;}


    
        
public: 
    // Funkcje gotowe, ale wymagające dokumentacji :)
    void setBit(unsigned int pos, bool v);
	bool getBit(unsigned int pos) const;
    void increment();   
        
private:
    // Przykładowe pola w klasie, można je zmienić
    unsigned char * m_data;
    unsigned int    m_cellCount;
    unsigned int    m_bitsCount;
         
};

class BitPos {
  public:
    BitPos (BitArray * bit, unsigned int npos):_bit(bit), _npos(npos){};

  operator bool(){return _bit->getBit(_npos);} 
  void operator=(bool b){_bit->setBit(_npos,b);}
  private:
    BitArray * _bit;
    unsigned int _npos;
};
std::ostream& operator<<(std::ostream & str, const BitArray & bit );