using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        Console.Write(solve(n));
    }
    
    static int solve(int n) {
        int res = 0;
        for (int i = 1; i <= n; i += 2) 
            res += i;
        return res;
    }
}