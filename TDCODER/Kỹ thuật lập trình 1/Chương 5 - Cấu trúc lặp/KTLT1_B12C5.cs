using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        for (int i = 2; i <= n; i++)
            if (check(i))
                Console.Write("{0} ", i);
    }
    
    static bool check(int n) {
        for (int i = 2; i*i <= n; i++)
            if (n % i == 0)
                return false;
        return n > 1;
    }
}