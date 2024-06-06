import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        int[] v = new int[31];
        long[][] dp = new long[31][2001];
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int m = sc.nextInt();
        for (int i = 1; i <= n; i++)
            v[i] = sc.nextInt();
        
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = dp[i-1][j];
                if (v[i] <= j)
                    dp[i][j] = Math.max(dp[i][j], dp[i-1][j - v[i]] + v[i]);
            }
        }
        
        System.out.print(dp[n][m]);
    }
}