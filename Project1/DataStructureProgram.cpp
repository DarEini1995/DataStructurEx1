#include <windows.h>
#include <process.h>
#include <iostream>
#include <sstream>
#include <conio.h>
#include <stdlib.h>
#include <sstream> 
#include <iostream>
#include <vector>
#include "DataStuctureProgram.h"
#include "Stack.h"
#include "ItemType.h"


int START=0;
int AFTER_FIRST=1;
int AFTER_SECOND=2;
int AFTER_THIRD = 3;

using namespace std;


#define _CRT_SECURE_NO_WARNINGS


void findSumInRecursiveWay(int* A, int n, int x)
{
	findSumInRecursiveWay(A, n, x, 0);
}


void findSumInRecursiveWay(int* A, int n, int x, int y) {
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
			findSumInRecursiveWay(A, n - 1, x, y);
		}
		else if (y == 0) {
			findSumInRecursiveWay(A, n - 1, x, A[n - 1]);
			findSumInRecursiveWay(A, n - 1, x, 0);
		}
	}
}

void findSumInWithStack(int* A, int n, int x)
{
	findSumInWithStack(A, n, x, 0);
}

void findSumInWithStack(int* A, int n, int x, int y)
{
	Stack S;
	ItemType Curr;
	ItemType Next;

	Curr = { A, n, x, y, START};

	S.Push(Curr);
	while (!S.IsEmpty()) {
		Curr = S.Pop();
		if (Curr.line == START)
		{
			if ((Curr.n == 1) && (Curr.y != 0)) {
				if (Curr.x == Curr.A[0] + Curr.y) {
					cout << Curr.y << " " << Curr.A[0] << "\n";
				}
			}
			if ((Curr.n == 1) && (Curr.y == 0)) {
				cout << "";
			}
			else if (Curr.n != 1)
			{
				if (Curr.y != 0)
				{
					if (Curr.x == Curr.A[Curr.n - 1] + Curr.y) {
						cout << Curr.y << " " << Curr.A[Curr.n - 1] << "\n";
					}
					Curr.line = AFTER_FIRST;
					S.Push(Curr);
					Next = { Curr.A, Curr.n - 1, Curr.x, Curr.y, START};
					S.Push(Next);
				}
				else if (Curr.y == 0)
				{
					Curr.line = AFTER_SECOND;
					S.Push(Curr);
					Next = { Curr.A, Curr.n - 1, Curr.x, Curr.A[Curr.n - 1], START };
					S.Push(Next);
				}

			}
		}
		else if (Curr.line == AFTER_FIRST)
		{
			//noting more happends
		}
		else if (Curr.line == AFTER_SECOND)
		{
			Curr.line = AFTER_THIRD;
			S.Push(Curr);
			Next = { Curr.A, Curr.n - 1, Curr.x, 0, START };
			S.Push(Next);
		}
		else if (Curr.line == AFTER_THIRD)
		{
			//noting more happends
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
	//findSumInIterativeWay(arr, size, x);
	//findSumInrecursiveWay(arr, size, x,0);
	findSumInWithStack(arr, size, x);

}