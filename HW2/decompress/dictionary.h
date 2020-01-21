#ifndef DICTIONARY_H_
#define DICTINARY_H_
#include <string>
#include <climits>

//created by skarahoda @02.12.2012

class Dictionary{
public:
	Dictionary(): key(""), code(UINT_MAX){}
	Dictionary(int i, std::string c=""): code(i), key(c){}
	Dictionary(const Dictionary & rhs): code(rhs.code), key(rhs.key) {}

	bool operator == (const Dictionary & rhs) const;
	bool operator != (const Dictionary & rhs) const;
	void operator = (Dictionary & rhs);
	unsigned code;
	std::string key;
};

unsigned hashing(const Dictionary & d, int size);


#endif