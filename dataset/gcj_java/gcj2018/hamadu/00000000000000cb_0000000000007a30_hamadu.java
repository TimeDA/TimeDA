// package gcj2018.qual;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Solution {
    static InputReader in;
    static PrintWriter out;
    static int[][] field;

    static final int SMALL_A = 20;
    static final int LARGE_A = 200;
    static final int MAX_NUMBER_OF_DEPLOYMENT = 1000;

    static final int[] DX = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    static final int[] DY = {-1, -1, -1, 0, 0, 0, 1, 1, 1};

    public static void main(String[] args) {
        in = new InputReader(System.in);
        out = new PrintWriter(System.out);
        field = new int[60][60];

        int T = in.nextInt();
        for (int t = 1; t <= T ; t++) {
            for (int i = 0; i < field.length; i++) {
                Arrays.fill(field[i], 0);
            }
            solve();
        }

        out.flush();
    }

    private static void solve() {
        int A = in.nextInt();
        int w, h;
        if (A == SMALL_A) {
            w = 5;
            h = 4;
        } else if (A == LARGE_A) {
            w = 20;
            h = 10;
        } else {
            throw new RuntimeException("invalid A");
        }

        int count = 0;
        int g = 5;
        for (int c = 0 ; c < MAX_NUMBER_OF_DEPLOYMENT ; c++) {
            int bestI = -1;
            int bestJ = -1;
            int bestScore = 0;
            sch: for (int i = g ; i < g+h-2 ; i++) {
                for (int j = g; j < g+w-2 ; j++) {
                    int score = 0;
                    for (int d = 0 ; d < 9 ; d++) {
                        if (field[i+DY[d]][j+DX[d]] == 0) {
                            score++;
                        }
                    }
                    if (bestScore < score) {
                        bestScore = score;
                        bestI = i;
                        bestJ = j;
                    }
                    if (bestScore == 9) {
                        break sch;
                    }
                }
            }
            int[] res = doit(bestI, bestJ, false);
            if (res[0] == 0 && res[1] == 0) {
                // OK
                return;
            } else if (field[res[0]][res[1]] == 0) {
                field[res[0]][res[1]] = 1;
                count++;
            }

            if (count == A) {
//                debug("ok", c, MAX_NUMBER_OF_DEPLOYMENT);
//                for (int i = 0; i < field.length; i++) {
//                    for (int j = 0; j < field[0].length; j++) {
//                        out.print(field[i][j]);
//                    }
//                    out.println();
//                }
                return;
            }
        }
    }

    private static int[] doit(int i, int j, boolean debug) {
        out.println(String.format("%d %d", i, j));
        out.flush();
        int I, J;
        if (debug) {
            I = (int)(Math.random() * 3) + i - 1;
            J = (int)(Math.random() * 3) + j - 1;
        } else {
            I = in.nextInt();
            J = in.nextInt();
        }

        if (I == -1 || J == -1) {
            throw new RuntimeException("failed");
        }
        return new int[]{I, J};
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