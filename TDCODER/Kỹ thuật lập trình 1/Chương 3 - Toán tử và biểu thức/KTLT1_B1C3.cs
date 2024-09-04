using System;

public class Program {
    public static void Main(string[] args) {
        int a = int.Parse(Console.ReadLine());
        int b = int.Parse(Console.ReadLine());
        Console.Write("{0} {1} {2} {3:0.0}", a+b, a-b, a*b, (double) a/b);
    }
}