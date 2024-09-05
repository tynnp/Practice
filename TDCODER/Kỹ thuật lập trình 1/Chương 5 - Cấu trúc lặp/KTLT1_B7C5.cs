using System;

public class Program {
    static int gcd(int a, int b) {
        if (b == 0) 
            return a;
        return gcd(b, a % b);
    }
    
    public static void Main(string[] args) {
        int a = int.Parse(Console.ReadLine());
        int b = int.Parse(Console.ReadLine());
        int ucln = gcd(a, b);
        int bcnn = (a * b) / ucln;
        Console.Write("{0}\n{1}", ucln, bcnn);
    }
}