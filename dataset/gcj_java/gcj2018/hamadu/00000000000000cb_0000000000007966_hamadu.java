import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Solution {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);

        int n = in.nextInt();
        for (int t = 1; t <= n ; t++) {
            long d = in.nextInt();
            char[] program = in.nextToken().toCharArray();
            int result = solve(d, program);
            out.println(String.format("Case #%d: %s", t, (result == -1 ? "IMPOSSIBLE" : result)));
        }
        out.flush();
    }

    private static int solve(long d, char[] program) {
        int min = 0;
        for (char p : program)
            if (p == 'S') {
            min++;
        }
        if (d < min) {
            return -1;
        }
        int count = 0;
        while (eval(program) > d) {
            long mincost = Long.MAX_VALUE;
            char[] mintp = null;
            for (int i = 0; i+1 < program.length; i++) {
                char[] tp = program.clone();
                char c = tp[i];
                tp[i] = tp[i+1];
                tp[i+1] = c;
                long tc = eval(tp);
                if (tc < mincost) {
                    mincost = tc;
                    mintp = tp;
                }
            }
            if (mintp != null) {
                program = mintp.clone();
            }
            count++;
        }
        return count;
    }

    private static long eval(char[] program) {
        long total = 0;
        long power = 1;
        for (char c : program) {
            if (c == 'S') {
                total += power;
            } else {
                power *= 2;
            }
        }
        return total;
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