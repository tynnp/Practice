using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        Console.Write((n & 1) == 1 ? n - 1 : n + 1);
    }
}