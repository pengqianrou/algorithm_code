#define _CRT_SECURE_NO_WARNINGS

#include<math.h>
#include <stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>

using namespace std;


void matixMultiply(int **a,int **b, int **c,int ra,int ca, int rb, int cb) {
	if (ca != rb) {
		printf("æÿ’Û≤ªø…¡¨≥À\n");
		return;
	}
		
	for (int i = 0; i < ra; i++) {
		for (int j = 0; j < cb; j++) {
			int sum = a[i][0] * b[0][j];
			for (int k = 1; k < ca; k++) {
				sum += a[i][k]*b[k][j];
			}
			c[i][j] = sum;
		}
	}
}


void displayAll(int **array,int row,int column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (j == 0)
				cout << " |\t";
			cout << array[i][j] << "\t";
			if (j == column - 1)
				cout << "|" << endl;
		}
	}
	cout << endl;
}


int** getArray(int row, int column) {
	int** array = (int **)malloc(row * sizeof(int *));
	for (int i = 0; i < row; i++)
	{
		array[i] = (int *)malloc(column * sizeof(int));
	}
	return array;
}


int main() {


	//int** a[4][5], b[5][6], c[4][6]
	int ra = 4, ca = 5, rb = 5, cb = 6,rc=4, cc=6;
	int **a = getArray(ra,ca);
	int **b = getArray(rb, cb);
	int **c = getArray(rc, cc);

	
	int num = 1;
	for (int i = 0; i < ra; i++) {
		for (int j = 0; j < ca; j++) {
			a[i][j] = num;
			num++;
		}
	}

	for (int i = 0; i < rb; i++) {
		for (int j = 0; j < cb; j++) {
			b[i][j] = num;
			num++;
		}
	}

	cout << "a[4][5]£∫" << endl;
	displayAll(a,ra,ca);
	cout << "b[5][6]£∫" << endl;
	displayAll(b, rb, cb);
	matixMultiply(a, b, c, ra, ca, rb, cb);
	cout << "a[4][5]*b[5][6]:" << endl;
	displayAll(c, rc, cc);

	system("pause");
	return 0;
}