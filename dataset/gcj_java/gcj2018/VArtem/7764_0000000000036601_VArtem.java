import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Collections;
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
        RoundingError solver = new RoundingError();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class RoundingError {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            out.printf("Case #%d: ", testNumber);

            int n = in.nextInt(), l = in.nextInt();
            int[] a = new int[n];
            int sum = n;
            for (int i = 0; i < l; i++) {
                a[i] = in.nextInt();
                sum -= a[i];
            }
            if (n <= 201) {
                long result = small(n, a, sum);
                out.println(result / n);
            } else {
                long result = 0;
                List<Integer> ops = new ArrayList<>();
                for (int i = 0; i < n; i++) {
                    int val = 100 * a[i] % n;
                    result -= val;
                    if (val < n) {
                        ops.add(((n + 1) / 2 - val + 99) / 100);
                    } else {
                        result += n;
                    }
                }
                Collections.sort(ops);
                int initSum = sum;
                for (int i : ops) {
                    if (i <= sum) {
                        sum -= i;
                        result -= 100 * i;
                        result += n;
                    }
                }
                result -= 100 * sum;
                result += 100 * n;
                if (result % n != 0) {
                    throw new AssertionError();
                }
//            if (result != small(n, a, initSum)) {
//                throw new AssertionError();
//            }
                out.println(result / n);
            }
        }

        private long small(int n, int[] a, int sum) {
            long[][] dp = new long[n + 1][sum + 1];
            long INF = Long.MIN_VALUE / 3;
            for (long[] i : dp) {
                Arrays.fill(i, INF);
            }
            dp[0][sum] = 0;
            for (int i = 0; i < n; i++) {
                for (int s = 0; s <= sum; s++) {
                    if (dp[i][s] != INF) {
                        for (int cur = 0; cur <= s; cur++) {
                            long val = 100 * (a[i] + cur) % n;
                            if (val * 2 >= n) {
                                dp[i + 1][s - cur] = Math.max(dp[i + 1][s - cur], dp[i][s] - val + n);
                            } else {
                                dp[i + 1][s - cur] = Math.max(dp[i + 1][s - cur], dp[i][s] - val);
                            }
                        }
                    }
                }
            }
            long result = (100 * n + dp[n][0]);
            if (result % n != 0) {
                System.err.println(result + " " + n);
                throw new AssertionError();
            }
            return result;
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

