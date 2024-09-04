using System;

public class Program {
    public static void Main(string[] args) {
        int h = int.Parse(Console.ReadLine());
        int m = int.Parse(Console.ReadLine());
        int s = int.Parse(Console.ReadLine());
        int sAdd = int.Parse(Console.ReadLine());
        s += h*3600 + m*60 + sAdd;
        
        h = s/3600;
        m = s/60 % 60;
        s %= 60;
        
        Console.Write("{0:00}:{1:00}:{2:00}", h, m, s);
    }
}