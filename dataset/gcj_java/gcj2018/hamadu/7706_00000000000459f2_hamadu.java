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
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }

            List<String> res = solve(a);
            StringBuilder lin = new StringBuilder();
            if (res == null) {
                lin.append("IMPOSSIBLE");
            } else {
                lin.append(res.size());
                for (String r : res) {
                    lin.append("\n").append(r);
                }
            }
            out.println(String.format("Case #%d: %s", t, lin.toString()));
        }
        out.flush();
    }

    private static List<String> solve(int[] a) {
        int n = a.length;
        if (a[0] == 0 || a[n-1] == 0) {
            return null;
        }
        int[] L = new int[n];
        int[] R = new int[n];

        int left = 0;
        for (int c = 0 ; c < n ; c++) {
            if (a[c] >= 1) {
                int from = left;
                int to = left + a[c] - 1;
                int placeL = from < c ? c - from : 0;
                int placeR = c < to ? to - c : 0;
                L[from] = placeL;
                R[to] = placeR;
                left += a[c];
            }
        }

        int max = 0;
        for (int i = 0; i < n ; i++) {
            max = Math.max(max, L[i]);
            max = Math.max(max, R[i]);
        }

        char[][] table =new char[max+1][n];
        for (int i = 0; i <= max ; i++) {
            Arrays.fill(table[i], '.');
        }
        for (int i = 0; i < n ; i++) {
            if (L[i] >= 1) {
                for (int h = 0 ; h < L[i] ; h++) {
                    table[h][i+h] = '\\';
                }
            } else if (R[i] >= 1) {
                for (int h = 0 ; h < R[i] ; h++) {
                    table[h][i-h] = '/';
                }
            }
        }

        List<String> pl = new ArrayList<>();
        for (int i = 0 ; i < table.length ; i++) {
            pl.add(String.valueOf(table[i]));
        }
        return pl;
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