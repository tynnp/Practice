using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        int h = n / 3600;
        int m = n / 60 % 60;
        int s = n % 60;
        Console.Write("{0:00}:{1:00}:{2:00}", h, m, s);
    }
}