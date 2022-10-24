import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
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
        int m = readInt();
        int[] cnt = new int[m];
        for (int i = 0; i < m; i++) {
            cnt[i] = readInt();
        }
        if (cnt[0] == 0 || cnt[m - 1] == 0) {
            out.println("IMPOSSIBLE");
            return;
        }
        int l = 1, r = m + 1, ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            char[][] field = f(mid, m, cnt);
            if (field != null) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (ans == -1) {
            throw new AssertionError();
        }
        char[][] field = f(ans, m, cnt);
        if (field == null) {
            throw new AssertionError();
        }
        if (ans != field.length) {
            throw new AssertionError();
        }
        out.println(ans);
        for (char[] arr : field) {
            out.println(new String(arr));
        }
    }

    private char[][] f(int n, int m, int[] cnt) {
        char[][] field = new char[n][m];
        for (char[] arr : field) {
            Arrays.fill(arr, '.');
        }
        try {
            int firstNotUsedColumn = 0;
            for (int i = 0; i < m; i++) {
                if (cnt[i] > 0) {
                    int cntLeft, cntRight;
                    if (firstNotUsedColumn <= i) {
                        cntLeft = i - firstNotUsedColumn;
                        cntRight = Math.max(0, cnt[i] - cntLeft - 1);
                    } else {
                        cntLeft = 0;
                        cntRight = (firstNotUsedColumn - i) + cnt[i] - 1;
                    }
                    firstNotUsedColumn += cnt[i];
                    for (int j = i - cntLeft; j < i; j++) {
                        field[n - (i - j) - 1][j] = '\\';
                    }
                    for (int j = i + 1; j <= i + cntRight; j++) {
                        field[n - (j - i) - 1][j] = '/';
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (field[i][0] != '.') {
                    return null;
                }
                if (field[i][m - 1] != '.') {
                    return null;
                }
            }
            for (int j = 0; j < m; j++) {
                if (field[n - 1][j] != '.') {
                    return null;
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    if (field[i][j - 1] == '\\' && field[i][j] == '/') {
                        return null;
                    }
                }
            }
            return field;
        } catch (ArrayIndexOutOfBoundsException e) {
            return null;
        }
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
