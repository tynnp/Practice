import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, res = 0;
        n = sc.nextInt();

        for (int i = 2; i < n/2; i++)
            res += (n % i == 0 ? n/i + i : 0);

        if (n == res + 1) System.out.println("Yes");
        else System.out.println("No");
    }
}