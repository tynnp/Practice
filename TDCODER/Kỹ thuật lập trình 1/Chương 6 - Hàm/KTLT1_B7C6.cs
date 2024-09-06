using System;

public class Program {
    public static void Main(string[] args) {
        for (int i = 1; i <= 500; i++)
            if (check(i))
                Console.Write("{0} ", i);
    }

    static bool check(int n) {
        int m = n;
        int res = 0;

        while (m > 0) {
            res = 10*res + m%10;
            m /= 10;
        }

        return res == n;
    }
} 