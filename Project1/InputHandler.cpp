#include "InputHandler.h"


int getANativeNum() {
	string input;
	int candidateNum, tmp;
	stringstream ss;

	getline(cin, input);
	ss << input;
	ss >> tmp;
	if (ss.eof()) { //validate we get only one word
		//validate this word is a nateive number
		if ((stringstream(input) >> candidateNum) && (candidateNum > 0))
			return candidateNum;
	}
	return 0;
}



int* getArr(int size) {
	int* arr = new int[size];
	string input;
	int currentSizeCounter = 0;
	stringstream ss;
	getline(cin, input);
	ss << input;
	string tmp;
	int candidateNum;
	while (!ss.eof()) {
		if (currentSizeCounter > size) return 0;
		ss >> tmp;
		if ((stringstream(tmp) >> candidateNum) && (candidateNum > 0)) {
			arr[currentSizeCounter++] = candidateNum;
			tmp = " ";
		}
		else return 0;
	}
	if (currentSizeCounter == size)
		return arr;
	return 0;
}