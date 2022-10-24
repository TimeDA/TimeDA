import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.ArrayList;

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
        CostumeChange solver = new CostumeChange();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class CostumeChange {
        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            out.printf("Case #%d: ", testNumber);
            int n = in.nextInt();
            int[][] a = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = in.nextInt();
                }
            }
            int ans = 0;
            MaximumMatching mm = new MaximumMatching(n, n);
            for (int color = -n; color <= n; color++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (a[i][j] == color) {
                            mm.addEdge(i, j);
                        }
                    }
                }
                int[] matching = mm.findMatching();
                for (int i : matching) {
                    ans += (i == -1) ? 0 : 1;
                }
                mm.clear();
            }
            out.println(n * n - ans);
        }

        public class MaximumMatching {
            List<Integer>[] graph;
            int[] matchLeft;
            int[] matchRight;
            boolean[] used;

            public MaximumMatching(int n, int m) {
                graph = Utils.listArray(n);
                matchRight = new int[m];
                matchLeft = new int[n];
                Arrays.fill(matchRight, -1);
                Arrays.fill(matchLeft, -1);
            }

            public void addEdge(int from, int to) {
                graph[from].add(to);
            }

            public void clear() {
                for (int i = 0; i < graph.length; i++) {
                    graph[i].clear();
                }
                Arrays.fill(matchRight, -1);
                Arrays.fill(matchLeft, -1);
            }

            boolean dfs(int u) {
                used[u] = true;
                for (int t = 0; t < graph[u].size(); t++) {
                    int v = graph[u].get(t);
                    if (matchRight[v] == -1) {
                        matchRight[v] = u;
                        matchLeft[u] = v;
                        return true;
                    }
                }


                for (int t = 0; t < graph[u].size(); t++) {
                    int v = graph[u].get(t);
                    if (!used[matchRight[v]] && dfs(matchRight[v])) {
                        matchRight[v] = u;
                        matchLeft[u] = v;
                        return true;
                    }
                }
                return false;
            }

            public int[] findMatching() {
                used = new boolean[graph.length];
                while (true) {
                    Arrays.fill(used, false);
                    boolean found = false;
                    for (int i = 0; i < graph.length; i++) {
                        if (matchLeft[i] == -1 && !used[i]) {
                            found |= dfs(i);
                        }
                    }
                    if (!found) {
                        break;
                    }
                }
                return matchLeft;
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

    }

    static class Utils {
        public static <T> List<T>[] listArray(int size) {
            List<T>[] result = new List[size];
            for (int i = 0; i < size; i++) {
                result[i] = new ArrayList<>();
            }
            return result;
        }

    }
}

