#include<iostream>
#define LEN 6 
using namespace std;
 


void MatrixChain(int *p,int m[][LEN + 1], int s[][LEN + 1]){
    for(int i = 0; i <= LEN; ++i){
        m[i][i] = 0;
    }
    for(int r = 2; r <= LEN; ++r){
        for(int i = 1; i <= LEN - r + 1; ++i){
            int j = i + r - 1;
            m[i][j] = m[i + 1][j] + p[i-1]*p[i]*p[j];  
            s[i][j] = i;
            for(int k = i + 1; k < j; ++k){
                int t = m[i][k] + m[k + 1][j] + p[i-1]*p[k]*p[j];
                if(m[i][j] > t){
                	m[i][j] = t;
                    s[i][j] = k;
                    
                }
            }
        }
    }
}
void TrackBack(int i, int j,int s[][LEN + 1]){
    if(i == j){
        
        return;
    } 
    
    TrackBack(i,s[i][j],s);
    TrackBack(s[i][j] + 1,j,s);
    cout<<"Multiply A"<<i<<","<<s[i][j];
    cout<<"and A"<<(s[i][j]+1)<<","<<j<<endl;
}
int main()
{	
	int p[LEN + 1] ={ 30,35,15,5,10,20,25};
	int m[LEN + 1][LEN + 1] = { 0,0,0};
	int s[LEN + 1][LEN + 1] = { 0,0,0};
    MatrixChain(p,m,s); 
    TrackBack(1,LEN,s);
    cout<<endl;
 
}
