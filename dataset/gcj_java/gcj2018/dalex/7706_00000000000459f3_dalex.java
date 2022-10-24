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

    private static class Man {
        int r, b;

        Man(int r, int b) {
            this.r = r;
            this.b = b;
        }
    }

    private void solveTest(int t) throws IOException {
        out.printf("Case #%d: ", t);
        int R = readInt();
        int B = readInt();
//        for (int N = 0; N <= 20; N++) {
//            System.err.println("prec = " + Arrays.toString(getPrecalc(N)));
//        }
//        if (true) return;
        List<Man> men = new ArrayList<>();
        for (int r = 0; r <= R; r++) {
            for (int b = 0; b <= B; b++) {
                if (r > 0 || b > 0) {
                    men.add(new Man(r, b));
                }
            }
        }
        int[][] cur = new int[R + 1][B + 1];
        int[][] nxt = new int[R + 1][B + 1];
        for (Man man : men) {
            int manR = man.r;
            int manB = man.b;
            for (int r = 0; r <= R; r++) {
                for (int b = 0; b <= B; b++) {
                    if (r + manR <= R && b + manB <= B) {
                        nxt[r + manR][b + manB] = Math.max(nxt[r + manR][b + manB], cur[r][b] + 1);
                    }
                }
            }
            for (int r = 0; r <= R; r++) {
                for (int b = 0; b <= B; b++) {
                    cur[r][b] = nxt[r][b];
                }
            }
        }
        out.println(cur[R][B]);
    }

    /*private int[] getPrecalc(int N) {
        int[] cur = new int[N + 1];
        int[] nxt = new int[N + 1];
        cur[0] = nxt[0] = 1;
        for (int x = 1; x <= N; x++) {
            for (int i = 0; i <= N; i++) {
                if (i + x <= N) {
                    nxt[i + x] = Math.max(nxt[i + x], cur[i] + 1);
                }
            }
            for (int i = 0; i <= N; i++) {
                cur[i] = nxt[i];
            }
        }
        return cur;
    }*/

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
