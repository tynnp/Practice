using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        long ans = 1;
        for (int i = 3; i <= n; i += 3)
            ans *= i;
        Console.Write(ans);
    }
}