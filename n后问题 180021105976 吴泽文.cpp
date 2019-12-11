
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include<cmath> 
using namespace std;

int c[20];
int n;

void OP(int n){
	int i;
	for(i=1;i<=n;i++){
		cout<<c[i];
	}
	cout<<endl;
}
 
 int place(int t,int r){
 	int i=1;
 	while(i<r){
 		if(t==c[i]||abs(r-i)==abs(t-c[i]))
 			return 0;
 		++i;	
 	}
 	return 1;
 }
 
 void queen(int m){
 	int i;
 	for(i=1;i<=n;i++){
 		c[m]=i;
 		if(place(i,m)){
 			if(m==n)
 				OP(n);
 			else
			  queen(m+1);	
 		}
 	}
 }
 
 int main(){
 	cout<<"请输入皇后个数：";
	 cin>>n;
	 if(n>20){
	 	cout<<"数值过大，请输入20以内数字：";
	 	cin>>n; 
	 } 
	 queen(1);
	 system("pause");
	 return 0;
 }
