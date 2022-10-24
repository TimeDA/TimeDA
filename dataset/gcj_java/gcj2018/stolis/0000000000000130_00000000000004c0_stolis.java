import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            int N = in.nextInt();
            int[] P = new int[N];
            int max = 0;
            for (int n = 0; n < N; n++) {
                int count = in.nextInt();
                P[n] = count;
                if (count > max) {
                    max = count;
                }
            }

            StringBuilder answer = new StringBuilder();

            if (N == 2) {
                for (int i = 0; i < P[0]; i++) {
                    answer.append(" AB");
                }
            } else {
                for (int i = max; i > 0; i--) {
                    for (int n=0; n < N; n++) {
                        if (P[n] == i) {
                            P[n]--;
                            answer.append(' ').append((char) ('A' + n));
                        }
                    }
                }
                int length = answer.length();
                answer.setCharAt(length-2, answer.charAt(length-1));
                answer.setLength(length-1);
            }

            System.out.printf("Case #%d:%s\n", t, answer);
        }

    }

}
