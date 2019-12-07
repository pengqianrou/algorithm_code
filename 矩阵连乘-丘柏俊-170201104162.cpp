#include<iostream>
using namespace std;

const int N=7;
void MatrixChain(int *p,int m[N][N],int s[N][N],int n)
{		
	int r,i,j,k,t=0;	//m[i][i]只有一个矩阵，所以相乘次数为0，即m[i][i]=0;	
	for(i=1;i<=n;i++)	
	{		
		m[i][i]=0;//对角线位置	
	}
	for(int r=2;r<=n;r++)//l=2为对角线紧邻的右上位置，随着l的增大，即沿着右上角的方向递增，扩大链的长度	
	{		
		for(i=1;i<=n-r+1;i++)		
		{			
			j=i+r-1; //以i为起始位置，j为长度为l的链的末位，			
			m[i][j]=m[i+1][j]+p[i-1]+p[i]*p[j];			//k从i到j-1,以k为位置划分
			s[i][j]=i;			
			for(k=i+1;k<j;k++){				
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];				
				if(t<m[i][j]){					
					m[i][j]=t;					
					s[i][j]=k;				
				}			
			}		
		}	
	}	
	cout << m[1][N-1] << endl;
}

void PrintAnswer(int s[N][N],int i,int j){	
	if(i==j)//只有一个矩阵，直接输出	
	{		
		cout<<"A"<<i;	}
	else//是否需要再添加一种情况：两个矩阵，加括号输出？？	
	{		
	cout<<"(";	
	PrintAnswer(s,i,s[i][j]);//递归，从得到最优解的地方开始s[i][j]处断开		
	PrintAnswer(s,s[i][j]+1,j);		
	cout<<")";	
	}
}

int main()
{
	int p[N]={30,35,15,5,10,20,25};
	int m[N][N],s[N][N];
	MatrixChain(p,m,s,N);
	PrintAnswer(s,1,N-1);
	return 0;
}
