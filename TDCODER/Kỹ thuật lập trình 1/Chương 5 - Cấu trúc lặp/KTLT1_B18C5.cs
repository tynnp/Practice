using System;

public class Program {
    public static void Main(string[] args) {
        long n = long.Parse(Console.ReadLine());
        Console.Write(solve(n) ? "YES" : "NO");
    }
    
    static long soChuSo(long n) {
        long res = 0;
        while (n > 0) {
            res++;
            n /= 10;
        }
        return res;
    }
    
    static long luyThua(long n, long x) {
        long res = 1;
        for (long i = 1; i <= x; i++)    
            res *= n;
        return res;
    }
    
    static bool solve(long n) {
        long m = n;
        long x = soChuSo(n);
        long res = 0;
        
        while (n > 0) {
            res += luyThua(n % 10, x);
            n /= 10;
        }
        
        return res == m;
        
    }
} 