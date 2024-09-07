using System;

public class Program {
    public static void Main(string[] args) {
        long n = long.Parse(Console.ReadLine());
        Console.Write(fib(n));
    }

    static long fib(long n) {
        if (n == 0 || n == 1) 
            return 1;
        return fib(n - 1) + fib(n - 2);
    }
}