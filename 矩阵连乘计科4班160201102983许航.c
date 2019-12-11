/*计科4班 许航 矩阵连乘*/
#include <limits.h> 
#include <stdio.h> 

int MatrixChainOrder(int p[], int i, int j) 
{ 
	if (i == j) 
		return 0; 
	int k; 
	int min = INT_MAX; 
	int count; 

	for (k = i; k < j; k++) { 
		count = MatrixChainOrder(p, i, k) + 
				MatrixChainOrder(p, k + 1, j) + 
				p[i - 1] * p[k] * p[j]; 

		if (count < min) 
			min = count; 
	} 

	//返回最小值
	return min; 
} 

// 测试函数
int main() 
{ 
	int arr[] = { 1, 2, 3, 4, 3 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	printf("Minimum number of multiplications is %d ", 
		MatrixChainOrder(arr, 1, n - 1)); 

	getchar(); 
	return 0; 
} 
