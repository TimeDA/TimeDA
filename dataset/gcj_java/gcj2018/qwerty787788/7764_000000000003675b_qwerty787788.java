import java.io.*;
import java.util.*;

public class Solution {
    FastScanner in;
    PrintWriter out;

    int[] a;
    int[] b;
    int curMaxLen;
    long ways;

    void updateAns(int len) {
        if (len < curMaxLen) {
            return;
        }
        if (len > curMaxLen) {
            curMaxLen = len;
            ways = 0;
        }
        ways++;
    }

    // [l..r]
    void go(int l, int r) {
        if (l == r) {
            updateAns(1);
            return;
        }
        int m = (l + r) >> 1;
        go(l, m);
        go(m + 1, r);
        List<Pair> all = new ArrayList<>();
        for (int mv = 0; mv < 2; mv++) {
            int[] tmp = a;
            a = b;
            b = tmp;
            int fr = m, to = m + 1;
            int useAI = a[fr];
            while (fr >= l && a[fr] == useAI) {
                fr--;
            }
            while (to <= r && a[to] == useAI) {
                to++;
            }
            all.add(new Pair(fr, to));
            for (int rev = 0; rev < 2; rev++) {
                int nextFr = fr, nextTo = to;
                int useBI = 0;
                if (rev == 0 && fr >= l) {
                    useBI = b[fr];
                }
                if (rev == 1 && to <= r) {
                    useBI = b[to];
                }
                while (nextFr >= l && (a[nextFr] == useAI || b[nextFr] == useBI)) {
                    nextFr--;
                }
                while (nextTo <= r && (a[nextTo] == useAI || b[nextTo] == useBI)) {
                    nextTo++;
                }
                all.add(new Pair(nextFr, nextTo));
            }
        }
        Collections.sort(all);
        for (int i = 0; i < all.size(); ) {
            int j = i;
            while (j != all.size() && all.get(i).compareTo(all.get(j)) == 0) {
                j++;
            }
            if (all.get(i).fr < m && all.get(i).to > m + 1) {
                updateAns(all.get(i).to - all.get(i).fr - 1);
            }
            i = j;
        }
    }

    class Pair implements Comparable<Pair>{
        int fr, to;

        @Override
        public String toString() {
            return "Pair{" +
                    "fr=" + fr +
                    ", to=" + to +
                    '}';
        }

        public Pair(int fr, int to) {
            this.fr = fr;
            this.to = to;
        }

        @Override
        public int compareTo(Pair o) {
            if (fr != o.fr) {
                return Integer.compare(fr, o.fr);
            }
            return Integer.compare(to, o.to);
        }
    }

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            a = new int[n];
            b = new int[n];
            for (int i = 0; i < n; i++) {
                int di = in.nextInt();
                int ai = in.nextInt();
                int bi = in.nextInt();
                a[i] = di + ai;
                b[i] = di - bi;
            }
            curMaxLen = -1;
            ways = 0;
            go(0, n - 1);
            out.println("Case #" + (t + 1) + ": " + curMaxLen + " " + ways);
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