#ifndef Rect_h
#define Rect_h

#include <iostream>

using namespace std;

struct Rect{

	float x, y, w, h;
	bool isused;
	char occupied;

	Rect() {
		x = 0.0, y = 0.0, w = 0.0, h = 0.0, isused = 0, occupied = ' ';
	}

	void Rec(float xcoord, float ycoord, float wcoord, float hcoord) {
		x = xcoord, y = ycoord, w = wcoord, h = hcoord, isused = 0, occupied = ' ';
	}

	bool getused() {return isused;}

	float getX() {return x;}
	float getY() {return y;}
	float getW() {return w;}
	float getH() {return h;}

	bool contains(float testx, float testy) {
		if (testx > x && testx < (x + w) && testy < y && testy > (y - h)) {
			return true;
		}
		else {
			return false;
		}
	}
	
	~Rect() {

	}

};




#endif