using System;

public class Program {
    public static void Main(string[] args) {
        double a = double.Parse(Console.ReadLine());
        double b = double.Parse(Console.ReadLine());
        double c = double.Parse(Console.ReadLine());

        if (a == 0) {
            if (b == 0 && c == 0)
                Console.Write("VSN");
            else if (b == 0 && c != 0)
                Console.Write("VN");
            else 
                Console.Write("{0:0.00}", -1*c/b);

        } else {
            double delta = b*b - 4*a*c;
            if (delta < 0)
                Console.Write("VN");
            else if (delta == 0)    
                Console.Write("{0:0.00}", -b/2*a);
            else 
                Console.Write("{0:0.00}\n{1:0.00}", (-b-Math.Sqrt(delta))/2*a, (-b+Math.Sqrt(delta))/2*a);
        }
    }
}