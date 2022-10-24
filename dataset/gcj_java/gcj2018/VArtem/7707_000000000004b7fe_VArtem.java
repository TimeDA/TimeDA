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
        FieldTrip solver = new FieldTrip();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class FieldTrip {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            out.printf("Case #%d: ", testNumber);
            int n = in.nextInt();
            long[] r = new long[n], c = new long[n];
            for (int i = 0; i < n; i++) {
                r[i] = in.nextInt();
                c[i] = in.nextInt();
            }
            long left = -1, right = Long.MAX_VALUE / 3;
            while (left < right - 1) {
                long mid = (left + right) >>> 1;

                long minX = Long.MIN_VALUE, maxX = Long.MAX_VALUE;
                long minY = minX, maxY = maxX;
                for (int i = 0; i < n; i++) {
                    minX = Math.max(minX, r[i] - mid);
                    minY = Math.max(minY, c[i] - mid);
                    maxX = Math.min(maxX, r[i] + mid);
                    maxY = Math.min(maxY, c[i] + mid);
                }
                if (minX <= maxX && minY <= maxY) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            out.println(right);
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

