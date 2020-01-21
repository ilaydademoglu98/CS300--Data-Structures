#include "dictionary.h"
#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	ifstream input;
	ofstream output;
	input.open("compout.txt");
	output.open("decompout.txt");
	string get;
	Dictionary empty;
	string notfound;
	string added;
	unsigned cur;
	unsigned prev;
	unsigned now=256; //they are going to be the indexes of hash table
	HashTable<Dictionary> hashtable(4096);
	for(int i=0; i<256; i++){ //getting hash table with ascii codes
		get=i;
		hashtable.insert(Dictionary(i,get));
	}
	input>>prev;
	output << hashtable.find(Dictionary(prev)).key; 
	while(!input.eof()){
		input>>cur;
		added=hashtable.find(prev).key;						//it creates next entry of hashtable
		if(hashtable.find(cur).key ==notfound)
			added+=added[0];  
		else
			added+=hashtable.find(cur).key[0];
		hashtable.insert(Dictionary(now++,added));			//Then it inserts to hashtable
		output << hashtable.find(cur).key;
		prev=cur;
	}
	output.close();
	input.close();

	return 0;
}