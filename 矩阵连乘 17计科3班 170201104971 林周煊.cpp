#include<iostream>
#include<stdio.h> 
using namespace std;

int p[100],m[100][100],s[100][100];
int n;

void MatrixChain()
{
	for(int i=1;i<=n;i++){
		m[i][i]=0;
	for(int r=2;r<=n;r++){
		for(int i=1;i<=n-r+1;i++){
			int j=i+r-1;
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;
			for(int k=i+1;k<j;k++){
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if (t<m[i][j]){
					m[i][j]=t;
					s[i][j]=k;
				}	
			}	
		}
		}	
	}
}
void Traceback(int i,int j)
{
	if(i==j)
		return;
	Traceback(i,s[i][j]);
	Traceback(s[i][j]+1,j);
	cout<<"Multiply A"<<i<<","<<s[i][j];
	cout<<"and A"<<s[i][j]+1<<","<<j<<endl;
} 
int main()
{
	int i;
	int j;
	cout<<"请输入矩阵的数量："<<endl;
	cin>>n;
	cout<<"请输入所有矩阵的行和最后一个矩阵的列："<<endl;
	for(i=0;i<=n;i++)
		{	
		cin>>p[i];
		}
	MatrixChain();
	Traceback(1,n);
	cout<<m[1][n]<<endl;
	return 0;
}
