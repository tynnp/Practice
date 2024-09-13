using System;

public class Program {
    public static void Main(string[] args) {
        string[] s = (Console.ReadLine()).Split(' ');
        int n = s.Length;
        int[] a = new int[n];

        for (int i = 0; i < n; i++)
            a[i] = int.Parse(s[i]);
        
        int x = int.Parse(Console.ReadLine());
        a = solve(a, ref n, x);

        for (int i = 0; i < n; i++) 
            Console.Write("{0} ", a[i]);
    }

    static int[] solve(int[] a, ref int n, int x) {
        if (x < 0 || x >= n)
            return a;

        n -= 1;
        for (int i = x; i < n; i++)
            a[i] = a[i+1];

        return a;
    }
}