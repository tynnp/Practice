using System;

public class Program {
    public static void Main(string[] args) {
        string[] s = (Console.ReadLine()).Split(' ');
        int x = int.Parse(Console.ReadLine());
        int n = s.Length;
        int[] a = new int[n];
        
        for (int i = 0; i < n; i++) 
            a[i] = int.Parse(s[i]);
            
        a = remove(a, ref n, x);
        
        for (int i = 0; i < n; i++)
            Console.Write("{0} ", a[i]);
    }
    
    static int find(int[] a, int n, int x) {
        for (int i = 0; i < n; i++)
            if (a[i] == x)
                return i;
        return -1;
    }
    
    static int[] remove(int[] a, ref int n, int x) {
        int[] res = new int[n];
        int k = 0;
        
        for (int i = 0; i < n; i++) 
            if (a[i] != x)
                res[k++] = a[i];
        
        n = k;
        return res;
    }
} 