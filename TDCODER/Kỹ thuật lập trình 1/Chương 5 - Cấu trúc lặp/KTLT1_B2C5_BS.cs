using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (n % i == 0)
                ans++;
        Console.Write(ans);
    }
}