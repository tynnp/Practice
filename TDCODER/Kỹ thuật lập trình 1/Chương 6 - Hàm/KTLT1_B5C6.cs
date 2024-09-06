using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        Console.Write(check(n) ? "SCP" : "Khong la SCP");
    }

    static bool check(int n) {
        return (int) Math.Sqrt(n) == Math.Sqrt(n);
    }
}