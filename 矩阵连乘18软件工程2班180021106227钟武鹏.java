public class texted {

    public static int[][] text(int a[][], int b[][]) {
        int c[][] = new int[a.length][b[0].length];
        if (a[0].length != b.length)
        	System.out.println("矩阵不能相乘！");       
            // 控制循环次数
        else
            for(int i=0;i<a.length;i++){
                for (int j = 0; j < b[0].length; j++) {
                    int sum = a[i][0]*b[i][0];
                    for (int k = 0; k < a.length; k++) {
                        sum += a[i][k] * b[k][j];
                        System.out.println(a[i][k]+" * "+b[k][j]+"----->"+sum);
                    }
                    c[i][j]=sum;
                }
            }

        
            
        
        return null;
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        int a[][] = { { 1, 2},
                      { 4, 5 } };
        int b[][] = { { 1, 2 }, 
                      { 3, 4 }, };
        texted.text(a, b);
    }

}
