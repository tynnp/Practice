using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        Console.Write(check(n) ? "TRUE" : "FALSE");
    }
    
    static bool check(int n) {
        int m = 0;
        int tmp = n;
        
        while (tmp > 0) {
            m = 10*m + tmp%10;
            tmp /= 10;
        }
        
        return n == m;
    }
}