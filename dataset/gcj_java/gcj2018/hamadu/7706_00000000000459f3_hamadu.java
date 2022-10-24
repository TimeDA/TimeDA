import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class Solution {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int T = in.nextInt();

        dp = new int[2][501][501];
        ans = new int[501][501];
        solve(500, 500);

        for (int t = 1; t <= T ; t++) {
            int R = in.nextInt();
            int B = in.nextInt();

            int res = Math.max(solve(R, B), solve(B, R));
            out.println(String.format("Case #%d: %d", t, res));
        }
        out.flush();
    }

    static int[][][] dp;
    static int[][] ans;
    static int comp = 1;

    private static int solve(int R, int B) {
        if (comp == 0) {
            int ret = 0;
            for (int i = 0; i <= R; i++) {
                for (int j = 0; j <= B; j++) {
                    ret = Math.max(ret, ans[i][j]);
                }
            }
            return ret;
        }

        comp = 0;
        int[] bc = new int[501];
        for (int i = 1 ; i <= bc.length-1 ; i++) {
            bc[i] = bc[i-1] + i;
        }

        for (int i = 0; i <= R; i++) {
            Arrays.fill(dp[0][i], -1);
            Arrays.fill(dp[1][i], -1);
        }
        dp[0][0][0] = 0;

        for (int i = 0 ; i <= R ; i++) {
            int fr = i % 2;
            int to = 1 - fr;
            for (int j = 0; j <= R; j++) {
                Arrays.fill(dp[to][j], -1);
            }
            for (int j = 0; j <= R ; j++) {
                for (int k = 0; k <= B; k++) {
                    int base = dp[fr][j][k];
                    if (base == -1) {
                        continue;
                    }
                    for (int ub = 0 ; j + i * (ub+1) <= R && k + bc[ub] <= B && ub <= B ; ub++) {
                        int add = i == 0 ? ub : ub+1;
                        int tj = j+i*(ub+1);
                        int tk = k+bc[ub];
                        dp[to][tj][tk] = Math.max(dp[to][tj][tk], base+add);
                        ans[tj][tk] = Math.max(ans[tj][tk], dp[to][tj][tk]);
                    }
                }
            }
        }
        return 0;
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