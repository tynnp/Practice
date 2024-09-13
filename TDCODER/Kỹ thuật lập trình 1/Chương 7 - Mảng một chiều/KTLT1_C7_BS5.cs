using System;

public class Program {
    public static void Main(string[] args) {
        string[] s = (Console.ReadLine()).Split(' ');
        int n = s.Length;
        int[] a = new int[n];
        
        int x = int.Parse(Console.ReadLine());
        int k = int.Parse(Console.ReadLine());
        
        for (int i = 0; i < n; i++)
            a[i] = int.Parse(s[i]);
            
        a = solve(a, n, k, x);
        
        for (int i = 0; i < n; i++) 
            Console.Write("{0} ", a[i]);
    }
    
    static int[] solve(int[] a, int n, int k, int x) {
        
    }
}