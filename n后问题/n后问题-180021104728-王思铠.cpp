#include<iostream>
#define N 1000
using namespace std;
int n;
int x[N];
int sum;
int abs(int a )
{
	return a>0?a:-a;
} 
 
int Place(int k)
{
	int j,a=0;
	for(j=1;j<k;j++){
		if((abs(k-j)==abs(x[k]-x[j])) || (x[j]==x[k]))
		return 0;
	}
	return 1;
}
backtrack(){
	int k=1; 
	x[1]=0;
	while(k>0){
		x[k]+=1;
		while((x[k]<=n)&&!(Place[k]))
		x[k]+=1;
		if(x[k]<=n)
		if(k==n)
		sum++;
		else{
			k++;
			x[k]=0;
		}
		else k--;
	}
}

int nQueen(){
	int i ;
	sum=0;
	for(i=0;i<n;i++)
	x[i]=0;
	backtrack();
	return sum;
}

int main(){
	int a;
	cout<<"请输入女王的数量："<<endl;
	cin>>n;
	a=nQueen();
	cout<<"共找到"<<a<<"组解"<<endl; 
}
