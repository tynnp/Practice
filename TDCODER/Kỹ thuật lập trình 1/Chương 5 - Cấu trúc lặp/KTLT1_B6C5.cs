using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        int[] fib = new int[n+5];

        fib[0] = 1; 
        fib[1] = 1;
        for (int i = 2; i <= n; i++) {
            fib[i] = fib[i-1] + fib[i-2];
            //Console.WriteLine("{0} {1} {2}", fib[i-1], fib[i-2], fib[i]);
        }
        
        Console.Write(fib[n]);
    }
}