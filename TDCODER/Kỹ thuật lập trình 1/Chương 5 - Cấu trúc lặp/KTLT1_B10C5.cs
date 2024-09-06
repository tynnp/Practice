using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        for (int i = 0; i < n; i++) {
            for (int j = n-1; j >= 0; j--)
                if (j > i)
                    Console.Write(' ');
                else 
                    Console.Write("* ");
            Console.WriteLine();
        } 
    }
}