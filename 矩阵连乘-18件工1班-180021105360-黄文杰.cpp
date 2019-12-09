#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
# define N 105

void MatrixChain(int p[], int n, int m[][N], int s[][N])
{
	for(int i=1;i<=n;i++)
	{
		m[i][i]=0;
	}
	for(int r=2;r<=n;r++)
	{ 
		for(int i=1;i<=n-r+1;i++)
		{
			int j=i+r-1;
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;
			for(int k=i+1;k<j;k++)
			{
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j])
				{
					m[i][j]=t; 
					s[i][j]=k;
				}
			}
		}
	}
}


void Traceback(int i, int j, int s[][N])
{
	if(i==j)
		cout << "A" << i;
	else
	{
		cout << "(";
		Traceback(i,s[i][j],s);
		Traceback(s[i][j]+1,j,s);
		cout << ")";
	}
}

int main()
{
	int p[N*10];//存储第一个矩阵的行数，以及其他矩阵的列数 p[0]为第一个行数 
	int m[N][N];//存储最优结果
	int s[N][N];//存储当前结构的最优断点
	cout << "请输入矩阵的个数：";
	int n;
	int flag=1;
	while(cin >> n)
	{
		memset(p,0,sizeof(p));
		memset(m,0,sizeof(m));
		memset(s,0,sizeof(s));

		for(int i=0;i<n;i++)
		{
			cout << "请输入第" << i+1 << "个矩阵的行和列：";
			if(i==0)
			{
				cin >> p[0] >> p[1];//第一个矩阵的行和列 
			}
			else
			{
				int a,b;
				cin >> a >> b;
				if(a!=p[i])
				{
					cout << "矩阵不可乘" << endl;
					flag=0;
					break;
				}
				p[i+1]=b;
			}
		}
		if(flag)
		{
			MatrixChain(p,n,m,s);
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i>j)
						cout << "\t";
					else
						cout << m[i][j] << "\t";
				}
				cout << endl;
			}
			cout << endl;
			cout << "矩阵相乘的最少数乘次数为：" << m[1][n] << endl;
			cout << endl << "最佳数乘方式顺序：" << endl;
			Traceback(1,n,s);
			cout << endl << endl;
		}
		cout << "请输入矩阵的个数：";
	}
	return 0;
}
