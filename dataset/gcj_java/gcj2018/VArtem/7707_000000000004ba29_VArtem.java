import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.Random;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        NamePreservingNetwork solver = new NamePreservingNetwork();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class NamePreservingNetwork {
        int INF = Integer.MAX_VALUE / 3;
        static int[] seed = new int[101];

        static {
            seed[10] = 8;
            seed[11] = 1;
            seed[12] = 0;
            seed[13] = 1;
            seed[14] = 1;
            seed[15] = 0;
            seed[16] = 0;
            seed[17] = 0;
            seed[18] = 0;
            seed[19] = 0;
            seed[20] = 0;
            seed[21] = 0;
            seed[22] = 0;
            seed[23] = 0;
            seed[24] = 0;
            seed[25] = 0;
            seed[26] = 0;
            seed[27] = 0;
            seed[28] = 0;
            seed[29] = 0;
            seed[30] = 0;
            seed[31] = 0;
            seed[32] = 0;
            seed[33] = 0;
            seed[34] = 0;
            seed[35] = 0;
            seed[36] = 0;
            seed[37] = 0;
            seed[38] = 0;
            seed[39] = 0;
            seed[40] = 0;
            seed[41] = 0;
            seed[42] = 0;
            seed[43] = 0;
            seed[44] = 0;
            seed[45] = 0;
            seed[46] = 0;
            seed[47] = 0;
            seed[48] = 0;
            seed[49] = 0;
            seed[50] = 0;
            seed[51] = 0;
            seed[52] = 0;
            seed[53] = 0;
            seed[54] = 0;
            seed[55] = 0;
            seed[56] = 0;
            seed[57] = 0;
            seed[58] = 0;
            seed[59] = 0;
            seed[60] = 0;
            seed[61] = 0;
            seed[62] = 0;
            seed[63] = 0;
            seed[64] = 0;
            seed[65] = 0;
            seed[66] = 0;
            seed[67] = 0;
            seed[68] = 0;
            seed[69] = 0;
            seed[70] = 0;
            seed[71] = 0;
            seed[72] = 0;
            seed[73] = 0;
            seed[74] = 0;
            seed[75] = 0;
            seed[76] = 0;
            seed[77] = 0;
            seed[78] = 0;
            seed[79] = 0;
            seed[80] = 0;
            seed[81] = 0;
            seed[82] = 0;
            seed[83] = 0;
            seed[84] = 0;
            seed[85] = 0;
            seed[86] = 0;
            seed[87] = 0;
            seed[88] = 0;
            seed[89] = 0;
            seed[90] = 0;
            seed[91] = 0;
            seed[92] = 0;
            seed[93] = 0;
            seed[94] = 0;
            seed[95] = 0;
            seed[96] = 0;
            seed[97] = 0;
            seed[98] = 0;
            seed[99] = 0;
            seed[100] = 0;
        }

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            int l = in.nextInt(), u = in.nextInt();
//        for (int n = 10; n <= 100; n++) {
//            for (int IT = 0; IT < 1000000; IT++) {
//                Graph g = new Graph(n);
//                int seed = IT;
//                Random rng = new Random(seed);
//                g.addEdges(rng);
//                if (g.isOk()) {
//                    System.err.println("seed[" + n + "] = " + seed + ";");
////                out.println(n);
////                for (int i = 0; i < n; i++) {
////                    for (int j : g.graph[i]) {
////                        out.println((i + 1) + " " + (j + 1));
////                    }
////                }
////                out.flush();
//                    break;
//                }
//            }
//        }
            printSolution(l, in, out);

        }

        void printSolution(int l, FastScanner in, PrintWriter out) {
            int n = l;
            Random rng = new Random(seed[n]);
            Graph g = new Graph(n);
            g.addEdges(rng);
            g.calc();
            out.println(n);
            for (int i = 0; i < n; i++) {
                for (int j : g.graph[i]) {
                    if (i < j) {
                        out.println((i + 1) + " " + (j + 1));
                    }
                }
            }
            out.flush();

            n = in.nextInt();
            Graph newG = new Graph(n);
            for (int i = 0; i < 2 * n; i++) {
                int from = in.nextInt() - 1, to = in.nextInt() - 1;
                newG.graph[from].add(to);
                newG.graph[to].add(from);
                newG.a[from][to] = newG.a[to][from] = true;
            }
            newG.calc();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (g.hash[i] == newG.hash[j]) {
                        out.print((j + 1) + " ");
                    }
                }
            }
            out.println();
            out.flush();
        }

        class Graph {
            List<Integer>[] graph;
            boolean[][] a;
            long[] hash;
            int n;

            public Graph(int n) {
                this.n = n;
                a = new boolean[n][n];
                graph = Utils.listArray(n);
            }

            void addEdges(Random rng) {
                outer:
                while (true) {
                    DSU dsu = new DSU(n);
                    for (int i = 0; i < n - 1; i++) {
                        while (true) {
                            int u = rng.nextInt(n), v = rng.nextInt(n);
                            if (u != v && !a[u][v] && graph[u].size() < 4 && graph[v].size() < 4 && dsu.get(u) != dsu.get(v)) {
                                a[u][v] = a[v][u] = true;
                                graph[u].add(v);
                                graph[v].add(u);
                                dsu.unite(u, v);
                                break;
                            }
                        }
                    }
                    for (int i = n - 1; i < 2 * n; i++) {
                        boolean ok = false;
                        for (int u = 0; u < n; u++) {
                            for (int v = u + 1; v < n; v++) {
                                if (u != v && !a[u][v] && graph[u].size() < 4 && graph[v].size() < 4) {
                                    ok = true;
                                }
                            }
                        }
                        if (!ok) {
                            graph = Utils.listArray(n);
                            a = new boolean[n][n];
                            continue outer;
                        }
                        while (true) {
                            int u = rng.nextInt(n), v = rng.nextInt(n);
                            if (u != v && !a[u][v] && graph[u].size() < 4 && graph[v].size() < 4) {
                                a[u][v] = a[v][u] = true;
                                graph[u].add(v);
                                graph[v].add(u);
                                break;
                            }
                        }
                    }
                    return;
                }
            }

            void calc() {
                hash = new long[n];
                long[] start = new long[n];
                Arrays.fill(start, 1);
                for (int IT = 0; IT < n; IT++) {
                    long[][] d2 = new long[n][n];
                    for (int i = 0; i < n; i++) {
                        Arrays.fill(d2[i], INF);
                        d2[i][i] = 0;
                        for (int j = 0; j < n; j++) {
                            if (a[i][j]) {
                                d2[i][j] = (start[i] * start[j]) & ((1 << 20) - 1);
                                d2[i][j]++;
                            }
                        }
                    }
                    for (int k = 0; k < n; k++) {
                        for (int i = 0; i < n; i++) {
                            for (int j = 0; j < n; j++) {
                                d2[i][j] = Math.min(d2[i][j], d2[i][k] + d2[k][j]);
                            }
                        }
                    }
                    for (int i = 0; i < n; i++) {
                        long[] tmp = d2[i].clone();
                        Arrays.sort(tmp);
                        start[i] = 0;
                        for (long t : tmp) {
                            start[i] = start[i] * 424243 + t;
                        }
                        hash[i] = start[i];
                    }
                }

//            long[] tmp = new long[n];
//            for (int IT = 0; IT < n; IT++) {
//                for (int i = 0; i < n; i++) {
//                    List<Long> h = new ArrayList<>();
//                    for (int j : graph[i]) {
//                        h.add(hash[j]);
//                    }
//                    Collections.sort(h);
//                    tmp[i] = start[i];
//                    for (long val : h) {
//                        tmp[i] = tmp[i] * 1000003 + val;
//                    }
//                }
//                System.arraycopy(tmp, 0, hash, 0, n);
//            }
            }

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

    static class DSU {
        int[] parent;
        int[] rank;
        public int[] size;
        public int sets;

        public DSU(int n) {
            parent = new int[n];
            rank = new int[n];
            size = new int[n];
            Arrays.fill(size, 1);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
            this.sets = n;
        }

        public int get(int v) {
            if (parent[v] == v) {
                return v;
            }
            return parent[v] = get(parent[v]);
        }

        public boolean unite(int u, int v) {
            u = get(u);
            v = get(v);
            if (u == v) {
                return false;
            }
            sets--;
            if (rank[u] == rank[v]) {
                rank[u]++;
            }
            if (rank[u] > rank[v]) {
                parent[v] = u;
                size[u] += size[v];
            } else {
                parent[u] = v;
                size[v] += size[u];
            }
            return true;
        }

    }
}

