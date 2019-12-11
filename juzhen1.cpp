#include<iostream>;
using namespace std;

int main() {
	int sum = 0;

	int a[2][3] = { {1,2,3} ,{5,6,7} };
	int b[3][3]= { {2,3,5},{13,45,23},{14,35,42} };	
	int ra = 2;
	int ca = 3;
	int rb = 3;
	int cb = 3;
	
	int c[3][3] = {0} ;
	if (ca != rb)
		cout << "¾ØÕó²»¿É³Ë";
	for (int i = 0; i < ra; i++) {
		for (int j = 0; j < cb; j++) {
			 sum = a[i][0] * b[0][j];
			for (int k = 1; k < ca; k++) {
				sum += a[i][k] * b[k][j];
			}
			c[i][j] = sum;
		}
	}
	cout << sum;

	return 0;
}