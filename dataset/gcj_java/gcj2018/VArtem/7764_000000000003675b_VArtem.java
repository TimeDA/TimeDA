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
        MysteriousRoadSigns solver = new MysteriousRoadSigns();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class MysteriousRoadSigns {
        final int NONE = (int) 1e9;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            out.printf("Case #%d: ", testNumber);
            int n = in.nextInt();
            int[] a = new int[n], b = new int[n];
            for (int i = 0; i < n; i++) {
                int d = in.nextInt();
                a[i] = d + in.nextInt();
                b[i] = d - in.nextInt();
            }

            int[] nextA = build(a), nextB = build(b);
            Data[] maxChainA = new Data[n + 1];
            Data[] maxChainB = new Data[n + 1];
            maxChainA[n] = maxChainB[n] = new Data(NONE, NONE, 0);
            int maxLen = 0, count = 0;
            for (int i = n - 1; i >= 0; i--) {
                {
                    int val = a[i];
                    int next = nextA[i];
                    Data nextData = maxChainB[next];
                    if (nextData.valA == NONE || nextData.valA == val) {
                        maxChainA[i] = new Data(val, nextData.valB, nextData.len + next - i);
                    } else {
                        if (next == n) {
                            maxChainA[i] = new Data(val, NONE, next - i);
                        } else {
                            maxChainA[i] = new Data(val, b[next], nextB[next] - i);
                        }
                    }
                }
                {
                    int val = b[i];
                    int next = nextB[i];
                    Data nextData = maxChainA[next];
                    if (nextData.valB == NONE || nextData.valB == val) {
                        maxChainB[i] = new Data(nextData.valA, val, nextData.len + next - i);
                    } else {
                        if (next == n) {
                            maxChainB[i] = new Data(NONE, val, next - i);
                        } else {
                            maxChainB[i] = new Data(a[next], val, nextA[next] - i);
                        }
                    }
                }
                int curLen = Math.max(maxChainA[i].len, maxChainB[i].len);
                if (curLen > maxLen) {
                    maxLen = curLen;
                    count = 0;
                }
                if (curLen == maxLen) {
                    count++;
                }
            }
            out.println(maxLen + " " + count);
        }

        private int[] build(int[] a) {
            int[] next = new int[a.length];
            for (int i = 0; i < a.length; ) {
                int j = i;
                while (j < a.length && a[i] == a[j]) {
                    j++;
                }
                for (int t = i; t < j; t++) {
                    next[t] = j;
                }
                i = j;
            }
            return next;
        }

        private class Data {
            int valA;
            int valB;
            int len;

            public Data(int valA, int valB, int len) {
                this.valA = valA;
                this.valB = valB;
                this.len = len;
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
}

