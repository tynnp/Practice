using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        string ans = "";
        
        if (n >= 1 && n <= 3) ans = "Quy 1";
        else if (n >= 4 && n <= 6) ans = "Quy 2";
        else if (n >= 7 && n <= 9) ans = "Quy 3";
        else if (n >= 10 && n <= 12) ans = "Quy 4";
        else ans = "Khong hop le";
        
        Console.Write(ans);
    }
}