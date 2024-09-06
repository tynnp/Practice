using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        int[,] dp = new int[1000, 1000];
        
        for (int i = 0; i < 1000; i++)
            for (int j = 0; j < 1000; j++)
                dp[i, j] = 0;
                
        dp[0, 0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i, j] = dp[i-1, j-1] + dp[i-1, j];
                Console.Write("{0} ", dp[i, j]);
            }
            Console.WriteLine();
        }
    }
}