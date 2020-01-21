//#include "basicobj.h"
#include <vector>
using namespace std;
template <class Comparable>
class modifiedpqueue{
public:
	//modifiedpqueue();
	modifiedpqueue() : objects() {}
	modifiedpqueue(const modifiedpqueue &copy) : objects(copy.objects){}
	//~modifiedpqueue();
	void insert(Comparable &value, int label){  //insert function inserts comparable values into the array
		objects.push_back(value);
	}
	void heapsort(vector<Comparable> & a)  //modified heapsort function taken from the lecture slides
	{
		// buildHeap
		for(int i = a.size()/2; i >=0; i--)
			percDown(a,i, a.size());
		// sort
		for(int j = a.size() -1; j >0; j--)
		{
			swap(a[0], a[j]);  // swap max to the last pos.
			percDown(a,0,j); // re-form the heap
		}
	}

	inline int leftChild( int i )
	{
		return 2*i+1;
	}


	void percDown( vector<Comparable> &a, int i, int n ) //perculate down function
	{
		int child;
		Comparable tmp;


		for(tmp=a[i] ; leftChild(i) < n; i = child )
		{
			child = leftChild(i);
			if( child != n-1 && a[ child  ].value < a[ child+1 ].value )
				child++;
			if( a[child ].value > tmp.value )
				a[i] = a[ child ];
			else
				break;
		}
		a[ i ] = tmp;

	}

	void sorting(){
		heapsort(objects); //in the sorting function we first sort the vector 
		for(int i = 0; i < objects.size(); i++){ //pushing into other vector called label
			labels.push_back(objects[i].label);
		}
	}

	Comparable GetMax(){ //this function returns the comparable objects which has the highest height among them 
		vector<Comparable> popvector = objects;
		int maxheight = 0;
		Comparable x;
		for(int i = 0; i < popvector.size(); i++){
			if(popvector[i].height > maxheight){
				maxheight = popvector[i].height;
				x = popvector[i];
			}
			
		}
		return x;
	}

Comparable & Remove(int label){ //this function removes the specified label and which is left coordinate of the building and regulates vector itself again, returns the removed object
		vector<Comparable> newvector;
		Comparable x;
		Comparable returncom; 
		for(int i = 0; i < objects.size(); i++){
			if(!(objects[i].label == label && objects[i].right == false)){
				x = objects[i];
				newvector.push_back(x);
			}
			else{
				returncom = objects[i];
			}
		}
		this->objects = newvector;
		return returncom;
	}

bool IsEmpty(){ //this function returns true if the size is 1 or 0 because if its 1, the only value inside in it is 0 0 or nothing
		if(objects.size() == 1 || objects.size() == 0)
			return true;
		else 
			return false;
}

	int returnsize(){ //this function returns the objects size 
		return objects.size();

	}
	vector <Comparable> objects; 
private:
	//int size;
	vector <int> labels;
	vector <int> labelsreverse;




};
