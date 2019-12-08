#include <iostream>
#include <stdio.h>

using namespace std;

class Queen
{
	friend int nQueen(int);

private:
	bool Place(int k) {
		for (int j = 0; j < k; j++) {
			if (abs(k-j) == abs(x[j]-x[k]) || (x[j] == x[k])) {
				return false;
			}
		}
		return true;
	}
	
	void Backtrack(int t) {
		if (t > this->n) {
			this->sum++;
		} else {
			for (int i = 1; i <= n; i++) {
				x[t] = i;
				if (Place(t)) {
					Backtrack(t+1);
				}
			}
		}
	}

	int n,
		*x;

	long sum;
};

int nQueen(int n) {
	Queen X;

	// Init
	X.n = n;
	X.sum = 0;
	int *p = new int[n+1];
	for (int i = 0; i <= n; i++) {
		p[i] = 0;
	}

	X.x = p;
	X.Backtrack(1);

	delete[] p;

	return X.sum;
}

int main()
{
	int n;
	cout << "请输入Queen个数：" << endl;
	cin>>n;
	cout<<"解法有 "<< nQueen(n) << "种" <<endl;

	return 0;
}
