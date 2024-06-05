import java.util.Scanner;
import java.util.ArrayList;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, m;
        n = sc.nextInt();
        m = sc.nextInt();
        
        int[] a = new int[n+1];
        int[] c = new int[n+1];
        for (int i = 1; i <= n; i++) {
            a[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }
        
        int dp[][] = new int[n+1][m+1];
        dp[0][0] = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = dp[i-1][j];
                if (c[i] <= j)
                    dp[i][j] = Math.max(dp[i][j], dp[i-1][j- c[i]] + a[i]);
            }
        }
        
        int v = m;
        ArrayList<Integer> ans = new ArrayList<>();
        
        for (int i = n; i > 0; i--) 
            if (dp[i][v] != dp[i-1][v]) {
                ans.add(0, i);
                v -= c[i];
            }
        
        System.out.println(dp[n][m]);
        System.out.print(ans.size() + " ");
        
        for (int i = 0; i < ans.size(); i++)
            System.out.print(ans.get(i) + " ");
    }
}