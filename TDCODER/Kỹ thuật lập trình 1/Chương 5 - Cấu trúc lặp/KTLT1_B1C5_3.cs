using System;

public class ThuDiem {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        double res = 0;
        for (int i = 1; i < n; i++) 
            res += 1.0/i;
        res = Math.Round(res, 2);
        Console.Write(res);
        //Console.Write("{0:0.00}", res);
    }
}