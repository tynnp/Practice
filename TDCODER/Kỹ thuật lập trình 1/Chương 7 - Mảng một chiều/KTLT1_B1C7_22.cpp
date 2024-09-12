using System;

public class Program {
    public static void Main(string[] args) {
        string[] s = (Console.ReadLine()).Split(' ');
        double[] a = new double[s.Length];
        int n = s.Length;
        
        for (int i = 0; i < n; i++)
            a[i] = double.Parse(s[i]);
        
        double x = double.Parse(Console.ReadLine());
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == x)
                ans++;
        
        Console.Write(ans);
    }
}