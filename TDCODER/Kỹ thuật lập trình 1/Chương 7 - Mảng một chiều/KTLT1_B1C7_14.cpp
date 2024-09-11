using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        int[] a = new int[n];
        
        for (int i = 0; i < n; i++)
            a[i] = int.Parse(Console.ReadLine());
            
        for (int i = 0; i < n; i++) 
            if (check(a[i]))
                Console.Write("{0} ", a[i]);
    }
    
    static bool check(int n) {
        for (int i = 2; i < n; i++) 
            if (n % i == 0)
                return true;
        
        return false;
    }
} 