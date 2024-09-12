using System;

public class Program {
    public static void Main(string[] args) {
        string[] s = (Console.ReadLine()).Split(' ');
        int n = s.Length;
        double[] a = new double[n];
        
        for (int i = 0; i < n; i++)
            a[i] = double.Parse(s[i]);
        
        sort(a, n);
        for (int i = 0; i < n; i++)
            Console.Write("{0} ", a[i]);
    }
    
    static void sort(double[] a, int n) {
        for (int i = 0; i < n; i++) {
            int min_idx = i;
            
            for (int j = i+1; j < n; j++)
                if (a[min_idx] > a[j])
                    min_idx = j;
            
            swap(ref a[min_idx], ref a[i]);
        }
    }
    
    static void swap(ref double a, ref double b) {
        double c = a;
        a = b;
        b = c;
    }
}