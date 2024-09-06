using System;

public class Program {
    public static void Main(string[] args) {
        long n = long.Parse(Console.ReadLine());
        Console.Write(fac(n));
    }
    
    static long fac(long n) {
        if (n == 0)
            return 1;
        return n * fac(n - 1);
    }
}