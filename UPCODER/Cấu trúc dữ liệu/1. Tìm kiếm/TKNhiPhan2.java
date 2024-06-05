import java.util.Scanner;

class Main {
    public static int binarySearch(int[] arr, int n, int x) {
        int left = 0, right = n-1;
        int mid = (left + right)/2;
        
        while (left <= right) {
            if (arr[mid] < x) left = mid + 1;
            else if (arr[mid] > x) right = mid - 1;
            else return mid;
            mid = (left + right)/2;
        }
        
        return -1;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, x, ans;
        n = sc.nextInt();
        x = sc.nextInt();
        
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
            
        ans = binarySearch(arr, n, x);
        if (ans == -1) System.out.print(-1);
        else {
            for (int i = 0; i < n; i++)
                if (arr[i] == x) 
                    System.out.print(i + " ");
        }
    }
}