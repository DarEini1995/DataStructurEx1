#include <windows.h>
#include <process.h>
#include <iostream>
#include <sstream>
#include <conio.h>
#include <stdlib.h>
#include <sstream> 
#include <iostream>
#include <vector>
using namespace std;


#define _CRT_SECURE_NO_WARNINGS


void findSumInrecursiveWay(int* A, int n, int x, int y) {
	if ((n == 1) && (y != 0)) {
		if (x == A[0] + y) {
			cout << y << " " << A[0] << "\n";
		}
	}
	if ((n == 1) && (y == 0)) {
		cout << "";
	}

	else  if (n != 1) {
		if (y != 0) {
			if (x == A[n - 1] + y) {
				cout << y << " " << A[n - 1] << "\n";
			}
			findSumInrecursiveWay(A, n - 1, x, y);
		}
		else if (y == 0) {
			findSumInrecursiveWay(A, n - 1, x, A[n - 1]);
			findSumInrecursiveWay(A, n - 1, x, 0);
		}
	}
}


bool isPrinted(vector <vector <int>> printedIndexes, int i, int j) {
	for (int z = 0; z < printedIndexes.size(); z++) {
		if (((printedIndexes[z][0] == i && printedIndexes[z][1] == j)) || ((printedIndexes[z][1] == i && printedIndexes[z][0] == j))) {
			return true;
		}
	}
	return false;
}


void findSumInIterativeWay(int* nativeNumbers, int n, int x) {
	vector <vector <int>> printedIndexes;
	int iVec = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i != j) && (x == nativeNumbers[i] + nativeNumbers[j])) {
				if (!isPrinted(printedIndexes, i, j)) {
					cout << nativeNumbers[i] << " " << nativeNumbers[j] << "\n";
					vector<int> v;
					v.push_back(i);
					v.push_back(j);
					printedIndexes.push_back(v);

				}
			}
		}
	}
}


int main() {
	int n;

	//test
	int arr[8] = { 5,5,4,5,2,4,3,1 };
	int size = 8;
	int x = 3;
	findSumInIterativeWay(arr, size, x);
	//findSumInrecursiveWay(arr, size, x,0);

}