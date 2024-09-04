using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        for (int i = 1; i <= 10; i++)
            Console.Write("{0} ", n*i);
    }
}