import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
    private BufferedReader in;
    private StringTokenizer tok;
    private PrintWriter out;

    //------------------------------------------------------------------------------
    public static void main(String[] args) {
        new Solution().run();
    }

    private void solve() throws IOException {
        int T = readInt();
        for (int t = 1; t <= T; t++) {
            solveTest(t);
        }
    }

    private static class Cashier {
        long m, s, p;

        private Cashier(long m, long s, long p) {
            this.m = m;
            this.s = s;
            this.p = p;
        }
    }

    private void solveTest(int t) throws IOException {
        out.printf("Case #%d: ", t);
        int R = readInt();
        long B = readLong();
        int C = readInt();
        Cashier[] cashiers = new Cashier[C];
        for (int i = 0; i < C; i++) {
            cashiers[i] = new Cashier(readLong(), readLong(), readLong());
        }
        long left = 1;
        long right = (long) 1e18;
        long ans = -1;
        while (left <= right) {
            long mid = (left + right) / 2;
            if (can(R, B, C, cashiers, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (ans == -1) {
            throw new AssertionError();
        }
        out.println(ans);
    }

    private boolean can(int R, long B, int C, Cashier[] cashiers, long T) {
        long[] dp1 = new long[R + 1];
        long[] dp2 = new long[R + 1];
        for (int c = 0; c < C; c++) {
            //noinspection ManualArrayCopy
            for (int r = 0; r <= R; r++) {
                dp2[r] = dp1[r];
            }
            for (int r = 0; r < R; r++) {
                // T <= s * bits + p
                // (T - p) / s <= bits
                long bits = Math.min(cashiers[c].m, (T - cashiers[c].p) / cashiers[c].s);
                bits = Math.min(bits, B - dp1[r]);
                bits = Math.max(bits, 0);
                dp2[r + 1] = Math.max(dp2[r + 1], dp1[r] + bits);
            }
            long[] tmp = dp1;
            dp1 = dp2;
            dp2 = tmp;
        }
        return dp1[R] >= B;
    }

    private void run() {
        try {
            initIO();
            solve();
            in.close();
            out.close();
        } catch (Throwable e) {
            throw new RuntimeException(e);
        }
    }

    private void initIO() throws IOException {
        if (new File("input.txt").exists()) {
            in = new BufferedReader(new FileReader(new File("input.txt")));
            out = new PrintWriter(new File("output.txt"));
        } else {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        }
    }

    private String readString() throws IOException {
        while (tok == null || !tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    @SuppressWarnings("unused")
    private int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    @SuppressWarnings("unused")
    private long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    @SuppressWarnings("unused")
    private double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }
}
