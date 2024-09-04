using System;

public class Program {
    public static void Main(string[] args) {
        double a = double.Parse(Console.ReadLine());
        double b = double.Parse(Console.ReadLine());
        double c = double.Parse(Console.ReadLine());
        Console.Write("{0:0.00}", (a+b+c)/3);
    }
}