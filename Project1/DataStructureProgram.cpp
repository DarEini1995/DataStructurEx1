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
#include <functional>
#include "InputHandler.h"
#include <chrono>
#include <fstream>
#include <iomanip>

int START=0;
int AFTER_FIRST=1;
int AFTER_SECOND=2;
int AFTER_THIRD = 3;
#define WRONG_INPUT 0

using namespace std;

#define _CRT_SECURE_NO_WARNINGS


void findSumInRecursiveWayInit(int* A, int n, int x) {
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

void findSumInWithStackInit(int* A, int n, int x) {
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
		if (Curr.getLine() == START)
		{
			if ((Curr.getN() == 1) && (Curr.getY() != 0)) {
				if (Curr.getX() == Curr.getA()[0] + Curr.getY()) {
					cout << Curr.getY() << " " << Curr.getA()[0] << "\n";
				}
			}
			if ((Curr.getN() == 1) && (Curr.getY() == 0)) {
				cout << "";
			}
			else if (Curr.getN() != 1)
			{
				if (Curr.getY() != 0)
				{
					if (Curr.getX() == Curr.getA()[Curr.getN() - 1] + Curr.getY()) {
						cout << Curr.getY() << " " << Curr.getA()[Curr.getN() - 1] << "\n";
					}
					Curr.setLine(AFTER_FIRST);
					S.Push(Curr);
					Next = { Curr.getA(), Curr.getN() - 1, Curr.getX(), Curr.getY(), START};
					S.Push(Next);
				}
				else if (Curr.getY() == 0)
				{
					Curr.setLine(AFTER_SECOND);
					S.Push(Curr);
					Next = { Curr.getA(), Curr.getN() - 1, Curr.getX(), Curr.getA()[Curr.getN() - 1], START };
					S.Push(Next);
				}

			}
		}
		else if (Curr.getLine() == AFTER_FIRST)
		{
			//noting more happends
		}
		else if (Curr.getLine() == AFTER_SECOND)
		{
			Curr.setLine(AFTER_THIRD);
			S.Push(Curr);
			Next = { Curr.getA(), Curr.getN() - 1, Curr.getX(), 0, START };
			S.Push(Next);
		}
		else if (Curr.getLine() == AFTER_THIRD)
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


string runAndMeasure(int* A, int n, int x, function<void(int*,int,int)> func,string funcName) {
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);
	func(A, n, x);
	auto end = chrono::high_resolution_clock::now();
	// Calculating total time taken by the program.
	double time_taken =
		chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	
	std::ostringstream output;
	output << "Time taken by function " << funcName << " is : " << fixed
		<< time_taken << setprecision(9) << " sec" << endl;

	return output.str();
}

void saveToFile(string output) {
	ofstream myfile("Measure.txt"); // The name of the file
	myfile << output;
	myfile.close();
}

void exitProgram() {
	cout << "wrong input";
	exit(0);
}

int main() {
	int arrSize = getANativeNum();
	if (arrSize == WRONG_INPUT) exitProgram();
	int* arr = getArr(arrSize);
	if (arr == WRONG_INPUT) exitProgram();
	int sum = getANativeNum();
	if (sum == WRONG_INPUT) exitProgram();

	string output = "";

	cout << "Iterative:\n";
	output += runAndMeasure(arr, arrSize, sum, findSumInIterativeWay, "findSumInIterativeWay");
	cout << "\nRecursive:\n";
	output += runAndMeasure(arr, arrSize, sum, findSumInRecursiveWayInit, "findSumInRecursiveWay");
	cout << "\nRecursion implemented using stack:\n";
	output += runAndMeasure(arr, arrSize, sum, findSumInWithStackInit, "findSumInWithStack");
	saveToFile(output);
}