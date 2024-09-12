using System;

public class Program {
    static void Main(string[] args) {
        string[] s = (Console.ReadLine()).Split(' ');
        int[] a = new int[s.Length];
        int n = s.Length;
        
        for (int i = 0; i < n; i++)
            a[i] = int.Parse(s[i]);
            
        sort(a, n);
        for (int i = 0; i < n; i++)
            Console.Write("{0} ", a[i]);
    }
    
    static void sort(int[] a, int n) {
        for (int i = 0; i < n; i++) {
            int max_idx = i;
            
            for (int j = i+1; j < n; j++)
                if (a[max_idx] < a[j])
                    max_idx = j;
            
            swap(ref a[max_idx], ref a[i]);
        }
    }
    
    static void swap(ref int a, ref int b) {
        int c = a;
        a = b;
        b = c;
    }
}