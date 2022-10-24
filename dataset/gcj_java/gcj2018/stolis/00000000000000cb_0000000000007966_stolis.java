import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t=1; t<=T; t++) {
            long D = in.nextLong();
            char[] s = in.next().toCharArray();
            int min = 0;
            for (char c : s) {
                if (c == 'S') min++;
            }
            String answer;
            if (D < min) {
                answer = "IMPOSSIBLE";
            } else {
                int swaps = 0;
                while (damage(s) > D) {
                    int i = s.length-1;
                    while (s[i] != 'S' || s[i-1] != 'C') i--;
                    s[i] = 'C';
                    s[i-1] = 'S';
                    swaps ++;
                }
                answer = Integer.toString(swaps);
            }
            System.out.printf("Case #%d: %s\n", t, answer);
        }
    }

    private static long damage(char[] s) {
        long charge = 1;
        long damage = 0;
        for (char c : s) {
            if (c == 'S') {
                damage += charge;
            } else {
                charge *= 2;
            }
        }
        return damage;
    }

}
