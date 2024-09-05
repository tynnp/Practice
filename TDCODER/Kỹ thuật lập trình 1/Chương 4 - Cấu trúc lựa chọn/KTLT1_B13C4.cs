using System;

public class Program {
    public static void Main(string[] args) {
        int[] day = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = int.Parse(Console.ReadLine());
        int year = int.Parse(Console.ReadLine());
        day[2] = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 29 : 28;
        Console.Write(day[month]);
    }
}