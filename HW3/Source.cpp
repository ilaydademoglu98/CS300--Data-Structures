#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include "modifiedpqueue.h"
#include "basicobj.h"
using namespace std;

//Ilayda Ademoglu (2385), this is the third homework of cs300.
//This code finds skyline in given input.

int main(){
	ifstream input;
	istringstream iss;
	input.open("input.txt");    
	int thenumberofbuildings;
	input >> thenumberofbuildings; //taking the input of the first line which is the number of rows/buildings
	int i = 0;
	int xleft, middle, xright;
	modifiedpqueue<basicobj> x; //main heap  
	basicobj zero(0,i,0,false);
	x.insert(zero,i);  //first insert into queue of 0,0 input then if another 0 starting buildings is found, remove it
	while(!input.eof()){
		while(input >> xleft){  //Taking the input
			input >>middle >> xright;
			if(xleft == 0){  //if any of the buildings starting with the x coordinate, the first one which is 0,0 removed
				x.Remove(0);
			}
			basicobj obj1(xleft,i+1,middle,false);   //inserting the coordinates
			x.insert(obj1,i+1);
			basicobj obj2(xright,i+1,middle,true);
			x.insert(obj2, i);
			i++;
		}

	}
	x.sorting(); //sorting the coordinates
	modifiedpqueue<basicobj> skyline;  //this is the skyline priority queue that will be calculated by looking at maximum heights
	for(int i = 0; i < x.returnsize() ; i++){    //its going to process all the sorted elements inside of the x
		basicobj maxheight; //its going to keep maximum heighted basicobj inside in it
		basicobj inlsert = x.objects[i]; 
		if(inlsert.right == false)  //when we see a left sided input we will insert it in the queue and when we see its equal label we will remove that, so we insert into skyline priority queue only if its left sided
			skyline.insert(inlsert,inlsert.label);
		basicobj maxheightprintxleft;
		maxheightprintxleft = skyline.GetMax();  //after insertion object with the max height 
		bool goin= false; 
		if(inlsert.right == true){
		for(int i = 0; i < skyline.returnsize(); i++){
			if(skyline.objects[i].label == inlsert.label && skyline.objects[i].right == false){
				skyline.Remove(skyline.objects[i].label); //it removes if it finds the end of the building
				goin = true;
				maxheightprintxleft = skyline.GetMax();
				if(inlsert.height > maxheightprintxleft.height){
					cout << inlsert.value << " " << maxheightprintxleft.height << endl;  //it prints
				
				}
			}
		}
		}
		if(goin == false){
		if(maxheightprintxleft.height > maxheight.height){ //if its the left start of the building it prints according to the height
			maxheight = maxheightprintxleft;
		}
		if(inlsert.height >= maxheight.height)
			cout << maxheight.value << " " << maxheight.height << endl;
		}

	}




}

