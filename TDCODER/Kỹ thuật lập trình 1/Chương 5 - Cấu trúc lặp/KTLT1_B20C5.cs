using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n - i; j++)
                Console.Write(' ');
                
            if (i == n-1) {
                for (int k = 1; k <= n; k++)
                    Console.Write("* ");
                    break;
            }
                
            for (int j = 0; j <= 2*i; j++) {
                if (j == 0 || j == 2*i)
                    Console.Write('*');
                else
                    Console.Write(' ');
            }
            
            Console.WriteLine();
        } 
    }
}