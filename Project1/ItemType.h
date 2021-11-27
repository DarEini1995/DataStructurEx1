#pragma once
#include <cstddef>

class ItemType
{
private:
	int n;
	int* A;
	int x;
	int y;
	int line;
public:
	int getN();
	int* getA();
	int getX();
	int getY();
	int getLine();
	void setLine(int line);
	ItemType() {
		n = -1;
		A = NULL;
		x = -1;
		y = -1;
		line = -1;
	};
	ItemType(int* A, int n, int x, int y, int line) {
		this->A = A;
		this->n = n;
		this->x = x;
		this->y = y;
		this->line = line;
	};
};
