using System;

public class Program {
    public static void Main(string[] args) {
        int num1 = int.Parse(Console.ReadLine());
        int num2 = int.Parse(Console.ReadLine());
        int num3 = num1;
        num1 = num2;
        num2 = num3;
        Console.Write($"{num1}\n{num2}");
    }
}