using System;

public class Program {
    public static void Main(string[] args) {
        string[] s = (Console.ReadLine()).Split(' ');
        int[] a = new int[s.Length];
        
        for (int i = 0; i < s.Length; i++)
            a[i] = int.Parse(s[i]);
        
        Console.Write(check(a));
    }
    
    static bool check(int[] a) {
        for (int i = 0; i < a.Length; i++)
            if ((a[i] & 1) == 1)    
                return false;
        return true;
    }
}