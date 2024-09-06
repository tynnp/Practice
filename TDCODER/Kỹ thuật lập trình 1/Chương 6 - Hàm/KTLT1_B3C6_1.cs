using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        solve(n);
    }
    
    static void solve(int n) {
        for (int i = 1; i <= n; i++)
            if (n % i == 0)
                Console.Write("{0} ", i);
    }
}