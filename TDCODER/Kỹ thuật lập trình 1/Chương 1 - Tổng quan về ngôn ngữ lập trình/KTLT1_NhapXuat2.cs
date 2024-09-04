using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        int a = n/100;
        int b = n/10 % 10;
        int c = n % 10;
        Console.WriteLine(a);
        Console.WriteLine(b);
        Console.WriteLine(c);
    }
}