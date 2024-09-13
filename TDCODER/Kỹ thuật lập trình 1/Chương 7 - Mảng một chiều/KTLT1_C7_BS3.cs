using System;

public class Program {
    public static void Main(string[] args) {
        string[] s = (Console.ReadLine()).Split(' ');
        int n = s.Length;
        int[] a = new int[n];

        for (int i = 0; i < n; i++)
            a[i] = int.Parse(s[i]);

        a = solve(a, ref n);

        for (int i = 0; i < n; i++)
            Console.Write("{0} ", a[i]);
    }

    static bool check(int n) {
        int m = n;
        int res = 0;

        while (n > 0) {
            res = res*10 + n%10;
            n /= 10;
        }

        return res == m;
    }

    static int[] solve(int[] a, ref int n) {
        int[] res = new int[n];
        int x = 0;

        for (int i = 0; i < n; i++)
            if (!check(a[i]))  
                res[x++] = a[i];
        
        n = x;
        return res;
    }
}