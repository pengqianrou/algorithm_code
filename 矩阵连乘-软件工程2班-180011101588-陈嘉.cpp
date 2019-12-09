#include <iostream>
#include <cstdio>
#include <cstring>
#define x 100
using namespace std;
void muti(int p[],int n,int m[x][x],int s[x][x])
{
	for(int i=1;i<=n;i++)
		m[i][i]=0;
	for(int r=2;r<=n;r++)
	{
		for(int i=1;i<=n;i++)
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

int main()
{
	int p[x],n,m[x][x],s[x][x],t,a,b;
	cout<<"number of martix?(less than 100)"<<endl;
	cin>>n;
	cout<<"number of conlum of every martix"<<endl;
	for(int i=0;i<=n;i++)
		cin>>p[i];
	memset(m,99999,sizeof(m));
	memset(s,0,sizeof(s));
	muti(p,n,m,s);
	cout<<"from ? to ?"<<endl;
	cin>>a>>b;
	cout<<m[a][b];
	return 0;
} 
