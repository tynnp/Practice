using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        if ((n & 1) != 1 && n % 3 == 0 && n >= 1 && n <= 100)
            Console.Write("La so chan chia het cho 3");
        else    
            Console.Write("Khong thoa dieu kien");
    }
}