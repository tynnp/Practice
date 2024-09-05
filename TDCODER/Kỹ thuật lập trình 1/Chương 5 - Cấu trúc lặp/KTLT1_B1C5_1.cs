using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        int ans = 0;
        for (int i = 1; i <= n; i += 2)
            ans += i;
        Console.Write(ans);
    }
}