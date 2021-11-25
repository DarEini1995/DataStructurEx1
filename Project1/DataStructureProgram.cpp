#include <stdio.h>
#include <stdlib.h>


#define _CRT_SECURE_NO_WARNINGS


void findSumInrecursiveWay(int* A, int n, int x, int y) {
	if ((n == 1) && (y!=0)) {
		if (x = A[0] + y) {
			printf("%d %d", y, A[0]);
		}
		else if ((n == 1) && (y == 0)) {
			printf("");
		}
		
		else if (n != 1) {
			if (y!=0)
			{
				if (x = A[n - 1] + y) {
					printf("%d %d", y, A[n - 1]);
				}
				findSumInrecursiveWay(A, n - 1, x, y);
			}
			else {
				findSumInrecursiveWay(A, n-1, x, A[n - 1]);
				findSumInrecursiveWay(A, n-1,x, 0);
			}
	}
	}

}


void findSumInIterativeWay(int * nativeNumbers, int n, int x) {
	for (int i = 0; i < n-1; i++) {
		if (nativeNumbers[i] + nativeNumbers[i + 1] == x)
			printf("%d %d", nativeNumbers[i], nativeNumbers[i + 1]);
	}
}

int main() {
	int n;
	//scanf("%d", &n);



	//test
	int arr[5] = { 1,2,3,4,5};
	int size = 5;
	int x = 3;
	findSumInIterativeWay(arr, size, x);
	
}