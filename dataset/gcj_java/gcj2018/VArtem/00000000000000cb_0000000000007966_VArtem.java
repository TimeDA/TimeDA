import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Solution {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        SavingTheUniverseAgain solver = new SavingTheUniverseAgain();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class SavingTheUniverseAgain {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            out.printf("Case #%d: ", testNumber);
            int d = in.nextInt();
            char[] c = in.next().toCharArray();
            int ans = 0;
            while (get(c) > d) {
                int pos = -1;
                for (int i = 0; i < c.length - 1; i++) {
                    if (c[i] == 'C' && c[i + 1] == 'S') {
                        pos = i;
                    }
                }
                if (pos == -1) {
                    out.println("IMPOSSIBLE");
                    return;
                }
                c[pos] = 'S';
                c[pos + 1] = 'C';
                ans++;
            }
            out.println(ans);
        }

        private long get(char[] c) {
            long ans = 0;
            for (int i = c.length - 1; i >= 0; i--) {
                if (c[i] == 'S') {
                    ans++;
                } else {
                    ans *= 2;
                }
            }
            return ans;
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (st == null || !st.hasMoreElements()) {
                String line = null;
                try {
                    line = br.readLine();
                } catch (IOException e) {
                }
                st = new StringTokenizer(line);
            }
            return st.nextToken();
        }

    }
}

