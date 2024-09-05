using System;

public class Program {
    public static void Main(string[] args) {
        long n = long.Parse(Console.ReadLine());
        bool check = (long) Math.Sqrt(n) == Math.Sqrt(n);
        Console.Write(check && n != 0 ? "TRUE" : "FALSE");
    }
}