using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        int res = 0;
        for (int i = 1; i < n; i++)
            if (n % i == 0)
                res += i;
        Console.Write(n == res ? "TRUE" : "FALSE");
    }
}