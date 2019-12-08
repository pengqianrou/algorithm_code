#include<iostream>
#include<algorithm>

using namespace std;

void MatrixChain(int p[],int n,int m[][5],int s[][5])
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


void Traceback1(int i,int j,int s[][5])
{
	if(i==j)
	{
		cout<<"A"<<i;
	}
		
	else
	{
		cout<<"(";
		Traceback1(i,s[i][j],s);
		Traceback1(s[i][j]+1,j,s);
		cout<<")";
	}
}

void Traceback2(int i, int j, int s[][5])
{
	if(i==j)
	{
		return;
	}
	Traceback2(i,s[i][j],s);
	Traceback2(s[i][j]+1,j,s);
	cout<<"Multiply A "<<i<<", "<<s[i][j];
	cout<<" and A "<<(s[i][j]+1)<< ", " <<j<<endl;
}

int main()
{
	int p[5]={8,75,100,12,5};
    int m[5][5],s[5][5];
	MatrixChain(p,4,m,s);
	cout<<"The minimum times of matrix multiplication are:"<<m[1][4]<<endl<<endl;
	cout<<"The optimal calculation order is:";
	Traceback1(1,4,s);
	cout<<endl;
	cout<<"OR"<<endl;
	Traceback2(1,4,s);
	return 0;
}

