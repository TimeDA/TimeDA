import java.io.*;
import java.util.*;

public class Solution {
    FastScanner in;
    PrintWriter out;

    class Point {
        long x, y, z;

        public Point(long x, long y, long z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }

    int side(Point A, Point B, Point C, Point D) {
        long x1 = B.x - A.x, x2 = C.x - A.x, x3 = D.x - A.x;
        long y1 = B.y - A.y, y2 = C.y - A.y, y3 = D.y - A.y;
        long z1 = B.z - A.z, z2 = C.z - A.z, z3 = D.z - A.z;
        long r = x1 * (y2 * z3 - y3 * z2) - x2 * (y1 * z3 - y3 * z1) + x3 * (y1 * z2 - y2* z1);
        return Long.signum(r);
    }

    boolean ok(Point a, Point b, Point c, Point d) {
        int s1 = side(a, b, c, d);
        int s2 = side(a, b, c, new Point(c.x, c.y, c.z - 1));
        return s1 == s2;
    }

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            Point[] a = new Point[n];
            for (int i =0 ; i < n; i++) {
                a[i] = new Point(in.nextLong(), in.nextLong(), in.nextLong());
            }
            int[][][][] dp = new int[n][n][n][1 << n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k =0 ; k < n;k++) {
                        Arrays.fill(dp[i][j][k], -2);
                    }
                }
            }
            for (int x =0 ; x < n; x++) {
                for (int y =0 ; y < n; y++) {
                    for (int z =0  ;z < n; z++) {
                        if (x != y && x != z && y != z) {
                            int mask = (1 << x) | (1 << y) | (1 << z);
                            dp[x][y][z][mask] = -1;
                        }
                    }
                }
            }
            int ansX = -1, ansY = -1, ansZ = -1;
            int ansMask = (1 << n) - 1;
            for (int mask =0 ; mask < 1 << n; mask++) {
                for (int x = 0;x < n; x++) {
                    for (int y = 0; y < n; y++) {
                        for (int z = 0;z < n; z++) {
                            if (dp[x][y][z][mask] == -2) {
                                continue;
                            }
                            for (int q = 0;q < n; q++) {
                                if (((1<<q)&mask)!= 0) {
                                    if (q != x && q != y && q != z) {
                                        if (!ok(a[x], a[y], a[z], a[q])) {
                                            dp[x][y][z][mask] = -2;
                                        }
                                    }
                                }
                            }
                            if (dp[x][y][z][mask] == -2) {
                                continue;
                            }
                            if (mask == ansMask) {
                                ansX = x;
                                ansY = y;
                                ansZ = z;
                            }
                            for (int next = 0; next < n; next++) {
                                if (((1<<next)&mask)==0) {
                                    dp[y][z][next][mask | (1<< next)] = x;
                                }
                            }
                        }
                    }
                }
            }
            if (ansX == -1) {
                throw new AssertionError();
            }
            List<Integer> ans = new ArrayList<>();
            ans.add(ansZ);
            ans.add(ansY);
            ans.add(ansX);
            while (true) {
                int prev = dp[ansX][ansY][ansZ][ansMask];
                if (prev == -1) {
                    break;
                }
                ans.add(prev);
                ansMask ^= (1 << ansZ);
                ansZ = ansY;
                ansY = ansX;
                ansX = prev;
            }
            Collections.reverse(ans);
            out.print("Case #" + (t + 1)+":");
            for (int id : ans) {
                out.print(" " + (id + 1));
            }
            out.println();
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("Solution.in"));
            out = new PrintWriter(new File("Solution.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new Solution().runIO();
    }
}