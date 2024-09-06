using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        int[] f = new int[100];
        f[1] = 1; f[2] = 1;
        
        for (int i = 1; i <= n; i++) {
            if (i > 2)
                f[i] = f[i-1] + f[i-2];
            Console.Write("{0} ", f[i]);
        }
    }
}