#include<iostream>
using namespace std;
 
const int N=5;

void MatrixChainOrder(int *p,int n,int m[N][N],int s[N][N])
{
	for(int i=1;i<=n;i++)
		m[i][i]=0; //对角线
	for(int r=2;r<=n;r++)   //段长从2开始到n为止 
	{
		for(int i=1;i<n-r+1;i++)  //最后一个段的起点为n-r+1 
		{
			int j=i+r-1;  //段的终点 
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];  
			s[i][j]=i; 
			for(int k=i+1;k<j;k++)
			{
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j]){
					m[i][j]=t;
					s[i][j]=k;
				}
			}
		}
	} 
	
	
 } 
void PrintAnswer(int s[N][N],int i,int j)
{
    if(i==j)
    {
        cout<<"A"<<i;
    }
    else
    {
        cout<<"(";
        PrintAnswer(s,i,s[i][j]);
        PrintAnswer(s,s[i][j]+1,j);
        cout<<")";
    }
}
int main()
{
    int p[N]={3,5,8,4,2};
    int m[N][N],s[N][N];
    MatrixChainOrder(p,N,m,s);
    PrintAnswer(s,1,N-1);
    return 0;
}
