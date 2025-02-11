package Array;

public class SortAll {

    public static void printAr(int[] a) {
        for (int x : a) {
            System.out.print(x + " ");
        }
        System.out.println();
    }

    public static void insertionSort(int[] a) {
        int n = a.length;
        for (int i = 1; i < n; i++) {
            int ai = a[i];
            int j = i - 1;

            while (j >= 0 && a[j] > ai) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = ai;
        }
        printAr(a);
    }

    public static void bubbleSort(int[] a){
        int n = a.length;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n - i - 1 ; j++){
                // n - j -1 vì : j so sanh j+1 < n - i(vi moi vong lap giam di 1 i) -> j < n - i -1
                if(a[j] > a[j + 1]){
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }

    public static void selectionSort(int[] a){
        int n = a.length;

        for(int i = 0 ; i < n ; i++){
            int minIndex = i;
            for(int j = i + 1; j < n ; j++){
                if(a[j] < a[minIndex]){
                    minIndex = j;
                }
            }
            if(minIndex != i){
                int t = a[i];
                a[i] = a[minIndex];
                a[minIndex] = t;
            }
        }
    }

    public static void main(String[] args) {
        int[] a = {5, 3, 7, 8, 1, 2};
        insertionSort(a);
    }
}
