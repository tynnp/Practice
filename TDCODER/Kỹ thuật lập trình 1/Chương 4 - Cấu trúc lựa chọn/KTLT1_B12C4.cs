using System;

public class Program {
    public static void Main(string[] args) {
        string ans = "";
        char c = char.Parse(Console.ReadLine());
        
        if (c >= 'A' && c <= 'Z')
            ans = "IN HOA";
        else if (c >= 'a' && c <= 'z')
            ans = "IN THUONG";
        else if (c >= '0' && c <= '9')
            ans = "SO";
        else 
            ans = "KHAC";
            
        Console.Write(ans);
    }
}