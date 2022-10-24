import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
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
        char[][] a = new char[n][];
        char[][] origA = new char[n][];
        for (int i = 0; i < n; i++) {
            String str = readString();
            if (str.length() != m) {
                throw new AssertionError();
            }
            a[i] = str.toCharArray();
            origA[i] = a[i].clone();
        }
        for (int times = 0; times < 5; times++) {
            a = grow(a);
        }
//        System.err.println("========");
//        for (char[] str : a) {
//            System.err.println(new String(str));
//        }
//        System.err.println("========");
        int maxAns = Integer.MIN_VALUE;
        for (int mask = 1; mask < (1 << (n * m)); mask++) {
            char[][] pattern = new char[n][m];
            for (int bit = 0; bit < n * m; bit++) {
//                System.err.println("mask = " + mask + ", x = " + (bit / m) + ", y = " + (bit % m));
                if (((1 << bit) & mask) != 0) {
                    pattern[bit / m][bit % m] = origA[bit / m][bit % m];
                } else {
                    pattern[bit / m][bit % m] = (char) 0;
                }
            }
            if (!isConnected(pattern)) {
                continue;
            }
//            System.err.println("m = " + mask + ", p = " + Arrays.deepToString(pattern));
            pattern = fixSizes(pattern);
            if (ok(a, pattern)) {
                maxAns = Math.max(maxAns, Integer.bitCount(mask));
            }
        }
        out.println(maxAns);
    }

    private boolean isConnected(char[][] a) {
        int n = a.length;
        int m = a[0].length;
        boolean[][] vis = new boolean[n][m];
        ttt:
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != 0) {
                    dfs(vis, i, j, a);
                    break ttt;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != 0) {
                    if (!vis[i][j]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    private static final int[] dx = {0, 1, 0, -1};
    private static final int[] dy = {-1, 0, 1, 0};

    private void dfs(boolean[][] vis, int x, int y, char[][] a) {
        if (vis[x][y]) return;
        vis[x][y] = true;
        for (int z = 0; z < 4; z++) {
            int nx = x + dx[z];
            int ny = y + dy[z];
            if (inRange(nx, a.length) && inRange(ny, a[0].length)) {
                if (a[nx][ny] != 0) {
                    dfs(vis, nx, ny, a);
                }
            }
        }
    }

    private boolean inRange(int x, int n) {
        return x >= 0 && x < n;
    }

    private boolean ok(char[][] arr, char[][] pattern) {
        for (int i = 0; i < arr.length - pattern.length + 1; i++) {
            for (int j = 0; j < arr[i].length - pattern[0].length + 1; j++) {
                boolean ok = true;
                ttt:
                for (int x = 0; x < pattern.length; x++) {
                    for (int y = 0; y < pattern[x].length; y++) {
                        if (pattern[x][y] == 0) {
                            continue;
                        }
                        if (arr[i + x][j + y] != pattern[x][y]) {
                            ok = false;
                            break ttt;
                        }
                    }
                }
                if (ok) {
                    return true;
                }
            }
        }
        return false;
    }

    private char[][] grow(char[][] a) {
        int n = a.length;
        int m = a[0].length;
        char[][] res = new char[2 * n][2 * m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int dx = 0; dx < 2; dx++) {
                    for (int dy = 0; dy < 2; dy++) {
                        res[2 * i + dx][2 * j + dy] = a[i][j];
                    }
                }
            }
        }
        return res;
    }

    private char[][] fixSizes(char[][] a) {
        int n = a.length;
        int m = a[0].length;

        int minX = Integer.MAX_VALUE;
        int minY = Integer.MAX_VALUE;

        int maxX = Integer.MIN_VALUE;
        int maxY = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] != 0) {
                    minX = Math.min(minX, i);
                    minY = Math.min(minY, j);

                    maxX = Math.max(maxX, i);
                    maxY = Math.max(maxY, j);
                }
            }
        }

        int lenX = maxX - minX + 1;
        int lenY = maxY - minY + 1;
        char[][] res = new char[lenX][lenY];
        for (int i = 0; i < lenX; i++) {
            //noinspection ManualArrayCopy
            for (int j = 0; j < lenY; j++) {
                res[i][j] = a[minX + i][minY + j];
            }
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
