#include <iostream>
using namespace std;

const int N = 7;

void MatrixChain(int *p, int m[N][N], int s[N][N], int n){
	for(int i = 1; i <= n; i++){
		m[i][i] = 0;
	}
	for(int r = 2; r <= n; r++){
		for(int i = 1; i <= n - r + 1;i++){
			int j = i + r -1;
			m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];
			s[i][j] = i;
			for(int k = i + 1;k < j;k++){
				int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(t < m[i][j]){
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
}
void Traceback(int s[N][N],int i, int j){
	if(i == j)
	return;
	Traceback(s,i,s[i][j]);
	Traceback(s, s[i][j]+1,j);
	cout << "Multiply A" << i << ", " << s[i][j];
	cout << "and A" << (s[i][j] + 1) << ", " << j << endl;	 
}
int main()
{
	int p[N]={30,35,15,5,10,20,25};
	int m[N][N],s[N][N];
	MatrixChain(p,m,s,N);
	Traceback(s,1,N-1);
	return 0;
}
