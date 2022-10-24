import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.Set;
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
        Gridception solver = new Gridception();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class Gridception {
        int[] dx = new int[]{-1, 0, 1, 0};
        int[] dy = new int[]{0, 1, 0, -1};

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            out.printf("Case #%d: ", testNumber);
            int r = in.nextInt(), c = in.nextInt();
            char[][] a = new char[r][c];
            for (int i = 0; i < r; i++) {
                a[i] = in.next().toCharArray();
            }
            Set<String> visited = new HashSet<>();
            int ans = 0;
            char[][] grid = new char[64][64];
            for (int I = 0; I < r; I++) {
                for (int J = 0; J < c; J++) {

                    for (int NI = I; NI < r && NI < I + 2; NI++) {
                        for (int NJ = J; NJ < c && NJ < J + 2; NJ++) {

                            char[][] b = new char[NI - I + 1][NJ - J + 1];
                            for (int s = I; s <= NI; s++) {
                                for (int t = J; t <= NJ; t++) {
                                    b[s - I][t - J] = a[s][t];
                                }
                            }
                            if (visited.contains(Arrays.deepToString(b))) {
                                continue;
                            }
                            visited.add(Arrays.deepToString(b));
                            for (int i = 0; i < 32 * b.length; i++) {
                                for (int j = 0; j < 32 * b[0].length; j++) {
                                    grid[i][j] = b[i / 32][j / 32];
                                }
                            }
                            ans = Math.max(ans, check(a, grid, 32 * b.length, 32 * b[0].length));
                        }
                    }
                }
            }
            out.println(ans);
        }

        private int check(char[][] a, char[][] grid, int n, int m) {
            int best = 0;
            boolean[][] present = new boolean[a.length][a[0].length];
            int[] q = new int[2 * a.length * a[0].length];
            boolean[][] used = new boolean[a.length][a[0].length];
            for (int i = 0; i + a.length <= n; i++) {
                for (int j = 0; j + a[0].length <= m; j++) {

                    for (int r = 0; r < a.length; r++) {
                        for (int c = 0; c < a[0].length; c++) {
                            present[r][c] = a[r][c] == grid[i + r][j + c];
                            used[r][c] = false;
                        }
                    }

                    for (int R = 0; R < a.length; R++) {
                        for (int C = 0; C < a[0].length; C++) {
                            if (!used[R][C] && present[R][C]) {
                                int head = 0, tail = 0;
                                used[R][C] = true;
                                q[tail++] = R;
                                q[tail++] = C;
                                while (head < tail) {
                                    int curR = q[head++], curC = q[head++];
                                    for (int d = 0; d < 4; d++) {
                                        int nr = curR + dx[d], nc = curC + dy[d];
                                        if (0 <= nr && nr < a.length && 0 <= nc && nc < a[0].length && present[nr][nc] && !used[nr][nc]) {
                                            used[nr][nc] = true;
                                            q[tail++] = nr;
                                            q[tail++] = nc;
                                        }
                                    }
                                }

                                best = Math.max(best, tail / 2);
                            }
                        }
                    }
                }
            }
            return best;
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

