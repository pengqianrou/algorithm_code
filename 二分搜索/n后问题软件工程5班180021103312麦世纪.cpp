#include <stdio.h>
 
#define N 4 //4皇后 
#define M N-1
 
int Num = 0; //Num为解的个数
 
int attack(int a[][N], int i, int j) //attack函数模拟(i,j)位置上的皇后能否攻击到其他皇后。若是可以攻击到函数返回0，否则返回1。
{
	int n,m;
	for(n = 0; n < N; n ++) //列检测 
	{
		if(n == i)
			continue;
		if (a[n][j] != 0)
			return 0;
	}
	if(i != M && j != M) //检测a[i][j]是否在右下边界 
		for(n = i + 1, m = j + 1; n != N && m != N; n ++, m ++)	  // 右下对角线检测	
			if(a[n][m] != 0)
				return 0;
	if(i != 0 && j != 0) //检测a[i][j]是否在左上边界 
		for(n = i - 1, m = j - 1; n != -1 && m != -1; n --, m --) // 右上对角线检测	
			if(a[n][m] != 0)
				return 0;
	if(i != M && j != 0) //检测a[i][j]是否在左下边界 
		for(n = i + 1, m = j - 1; n != N && m != -1; n ++, m --)  // 左下对角线检测
			if(a[n][m] != 0)
				return 0;
	if(i != 0 && j != M) //检测a[i][j]是否在右上边界 
		for(n = i - 1, m = j + 1; n != -1 && m != N; n --, m ++)  // 左上对角线检测
			if(a[n][m] != 0)
				return 0;
	return 1;
}
 
void put (int a[][N])
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}
 
void BT (int a[][N], int i)
{
	int j;
	if(i == N)
	{
		Num ++;
	}
	else
		for(j = 0 ; j < N; j ++)
		{
			a[i][j] = 1;
			if(attack(a,i,j) == 1)
				BT(a,i+1);
			a[i][j] = 0;
		}
}
 
int main ( void )
{
	int a[N][N] = {};
	BT(a,0);
	printf("Num = %d\n",Num);
	return 0;
}

