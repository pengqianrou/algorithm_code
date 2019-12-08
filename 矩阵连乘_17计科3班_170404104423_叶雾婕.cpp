#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int MAX = 100;
int n;
int p[MAX+1], m[MAX][MAX], s[MAX][MAX];
//p用来记录矩阵，m[i][j]表示第i个矩阵到第j个矩阵的最优解，s[][]记录从哪里断开可以得到最优解 


void MatrixChain(int *p, int n, int **m, int **s
{
	for (int i = 1; i <= n; i++) m[i][i]=0; 
	for (int r = 2; r <= n; r++)
	{ 
		for (int i = 1; i <= n-r+1; i++)
		{
			int j = i+r-1;
			m[i][j] = m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j] = i;
			for (int k = i+1; k < j; k++)
			{
				int t = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			 } 
		}
	} 
 } 
 
void traceback(int i, int j)
{
	if (i==j)
		return;
	traceback(i, s[i][j]);
	traceback(s[i][j]+1; j);
	cout<<"Multiply A"<<i<<","<<s[i][j]<<"and A"<<s[i][j]+1<<","<<j<<end;
 }
 
 int main()
 {
 	cin>>n;
 	for(int i = 0; i <= n; i++) cin>>p[i];
 	MatrixChain();
 	traceback(1,n);
 	cout<<m[1][n]<<endl;
 	return 0;
  } 
