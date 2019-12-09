#include <iostream>
#include <iomanip>
#include <memory.h>
using namespace std;
 
void MatrixChain( int p[],int n,int m[][7],int s[][7])
{
    int i,j,k,r,t;
    for( i = 1 ; i <= n ; ++i ) m[i][i]=0;
    for( r = 2 ; r <= n ; ++r ) {
        for( i = 1 ; i <= n-r+1 ; ++i ) {
            j = i+r-1;
            m[i][j] = m[i+1][j]+p[i-1]*p[i]*p[j];
            s[i][j] = i;
 
            // 和所有结合的情况比较，取最小的存入m[i][j]
            for( k = i+1 ; k < j ; ++k )    {
                t = m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if( t < m[i][j] )   {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}
 
void Traceback( int i , int j , int s[][7] )
{
    if( i == j )    return;
    Traceback(i,s[i][j],s);
    Traceback(s[i][j]+1,j,s);
    cout<<"Mul A"<<i<<","<<s[i][j];
    cout<<" and A"<<(s[i][j]+1)<<","<<j<<endl;
}
 
// 矩阵乘法 ra,ca为矩阵a的行列，rb,cb为矩阵b的行列
void matrixMultiply(int** a,int** b,int** c,int ra,int ca,int rb,int cb)
{
    // 检测两个矩阵是否可以相乘
    if( ca != rb )  return;
 
    for( int i = 0 ; i < ra ; ++i ) {
        for( int j = 0 ; j < cb ; ++j ) {
            int sum = a[i][0] * b[0][j];
            for( int k = 1 ; k < ca ; ++k )
                sum += a[i][k] * b[k][j];
            c[i][j] = sum;
        }
    }
}
