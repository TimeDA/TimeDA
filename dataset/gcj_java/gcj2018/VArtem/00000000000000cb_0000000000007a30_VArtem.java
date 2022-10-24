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
        GoGopher solver = new GoGopher();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class GoGopher {
        FastScanner in;
        PrintWriter out;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int a = in.nextInt();
            this.in = in;
            this.out = out;
            int sx = 100, sy = 100;
            while (true) {
                if (go(sx, sy)) {
                    break;
                }
                sx += 3;
            }
        }

        private boolean go(int sx, int sy) {
            int count = 0;
            boolean[][] was = new boolean[3][3];
            while (count < 9) {
                out.println(sx + " " + sy);
                out.flush();
                int rx = in.nextInt(), ry = in.nextInt();
                if (rx == 0 && ry == 0) {
                    return true;
                }
                if (!was[sx + 1 - rx][sy + 1 - ry]) {
                    was[sx + 1 - rx][sy + 1 - ry] = true;
                    count++;
                }
            }
            return false;
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

