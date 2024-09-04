using System;

public class Program {
    public static void Main(string[] args) {
        const double PI = 3.141;
        double r = double.Parse(Console.ReadLine());
        Console.Write("{0:F2} {1:F2}", 2*r*PI, PI*r*r);
    }
}