using System;

public class Program {
    public static void Main(string[] args) {
        string[] s = (Console.ReadLine()).Split(' ');
        int n = s.Length;
        int[] a = new int[n];
        
        int m = 0;
        int[] res = new int[n];
        
        for (int i = 0; i < n; i++)
            a[i] = int.Parse(s[i]);
        
        for (int i = 0; i < n; i++)
            if (prime(a[i]))
                res[m++] = a[i];
        
        for (int i = 0; i < m; i++)
            Console.Write("{0} ", res[i]);
    }
    
    static bool prime(int n) {
        for (int i = 2; i*i <= n; i++)
            if (n % i == 0)
                return false;
        return n > 1;
    }
}