import java.util.Scanner;

class SavingTheUniverseAgain {
    static String solve(int D, char[] P) {
        int d = 0;
        int p = 1;
        for (int i = 0; i < P.length; i++)
            if (P[i] == 'C')
                p <<= 1;
            else
                d += p;
        if(d <= D)
            return Integer.toString(0);
        int ans = 0;
        for(int i = P.length - 1; i >= 0; i--)
            if(P[i] == 'C') {
                p >>= 1;
                int j = i;
                for(; j + 1 < P.length && P[j + 1] == 'S'; j++) {
                    d -= p;
                    ans++;
                    if(d <= D)
                        return Integer.toString(ans);
                }
                if(j > i) {
                    P[j] = 'C';
                    P[i] = 'S';
                }
            }
        return "IMPOSSIBLE";
    }

    public static void main(String... args) {
        final Scanner sc = new Scanner(System.in);
        final int T = sc.nextInt();
        for (int c = 1; c <= T; c++) {
            final int D = sc.nextInt();
            final char[] P = sc.next().toCharArray();
            System.out.printf("Case #%d: %s\n", c, solve(D, P));
        }
    }
}
public class Solution {
    public static void main(String...args) {
        SavingTheUniverseAgain.main();
    }
}