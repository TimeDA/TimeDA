import java.io.*;
import java.util.*;

public class Solution {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            int[][] need = new int[n][2];
            for (int i = 0; i < n; i++) {
                need[i][0] = in.nextInt() - 1;
                need[i][1] = in.nextInt() - 1;
            }
            long[] have = new long[n];
            long sum = 0;
            for (int i = 0; i < n; i++) {
                have[i] = in.nextLong();
                sum += have[i];
            }

            long left = 0, right = sum + 1;
            while (right - left > 1) {
                long check = (left + right) >> 1;
                long[] curHave = new long[n];
                for (int i = 0; i < n; i++) {
                    curHave[i] = have[i];
                }
                curHave[0] -= check;
                boolean ok = true;
                while (true) {
                    long s = 0;
                    for (int i = 0; i < n; i++) {
                        s += curHave[i];
                    }
                    if (s < 0) {
                        ok = false;
                        break;
                    }
                    boolean done = true;
                    for (int i = 0; i < n; i++) {
                        if (curHave[i] < 0) {
                            long nn = -curHave[i];
                            curHave[i] = 0;
                            curHave[need[i][0]] -= nn;
                            curHave[need[i][1]] -= nn;
                            done = false;
                        }
                    }
                    if (done) {
                        break;
                    }
                }
                if (ok) {
                    left = check;
                } else {
                    right = check;
                }
            }
            out.println("Case #" + (t + 1) + ": " + left);
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("Main.in"));
            out = new PrintWriter(new File("Main.out"));

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