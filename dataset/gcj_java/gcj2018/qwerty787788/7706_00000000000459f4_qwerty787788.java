import java.io.*;
import java.util.*;

public class Solution {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            int m = in.nextInt();
            char[][] a = new char[n][];
            for (int i = 0; i < n; i++) {
                a[i] = in.next().toCharArray();
            }
            int res = 1;
            int[][] id = new int[n][m];
            int sz = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    id[i][j] = sz++;
                }
            }
            Dsu dsu = new Dsu(sz);
            boolean[][] alive = new boolean[n][m];
            for (int s1 = 1; s1 <= 2; s1++) {
                for (int s2 = 1; s2 <= 2; s2++) {
                    boolean[] used =new boolean[1 << (s1 * s2)];
                    for (int i = 0; i + s1 <= n; i++) {
                        for (int j = 0; j + s2 <= m; j++) {
                            int mask =0 ;
                            char[][] pattern = new char[s1][s2];
                            for (int k = 0; k < s1; k++) {
                                for (int l = 0; l < s2; l++) {
                                    pattern[k][l] = a[i + k][j + l];
                                    mask *= 2;
                                    if (pattern[k][l] == 'B') {
                                        mask++;
                                    }
                                }
                            }
                            if (used[mask]) {
                                continue;
                            }
                            used[mask] =true;
                            for (int sX = 1; sX <= n; sX++) {
                                if (s1 == 1 && sX != n) {
                                    continue;
                                }
                                for (int sY = 1; sY <= m; sY++) {
                                    if (s2 == 1 && sY != m) {
                                        continue;
                                    }
                                    res = Math.max(res, getAns(dsu, alive, a, pattern, sX, sY, id));
                                }
                            }
                        }
                    }
                }
            }
            out.println("Case #" + (t + 1) + ": " + res);
        }
    }

    int getAns(Dsu dsu, boolean[][] alive, char[][] a, char[][] pattern, int sX, int sY, int[][] id) {
        dsu.init();
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                int patternX = (i < sX ? 0 : 1);
                int patternY = (j < sY ? 0 : 1);
                char needC = pattern[patternX][patternY];
                alive[i][j] = (a[i][j] == needC);
            }
        }
        int[] dx = new int[]{-1, 0, 0, 1};
        int[] dy = new int[]{0, -1, 1, 0};
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                if (alive[i][j]) {
                    for (int it = 0; it < dx.length; it++) {
                        int ni = i + dx[it], nj = j + dy[it];
                        if (ni >= 0 && ni < a.length && nj >= 0 && nj < a[i].length) {
                            if (alive[ni][nj]) {
                                dsu.join(id[i][j], id[ni][nj]);
                            }
                        }
                    }
                }
            }
        }
        int res = 1;
        for (int i = 0; i < dsu.size.length; i++) {
            res = Math.max(res, dsu.size[i]);
        }
        return res;
    }

    class Dsu {
        int[] p;
        int[] size;

        void init() {
            for (int i = 0; i < p.length; i++) {
                p[i] = i;
            }
            Arrays.fill(size, 1);
        }

        Dsu(int n) {
            p = new int[n];
            size =new int[n];
        }

        void join(int x, int y) {
            x = get(x);
            y = get(y);
            if (x == y) {
                return;
            }
            size[y] += size[x];
            p[x] = y;
        }

        int get(int x) {
            return p[x] == x ? x : (p[x] = get(p[x]));
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