using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        bool check = true;
        
        if (n < 2)
            check = false;
        
        for (int i = 2; i*i <= n; i++)
            if (n % i == 0)
                check = false;
                
        Console.Write(check ? "TRUE" : "FALSE");
    }
}