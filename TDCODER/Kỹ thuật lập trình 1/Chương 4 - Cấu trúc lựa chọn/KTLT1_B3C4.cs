using System; 

public class Program {
    public static void Main(string[] args) {
        double a = double.Parse(Console.ReadLine());
        double b = double.Parse(Console.ReadLine());
        
        if (a == 0 && b == 0)
            Console.Write("VSN");
        else if (a == 0 && b != 0)  
            Console.Write("VN");
        else 
            Console.Write("{0:0.00}", -b/a);
    }
}   