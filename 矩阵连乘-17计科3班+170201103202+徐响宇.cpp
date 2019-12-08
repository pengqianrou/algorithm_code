#include<stdio.h>
#define N 20
void MatrixChain(int p[N],int n,int m[N][N],int s[N][N])
{
	for(int i=1;i<=n;i++)
		m[i][i]=0;
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

int main()
{
	int n,n1,m1,i,j=2;
	int p[N]={0};
	int m[N][N]={0};
	int s[N][N]={0};
	printf("请输入矩阵个数：\n");
	scanf("%d",&n);
	for(i=1;i<n+1;i++)
	{
		printf("请输入第%d个矩阵的行和列(n1*m1格式):",i);
		scanf("%d*%d",&n1,&m1); 
    	if(i==1)
		{ 
      		p[0]=n1; 
      		p[1]=m1; 
    	} 
    	else
		{ 
     		p[j++]=m1; 
    	} 
  	} 
  	printf("\n记录矩阵行和列:\n"); 
  	for(i=0;i<=n;i++)
	{ 
    	printf("%d ",p[i]); 
  	} 
  	printf("\n"); 
  	MatrixChain(p,n,m,s); 
  	printf("\n矩阵相乘的最小次数矩阵为:\n"); 
  	for(i=1;i<=n;i++)
	{ 
      	for(j=1;j<=n;j++)
		{ 
      		printf("%d  ",m[i][j]); 
    	} 
    	printf("\n"); 
  	} 
  	printf("\n矩阵相乘断开的位置矩阵为:\n"); 
  	for(i=1;i<=n;i++)
	{ 
    	for(j=1;j<=n;j++)
		{ 
      		printf("%d ",s[i][j]); 
    	} 
    	printf("\n"); 
  	} 
  	printf("矩阵最小相乘次数为:%d\n",m[1][n]); 
  	return 0; 
	
}
