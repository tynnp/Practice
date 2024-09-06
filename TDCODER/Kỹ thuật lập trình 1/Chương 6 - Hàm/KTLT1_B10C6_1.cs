using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        for (int i = 1; i <= n; i++)
            if (check(i))
                Console.WriteLine(i);
    }

    static bool check(int n) {
        int res = 0;
        for (int i = 1; i < n; i++)
            if (n % i == 0)
                res += i;
        return res == n;
    }
}