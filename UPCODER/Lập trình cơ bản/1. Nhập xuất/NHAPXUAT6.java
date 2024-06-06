import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char a, b;
        a = sc.next().charAt(0);
        b = sc.next().charAt(0);
        System.out.print((int) a + (int) b);
    }
}