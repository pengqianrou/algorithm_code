#include<iostream>
using namespace std;

template<class Type>
int BinarySearch(Type a[],const Type& x,int n)
{
	int left=0;
	int right=n-1;
	while(left<=right)
	{
		int middle=(left+right)/2;
		if(x==a[middle])
		{
			return middle;
		}
		if(x>a[middle])
		{
			left=middle+1;
		}
		else
		{
			right=middle-1;
		}
	}
	return -1;
}

int main()
{
	int m=11;
	int y[8]={1,4,6,7,11,19,34,50};
	int p=BinarySearch(y,m,8);
	if(p!=-1)
	{
		cout<<"Find it , subscript in array is:"<<p<<endl;
	}
	else
	{
		cout<<"The element was not found"<<endl;
	}
	
	return 0;
}
