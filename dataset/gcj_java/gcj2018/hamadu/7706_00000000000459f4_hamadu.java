import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class Solution {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        int T = in.nextInt();
        for (int t = 1; t <= T ; t++) {
            int n = in.nextInt();
            int m = in.nextInt();
            char[][] tbl = new char[n][m];
            for (int i = 0; i < n; i++) {
                tbl[i] = in.nextToken().toCharArray();
            }
            out.println(String.format("Case #%d: %d", t, solve(tbl)));
        }
        out.flush();
    }

    private static int solve(char[][] t) {
        int n = t.length;
        int m = t[0].length;

        char[][] tk = t;
        for (int i = 0; i < 6 ; i++) {
            tk = goDeep(tk);
        }

        int nm = n * m;
        int best = 0;
        for (int p = 1 ; p < (1<<nm) ; p++) {
            char[][] map = new char[n][m];
            for (int i = 0; i < n ; i++) {
                for (int j = 0; j < m ; j++) {
                    map[i][j] = (p & (1<<(i*m+j))) >= 1 ? t[i][j] : '*';
                }
            }
            int w = Integer.bitCount(p);
            if (w <= best) {
                continue;
            }

            UnionFind uf = new UnionFind(n*m);
            int cnt = 0;
            int theid = 0;
            for (int i = 0; i < n ; i++) {
                for (int j = 0; j < m ; j++) {
                    if (map[i][j] == '*') {
                        continue;
                    }
                    theid = i*m+j;
                    cnt++;
                    for (int k = 0; k < 4 ; k++) {
                        int ti = i + dy[k];
                        int tj = j + dx[k];
                        if (ti < 0 || tj < 0 || ti >= n || tj >= m) {
                            continue;
                        }
                        if (map[ti][tj] != '*') {
                            uf.unite(i*m+j, ti*m+tj);
                        }
                    }
                }
            }

            if (cnt != uf.groupCount(theid)) {
                continue;
            }
            if (match(tk, map)) {
                best = Math.max(best, w);
            }
        }
        return best;
    }

    private static boolean match(char[][] tk, char[][] map) {
        for (int i = 0; i + map.length <= tk.length ; i++) {
            for (int j = 0; j + map[0].length <= tk[0].length ; j++) {

                boolean ok = true;
                sch: for (int k = 0; k < map.length; k++) {
                    for (int l = 0; l < map[0].length; l++) {
                        if (map[k][l] == '*') {
                            continue;
                        }
                        if (map[k][l] != tk[i+k][j+l]) {
                            ok = false;
                            break sch;
                        }
                    }
                }
                if (ok) {
                    return true;
                }
            }
        }
        return false;
    }

    static int[] dx = new int[]{1, 0, -1, 0};
    static int[] dy = new int[]{0, 1, 0, -1};

    static class UnionFind {
        int[] rank;
        int[] parent;
        int[] cnt;

        public UnionFind(int n) {
            rank = new int[n];
            parent = new int[n];
            cnt = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                cnt[i] = 1;
            }
        }

        public int find(int a) {
            if (parent[a] == a) {
                return a;
            }
            parent[a] = find(parent[a]);
            return parent[a];
        }

        public void unite(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) {
                return;
            }
            if (rank[a] < rank[b]) {
                parent[a] = b;
                cnt[b] += cnt[a];
                cnt[a] = cnt[b];
            } else {
                parent[b] = a;
                cnt[a] += cnt[b];
                cnt[b] = cnt[a];
                if (rank[a] == rank[b]) {
                    rank[a]++;
                }
            }
        }

        public int groupCount(int a) {
            return cnt[find(a)];
        }

        private boolean issame(int a, int b) {
            return find(a) == find(b);
        }
    }


    private static char[][] goDeep(char[][] t) {
        char[][] t2 = new char[t.length*2][t[0].length*2];
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[0].length; j++) {
                t2[i*2][j*2] = t2[i*2+1][j*2] = t2[i*2+1][j*2+1] = t2[i*2][j*2+1] = t[i][j];
            }
        }
        return t2;
    }


    public static void debug(Object... o) {
        System.err.println(Arrays.deepToString(o));
    }

    public static class InputReader {
        private static final int BUFFER_LENGTH = 1 << 12;
        private InputStream stream;
        private byte[] buf = new byte[BUFFER_LENGTH];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        private int next() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public char nextChar() {
            return (char) skipWhileSpace();
        }

        public String nextToken() {
            int c = skipWhileSpace();
            StringBuilder res = new StringBuilder();
            do {
                res.append((char) c);
                c = next();
            } while (!isSpaceChar(c));
            return res.toString();
        }

        public int nextInt() {
            return (int) nextLong();
        }

        public long nextLong() {
            int c = skipWhileSpace();
            long sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = next();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = next();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public double nextDouble() {
            return Double.valueOf(nextToken());
        }

        int skipWhileSpace() {
            int c = next();
            while (isSpaceChar(c)) {
                c = next();
            }
            return c;
        }

        boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
    }
}