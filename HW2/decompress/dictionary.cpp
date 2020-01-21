#include "dictionary.h"

//created by skarahoda @02.12.2012

bool Dictionary::operator == (const Dictionary & rhs) const{
	return code==rhs.code;
}

bool Dictionary::operator != (const Dictionary & rhs) const{
	return code!=rhs.code;
}

unsigned hashing(const Dictionary & d, int size){
	return d.code%size;
}

void Dictionary::operator = (Dictionary & rhs){
	code=rhs.code;
	key=rhs.key;
}
