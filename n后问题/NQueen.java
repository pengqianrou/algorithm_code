package nq;

public class NQueen {
    private int n;
    private long count;
    private int[] arr;

    public NQueen(int n){
        this.n = n;
        count = 0;
        arr = new int[n];
    }


    public boolean Check(int row, int col){
        for(int i = 0; i < row; i++){
            if(col == arr[i] || Math.abs(row - i) == Math.abs(col - arr[i])) //在同一列或者在同一斜线。一定不在同一行
                return false;
        }
        return true;
    }

    public void FindNQueen(int k) {
        if (k == n) {
            count++;
            return;
        }//如果能在最后一行放置皇后，则count++

        for (int i = 0; i < n; i++) {
            if (Check(k, i)) {   //检查
                arr[k] = i;
                FindNQueen(k + 1);   //递归
            }
        }

    }

    public static void main(String args[]){
        int n = 10;//十皇后问题
        NQueen nQueen = new NQueen(n);
        nQueen.FindNQueen(0);
        System.out.print( n + "Queen Question has ");
        System.out.println(nQueen.count + " answers.");
    }

}

