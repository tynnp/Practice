using System;

public class Program {
    public static void Main(string[] args) {
        long n = long.Parse(Console.ReadLine());
        long[,] dp = new long[1000, 1000];
        
        for (long i = 0; i < 1000; i++)
            for (long j = 0; j < 1000; j++)
                dp[i, j] = 0;
                
        dp[0, 0] = 1;
        for (long i = 1; i <= n; i++) {
            for (long j = 1; j <= i; j++) {
                dp[i, j] = dp[i-1, j-1] + dp[i-1, j];
                if (i == n)
                    Console.Write("{0} ", dp[i, j]);
            }
        }
    }
}