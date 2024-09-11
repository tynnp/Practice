using System;

public class Program {
    static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        int[] a = new int[n];
        
        for (int i = 0; i < n; i++) 
            a[i] = int.Parse(Console.ReadLine());
        
        int ans = -1;
        for (int i = 0; i < n; i++)
            if (check(a[i])) {
                ans = i;
                break;
            }
            
        Console.Write(ans);
    }
    
    static bool check(int n) {
        for (int i = 2; i*i <= n; i++)
            if (n % i == 0)
                return false;
        return n > 1;
    }
}