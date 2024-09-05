using System;

public class Program {
    public static void Main(string[] args) {
        int a = int.Parse(Console.ReadLine());
        int b = int.Parse(Console.ReadLine());
        int tieuThu = b - a;
        int tienDinhMuc = 50*1000;
        int vuotDinhMuc = 0;
        int tienVuotDinhMuc = 0;

        if (tieuThu > 50) {
            vuotDinhMuc = tieuThu - 50;
            if (vuotDinhMuc <= 50) 
                tienVuotDinhMuc = vuotDinhMuc * 1500;
            else if (vuotDinhMuc <= 100)
                tienVuotDinhMuc = 50*1500 + (vuotDinhMuc - 50)*1800;
            else 
                tienVuotDinhMuc = 50*1500 + 50*1800 + (vuotDinhMuc - 100)*2500;
        }

        Console.WriteLine(tieuThu);
        Console.WriteLine(tienDinhMuc);
        Console.WriteLine(tienVuotDinhMuc);
        Console.WriteLine(tienDinhMuc + tienVuotDinhMuc);
    }
}
// 20
// 150

// 130
// 50000
// 129000
// 179000