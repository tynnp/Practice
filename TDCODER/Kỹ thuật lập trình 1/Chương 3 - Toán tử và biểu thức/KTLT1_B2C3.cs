using System;

public class Program {
    public static void Main(string[] args) {
        double f = double.Parse(Console.ReadLine());
        Console.Write("{0:0.00}", (f - 32)*5/9);
    }
}