#include "twodimbinary.h"
#include "LinkedList.h"
#include <stddef.h>



int Rectangle::vertical()
{
	return (Left + Right / 2);
}

int Rectangle::Topp()
{
	return Top;
}

int Rectangle::Bottomm()
{
	return Bottom;
}
int Rectangle::Rightt()
{
	return Right;
}
int Rectangle::Leftt()
{
	return Left;
}
int Rectangle::horizontal()
{
	return (Top + Bottom / 2);
}

bool Rectangle::intersect(const Rectangle & control){
	if( Right < control.Left ||Left > control.Right ||Bottom < control.Top ||Top  > control.Bottom) {
		return false;
	}
	else
		return true;
}

Rectangle Rectangle::horizontalline(){
	return Rectangle((Top+Bottom)/2, (Top+Bottom)/2,Left,Right);
}

Rectangle Rectangle::verticalline(){
	return Rectangle(Top, Bottom,(Left+Right)/2,(Left+Right)/2);
}

Rectangle::Rectangle(){
	Top = NULL;
	Left = NULL;
	Right = NULL;
	Bottom = NULL;
}


Rectangle::Rectangle(int Topie, int Leftie, int Bottomie, int Rightie){
	Top = Topie;
	Left = Leftie;
	Right = Rightie;
	Bottom = Bottomie;
}

//BinarySearchTree::BinarySearchTree(){
//	root = NULL;
//}


BinarySearchTree::BinarySearchTree(Rectangle & E){
	root = new TwoDimTreeNode(E);
}

BinarySearchTree::TwoDimTreeNode::TwoDimTreeNode(Rectangle & E){
	Extent = E;
	TopRight = NULL;
	TopLeft = NULL;
	BottomLeft = NULL;
	BottomRight = NULL;
}

void BinarySearchTree::binaryekle(Rectangle & addedtolist){
	root->ekleme(addedtolist);

}

void BinarySearchTree::TwoDimTreeNode::ekleme(Rectangle & insertlist){
	if(insertlist.intersect(Extent.horizontalline())){ //If intersect horizantal line it stroes
		this->Horizontal.insertAtBack(insertlist);
	}
	else if(insertlist.intersect(Extent.verticalline())){
		this->Vertical.insertAtBack(insertlist);
	}
	else if(insertlist.horizontal() > Extent.horizontal() && insertlist.vertical() > Extent.vertical()){
			if(this->BottomRight == NULL){
				BottomRight = new TwoDimTreeNode(Rectangle(Extent.horizontal(),Extent.Bottom,Extent.vertical(),Extent.Right));
				//BottomRight->add(addedtolist);
			}
			BottomRight->ekleme(insertlist);
	}
	else if(insertlist.horizontal() > Extent.horizontal() && insertlist.vertical() < Extent.vertical()){
			if(this->BottomLeft == NULL){
				BottomLeft = new TwoDimTreeNode(Rectangle(Extent.horizontal(),Extent.Bottom,Extent.Left,Extent.vertical()));
				//BottomLeft->add(addedtolist);
			}
			BottomLeft->ekleme(insertlist);
		}

	
	else if(insertlist.horizontal() < Extent.horizontal() && insertlist.vertical() > Extent.vertical()){
		if(this->TopRight == NULL){
			TopRight = new TwoDimTreeNode(Rectangle(Extent.Top, Extent.horizontal(),Extent.vertical(),Extent.Right));
			//TopRight->add(addedtolist);
		}
		TopRight->ekleme(insertlist);
	}
	else if(insertlist.horizontal() < Extent.horizontal() && insertlist.vertical() < Extent.vertical()){
		if(this->TopLeft == NULL){
			TopLeft = new TwoDimTreeNode(Rectangle(Extent.Top,Extent.horizontal(), Extent.Left, Extent.vertical()));
			//TopLeft -> add(addedtolist);
		}
		TopLeft -> ekleme(insertlist);

	}
}

void BinarySearchTree::TwoDimTreeNode::denemebenimdenemem(int x, int y,LinkedList<Rectangle> & found){


	//LinkedList<Rectangle> temporaryvertical(Vertical);
	//LinkedList<Rectangle> temporaryhorizontal(Horizontal);
	int v = Vertical.size();
	while(Vertical.size() != 0){
		
		while(v > 0){
		Rectangle taken = Vertical.removerectangle();
		Vertical.insertAtBack(taken);
		if(taken.Left <= x && x < taken.Right && y >= taken.Top && y < taken.Bottom)
			found.insertAtBack(taken);
		v--;
		if(v == 0)
			break;
		}
		if(v == 0)
			break;
	}
	int h = Horizontal.size();
	while(Horizontal.size() != 0){
		
		while(h > 0){
			Rectangle taken = Horizontal.removerectangle();
			Horizontal.insertAtBack(taken);
			if(taken.Left <= x && x < taken.Right && y >= taken.Top && y < taken.Bottom)
				found.insertAtBack(taken);
			h--;
			if(h == 0)
				break;
		}
			if(h == 0)
				break;
	} 
	if(y == Extent.horizontal() || x == Extent.vertical()){
		return;
	}
	if(y > Extent.horizontal() && x > Extent.vertical()){ //BOTTOM RIGHT
		if(BottomRight != NULL){
			BottomRight->denemebenimdenemem(x,y,found);
		}
	}
	else if(y > Extent.horizontal() && x < Extent.vertical()){ //BOTTOM left 
		if(BottomLeft != NULL){
			BottomLeft->denemebenimdenemem(x,y,found);
		}
	}
	else if(y < Extent.horizontal() && x > Extent.vertical()){ //BOTTOM RIGHT
		if(TopRight != NULL){
			TopRight->denemebenimdenemem(x,y,found);
		}
	}
	else if(y < Extent.horizontal() && x < Extent.vertical()){ //BOTTOM RIGHT
		if(TopLeft != NULL){
			TopLeft->denemebenimdenemem(x,y,found);
		}
	}
}

void BinarySearchTree::findiebenimdenememxxxx(int x, int y,LinkedList<Rectangle> & found){ //bi diktortgen var eger linkedlistle kesisiyorsa bunu linked liste ekleyip ver
	root->denemebenimdenemem(x,y,found);
}

