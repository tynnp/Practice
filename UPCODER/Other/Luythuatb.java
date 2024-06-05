import java.util.Scanner;

class Main {
    public static long binaryMul(long a, long b, long m) {
        long res = 0;
        a = a % m;
        
        while (b > 0) {
            if (b % 2 != 0) res = (res + a) % m;
            a = (a << 1) % m;
            b = b / 2;
        }
        return res;
    }
    
    public static long binaryPow(long a, long b, long m) {
        long res = 1;
        a = a % m;
        
        while (b > 0) {
            if (b % 2 != 0) res = binaryMul(res, a, m);
            a = binaryMul(a, a, m);
            b /= 2;
        }
        
        return res;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long ans = binaryPow(a, b, 1000000007);
        System.out.print(ans);
    }
}
