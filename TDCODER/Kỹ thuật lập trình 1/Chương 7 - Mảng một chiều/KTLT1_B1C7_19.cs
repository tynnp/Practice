using System;

public class Program {
    public static void Main(string[] args) {
        string[] s = (Console.ReadLine()).Split(' ');
        int n = s.Length;
        int[] a = new int[n];
        
        for (int i = 0; i < n; i++) 
            a[i] = int.Parse(s[i]);
        
        for (int i = 0; i < n; i++)
            if (doiXung(a[i]))
                Console.Write("{0} ", a[i]);
    }
    
    static bool doiXung(int n) {
        int res = 0;
        int m = n;
        
        while (n > 0) {
            res = res*10 + n%10;
            n /= 10;
        }
        
        return res == m;
    }
}