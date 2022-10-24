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
        int n = readInt();
        int m = readInt();
        int nx = readInt();
        int ny = readInt();
        char[][] a = new char[n][m];
        for (int i = 0; i < n; i++) {
            String s = readString();
            for (int j = 0; j < m; j++) {
                a[i][j] = s.charAt(j);
            }
        }
        int[] arrX = new int[n];
        int[] arrY = new int[m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '@') {
                    arrX[i]++;
                    arrY[j]++;
                }
            }
        }
        int[] resX = f(arrX, n, nx);
        int[] resY = f(arrY, m, ny);
//        System.err.println("t = " + t);
//        System.err.println("resX = " + Arrays.toString(resX));
//        System.err.println("resY = " + Arrays.toString(resY));
        if (resX == null || resY == null) {
            out.println("IMPOSSIBLE");
            return;
        }
        if (resX.length != nx + 1) {
            throw new AssertionError();
        }
        if (resY.length != ny + 1) {
            throw new AssertionError();
        }
        int needCnt = 0;
        for (int i = 0; i < resX[0]; i++) {
            for (int j = 0; j < resY[0]; j++) {
                if (a[i][j] == '@') {
                    needCnt++;
                }
            }
        }
//        System.err.println("needCnt = " + needCnt);
        for (int x = 0; x <= nx; x++) {
            for (int y = 0; y <= ny; y++) {
                int cnt = 0;
//                System.err.println("start");
                for (int i = x == 0 ? 0 : resX[x - 1]; i < resX[x]; i++) {
                    for (int j = y == 0 ? 0 : resY[y - 1]; j < resY[y]; j++) {
//                        System.err.println("i = " + i + ", j = " + j);
                        if (a[i][j] == '@') {
                            cnt++;
                        }
                    }
                }
                if (cnt != needCnt) {
                    out.println("IMPOSSIBLE");
                    return;
                }
            }
        }
        out.println("POSSIBLE");
    }

    private int[] f(int[] arr, int n, int cuts) {
        if (cuts + 1 > n) {
            throw new AssertionError();
        }
        int sum = 0;
        for (int x : arr) {
            sum += x;
        }
        if (sum == 0) {
            int[] res = new int[cuts + 1];
            for (int i = 0; i < res.length - 1; i++) {
                res[i] = i + 1;
            }
            res[res.length - 1] = n;
            return res;
        }
        if (sum % (cuts + 1) != 0) {
            return null;
        }
        int singleSum = sum / (cuts + 1);
        int cnt = 0;
        int[] res = new int[cuts + 1];
        for (int i = 0; i < n; ) {
            int j = i;
            int s = 0;
            while (j < n && s < singleSum) {
                s += arr[j];
                j++;
            }
            while (j < n && arr[j] == 0) {
                j++;
            }
            if (s > singleSum) {
                return null;
            }
            if (cnt >= cuts + 1) {
                return null;
            }
            res[cnt] = j;
            cnt++;
            i = j;
        }
        //noinspection RedundantIfStatement
        if (cnt != cuts + 1) {
            return null;
        }
        if (res[res.length - 1] != n) {
            throw new AssertionError();
        }
        return res;
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
