import java.util.Scanner;

public class Solution { // Number Guessing

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t=1; t<=T; t++) {
            int low = in.nextInt() + 1;
            int high = in.nextInt();
            in.nextInt(); // N
            while (true) {
                int guess = (low + high)/2;
                System.out.println(guess);
                System.out.flush();
                String result = in.next();
                if ("CORRECT".equals(result)) {
                    break;
                } else if ("TOO_SMALL".equals(result)) {
                    low = guess + 1;
                } else { // TOO_BIG
                    high = guess - 1;
                }
            }
        }
    }

}
