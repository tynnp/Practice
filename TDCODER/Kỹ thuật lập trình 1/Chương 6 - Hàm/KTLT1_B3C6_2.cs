using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        Console.Write(demUoc(n));
    }
    
    static int demUoc(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++)
            if (n % i == 0)
                res++;
        return res;
    }
}