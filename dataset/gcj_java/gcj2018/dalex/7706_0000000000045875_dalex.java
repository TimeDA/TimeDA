import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Solution {
    private BufferedReader in;
    private StringTokenizer tok;
    private PrintWriter out;

    //------------------------------------------------------------------------------
    public static void main(String[] args) {
        new Solution().run();
    }

    private void solve() throws IOException {
        int T = readInt();
        for (int t = 1; t <= T; t++) {
            solveTest(t);
        }
    }

    private void solveTest(int t) throws IOException {
        out.printf("Case #%d: ", t);
        int n = readInt();
        int[][] a = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = readInt();
            }
        }
        int minAns = Integer.MAX_VALUE;
        boolean[][] canChange = new boolean[n][n];
        for (int mask = 0; mask < (1 << (n * n)); mask++) {
            for (int bit = 0; bit < n * n; bit++) {
                if (((1 << bit) & mask) != 0) {
                    canChange[bit / n][bit % n] = true;
                } else {
                    canChange[bit / n][bit % n] = false;
                }
            }
            boolean ok = true;
            outer:
            for (int r = 0; ok && r < n; r++) {
                for (int c1 = 0; c1 < n; c1++) {
                    for (int c2 = c1 + 1; c2 < n; c2++) {
                        if (!canChange[r][c1] && !canChange[r][c2] && a[r][c1] == a[r][c2]) {
                            ok = false;
                            break outer;
                        }
                    }
                }
            }
            outer:
            for (int c = 0; ok && c < n; c++) {
                for (int r1 = 0; r1 < n; r1++) {
                    for (int r2 = r1 + 1; r2 < n; r2++) {
                        if (!canChange[r1][c] && !canChange[r2][c] && a[r1][c] == a[r2][c]) {
                            ok = false;
                            break outer;
                        }
                    }
                }
            }
            if (ok) {
                minAns = Math.min(minAns, Integer.bitCount(mask));
            }
        }
        out.println(minAns);
    }

    private void run() {
        try {
            initIO();
            solve();
            in.close();
            out.close();
        } catch (Throwable e) {
            throw new RuntimeException(e);
        }
    }

    private void initIO() throws IOException {
        if (new File("input.txt").exists()) {
            in = new BufferedReader(new FileReader(new File("input.txt")));
            out = new PrintWriter(new File("output.txt"));
        } else {
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
        }
    }

    private String readString() throws IOException {
        while (tok == null || !tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    @SuppressWarnings("unused")
    private int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    @SuppressWarnings("unused")
    private long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    @SuppressWarnings("unused")
    private double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }
}
