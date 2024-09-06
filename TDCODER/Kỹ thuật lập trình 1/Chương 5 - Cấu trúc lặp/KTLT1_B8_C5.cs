using System;

public class Program {
    public static void Main(string[] args) {
        for (int i = 2; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) 
                Console.WriteLine("{0} x {1} = {2}", i, j, i*j);
            Console.WriteLine();
        }
    }
}