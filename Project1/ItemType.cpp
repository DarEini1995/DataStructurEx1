#include "ItemType.h"
int ItemType::getN() {
	return n;
}

int* ItemType::getA() {
	return A;
}
int ItemType::getX() {
	return x;
}

int ItemType::getY() {
	return y;
}

int ItemType::getLine() {
	return line;
}

void ItemType::setLine(int newline) {
	line = newline;
}