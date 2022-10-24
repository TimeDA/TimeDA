import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Solution {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        GracefulChainsawJugglers solver = new GracefulChainsawJugglers();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class GracefulChainsawJugglers {
        int MAX_ANS = 120;
        int MAX_RED = 50;
        int INF = Integer.MAX_VALUE / 3;
        int[][][] dp;

        void calcDp() {
            dp = new int[500 + 1][MAX_RED + 1][MAX_ANS];
            for (int[][] i : dp) {
                for (int[] j : i) {
                    Arrays.fill(j, INF);
                }
            }
            dp[0][0][0] = 0;
            for (int usedR = 0; usedR <= 500; usedR++) {
                for (int curRed = 0; curRed < MAX_RED; curRed++) {
                    for (int ans = 0; ans < MAX_ANS; ans++) {
                        if (dp[usedR][curRed][ans] > 500) {
                            continue;
                        }

                        int cntBlue = dp[usedR][curRed][ans];
                        for (int toUse = 0; toUse < MAX_RED && ans + toUse < MAX_ANS; toUse++) {
                            int costBlues = 0;
                            if (curRed == 0) {
                                costBlues = (toUse + 1) * toUse / 2;
                            } else {
                                costBlues = (toUse - 1) * toUse / 2;
                            }
                            if (cntBlue + costBlues > 500) {
                                break;
                            }
                            if (usedR + toUse * curRed > 500) {
                                break;
                            }
                            dp[usedR + toUse * curRed][curRed + 1][ans + toUse] = Math.min(dp[usedR + toUse * curRed][curRed + 1][ans + toUse], cntBlue + costBlues);
                        }
                    }
                }
            }
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            out.printf("Case #%d: ", testNumber);
            int r = in.nextInt(), b = in.nextInt();
            if (dp == null) {
                calcDp();
            }

            int ans = 0;
            for (int i = 0; i <= r; i++) {
                for (int j = 0; j <= MAX_RED; j++) {
                    for (int k = 0; k < MAX_ANS; k++) {
                        if (dp[i][j][k] <= b) {
                            ans = Math.max(ans, k);
                        }
                    }
                }
            }
            out.println(ans);
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }
}

