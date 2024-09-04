using System;

public class Program {
    public static void Main(string[] args) {
        double a = double.Parse(Console.ReadLine());
        double b = double.Parse(Console.ReadLine());
        double c = double.Parse(Console.ReadLine());
        
        if (a + b + c >= 15 && a >= 4 && b >= 4 && c >= 4) {
            if (a > 5 && b > 5 && c > 5)
                Console.Write("Hoc deu cac mon");
            else 
                Console.Write("Hoc chua deu cac mon");
        } else 
                Console.Write("Thi hong");
    }
}