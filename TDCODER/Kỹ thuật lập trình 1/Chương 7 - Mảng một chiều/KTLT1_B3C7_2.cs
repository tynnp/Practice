using System;

public class Program {
    public static void Main(string[] args) {
        string[] s = (Console.ReadLine()).Split(' ');
        string[] t = (Console.ReadLine()).Split(' ');
        
        int n = s.Length;
        int m = t.Length;
        int[] a = new int[Math.Max(n, m)];
        
        for (int i = 0; i < a.Length; i++) {
            int x = (i < n ? int.Parse(s[i]) : 0);
            int y = (i < m ? int.Parse(t[i]) : 0);
            a[i] = x + y;
        }
        
        for (int i = 0; i < a.Length; i++)
            Console.Write("{0} ", a[i]);
    }
}