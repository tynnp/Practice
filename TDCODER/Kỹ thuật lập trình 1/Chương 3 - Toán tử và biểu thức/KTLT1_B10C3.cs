using System;

public class Program {
    public static void Main(string[] args) {
        double a = double.Parse(Console.ReadLine());
        double b = double.Parse(Console.ReadLine());
        double c = double.Parse(Console.ReadLine());
        double d = double.Parse(Console.ReadLine());
        Console.Write("{0:0.00}", Math.Sqrt(Math.Pow(d - b, 2) + Math.Pow(c - a, 2)));
    }
}