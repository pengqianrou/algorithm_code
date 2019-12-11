#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <cstring>
using std::cout;
using std::endl;
using std::cin;

class Queen {
	friend int nQueen(int);

	bool Place(int k) {
		for (int j = 1; j < k; ++j)
			if ((abs(k-j) == abs(x[j] - x[k])) || (x[j] == x[k]))
				return false;
		return true;
	}
	void Backtrack(int t) {
		if (t > n)
			sum++;
		else {
			for (int i = 1; i <= n; ++i) {
				x[t] = i;
				if (Place(t)) Backtrack(t+1);
			}
		}
	}
	int n, *x; // n皇后个数 x当前解
	long sum; // 当前已找到的可行方案数
};
int nQueen(int n) {
	Queen X;
	X.n = n, X.sum = 0;
	int *p = new int[n+1];
	for (int i = 0; i <= n; ++i) p[i] = 0;
	X.x = p;
	X.Backtrack(1);
	delete[] p;
	return X.sum;
}

int main() {
	int n;
	cin >> n; // 输入n后
	cout << nQueen(n); // 输出解数
	return 0;
}