using System;

public class Program {
    public static void Main(string[] args) {
        string s = Console.ReadLine();
        string[] t = s.Split(' ');
        int[] a = new int[t.Length];
        
        for (int i = 0; i < t.Length; i++)
            a[i] = int.Parse(t[i]);
            
        Console.Write(solve(a));
    }
    
    static int solve(int[] a) {
        int res = -1;
        for (int i = 0; i < a.Length; i++)
            if (chinhPhuong(a[i]) && a[i] > res)
                res = a[i];
        return res;
    }
    
    static bool chinhPhuong(int n) {
        return (int) Math.Sqrt(n) == Math.Sqrt(n) && n != 0;
    }
}