using System;

public class Program {
    public static void Main(string[] args) {
        int c = char.Parse(Console.ReadLine());
        char c2 = (char) (c + 1);
        Console.Write($"{c} {c2}");
    }
}