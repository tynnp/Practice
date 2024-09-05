using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        long ans = 1;
        for (int i = 2; i <= 2*n; i += 2)
            ans *= i;
        Console.Write(ans);
    }
}