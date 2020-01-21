

//Ilayda Ademoglu(23856)
//HEADER FILE OF THE BASICOBJ 

class basicobj{
public:
	basicobj();
	basicobj(int val, int lab, int h, bool r);
	basicobj(const basicobj &);
	~basicobj();
	int value;
	int label;
	int height; //bunlari degistir
	bool right;


};