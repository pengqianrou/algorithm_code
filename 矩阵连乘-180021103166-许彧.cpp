#include<iostream>
using namespace std;
void MatrixChain(int *p,int m[][7],int s[][7]){
    for(int i=0;i<=6;i++){
        m[i][i] = 0;
    }
    for(int r=2; r<=6;r++){
        for(int i=1;i<=6-r+1;i++){
            int j=i+r-1;
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
void TraceBack(int i,int j,int s[][7]){
    if(i==j){
        cout<<"A"<<i;
        return;
    } 
    cout<<"(";
    TraceBack(i,s[i][j],s);
    cout<<")(";
    TraceBack(s[i][j]+1,j,s);
    cout<<")";
}
int main()
{
	int p[7]={ 30,35,15,5,10,20,25};
	int m[7][7]={0,0,0};
	int s[7][7]={0,0,0};
    MatrixChain(p,m,s); 
    TraceBack(1,6,s);
    cout<<endl;
}
