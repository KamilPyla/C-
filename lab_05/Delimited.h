#pragma once

struct Delimited 
{
  char separator;
  const char * poczatek_frag;
  const char * koniec_frag;
  const char * wsk_napis;
};

//procedura przygotowująca pomocniczą strukturę, jako argumenty przyjmuje stałą napisową, wskaźnik na strukturę Delimited oraz znak separatora.

void chunk (const char*, struct Delimited *, char);

//procedura wracająca na początek napisu, jako argument wskaźnik na strukturę

void rewind (struct Delimited *);

// proceruda przesuwająca wskaźnik na następny wyraz napisu

bool next (struct Delimited *);

// proceruda przesuwająca wskaźnik na następny wyraz napisu

bool prev (struct Delimited *);

int fragment_size (const struct Delimited *);
