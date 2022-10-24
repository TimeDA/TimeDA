import java.util.Arrays;
import java.util.Scanner;

class BitParty {
    static final long MAX = Long.MAX_VALUE >> 1;

    static boolean check(long time, int R, int B, int C, int[] M, int[] S, int[] P) {
        final long[] nums = new long[C];
        for (int i = 0; i < C; i++)
            nums[i] = Math.min(M[i], Math.max((time - P[i]), 0) / S[i]);
        Arrays.sort(nums);
        long sum = 0;
        for (int i = C - 1; i >= C - R; i--)
            sum += nums[i];
        return sum >= B;
    }

    static long solve(int R, int B, int C, int[] M, int[] S, int[] P) {
        long ok = 1;
        while (!check(ok, R, B, C, M, S, P))
            if (ok >= MAX)
                ok = Long.MAX_VALUE;
            else
                ok <<= 1;
        long ng = ok >> 1;
        while (ok - ng > 1) {
            final long x = (ok + ng) / 2;
            if (check(x, R, B, C, M, S, P))
                ok = x;
            else
                ng = x;
        }
        return ok;
    }

    public static void main(String... args) {
        final Scanner sc = new Scanner(System.in);
        final int T = sc.nextInt();
        for (int c = 1; c <= T; c++) {
            final int R = sc.nextInt();
            final int B = sc.nextInt();
            final int C = sc.nextInt();
            final int[] M = new int[C];
            final int[] S = new int[C];
            final int[] P = new int[C];
            for (int i = 0; i < C; i++) {
                M[i] = sc.nextInt();
                S[i] = sc.nextInt();
                P[i] = sc.nextInt();
            }
            System.out.printf("Case #%d: %s\n", c, solve(R, B, C, M, S, P));
        }
    }
}


public class Solution {
    public static void main(String...args) {
        BitParty.main();
    }
}