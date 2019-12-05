#include<stdio.h> 
#include<iostream>
using namespace std;
const int maxn=105;
int p[maxn];
int m[maxn][maxn];
int s[maxn][maxn];
int n;

void matrixChain(){ /*计算最优值*/
    for(int i=1;i<=n;i++){
    	m[i][i]=0;
    	for(int r=2;r<=n;r++){
            for(int i=1;i<=n-r+1;i++){
                int j=r+i-1;
                m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
                s[i][j]=i;
                for(int k=i+1;k<j;k++){
                	int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                    if(t<m[i][j]){
                        m[i][j]=t;
                        s[i][j]=k;
                    }
                }
            }
        }
	}
}
void trackBack(int i,int j){/*求最优计算次序,从1~n-1*/
    if(i==j) return;
    trackBack(i,s[i][j]);
    trackBack(s[i][j]+1,j);
    printf("A[%d:%d]*A[%d:%d]\n",i,s[i][j],s[i][j]+1,j);
}

int main(){
    while(~scanf("%d",&n)){
    	for(int i=0;i<n;i++){
            scanf("%d",&p[i]);
        }
    matrixChain();
    trackBack(1,n-1);/*矩阵连乘最优计算次序*/
    printf("%d\n",m[1][n-1]);/*最少次数的乘法*/
    }
    return 0;
}
    
        
    
