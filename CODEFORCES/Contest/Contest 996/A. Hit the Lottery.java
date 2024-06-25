import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] money = {100, 20, 10, 5, 1};
        int n, ans = 0;
        
        n = sc.nextInt();
        for (int i = 0; i < 5; i++) {
            ans += n/money[i];
            n %= money[i];
        }
        
        System.out.print(ans);
    }
}