using System;

public class Program {
    static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        int[] a = new int[n];
        
        for (int i = 0; i < n; i++)
            a[i] = int.Parse(Console.ReadLine());
        
        double tb = 0;
        for (int i = 0; i < n; i++) 
            tb += a[i];
        
        tb /= n;
        Console.Write("{0:0.00}", tb);
    }
}