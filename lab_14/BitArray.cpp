#include "BitArray.h"
#include <iostream>



// ----------------------------------------------------------
// Gotowe funkcje

void BitArray::setBit(unsigned int pos, bool v)
{
    unsigned int nCell = pos/8;
    unsigned int nBit  = pos%8;
    
    if( v ) 
    {
        m_data[nCell] |=   1 << nBit;
    }
    else
    {
        m_data[nCell] &= ~(1 << nBit);
    }
}

bool BitArray::getBit(unsigned int pos) const
{
    unsigned int nCell = pos/8;
    unsigned int nBit  = pos%8;
    
    return static_cast<bool>( m_data[nCell] & (1 << nBit) );
}

void BitArray::increment()
{
    for(auto i = 0u; i< m_bitsCount; ++i)
    {
        if( getBit(i) )
        {
            setBit(i, false);
        }
        else
        {
            setBit(i, true);
            break;
        }
    }
}

    BitArray::BitArray(int n){
      int nBit = n/8;
      if (n%8)
        ++nBit;
      m_data = new unsigned char [nBit];
      for (int i = 0; i < nBit; i++)
      {
        m_data[i] = 0;
      }
      m_cellCount = nBit;
      m_bitsCount = n;

    }
    BitArray::BitArray(int n, bool val)
    {
      int nBit = n/8;
      if (n%8)
        ++nBit;
      m_data = new unsigned char [nBit];
      for (int i = 0; i < nBit; i++)
      {
        m_data[i] = 0xFF;
      }
      m_cellCount = nBit;
      m_bitsCount = n;


    }
    BitArray::BitArray(BitArray & cpy){
      m_cellCount = cpy.m_cellCount;
      m_bitsCount = cpy.m_bitsCount;
      m_data = new unsigned char [m_cellCount];
            for (unsigned int i = 0; i < m_cellCount; i++)
      {
        m_data[i] = cpy.m_data[i];
      }
    }

    BitArray::~BitArray(){
      delete [] m_data;
    }


    bool BitArray::operator[](unsigned i) const{
        return getBit(i);
    }
    BitPos BitArray::operator[](unsigned i){
      return BitPos(this,i);
    }

    BitArray BitArray::operator++(){
      this->increment();
      return *this;

    }
    BitArray BitArray::operator++(int){
      BitArray temp = *this;
      this->increment();
      return temp;
    }

    std::ostream& operator<<(std::ostream & str,const BitArray & bit) {

      for ( unsigned int i = 1; i <= bit.getBits(); i++){
        if((bit.getBits()-i +1)%8==0)
          str << " <-"<<bit.getBits()-i +1 << " " ;
        str<< bit.getBit(bit.getBits()-i );
      }
      str << " <-"<<"0";
      return str;
      }
  
        