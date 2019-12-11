//3.1 矩阵连乘问题
#include<iostream>

using namespace std;

/**
* 矩阵连乘
*
*@param p 各矩阵的列数(除p[0]为第一个矩阵的行数) 
*@param n 矩阵个数 
*@param m[i][j]表示第i个矩阵到第j个矩阵最优方案时所需最少的数乘次数 
*@param s[i][j]表示第i个矩阵到第j个矩阵数乘次数最少时的断点位置 
*@return 
*/ 
void MatrixChain(int *p, int n, int (*m)[7], int (*s)[7])
{
	for(int i=1; i<=n; i++)
	{
		m[i][i]=0; //将对角线元素置为0
		s[i][i]=0; //断点位置设置为0	
	}
	
	for(int r=2; r<=n; r++) //r是段长 
	{
		for(int i=1; i<=n-r+1; i++) //i是段的起点 
		{
			int j=i+r-1; //j是段的终点 
			m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j]; 
			s[i][j] = i;
			
			for(int k=i+1; k<j; k++) //在k处分裂，遍历各种情况 
			{
				int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				
				if(t<m[i][j]) //如果本次结果t 比 历史上的最优结果 
				{
					//更新数乘次数和断点位置 
					m[i][j] = t;  
					s[i][j] = k;  
				}
			}
		}
	}
}

int main()
{
	int p[7] = {30,35,15,5,10,20,25};
	int n = 6;
	int m[7][7], s[7][7]; 
	
	MatrixChain(p, n, m, s);
	
	cout<<"m[][]的结果"<<endl; 
	for(int i=1;i<6;i++){
		for(int j=i;j!=1;j--)
			cout<<"\t";
			
		for(int j=i;j<=6;j++){
			cout<<m[i][j]<<"\t";	
		}		
		cout<<endl;
	}
	
	cout<<"s[][]的结果"<<endl; 
	for(int i=1;i<6;i++){
		for(int j=i;j!=1;j--)
			cout<<"\t";
			
		for(int j=i;j<=6;j++){
			cout<<s[i][j]<<"\t";	
		}		
		cout<<endl;
	}
	
	return 0;
}
