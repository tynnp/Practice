using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        Console.Write("{0:0.00}", solve(n));
    }
    
    static double solve(int n) {
        double res = 0;
        for (int i = 1; i < n; i++)
            res += (double) 1/i;
        return res;
    }
}