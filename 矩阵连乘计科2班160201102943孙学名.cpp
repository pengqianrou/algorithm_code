#include <iostream> 
#include <stdlib.h>

using namespace std;

const int L = 7;

int MatrixChain(int n, int** m, int** s, int* p);

int main()
{

	int p[L] = { 10,15,15,5,10,20,25 };

	int** s = new int* [L];
	int** m = new int* [L];
	for (int i = 0; i < L; i++)
	{
		s[i] = new int[L];
		m[i] = new int[L];
	}

	cout << "矩阵的最少计算次数为：" << MatrixChain(6, m, s, p) << endl;

	return 0;
}

int MatrixChain(int n, int** m, int** s, int* p)
{
	for (int i = 1; i <= n; i++)
	{
		m[i][i] = 0;
	}
	for (int r = 2; r <= n; r++)
	{
		for (int i = 1; i <= n - r + 1; i++)
		{
			int j = i + r - 1;

			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];

			s[i][j] = i;

			for (int k = i + 1; k < j; k++)
			{

				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
	return m[1][L - 1];
}
