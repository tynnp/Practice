using System;

public class Program {
    public static void Main(string[] args) {
        for (int i = 10; i <= 99; i++)
            if (check(i))
                Console.Write("{0} ", i);
    }
    
    static bool check(int n) {
        int a = n / 10;
        int b = n % 10;
        return a*b == 2*(a + b);
    }
}