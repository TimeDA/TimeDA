// package gcj2018.round1a;

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
            int r = in.nextInt();
            int b = in.nextInt();
            int c = in.nextInt();
            long[][] cashers = new long[c][3];
            for (int i = 0; i < c ; i++) {
                for (int j = 0; j < 3 ; j++) {
                    cashers[i][j] = in.nextLong();
                }
            }
            out.println(String.format("Case #%d: %d", t, solve(r, b, cashers)));
        }
        out.flush();


        // debug(solve(1, 1000000000, new long[][]{
        //         {1000000000, 1000000000, 1000000000},
        //         {3, 1, 1},
        //         {7, 2, 1},
        // }));
    }

    private static long solve(int r, int b, long[][] cashers) {
        long min = 0;
        long max = (long)4e18;
        while (max - min > 1) {
            long med = (max + min) / 2;
            if (isPossible(med, r, b, cashers)) {
                max = med;
            } else {
                min = med;
            }
        }
        return max;
    }

    private static boolean isPossible(long time, int r, int b, long[][] cashers) {
        int n = cashers.length;
        long[] acceptBits = new long[n];
        for (int i = 0; i < n ; i++) {
            long maxbit = cashers[i][0];
            long scanTime = cashers[i][1];
            long packtime = cashers[i][2];
            acceptBits[i] = Math.min(maxbit, Math.max(0, (time - packtime) / scanTime));
        }
        Arrays.sort(acceptBits);

        long total = 0;
        for (int i = 0; i < Math.min(r, n) ; i++) {
            total += acceptBits[n-1-i];
        }
        return total >= b;
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