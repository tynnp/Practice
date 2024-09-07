using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        solve(n);
    }

    static bool check(int n) {
        return (int) Math.Sqrt(n) == Math.Sqrt(n);
    }

    static void solve(int n) {
        int cnt = 1;
        int m = 1;

        while (cnt <= n) {
            if (check(m)) {
                Console.Write("{0} ", m);
                cnt++;
            }
            m++;
        }
    }
}