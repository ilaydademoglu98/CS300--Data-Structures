using namespace std; 
#include <iostream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
struct Node 
{
    T val; 
    Node<T> *next; 
};

template <class T>
class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();
        void insertAtBack(T valueToInsert);
        bool removeFromBack();
        void print();
        bool isEmpty();
        int size();
        void clear();

        void insertAtFront(T valueToInsert);
        bool removeFromFront();
		T removerectangle();
		void add(const LinkedList<T> &);

  T& firstNum();

 
    private:
        Node<T> *first; 
        Node<T> *last; 
	
};

#endif