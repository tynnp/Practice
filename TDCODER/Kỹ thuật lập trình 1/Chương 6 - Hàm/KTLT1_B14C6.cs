using System;

public class Program {
    public static void Main(string[] args) {
        int a = int.Parse(Console.ReadLine());
        int b = int.Parse(Console.ReadLine());
        swap(a, b);
        Console.Write("{0}\n{1}", a, b);
    }

    ///////////////////////////////
    static void swap(int &a, int &b) {
        int c = a;
        a = b;
        b = c;
    }
}