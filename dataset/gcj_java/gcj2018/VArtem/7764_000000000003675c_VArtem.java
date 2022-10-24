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
        Transmutation solver = new Transmutation();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class Transmutation {
        int[] a;
        int[] b;
        long[] count;
        int n;
        int[] color;
        long[] saveCount;

        boolean create(int i, long req) {
            if (count[i] >= req) {
                count[i] -= req;
                return true;
            }
            if (a[i] == 0 || b[i] == 0) {
                return false;
            }
            color[i] = 1;
            req -= count[i];
            count[i] = 0;
            boolean ret = false;
            if (color[a[i]] != 1 && color[b[i]] != 1) {
                ret = create(a[i], req) && create(b[i], req);
            }
            color[i] = 2;
            return ret;
        }

        void save() {
            System.arraycopy(count, 0, saveCount, 0, count.length);
        }

        void revert() {
            System.arraycopy(saveCount, 0, count, 0, count.length);
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            out.printf("Case #%d: ", testNumber);
            n = in.nextInt();
            a = new int[n];
            b = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt() - 1;
                b[i] = in.nextInt() - 1;
            }
            count = in.nextLongArray(n);
            saveCount = count.clone();

            long l = 0, r = (long) 1e12;
            while (l < r - 1) {
                long m = (l + r) >>> 1;
                save();
                color = new int[n];
                if (create(0, m)) {
                    l = m;
                } else {
                    r = m;
                }
                revert();
            }
            out.println(l);
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

        public long nextLong() {
            return Long.parseLong(next());
        }

        public long[] nextLongArray(int n) {
            long[] ret = new long[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextLong();
            }
            return ret;
        }

    }
}

