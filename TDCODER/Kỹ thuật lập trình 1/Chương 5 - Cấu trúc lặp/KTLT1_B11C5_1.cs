using System;

public class Program {
    public static void Main(string[] args) {
        double x = double.Parse(Console.ReadLine());
        int n = int.Parse(Console.ReadLine());
        double ans = 1;
        for (int i = 1; i <= n; i++)
            ans += Math.Pow(x, i);
        Console.Write(ans);
    }
}