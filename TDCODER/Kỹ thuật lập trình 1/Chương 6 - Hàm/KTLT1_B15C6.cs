using System;

public class Program {
    public static void Main(string[] args) {
        long a = long.Parse(Console.ReadLine());
        long b = long.Parse(Console.ReadLine());
        if (gcd(Math.Abs(a), Math.Abs(b)) == 1) 
            Console.Write("Toi gian");
        else 
            Console.Write("Chua toi gian");
    }
    
    static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
}