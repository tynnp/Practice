using System;

public class Program {
    static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        int[] a = new int[n];
        
        for (int i = 0; i < n; i++)
            a[i] = int.Parse(Console.ReadLine());
        
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (check(a[i]))
                ans++;
        
        Console.Write(ans);
    }
    
    static bool check(int n) {
        int sum = 0;
        for (int i = 1; i < n; i++)
            if (n % i == 0) 
                sum += i;
        return sum == n && sum != 0;
    }
}