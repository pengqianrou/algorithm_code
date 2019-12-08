#include<stdio.h>
#define N 100 //定义最大连乘矩阵的个数
/* **m用来存储矩阵的最小数乘次数   **s用来存储最小数乘次数断开的位置k
 */ 
void MatrixChain(int p[],int m[N+1][N+1],int s[N+1][N+1]){
	int n = N; 
    for(int i=1;i<=n;i++)//填对角线，对角线上的元素全部置零 
       m[i][i]=0;
    for(int r=2;r<=n;r++){//r表示斜对角线的层数，从2取到n 
    	for(int i=1;i<=n-r+1;i++){//表示计算第r层斜对角线上第i行元素的值 
    		int j=i+r-1;//j表示当斜对角线层数为r，行下标为i时的列下标 
    		m[i][j]=m[i+1][j]=p[i-1]*p[i]*p[j];//计算当断开位置为i时对应的数乘次数 
    		s[i][j]=i;//断开位置为i 
    		for(int k=i+1;k<j;k++){
    			int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
    			if(t<m[i][j]){
    				m[i][j]=t;
    				s[i][j]=k;//将对应的断开位置k存入s[i][j] 
				}
			}			
		}
	}		
}

void traceback (int i, int j, int s[][N+1]){
	if(i==j){
		printf("A%d",i);
	}else{
		printf("(");
		traceback(i,s[i][j],s);
		traceback(s[i][j]+1,j,s);
		printf(")");
	}
}

int main(){
	int n;
	int q[2*N];
	int p[N+1],flag=1;
	int m[N+1][N+1];
	int s[N+1][N+1];
	printf("请输入矩阵的个数（小于100）:");
	scanf("%d",&n);
	for(int i=0;i<=2*n-1;i++){
		if(i%2==0){
			printf("********************\n");
			printf("请输入A%d的行:",(i/2)+1);
		}
		else{
			printf("请继续输入列:");	
		}
		scanf("%d",&q[i]);
	}
	for(int i=1;i<=2*n-2;i++){
		if(i%2!=0&&q[i]!=q[i+1]){
			flag=0;
			break;
		}
	}
	for(int j=1;j<=n;j++){
		p[j]=q[2*n];
	}
	if(flag!=0){
		p[0]=q[0];
		p[n]=q[2*n-1];
		MatrixChain(p,m,s);
		printf("式子如下：\n");
		traceback(1,n,s);
		printf("\n");
		printf("最小数乘次数为：%d\n",m[1][n]); 
	}
	else{
		printf("这%d个矩阵不能连乘！\n",n);
	}
}
