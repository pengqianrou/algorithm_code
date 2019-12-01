#include <iostream>

using namespace std;

extern void binarySearch(double* a, int l, int r, double x);

int main(){
	
	//二分搜索算法
	double* a = new double[5] { 2, 4, 24, 57, 90 };
	int l = 0, r = 4;
	double x1 = 57, x2 = 8;
	cout << "二分搜索：" << endl;
	binarySearch(a, l, r, x1);
	binarySearch(a, l, r, x2);

	return 0;
}

