
#include <iostream> 
#include <stdlib.h>
using namespace std; 


int MatrixChain(int *p,int n,int **m,int **s); 
void Traceback(int i,int j,int **s);
void Traceback1(int i,int j,int **s); 
int main()
{ 
	int n ;
	cout<<"输入矩阵的个数：" ;
	cin>>n; 
	int p[n+1]; 
	cout<<"输入各矩阵的行列参数："<<endl;
	for(int i=0;i<n+1;i++)
	{
		cin>>p[i];
	}
    int **s = new int *[n+1];
	int **m = new int *[n+1];
	for(int i=0;i<=n;i++)  
    {  
		s[i] = new int[n+1];
		m[i] = new int[n+1];
    } 
	cout<<"矩阵的最少计算次数为："<<MatrixChain(p,n,m,s)<<endl;
	cout<<"矩阵最优计算次序为："<<endl;
	Traceback(1,6,s);
	system("pause");
	return 0;
}

int MatrixChain(int *p,int n,int **m,int **s)
{
	for(int i=1; i<=n; i++)
	{
		m[i][i] = 0;
	}
	for(int r=2; r<=n; r++) //r为当前计算的链长（子问题规模）  
	{
		for(int i=1; i<=n-r+1; i++)//n-r+1为最后一个r链的前边界  
		{
			int j = i+r-1;//计算前边界为r，链长为r的链的后边界  

			m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];//将链ij划分为A(i) * ( A[i+1:j] ) 

			s[i][j] = i;

			for(int k=i+1; k<j; k++)
			{
				//将链ij划分为( A[i:k] )* (A[k+1:j])   
				int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(t<m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
	return m[1][n];
}

void Traceback(int i,int j,int **s)
{
	if(i==j) return;
	Traceback(i,s[i][j],s);
	Traceback(s[i][j]+1,j,s);
	cout<<"Multiply A"<<i<<","<<s[i][j];
	cout<<" and A"<<(s[i][j]+1)<<","<<j<<endl;
}
