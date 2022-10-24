import java.io.*;
import java.util.*;

public class Solution {
    FastScanner in;
    PrintWriter out;

    int[] p;

    int get(int x) {
        return p[x] == x ? x: (p[x] = get(p[x]));
    }

    void unite(int x, int y) {
        p[get(x)] = get(y);
    }

    Random rnd = new Random(123);

    int calcHashes(List<Integer>[] g, int me) {
        int n = g.length;
        int p = 239017;
        int[] hashes = new int[n];
        Arrays.fill(hashes, 1);
        hashes[me] = (int) 1e9 + 7;
        for (int it = 0; it < 20; it++) {
            int[] nextHashes = new int[n];
            for (int v =0 ; v < n; v++) {
                int nextHash = 1;
                List<Integer> cur = new ArrayList<>();
                for (int to : g[v]) {
                    cur.add(hashes[to]);
                }
                Collections.sort(cur);
                for (int h : cur) {
                    nextHash = nextHash * p + h;
                }
                nextHashes[v] = nextHash;
            }
            hashes = nextHashes;
        }
        return hashes[me];
    }

    int[] calcHashes(List<Integer>[] g) {
        int[] res = new int[g.length];
        for (int i =0 ; i< res.length; i++) {
            res[i] =calcHashes(g, i);
        }
        return res;
    }

    List<Integer>[] solve(int n, int rec) {
        if (rec == 1000) {
            return null;
        }
        List<Integer>[] g = null;
        boolean ok = false;
        for (int ITER = 0; ITER < 1000; ITER++) {
            g = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                g[i] = new ArrayList<>();
            }
            p = new int[n];
            boolean[][] con = new boolean[n][n];
            for (int i = 0; i < n; i++) {
                p[i] = i;
                con[i][i] = true;
            }
            int fails = 0;
            ok = true;
            for (int it = 0; it < 2 * n; it++) {
                int fr = rnd.nextInt(n);
                int to = rnd.nextInt(n);
                if (con[fr][to] || g[fr].size() == 4 || g[to].size() == 4) {
                    it--;
                    fails++;
                    if (fails == 1000) {
                        ok = false;
                        break;
                    }
                    continue;
                }
                fails = 0;
                g[fr].add(to);
                g[to].add(fr);
                con[fr][to] = con[to][fr] = true;
                unite(fr, to);
            }
            if (ok) {
                break;
            }
        }
        if (!ok) {
            throw new AssertionError();
        }
//        System.err.println("created");
        for (int i =0 ; i < n; i++) {
            if (g[i].size() != 4) {
                throw new AssertionError();
            }
        }
        for (int i = 0; i < n; i++) {
            if (get(i) != get(0)) {
//                System.err.println("not connected");
                return solve(n, rec + 1);
            }
        }
        int[] hashes = calcHashes(g);
//        System.err.println(Arrays.toString(hashes));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (hashes[i] == hashes[j]) {
//                    System.err.println("bad hashes " + i + " " + j + " " + hashes[i]);
                    return solve(n, rec + 1);
                }
            }
        }
        return g;
    }

    void solve123() {
        int cntOk = 0;
        for (int n = 10; n <= 50; n++) {
            System.err.println("n = " + n);
            List<Integer>[] g =solve(n, 0);
            if (g != null) {
                cntOk++;
                System.err.println("wow!! " + n);
//                throw new AssertionError();
            } else {
                System.err.println(":( " + n);
            }
        }
        System.err.println("ok = " + cntOk);
    }

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int left = in.nextInt();
            int right = in.nextInt();
            List<Integer>[] g = solve(left, 0);
            out.println(g.length);
            for (int v =0 ; v < g.length; v++) {
                for (int to : g[v]) {
                    if (to > v) {
                        out.println((v+1)+" " + (to + 1));
                    }
                }
            }
            out.flush();
            int judgeN =in.nextInt();
            List<Integer>[] g2 = new ArrayList[judgeN];
            for (int i = 0; i < judgeN; i++) {
                g2[i] = new ArrayList<>();
            }
            for (int i = 0; i < judgeN * 2; i++) {
                int fr =in.nextInt() - 1;
                int to = in.nextInt() - 1;
                g2[fr].add(to);
                g2[to].add(fr);
            }
            int[] myHashes = calcHashes(g);
            int[] judgeHashes = calcHashes(g2);
            for (int i= 0; i < g.length; i++) {
                int nextId = -1;
                for (int j = 0; j < judgeHashes.length; j++) {
                    if (myHashes[i] == judgeHashes[j]) {
                        nextId = j + 1;
                    }
                }
                if (nextId == -1) {
                    throw new AssertionError();
                }
                out.print(nextId +" ");
            }
            out.println();
            out.flush();
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