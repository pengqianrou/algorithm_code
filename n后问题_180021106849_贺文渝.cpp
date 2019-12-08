#include<iostream>
#define N 100
using namespace std;
int n;
int x[N];
int sum;

int abs(int a)
{
	return a>0?a:-a;
} 

bool Place(int k)
{
	int j,a=0;
	for(j=1;j<k;j++){
		if((abs(k-j)==abs(x[k]-x[j])) || (x[j]==x[k]))
		return false;
	}
	return true;
}

void Backtrack(int t)
{
    if(t>n)
    	sum++;
    else{
    	for(int i=1; i<=n; i++){
    		x[t] = i;
    		if(Place(t))
    			Backtrack(t+1);
    	}
    }
}

int nQueen(int n){
	sum=0;
	for(int i=0;i<n;i++)
		x[i]=0;
	Backtrack(1);
	return sum;
}

int main(){

	cout<<"Please enter the number of queens£º"<<endl;
	cin>>n;
	cout<<"result:"<<nQueen(n)<<endl; 
}
