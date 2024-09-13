using System;

class Program {
    public static void Main(string[] args) {
        string[] s = (Console.ReadLine()).Split(' ');
        int n = s.Length;
        
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = int.Parse(s[i]);
            
        for (int i = 0; i < n; i++)
            if (a[i] % 2 == 0)
                Console.Write("{0} ", a[i]);
        Console.WriteLine();
        
        for (int i = 0; i < n; i++)
            if (a[i] % 2 != 0)
                Console.Write("{0} ", a[i]);
    }
}