import java.util.Scanner;

class GracefulChainsawJugglers {
    static int solve(int R, int B) {
        int max = 0;
        for (int rMax = 0; rMax <= R; rMax++) {
            int ans = -1;
            int resR = R;
            int resB = B;
            for (int b = 0; b <= resB && resB > 0; b++)
                for (int r = 0; r <= rMax && r <= resR && b <= resB && resB > 0; r++) {
                    ans++;
                    resR -= r;
                    resB -= b;
                }
            if (ans > max)
                max = ans;
        }
        return max;
    }

    public static void main(String... args) {
        final Scanner sc = new Scanner(System.in);
        final int T = sc.nextInt();
        for (int c = 1; c <= T; c++) {
            final int R = sc.nextInt();
            final int B = sc.nextInt();
            System.out.printf("Case #%d: %s\n", c, Math.max(solve(R, B), solve(B, R)));
        }
    }
}
public class Solution {
    public static void main(String...args) {
        GracefulChainsawJugglers.main();
    }
}