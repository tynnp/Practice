using System;

public class Program {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        int[] a = new int[n];
        
        for (int i = 0; i < n; i++)
            a[i] = int.Parse(Console.ReadLine());
            
        sort(a, n);
        for (int i = 0; i < n; i++)
            Console.Write("{0} ", a[i]);
    }
    
    static void sort(int[] a, int n) {
        for (int i = 0; i < n; i++) {
            int min_idx = i;
            
            for (int j = i+1; j < n; j++) 
                if (a[min_idx] > a[j])
                    min_idx = j;
                    
            swap(ref a[min_idx], ref a[i]);
        }
    }
    
    static void swap(ref int a, ref int b) {
        int c = a;
        a = b;
        b = c;
    }
}