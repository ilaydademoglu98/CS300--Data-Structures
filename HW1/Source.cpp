#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "twodimbinary.h"
#include "LinkedList.h"
using namespace std;

//I am ilayda ademoglu this is the first homework of cs300

struct dataNode{
	int x;
	int y;
	LinkedList <Rectangle> data;
	//vector<int> a;
	dataNode * next;
};

int main(){
	//TwoDimTreeNode firstnode;
	string theFilename;
	string thefirstline;
	//TwoDimTreeNode starting = x.root;
	ifstream input;
	/*BinarySearchTree gercek;*/
	do{ 
		cout << "Please enter a file name." << endl;
		cin >> theFilename;
		input.open(theFilename);
		if(input.fail()){
			cout << "Could not open the file" << endl;
		}
		else{
			int top, bottom, left, right;
			cout << "Successfully opened file " << theFilename << endl;
			getline(input,thefirstline);
			istringstream iss(thefirstline);
			iss >> top >> left >> bottom >> right;
			Rectangle extent(top,left,bottom,right); //EXTENT OLAN DIKDORTGENI YARATTIM 
			BinarySearchTree binarytree(extent); // EXTENT OLAN DIKTORTGENI BINARY SEARCH TREE XIMIN ELEMANI YAPTIM
			int count = 0;
			while(getline(input,thefirstline)){
				istringstream iss(thefirstline);
				iss >> top >> left >> bottom >> right;
				Rectangle gecici(top,left,bottom,right); //Bunlari gecici bir rectangle a atadim 
				binarytree.binaryekle(gecici); //bu rectangle i binary tree ye eklemesi icin add fonksiyonuna gonderdim 
				count++; //BU COUNT I KULLANMIYORSUN BIR ARA SIL 
				if(top == -1)
					break;
			}

			int x = 0; 
			int y= 0;	
			dataNode *yeni = NULL;
			LinkedList<Rectangle> bulma;
			while(true){
				cout << "Enter the inputs : ";
				cin>> x >> y;
				if(x < 0)
					break;
				else{
					if(yeni == NULL){
						yeni = new dataNode;
						yeni->x = x;
						yeni->y = y;
						yeni ->next = NULL;
						binarytree.findiebenimdenememxxxx(x,y,bulma);
						while(bulma.size() != 0){
							Rectangle x = bulma.removerectangle();
							yeni->data.insertAtBack(x);
						}
						}
					
					else{
						LinkedList<Rectangle> bulma2;
						dataNode *temp = yeni;
						while(temp -> next != NULL){
							temp = temp->next;
						}
						temp-> next = new dataNode;
						temp-> next-> x = x;
						temp->next ->y = y;
						temp->next-> next = NULL;
						binarytree.findiebenimdenememxxxx(x,y,bulma2);
						while(bulma2.size() != 0){
							Rectangle x = bulma2.removerectangle();
							temp->next->data.insertAtBack(x);
						}
					}
				}


			}
			dataNode *tempyeni = yeni;
			while(tempyeni != NULL){
				cout << tempyeni->x << " " << tempyeni->y << endl;
				cout << tempyeni->data.size() <<  endl;
				LinkedList <Rectangle> x = tempyeni->data;
				while(x.size() != 0){
					Rectangle gecici = x.removerectangle();
					cout << gecici.Topp() << " "  << gecici.Leftt() << " " << gecici.Bottomm() << " "<< gecici.Rightt() << endl;
				}
				tempyeni = tempyeni->next;

			}
			break;



		}
	}while(input.fail());









	return 0;
}