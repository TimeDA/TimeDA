import java.io.*;
import java.util.*;

public class Solution {
    FastScanner in;
    PrintWriter out;

    boolean decrease(char[] s) {
        for (int pos = s.length - 2; pos >= 0; pos--) {
            if (s[pos] == 'C' && s[pos + 1] == 'S') {
                s[pos] = 'S';
                s[pos + 1] = 'C';
                return true;
            }
        }
        return false;
    }

    long getScore(char[] s) {
        long cur = 1, sum = 0;
        for (char c : s) {
            if (c == 'C') {
                cur *= 2;
            } else {
                sum += cur;
            }
        }
        return sum;
    }

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            long d = in.nextLong();
            char[] s = in.next().toCharArray();
            int need = 0;
            boolean ok = true;
            while (true) {
                if (getScore(s) <= d) {
                    break;
                }
                need++;
                if (!decrease(s)) {
                    ok = false;
                    break;
                }
            }
            out.println("Case #" + (t + 1) + ": " + (ok ? need : "IMPOSSIBLE"));
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