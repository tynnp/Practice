using System;

public class Program {
    public static void Main(string[] args) {
        int a = int.Parse(Console.ReadLine());
        int b = int.Parse(Console.ReadLine());
        hoanDoi(ref a, ref b);
        Console.Write($"{a}\n{b}");
    }
    
    static void hoanDoi(ref int a, ref int b) {
        int c = a;
        a = b;
        b = c;
    }
} 