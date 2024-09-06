using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        Console.Write(check(n) ? "SNT" : "Khong la SNT");
    }

    static bool check(int n) {
        for (int i = 2; i*i <= n; i++)
            if (n % i == 0)
                return false;
        return n > 1;
    }
}   