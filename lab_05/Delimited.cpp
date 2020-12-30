#include <iostream>
#include "Delimited.h"
#include <stdio.h>

void chunk (const char* napis, struct Delimited * del, char sep){
  del->separator = sep;
  del->poczatek_frag = napis;
  del->koniec_frag = napis;
  del->wsk_napis = napis;
}

//procedura wracająca na początek napisu, jako argument wskaźnik na strukturę

void rewind (struct Delimited * del){
  del->poczatek_frag = del->koniec_frag = del->wsk_napis;
}

int fragment_size (const struct Delimited * del)
{
  return (del->koniec_frag - del->poczatek_frag);
}

 

bool next(struct Delimited *del ){
	if (*del->koniec_frag == '\0'){
		return false;
	}
	else {
		while (*del->koniec_frag == del->separator)
			del->koniec_frag++;
		del->poczatek_frag = del->koniec_frag;
		while (*del->koniec_frag != del->separator && *del->koniec_frag != '\0')
			del->koniec_frag++;
		return true;
	}
}

// proceruda przesuwająca wskaźnik na następny wyraz napisu

bool prev (struct Delimited * del){
	if(del->poczatek_frag == del->wsk_napis){
		return false;
	}
	else{
		del->poczatek_frag --;
		while (*del->poczatek_frag == del->separator)
			del->poczatek_frag --;
		del->koniec_frag = del->poczatek_frag +1;
		while (*del->poczatek_frag != del->separator && del->poczatek_frag != del->wsk_napis)
			del->poczatek_frag--;
		if (del->poczatek_frag != del->wsk_napis) del->poczatek_frag ++;
		return true;


	}

}
