@@ -0,0 +1,81 @@
#include <stdio.h>
const int MAX=100;
int n;
int p[MAX+1],m[MAX][MAX],s[MAX][MAX];
void matrixchain()
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
void traceback(int i,int j,int s[MAX][MAX])
{
	if(i==j)
		return;
	traceback(i,s[i][j],s);
	traceback(s[i][j]+1,j,s);
}
//?????????????????? 
//void matrixmultiply(int **a,int **b,int **c,int ra,int ca,int rb,int cb)
//{
//	if(ca!=rb)
//		error("???????");
//	for (int i=0;i<ra;i++)
//	{
//		for (int j=0;j<cb;j++)
//			{
//				int sum=a[i][0]*b[0][j];
//				for(int k=1;k<ca;k++)
//					sum+=a[i][k]*b[k][j];
//				c[i][j]=sum;
//			}
//	} 
//}
int main()
{
	printf("?????????????????????????????????????????????\n");
	scanf("%d",&n);
	for (int i=0;i<=n;i++)
		scanf("%d",&p[i]);
		matrixchain();
		traceback(1,n,s);
		printf("%d\n",m[1][n]);
		printf("\n\n\n");
	for (int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d\t",m[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;i<=n;i++)
		{
			printf("%d\t",s[i][j]);
		}
		printf("\n");
	}
	return 0;
}
