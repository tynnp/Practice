using System;

public class Program {
    static void Main(string[] args) {
        string s = Console.ReadLine();
        string[] t = s.Split(' ');
        int[] a = new int[t.Length];
        
        for (int i = 0; i < t.Length; i++)
            a[i] = int.Parse(t[i]);
            
        Console.Write(check(a));
    }
    
    static int check(int[] a) {
        int ans = 0;
        for (int i = 0; i < a.Length; i++)
            if (chinhPhuong(a[i]))
                ans++;
        return ans;
    }
    
    static bool chinhPhuong(int n) {
        return (int) Math.Sqrt(n) == Math.Sqrt(n)&& n != 0;
    }
}