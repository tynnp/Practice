using System;

public class Program {
    public static void Main(string[] args) {
        int a = int.Parse(Console.ReadLine());
        int b = int.Parse(Console.ReadLine());
        char c = char.Parse(Console.ReadLine());
        
        if (c == '/' && b == 0) {
            Console.Write("Khong chia duoc");
        } else {
            switch (c) {
                case '+':
                    Console.Write(a + b);
                    break;
                    
                case '-':
                    Console.Write(a - b);
                    break;
                    
                case '*':
                    Console.Write(a * b);
                    break;
                
                case '/':
                    Console.Write("{0:0.0}", (double) a/b);
                    break;
                
                default:
                    Console.Write("Phep toan khong hop le");
                    break;
            }
        }
    }
}