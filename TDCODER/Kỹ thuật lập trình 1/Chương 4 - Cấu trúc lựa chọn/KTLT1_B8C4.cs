using System;

public class Program {
    public static void Main(string[] args) {
        string ans = "";
        char c = char.Parse(Console.ReadLine());
        
        if (c == 'R' || c == 'r')
            ans = "RED";
        else if (c == 'G' || c == 'g')
            ans = "GREEN";
        else if (c == 'B' || c == 'b')
            ans = "BLUE";
        else 
            ans = "BLACK";
            
        Console.Write(ans);
    }
}