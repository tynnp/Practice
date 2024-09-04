using System;

public class Program {
    public static void Main(string[] args) {
        int a = int.Parse(Console.ReadLine());
        int b = int.Parse(Console.ReadLine());
        int c = int.Parse(Console.ReadLine());
        int d = int.Parse(Console.ReadLine());
        
        int ans = a;
        if (ans < b) ans = b;
        if (ans < c) ans = c;
        if (ans < d) ans = d;
        Console.Write(ans);
    }
} 