// package gcj2018.round2;

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
        for (int t = 1; t <= T ; t++) {
            int n = in.nextInt();
            int[][] tbl = new int[n][n];
            for (int i = 0; i < n ; i++) {
                for (int j = 0; j < n ; j++) {
                    tbl[i][j] = in.nextInt();
                }
            }
            out.println(String.format("Case #%d: %d", t, solve(tbl)));
        }
        out.flush();
    }

    private static int solve(int[][] t) {
        int n = t.length;

        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < n ; j++) {
                t[i][j] = (t[i][j] <= -1) ? n + Math.abs(t[i][j]) : t[i][j];
                t[i][j]--;
            }
        }

        int cost = 0;
        for (int a = 0; a < 2*n; a++) {
            boolean[] picked = new boolean[n];
            for (int i = 0; i < n ; i++) {
                int lcost = n;
                int best = -1;
                int wex = 0;
                for (int j = 0; j < n ; j++) {
                    if (picked[j] || t[i][j] != a) {
                        continue;
                    }
                    wex++;
                    int wc = 0;
                    for (int ti = i+1 ; ti < n ; ti++) {
                        if (t[ti][j] == a) {
                            wc++;
                        }
                    }
                    if (lcost > wc) {
                        lcost = wc;
                        best = j;
                    }
                }
                if (best == -1) {
                    continue;
                }
                picked[best] = true;
                cost += lcost + wex - 1;
            }
        }
        return cost;
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