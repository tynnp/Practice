using System;

public class Program {
    public static void Main(string[] args) {
        int a = int.Parse(Console.ReadLine());
        int b = int.Parse(Console.ReadLine());
        Console.WriteLine(uocChungLN(a, b));
        Console.WriteLine(boiChungNN(a, b));
    }

    static int uocChungLN(int a, int b) {
        if (b == 0)
            return a;
        return uocChungLN(b, a % b);
    }

    static int boiChungNN(int a, int b) {
        return (a * b) / uocChungLN(a, b);
    }
}