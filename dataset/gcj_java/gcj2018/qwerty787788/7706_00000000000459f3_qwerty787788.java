import java.io.*;
import java.util.*;

public class Solution {
    FastScanner in;
    PrintWriter out;

    void solve() {
        final int MAX = 505;
        int[][] dp = new int[MAX][MAX];
        for (int r = 0; r < MAX; r++) {
            for (int curR = MAX - 1; curR >= 0; curR--) {
                for (int curC = MAX - 1; curC >= 0; curC--) {
                    int f = dp[curR][curC];
                    int nextR = curR, nextC = curC;
                    for (int used = 1; ; used++) {
                        nextR += r;
                        nextC += used - 1;
                        if (r == 0) {
                            nextC++;
                        }
                        if (nextR >= MAX || nextC >= MAX) {
                            break;
                        }
                        dp[nextR][nextC] = Math.max(dp[nextR][nextC], f + used);
                    }
                }
            }
        }
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int r = in.nextInt();
            int c = in.nextInt();
            int max = 0;
            for (int i = 0; i <= r; i++) {
                for (int j = 0; j <= c; j++) {
                    max = Math.max(max, dp[i][j]);
                }
            }
            out.println("Case #" + (t + 1) + ": " + max);
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