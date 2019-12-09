#include <iostream>
using namespace std;
void matrixMultiply(int (*a)[3],int (*b)[2],int (*c)[2],int ra,int ca,int rb,int cb)
{
	if(ca!=rb)
		cout<<"¾ØÕó²»¿É³Ë";
	for(int i=0;i<ra;i++)
		{
			for(int j=0;j<cb;j++)
				{
					int sum=a[i][0]*b[0][j];
					for(int k=1;k<ca;k++)
						sum+=a[i][k]*b[k][j];
					c[i][j]=sum;
				}
		}
 } 
 
int main(){
	int a[2][3] = {{1,2,3},{4,5,6}};
	int b[3][2]={{1,3},{5,7},{2,4}};
	int c[2][2];
	matrixMultiply(a,b,c,2,3,3,2);
	for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
				cout<<c[i][j]<<"\t";
			cout<<endl;
		}
	return 0;
}
