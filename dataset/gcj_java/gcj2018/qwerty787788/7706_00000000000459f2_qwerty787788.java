import java.io.*;
import java.util.*;

public class Solution {
    FastScanner in;
    PrintWriter out;

    final String imp = "IMPOSSIBLE";

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            int[] s = new int[n];
            for (int i = 0; i < n; i++) {
                s[i] = in.nextInt();
            }
            out.print("Case #" + (t + 1) + ": ");
            if (s[0] == 0 || s[s.length - 1] == 0) {
                out.println(imp);
                continue;
            }
            int alrSum = 0;
            List<Seg> ans = new ArrayList<>();
            int rows = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] != 0) {
                    ans.add(new Seg(alrSum, alrSum + s[i] - 1, i));
                    alrSum += s[i];
                }
            }
            for (Seg seg : ans) {
                rows = Math.max(rows, seg.getCost());
            }
            rows++;
            char[][] answer = new char[rows][n];
            for (int i = 0; i < rows;i ++) {
                Arrays.fill(answer[i], '.');
            }
            for (Seg seg : ans) {
                int l = seg.fr, r = seg.to;
                for (int ro = 0; ro < rows - 1; ro++) {
                    if (seg.end < r) {
                        answer[ro][r] = '/';
                        r--;
                        if (r < l) {
                            l = r;
                        }
                    }
                    if (seg.end > l) {
                        answer[ro][l] = '\\';
                        l++;
                        if (l > r) {
                            r = l;
                        }
                    }
                }
                if (l != seg.end || r != seg.end) {
                    throw new AssertionError();
                }
            }
            out.println(rows);
            for (char[] cc : answer) {
                out.println(new String(cc));
            }
        }
    }

    class Seg {
        int fr, to, end;

        public Seg(int fr, int to, int end) {
            this.fr = fr;
            this.to = to;
            this.end = end;
        }

        int getCost() {
            return Math.max(getCost(fr - end), getCost(to - end));
        }

        int getCost(int len) {
            len = Math.abs(len);
            return len;
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