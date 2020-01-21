#include "LinkedList.h"
#include "LinkedList.cpp"

class Rectangle {
	friend class BinarySearchTree;
	friend class TwoDimTreeNode;
public:
	Rectangle(); //DEFAULT CONSTRUCTOR
	Rectangle(int Topie, int Leftie, int Bottomie, int Rightie); //CONSTRUCTOR OF THE RECTANGLE
	int vertical();
	int horizontal();
	Rectangle verticalline();
	Rectangle horizontalline();
	bool intersect(const Rectangle &);
	int Topp();
	int Bottomm();
	int Rightt();
	int Leftt();
private:
	int Top; // y coordinate of the upper edge
	int Left; // x coordinate of the left edge
	int Bottom; // y coordinate of the bottom edge
	int Right; // x coordinate of the right edge

};class BinarySearchTree{	friend class Rectangle;private:	class TwoDimTreeNode {
	public:
	TwoDimTreeNode(Rectangle & E);
	void ekleme(Rectangle &); // KISA KOD
	//void finder(Rectangle &, LinkedList<Rectangle> &);
	void deneme(Rectangle &,LinkedList<Rectangle> &); // deneme find in aynisi
	void denemebenimdenemem(int i, int y,LinkedList<Rectangle> &);
	LinkedList <Rectangle> LinkedListFind(Rectangle &,LinkedList<Rectangle> &); //deneme
	private:
	Rectangle Extent;
	LinkedList<Rectangle> Vertical, Horizontal;
	TwoDimTreeNode *TopLeft, *TopRight,*BottomLeft, *BottomRight;
	};	TwoDimTreeNode *root;public:	BinarySearchTree(Rectangle &);	void binaryekle(Rectangle &);	void findiebenimdenememxxxx(int x,int y,LinkedList<Rectangle> &);	LinkedList <Rectangle> findiebenimdenemem(int x,int y);	LinkedList <Rectangle> findie(Rectangle & query);	};