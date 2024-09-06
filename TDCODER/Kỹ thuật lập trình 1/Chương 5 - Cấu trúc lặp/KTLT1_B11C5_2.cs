using System;

public class Program {
    public static void Main(string[] args) {
        double x = double.Parse(Console.ReadLine());
        int n = int.Parse(Console.ReadLine());
        double ans = 0;
        for (int i = 0; i <= n; i++) 
            ans += Math.Pow(-1, i) * Math.Pow(x, i);
        Console.Write(ans);
    }
}