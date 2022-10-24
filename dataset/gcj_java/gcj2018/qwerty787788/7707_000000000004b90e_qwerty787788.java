import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution {
    FastScanner in;
    PrintWriter out;


    class Point implements Comparable<Point> {
        long x, y;

        public Point(long x, long y) {
            this.x = x;
            this.y = y;
        }

        public Point(long xx, long yy, int swap, int minusX, int minusY, int rot) {
            x = xx;
            y = yy;
            if (minusX == 1) {
                x = -x;
            }
            if (minusY == 1) {
                y = -y;
            }
            if (swap == 1) {
                long tmp = x;
                x = y;
                y = tmp;
            }
            for (int i = 0; i < rot; i++)
                r();
        }

        void r() {
            long t  = x;
            x = -y;
            y = t;
        }

        @Override
        public int compareTo(Point o) {
            if (x != o.x) {
                return Long.compare(x, o.x);
            }
            return Long.compare(y, o.y);
        }
    }

    int vectMul(Point a, Point b, Point c) {
        return Long.signum((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y));
    }

    class Segment implements Comparable<Segment>{
        Point A, B;
        int id;

        Segment(Point a, Point b, int id) {
            if (a.compareTo(b) < 0) {
                A = a;
                B = b;
            } else {
                A = b;
                B = a;
            }
            this.id = id;
        }

        @Override
        public int compareTo(Segment o) {
            int c = B.compareTo(o.B);
            if (c != 0) {
                return c;
            }
            int vmul = vectMul(B, A, o.A);
            return vmul;
        }
    }

    int[] solve(long[] x1, long[] y1, long[] x2, long[] y2, int cnt, int swap, int minusX, int minusY, int rot) {
        int n = x1.length;
        Segment[] s = new Segment[n];
        for (int i = 0; i < n; i++) {
            s[i] = new Segment(new Point(x1[i], y1[i], swap, minusX, minusY, rot), new Point(x2[i], y2[i], swap, minusX, minusY, rot), i);
        }
        Arrays.sort(s);
        if (cnt == 2) {
            int pos0 = -1, pos1 = -1;
            for (int i = 0; i < n; i++) {
                if (s[i].id == 0) {
                    pos0 =i;
                }
                if (s[i].id == 1) {
                    pos1 = i;
                }
            }
            if (pos0 > pos1) {
                return null;
            }
        }
        int[] res = new int[s.length];
        for (int i =0; i < res.length; i++) {
            res[i] = s[i].id;
        }
        return res;
    }

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            int cnt = in.nextInt();
            long[] x1 = new long[n];
            long[] y1 = new long[n];
            long[] x2 = new long[n];
            long[] y2 = new long[n];
            for (int i = 0; i < n; i++) {
                x1[i] = in.nextLong();
                y1[i] = in.nextLong();
                x2[i] = in.nextLong();
                y2[i] = in.nextLong();
            }
            int[] res =null;
            for (int sw = 0; sw < 2; sw++) {
                for (int ro = 0; ro < 2; ro++) {
                    for (int r2 = 0; r2 < 2; r2++) {
                        for (int rot =0; rot < 4; rot++) {
                            int[] tt = solve(x1, y1, x2, y2, cnt, sw, ro, r2, rot);
                            if (tt != null) {
                                res = tt;
                            }
                        }
                    }
                }
            }
            if (res == null) {
                throw new AssertionError();
            }
            out.print("Case #" + (t + 1)+":");
            for (int id : res) {
                out.print(" " + (id + 1));
            }
            out.println();
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