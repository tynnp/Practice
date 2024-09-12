using System;

public class Program {
    public static void Main(string[] args) {
        string[] s = (Console.ReadLine()).Split(' ');
        int n = s.Length;
        double[] a = new double[n];
        
        for (int i = 0; i < n; i++)
            a[i] = double.Parse(s[i]);
        
        for (int i = 0; i < n; i++)
            Console.Write("{0} ", a[i]);
    }
}