#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <vector>
using namespace std;

template <class HashedObj>
class HashTable{
public:
	HashTable( int size = 101 ):
	  array( nextPrime( size ) ), currentSize(0){}

	HashTable( const HashTable & rhs ):
	  array( rhs.array ), currentSize( rhs.currentSize ) { }

	const HashedObj & find( const HashedObj & x ) const;
	const HashedObj & giveTheElement(int i) const;
	void insert( const HashedObj & x );
	void remove( const HashedObj & x );

	int findPos( const HashedObj & x ) const;

	enum EntryType { ACTIVE, EMPTY, DELETED };

private:
	struct HashEntry{
		HashedObj element;
		EntryType info;

		HashEntry( const HashedObj & e = HashedObj( ), EntryType i = EMPTY )
			: element( e ), info( i ) { }
	};

	vector<HashEntry> array;
	int currentSize;
	const HashedObj ITEM_NOT_FOUND;

	bool isActive( int currentPos ) const;

	void rehash( );
};

int nextPrime( int n );
bool isPrime( int n );

int hash(string, int);

#include "HashTable.cpp"
#endif