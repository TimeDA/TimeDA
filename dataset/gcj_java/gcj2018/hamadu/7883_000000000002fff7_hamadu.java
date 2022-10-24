import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Solution {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int T = in.nextInt();
        for (int t = 1; t <= T ; t++) {
            int n = in.nextInt();
            double p = in.nextDouble();
            int[][] cookies = new int[n][2];
            for (int i = 0; i < n ; i++) {
                cookies[i][0] = in.nextInt();
                cookies[i][1] = in.nextInt();
            }
            out.println(String.format("Case #%d: %.9f", t, solve(p, cookies)));
        }
        out.flush();
    }

    static double[][] dp = new double[2][35000];

    private static double solve(double p, int[][] cookies) {
        int n = cookies.length;
        double defaultSum = 0;
        for (int i = 0; i < n ; i++) {
            defaultSum += (cookies[i][0] + cookies[i][1]) * 2;
        }

        Arrays.fill(dp[0], -1);
        dp[0][0] = 0;
        for (int i = 0; i < n ; i++) {
            int fr = i % 2;
            int to = 1 - fr;
            int add = Math.min(cookies[i][0], cookies[i][1]);
            double maxadd = Math.hypot(cookies[i][0], cookies[i][1]);
            Arrays.fill(dp[to], -1);
            for (int k = 0; k < dp[0].length ; k++) {
                if (dp[fr][k] < 0) {
                    continue;
                }
                double base = dp[fr][k];
                dp[to][k] = Math.max(dp[to][k], base);
                dp[to][k+add] = Math.max(dp[to][k+add], base + maxadd);
            }
        }

        double best = defaultSum;
        for (int i = 0; i < dp[0].length; i++) {
            if (defaultSum + i * 2 <= p && dp[n%2][i] >= 0) {
                double to = defaultSum + dp[n%2][i] * 2;
                best = Math.max(best, Math.min(p, to));
            }
        }
        return best;
    }

    public static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    public static class InputReader {
        private static final int BUFFER_LENGTH = 1 << 12;
        private InputStream stream;
        private byte[] buf = new byte[BUFFER_LENGTH];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int next() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public char nextChar() {
            return (char) skipWhileSpace();
        }

        public String nextToken() {
            int c = skipWhileSpace();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public long nextLong() {
            int c = skipWhileSpace();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        int skipWhileSpace() {
            int c = next();
            while (isSpaceChar(c)) {
                c = next();
            }
            return c;
        }

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
}