using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                if (i == n) {
                    Console.Write('*');
                    continue;
                }
                
                if (j == 1 || j == i)
                    Console.Write('*');
                else 
                    Console.Write(' ');
            }
            
            Console.WriteLine();
        }
    }
}