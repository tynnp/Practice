using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        Console.Write(solve(n));
    }

    static long solve(int n) {
        long res = 1;
        for (int i = 3; i <= n; i += 3) 
            res *= i;
        return res;
    }
}