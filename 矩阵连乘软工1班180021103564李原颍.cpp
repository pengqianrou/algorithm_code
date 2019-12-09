#include <iostream>
using namespace std;
#define N 6

//计算最优值 
void MatrixChain(int p[],int n,int m[N][N],int s[N][N])
{
    for(int i=0;i<n;i++)
	{
		m[i][i]=0;
		s[i][i]=0;
	}
    for(int r=1;r<n;r++)
    {
        for(int i=0;i<n-r;i++)
        {
            int j=i+r;
            m[i][j]=m[i][i]+m[i+1][j]+p[i]*p[i+1]*p[j+1];
            s[i][j]=i;
            for(int k=i+1;k<j;k++)
            {
                int t=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
                if(t<m[i][j]){
                    m[i][j]=t;
                    s[i][j]=k;
                }
            }
        }
    }
}
 
//计算最优解
void Traceback(int i,int j,int s[N][N])
{
    if(i==j)
		return;
    Traceback(i,s[i][j],s);
    Traceback(s[i][j]+1,j,s);
    cout<<"Multiply A "<<i<<","<<s[i][j];
    cout<<" and A "<<(s[i][j]+1)<<","<<j<<endl;
}
 
 
int main()
{
    int p[]={30,35,15,5,10,20,25};
    int m[N][N];
	int s[N][N];
    MatrixChain(p,N,m,s);
    cout<<m[0][5]<<endl;
    Traceback(0,5,s);
    cout<<endl;
    return 0;
}

