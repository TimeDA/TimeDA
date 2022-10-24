import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
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
        FallingBalls solver = new FallingBalls();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class FallingBalls {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            out.printf("Case #%d: ", testNumber);
            int n = in.nextInt();
            int[] b = in.nextIntArray(n);

            int[] dest = new int[n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (b[j] > 0) {
                        b[j]--;
                        dest[i] = j;
                        break;
                    }
                }
            }
            if (dest[0] != 0 || dest[n - 1] != n - 1) {
                out.println("IMPOSSIBLE");
            } else {
                int rows = 0;
                for (int i = 0; i < n; i++) {
                    rows = Math.max(rows, Math.abs(i - dest[i]) + 1);
                }
                char[][] result = new char[rows][n];
                for (char[] c : result) {
                    Arrays.fill(c, '.');
                }
                for (int i = 0; i < n; i++) {
                    go(result, i, dest[i]);
                }
                out.println(rows);
                for (char[] c : result) {
                    out.println(new String(c));
                }
            }
        }

        private void go(char[][] result, int l, int r) {
            int pos = 0;
            while (l != r) {
                if (l < r) {
                    result[pos][l] = '\\';
                    l++;
                } else {
                    result[pos][l] = '/';
                    l--;
                }
                pos++;
            }
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

        public int[] nextIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

    }
}

