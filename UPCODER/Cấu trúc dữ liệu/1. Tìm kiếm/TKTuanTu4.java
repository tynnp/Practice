import java.util.Scanner;

class Main {
    public static int sequential(int[] arr, int n, int x) {
        int tmp = -99999999;
        int res = -1;
        
        for (int i = 0; i < n; i++) 
            if (arr[i] > tmp && arr[i] <= x) {
                tmp = arr[i];
                res = i;
            }
            
        return res;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x, ans, n = 0;
        x = sc.nextInt();
        
        int[] arr = new int[1001];
        while (sc.hasNextInt()) {
            arr[n] = sc.nextInt();
            n += 1;
        }
        
        ans = sequential(arr, n, x);
        if (ans == -1) System.out.print(-1);
        else {
            for (int i = 0; i < n; i++) 
                if (arr[i] == arr[ans])
                    System.out.print(i + " ");
        }
    }
}