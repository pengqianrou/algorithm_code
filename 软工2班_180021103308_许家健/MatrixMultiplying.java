/*
 *许家健 180021103308 软件工程二班
 * 利用动态规划解决矩阵连乘的问题
 */
package dynamicProgramming;

public class MatrixMultiplying {
	public static void MatrixChain(int[] p,int n, int[][] m, int[][] s) {
		   for (int i = 1; i <= n; i++) {
		     m[i][i] = 0;
		   }
		    for(int r = 2;r <= n; r++ ) {
		      for(int i = 1; i <= n-r+1; i++) {
		        int j = i+r-1;										//j是为了使二维参数往矩阵右下角求值的列变量
		        m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];				//得到最开始位置的矩阵乘积次数，此位置可能为最少数乘次数
		        s[i][j] = i;										//得到初始次序的断开位置
		        for(int k = i+1; k < j; k++) {
		          int t = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];	//通过i+1逐渐把断开位置右移，再次计算矩阵数乘次数，此位置可能为最少数乘次数
		          if(t < m[i][j]) {									//比较当前值与前面存储的值，是否为最少数乘次数
		            m[i][j] = t;									//是则获得最优数乘次数
		            s[i][j] = k;									//是则获得最优断开位置
		          }
		        }
		      }
		    }
		  }
		  public static void Traceback(int i, int j, int[][] s) {
		    if(i == j) return;
		    Traceback(i,s[i][j],s);
		    Traceback(s[i][j] + 1,j,s);
		    System.out.println("Multiply  A" + i + "," + s[i][j] + "and A" + (s[i][j] + 1) + "," + j);
		  }
		  public static void main(String[] args) {
			System.out.println("运行结果为：");
		    MatrixMultiplying mc = new MatrixMultiplying();
		    int n = 7;
		    int p[] = { 30, 35, 15, 5, 10, 20, 25 };
		    int m[][] = new int[n][n];
		    int s[][] = new int[n][n];
		    int l = p.length-1;
		    mc.MatrixChain(p, l,m, s);
		    for (int i = 1; i < n; i++) {							//打印m[i][j]的矩阵相乘次数矩阵
		      for (int j = 1; j < n; j++) {
		        System.out.print(m[i][j] + "\t");
		      }
		      System.out.println();
		    }
		    System.out.println();
		    for (int i = 1; i < n; i++) {							//打印s[i][j]最优次序的断开位置矩阵
		      for (int j = 1; j < n; j++) {
		        System.out.print(s[i][j]+" ");
		      }
		      System.out.println();
		    }
		    mc.Traceback( 1, 6, s);									//按照断开位置矩阵加括号输出最优计算次序
		  }
	
	
	
	}


