#include<stdio.h>
#include<math.h>
int n;
int x[100];
int sum;

bool place(int k){
	int j;
	if((abs(k=j)==abs(x[j]-x[k]))||(x[j]==x[k]))
	return false;
	return true;
}
void backtrack(int t){
	int i;
	if(t>n) sum++;
	else{
		for(i=1;i<n;i++){
			x[t]=i;
			if(place(t))
			backtrack(t+1);
		}
	}
}
int nqueen(){
	for(int i=0;i<=n;i++){
		x[i]=0;
	}
	backtrack(1);
	return sum;
}

int main(){
	int xx;
	printf("input n ");
	scanf("%d",&n);
	xx=nqueen();
	printf("%d",xx);
	return 0;
}
