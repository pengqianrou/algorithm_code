#include<iostream>
#include <stdlib.h>

using namespace std;

bool Place(int *ar,int k){
	for(int j = 1;j<k;++j)
	{
		if(ar[k] == ar[j] || abs(k-j) == abs(ar[k] - ar[j]))
		{
			return false;
		}

	}
	return true;
}
int num = 0;
void nQueue(int *ar,int k,int n){
	if(k > n){
		num+=1;
	for(int j = 1;j <= n;++j){
		for(int j = 1;j <= n;++j){
			if(ar[j] == i)
			cout<<"@ ";
			else
			cout<<"# ";
		} 
		cout<<endl;
	}
	cout<<endl;
	}
	else{
	for(int i = 1;i<=n;++i){
		ar[k] = i;
		if(Place(ar,k)){
			nQueue(ar,k+1,n);
			} 
		}
	} 
} 
int main(){
	const int n = 4;
	int ar[n+1]={0,0,0,0,0};
	nQueue(ar,1,n);
	cout<<num<<endl;
	return 0;
}
