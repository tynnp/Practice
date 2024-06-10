import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        if ((int) Math.sqrt(n) == Math.sqrt(n))
            System.out.print("yes");
        else 
            System.out.print("no");
    }
}
