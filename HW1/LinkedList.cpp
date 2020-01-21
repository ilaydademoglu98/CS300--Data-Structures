#include "LinkedList.h"

//template <class T>
//struct Node 
//{
//    T val; 
//    Node<T> *next; 
//};

template <class T>
LinkedList<T>::LinkedList()
{
	first = NULL;
	last = NULL;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* temp = first;
	while(temp != NULL)
	{
		temp = temp->next;
		delete(first); 
		first = temp;
	}
}

template <class T>
void LinkedList<T>::insertAtBack(T valueToInsert)
{
	//Node<T>* newNode =new Node<T>;
	//newNode->val = valueToInsert;
	//newNode->next = NULL;

	Node<T>* temp = first;

	if (temp != NULL) 
	{
		while (temp->next != NULL) 
		{
			temp = temp->next;
		}

		temp->next = new Node<T>;
		temp->next->val = valueToInsert;
		temp->next->next = NULL;
	}
	else 
	{
		first = new Node<T>;
		first->val = valueToInsert;
		first ->next = NULL;
	}
}


template <class T>
bool LinkedList<T>::removeFromBack()
{	
	if (first == NULL && last == NULL) {return false;}

	if (first == last)
	{
		cout<<"First is equal to Last."<<endl;
		delete(first);
		first = last = NULL;
		return true;
	}

	else
	{
		Node<T>* temp = first;
		int nodeCount = 0;

		while (temp != NULL)
		{
			nodeCount = nodeCount + 1;
			temp = temp->next;
		}

		Node<T>* temp2 = first;
	
		for(int i = 1; i < (nodeCount - 1); i++)
		{
			temp2 = temp2->next;
		}

		cout << temp2->val<<endl;
		delete(temp2->next);
		
		last = temp2;
		last->next = NULL;
		
		return true;
	}
}

template <class T>
void LinkedList<T>::print()
{
	Node<T>* temp = first;

	if (temp == NULL) 
	{
		cout<<"";
	}

	if (temp->next == NULL) 
	{
		cout<<temp->val;
	}
	else 
	{
		while (temp != NULL)
		{
			cout<< temp->val;
			temp = temp->next;
			cout<< ",";
		}
	}
}

template <class T>
bool LinkedList<T>::isEmpty()
{
	if (first == NULL && last == NULL) {return true;}
	else {return false;}
}

template <class T>
int LinkedList<T>::size()
{	
	if (first == NULL && last == NULL) {return 0;}

	Node<T>* temp = first;
	int nodeCounter = 0;

	while (temp != NULL)
	{
		nodeCounter = nodeCounter + 1;
		temp = temp->next;
	}
	return nodeCounter;
}

template <class T>
void LinkedList<T>::clear()
{
	Node<T>* temp = first;
	while(temp != NULL)
	{
		temp = temp->next;
		first = temp;
		delete(temp);
	}
}

template <class T>
void LinkedList<T>::insertAtFront(T valueToInsert)
{
	/*Node<T>* newNode;*/
	//newNode->val = valueToInsert;
	Node<T>* temp = first;
	temp->val = valueToInsert;
	

  	 if(first == NULL)
   	{
   		first = new Node<T>;
   	}
   	else
   	{
   		temp->next = first;
   		first = new Node<T>;
   	}

}

template <class T>
bool LinkedList<T>::removeFromFront()
{
	if (first == NULL && last == NULL) {return false;}
	
	else
	{
		Node<T>* temp;

		temp = first;
		first = first->next;

		delete(temp);

		return true;
	}
}

template <class T>
T& LinkedList<T>::firstNum()
{
	return first->val;
}

template <class T>
T LinkedList<T>::removerectangle()
{
	/*if(first == NULL)
		return NULL;*/
	if(first != NULL){
		Node<T> * deleted;
		deleted = first;
		first = first->next;
		T returnv = deleted->val;
		delete deleted;
		return returnv;
	}
		

}

template <class T>
void LinkedList<T>::add(const LinkedList<T> & rhs) //PROBLEM BURDAAAAAAA
{
	LinkedList<T> added(rhs);
	while(added.size() != 0){
		this->insertAtBack(added.removerectangle()); //BURDA HATA VERMISTI
	}
}