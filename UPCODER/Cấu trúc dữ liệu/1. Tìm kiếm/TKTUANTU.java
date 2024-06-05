import java.util.Scanner;

class Main {
    public static int sequentialSearch(int[] arr, int n, int x) {
        for (int i = 0; i < n; i++)
            if (arr[i] == x) return i;
        return -1;
    }
     
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, x, ans;
        n = sc.nextInt();
        x = sc.nextInt();
        
        int arr[] = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        
        ans = sequentialSearch(arr, n, x);
        System.out.print(ans);
    }
}