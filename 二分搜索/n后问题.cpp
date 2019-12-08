#include <iostream>
#include<math.h>
#include<cmath>
#include<cstdio>
using namespace std;
int x[100];
int count;
int n;

	int Place(int t){
		for(int i=1;i<t;i++) 
	
		 {
			if((abs(x[t]-x[i])==abs(t-i))||(x[t]==x[i])) 
			return 0;
			}
			return 1;
	}
	
	void BackTrack(int t){
		if(t>n){
				count++;
				cout<<"放法"<<count<<" 放的位置是  ";
			for(int i=1;i<=n;i++) 
				cout<<x[i]<<" ";
				cout<<endl; 
	}
		else{
			for(int i=1;i<=n;i++){
				x[t]=i;
				if(Place(t)==1)
				BackTrack(t+1); 
			}
		}
	}
	
    int main(){
		count=0;
    	cout<<"皇后数量为"<<endl;
    	cin>>n;
    	BackTrack(1); 
   		return 0;
	}

