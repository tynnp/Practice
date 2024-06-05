import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        int a, b, c;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        
        c = a;
        a = b;
        b = c;
        
        System.out.print(a + " " + b);
    }
}