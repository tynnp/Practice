using System;

public class Program {
    static void Main(string[] args) {
        string s = Console.ReadLine();
        string[] t = s.Split(' ');
        int[] a =  new int[t.Length];
        
        for (int i = 0; i < t.Length; i++)
            a[i] = int.Parse(t[i]);
        for (int i = 0; i < t.Length; i++)
            Console.Write("{0} ", a[i]);
    }
}