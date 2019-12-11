public class MatrixChainOrder {
    int[] p;
    int[][] m;
    int[][] s;
    int length;
    public MatrixChainOrder(int[] p,int[][] m,int[][] s){
        this.p = p;
        this.length = p.length/2;
        this.m = m;
        this.s = s;
        
        init();
        clac();
        printM();
    }
    
    public void init(){
        for (int i=0;i<length;i++){
            m[i][i] = 0;
        }
        
        
    }
    
    public void clac(){
        for (int i=1;i<length;i++){
            for (int j=0;j<length-i;j++){
                int r = j+i;
                int t = Integer.MAX_VALUE;
                for (int k = j;k<r;k++){
                    int temp = m[j][k] + m[k+1][r] + p[j*2]*p[k*2+1]*p[r*2+1];
                    if (t > temp){
                        t = temp;
                        m[j][r] = temp;
                    }
                }
            }
        }
    }
    
    public void printM(){
        for (int i=0;i<length;i++){
            for (int j=0;j<length;j++){
                System.out.print(m[i][j]+ "/t");
            }
            System.out.println();
        }
    }
    
    public static void main(String args[]){
        int p[] = {30,35,35,15,15,5,5,10,10,20,20,25};
        int length = 6;
        int[][] m = new int[6][6];
        int[][] s = new int[6][6];
        new MatrixChainOrder(p,m,s);
    }
}
