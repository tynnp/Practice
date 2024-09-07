using System;

public class Program {
    public static void Main(string[] args) {
        long n = long.Parse(Console.ReadLine());
        for (long i = 0; i < n; i++)
            Console.Write("{0} ", fib(i));
    }

    static long fib(long n) {
        if (n == 0 || n == 1)
            return 1;
        return fib(n - 1) + fib(n - 2);
    }
}