// package gcj2018.round1a;

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
            int r = in.nextInt();
            int c = in.nextInt();
            int h = in.nextInt();
            int v = in.nextInt();
            int[][] table = new int[r][c];
            for (int i = 0; i < r ; i++) {
                char[] l = in.nextToken().toCharArray();
                for (int j = 0; j < c ; j++) {
                    table[i][j] = l[j] == '.' ? 0 : 1;
                }
            }
            out.println(String.format("Case #%d: %s", t, (solve(table, h, v)  ? "POSSIBLE" : "IMPOSSIBLE")));
        }
        out.flush();

//        debug(solve(new int[][]{
//                {0,0,0,0,0},
//                {0,1,0,1,0},
//                {0,0,0,0,0},
//                {0,0,0,0,0},
//                {0,0,0,0,0},
//                {0,0,0,0,0},
//                {0,1,0,1,0},
//                {0,0,0,0,0}
//        }, 1, 1));
    }



    private static boolean solve(int[][] table, int h, int v) {
        int n = table.length;
        int m = table[0].length;


        int[][] imos = new int[n+1][m+1];
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < m ; j++) {
                imos[i+1][j+1] = imos[i+1][j] + imos[i][j+1] - imos[i][j] + table[i][j];
            }
        }

        int total = imos[n][m];
        int piece = (h+1)*(v+1);
        if (total % piece != 0) {
            return false;
        }
        if (total == 0) {
            return true;
        }

        List<Integer> hcut = new ArrayList<>();
        {
            hcut.add(0);
            int perh = total / (h+1);
            for (int i = 0; i < n; ) {
                int j = i;
                while (j < n && rangeSum(imos, 0, i, m, j) < perh) {
                    j++;
                }
                if (rangeSum(imos, 0, i, m, j) != perh) {
                    return false;
                }
                hcut.add(j);
                if (hcut.size() == h+1) {
                    hcut.add(n);
                    break;
                }
                i = j;
            }
            if (hcut.size() != h+2) {
                return false;
            }
        }

        List<Integer> vcut = new ArrayList<>();
        {
            vcut.add(0);
            int perv = total / (v+1);
            for (int i = 0; i < m; ) {
                int j = i;
                while (j < m && rangeSum(imos, i, 0, j, n) < perv) {
                    j++;
                }
                if (rangeSum(imos, i, 0, j, n) != perv) {
                    return false;
                }
                vcut.add(j);
                if (vcut.size() == v+1) {
                    vcut.add(m);
                    break;
                }

                i = j;
            }

            if (vcut.size() != v+2) {
                return false;
            }
        }


        for (int i = 0; i+1 < vcut.size() ; i++) {
            for (int j = 0; j+1 < hcut.size() ; j++) {
                int fx = vcut.get(i);
                int tx = vcut.get(i+1);
                int fy = hcut.get(j);
                int ty = hcut.get(j+1);
                if (rangeSum(imos, fx, fy, tx, ty) != (total / piece)) {
                    return false;
                }
            }
        }


        return true;
    }

    private static int rangeSum(int[][] imos, int fx, int fy, int tx, int ty) {
        return imos[ty][tx] - imos[ty][fx] - imos[fy][tx] + imos[fy][fx];
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