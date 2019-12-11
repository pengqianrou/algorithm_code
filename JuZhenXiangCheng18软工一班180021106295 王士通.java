package homework;

public class Homework {
	 
	 
	public static void main(String[] args) {
		final int N = 5;
		int a[][] = new int[N][N];
		int b[][] = new int[N][N];
		int c[][] = new int[N][N];

		for(int i = 0;i<a.length;i++)
		{
			for(int j = 0;j<a[i].length;j++)
			{
				a[i][j] = (int)((Math.random()*10000)%11+5);
			}
		}

		for(int i = 0;i<b.length;i++)
		{
			for(int j = 0;j<b[i].length;j++)
			{
				b[i][j] = (int)((Math.random()*10000)%11+5);
			}
		}

		for(int i = 0;i<a.length;i++)
		{
			for(int j = 0;j<a.length;j++)
			{
				for(int k = 0;k<a.length;k++)
				{
					c[i][j] += a[i][k]*b[k][j];
				}
			}
		}

		System.out.println("Êä³ö¾ØÕóa£º");
		for(int i = 0;i<a.length;i++)
		{
			for(int j = 0;j<a.length;j++)
			{
				System.out.printf("%d",a[i][j]);
				if(j == 4)
				{
					System.out.println();
				}
				else
				{
					System.out.print(",");
				}
			}
		}

		System.out.println("Êä³ö¾ØÕób£º");
		for(int i = 0;i<b.length;i++)
		{
			for(int j = 0;j<b.length;j++)
			{
				System.out.printf("%d",b[i][j]);
				if(j == 4)
				{
					System.out.println();
				}
				else
				{
					System.out.print(",");
				}
			}
		}

		System.out.println("Êä³ö¾ØÕóÏà³ËµÃµ½µÄ¾ØÕóc£º");
		for(int i = 0;i<c.length;i++)
		{
			for(int j = 0;j<c.length;j++)
			{
				System.out.printf("%d",c[i][j]);
				if(j == 4)
				{
					System.out.println();
				}
				else
				{
				System.out.print(",");
				}
			}
		}		
	}
}
