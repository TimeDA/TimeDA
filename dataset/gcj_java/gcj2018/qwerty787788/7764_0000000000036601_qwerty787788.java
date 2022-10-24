import java.io.*;
import java.util.*;

public class Solution {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            int l = in.nextInt();
            int[] perc = new int[n + 1];
            for (int people = 1; people <= n; people++) {
                int cur = people * 100;
                perc[people] = cur / n;
                cur %= n;
                if (cur * 2 >= n) {
                    perc[people]++;
                }
            }
            int[] minNeed = new int[102];
            Arrays.fill(minNeed, n);
            for (int people = n; people >= 0; people--) {
                minNeed[perc[people]] = people;
            }
            for (int p = 100; p > 0; p--) {
                minNeed[p - 1] = Math.min(minNeed[p - 1], minNeed[p]);
            }
            int more = n;
            final int M = 205;
            int[] dp = new int[M];
            Arrays.fill(dp, Integer.MAX_VALUE);
            dp[0] = 0;
            int[] nextDp = new int[M];
            boolean full = (n < 1000);
            for (int i = 0; i < l; i++) {
                int val = in.nextInt();
                more -= val;
                Arrays.fill(nextDp, Integer.MAX_VALUE);
                int left = 0;
                while (left != 100 && minNeed[left] <= val) {
                    left++;
                }
                left--;
                for (int cur = 0; cur + left + 1 < M; cur++) {
                    int v = dp[cur];
                    if (v == Integer.MAX_VALUE) {
                        continue;
                    }
                    if (full) {
                        for (int use = left; use <= 100 && cur + use < M; use++) {
                            nextDp[use + cur] = Math.min(nextDp[use + cur], v + Math.max(0, minNeed[use] - val));
                        }
                    } else {
                        nextDp[cur + left] = Math.min(nextDp[cur + left], v);
                        nextDp[cur + left + 1] = Math.min(nextDp[cur + left + 1], v + (minNeed[left + 1] - val));
                    }
                }
                int[] tmp = dp;
                dp = nextDp;
                nextDp = tmp;
            }
            for (int i = 0; i < M; i++) {
                int v = dp[i];
                if (v == Integer.MAX_VALUE) {
                    continue;
                }
                for (int use = 1; use <= 100 && use + i < M; use++) {
                    dp[use + i] = Math.min(dp[use + i], v + minNeed[use]);
                }
            }
            int res = 0;
            for (int i = 0; i < M; i++) {
                if (dp[i] <= more) {
                    res = i;
                }
            }
            out.println("Case #" + (t + 1) + ": " + res);
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