public class BinarySearch {
    public static void main(String[] args) {
        int[] array ={1,2,3,4,6,7,8,9,10};
        System.out.println( binSearch_2(3,array,0,array.length-1));
        System.out.println( binSearch_2(5,array,0,array.length-1));
    }

    /*
     *循环实现二分算法
     */
    public static int binSearch_1(int key, int[] array) {
        int low = 0; //第一个下标
        int high = array.length - 1;//最后一个下标
        int middle = 0;
        //防越界
        if (key < array[low] || key > array[high] || low > high) {
            return -1;
        }
        while (low <= high) {
            middle = (low + high) / 2;
            if (middle == key) {
                return array[middle];
            } else if (middle < key) {
                low = middle + 1;
            } else {
                high = middle - 1;
            }
        }
        return -1;
    }

    /*
     *递归实现二分算法
     */
    public static int binSearch_2(int key,int[] array,int low,int high){
        //防越界
        if (key < array[low] || key > array[high] || low > high) {
            return -1;
        }
        int middle = (low+high)/2;
        if(array[middle]>key){
            //大于关键字
            return  binSearch_2(key,array,low,middle-1);
        }else if(array[middle]<key){
            //小于关键字
            return binSearch_2(key,array,middle+1,high);
        }else{
            return array[middle];
        }
    }
}
