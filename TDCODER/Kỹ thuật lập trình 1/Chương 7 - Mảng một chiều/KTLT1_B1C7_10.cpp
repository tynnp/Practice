using System;

public class Program {
    static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        int[] a = new int[n];
        
        for (int i = 0; i < n; i++)
            a[i] = int.Parse(Console.ReadLine());
        
        int ans = -9999;
        for (int i = 0; i < n; i++)
            ans = Math.Max(ans, a[i]);
        
        Console.Write(ans);
    }
}