using System;

public class Program {
    public static void Main(string[] args) {
        string[] s = (Console.ReadLine()).Split(' ');
        string[] t = (Console.ReadLine()).Split(' ');
        
        int[] a = new int[s.Length];
        int n = s.Length;
        
        for (int i = 0; i < n; i++)
            a[i] = int.Parse(s[i]) + int.Parse(t[i]);
            
        for (int i = 0; i < n; i++)
            Console.Write("{0} ", a[i]);
    }
}