using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        int[] a = new int[n];
        
        for (int i = 0; i < n; i++)
            a[i] = int.Parse(Console.ReadLine());
        
        int ans = solve(a, n);
        Console.WriteLine(ans);
    }
    
    static int solve(int[] a, int n) {
        int res = 1000007;
        for (int i = 0; i < n; i++)
            if (a[i] < res && a[i] > 0)
                res = a[i];
        return (res != 1000007 ? res : -1);
    }
}
