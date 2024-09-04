using System;

public class Program {
    public static void Main(string[] args) {
        double n = double.Parse(Console.ReadLine());
        string ans = "";
        
        if (n >= 0 && n < 3) ans = "Kem";
        else if (n < 5) ans = "Yeu";
        else if (n < 6.5) ans = "Trung binh kha";
        else if (n < 8) ans = "Kha";
        else if (n < 9) ans = "Gioi";
        else ans = "Xuat sac";
        
        Console.Write(ans);
    }
}