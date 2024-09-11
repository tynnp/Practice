using System;

public class Program {
    static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = int.Parse(Console.ReadLine());
        for (int i = 0; i < n; i++)
            if (a[i] % 2 == 0)
                Console.WriteLine(a[i]);
    }
}