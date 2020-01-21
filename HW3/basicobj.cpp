#include "basicobj.h"

//	Ilayda Ademoglu (23856) basic objects cpp file
basicobj::basicobj(){ // default constructor
	value = 0;
	label = 0;
	height = 0;
	right; 
}


basicobj::basicobj(int val, int lab, int h, bool r){ //constructor with the values
	value = val;
	label = lab;
	height = h;
	right = r; //BUNA BAK SONRA SILERSIN BELKI
}

basicobj::~basicobj(){
	//value = 0;
	//label = 0;
	//height = 0;
	//right; 
}


basicobj::basicobj(const basicobj & copy){ //copy constructor
	value = copy.value;
	label = copy.label;
	height = copy.height;
	right = copy.right; //BUNA BAK SONRA SILERSIN BELKI
}