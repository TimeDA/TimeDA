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
        CubicUFO solver = new CubicUFO();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class CubicUFO {
        PrintWriter out;

        public void solve(int testNumber, FastScanner in, PrintWriter out) {
            out.printf("Case #%d: ", testNumber);
            out.println();
            double a = in.nextDouble();
            this.out = out;

            if (a <= Math.sqrt(2)) {
                solve(a, 0, 1 / Math.sqrt(2), 0);
            } else {
                solve(a, 0, Math.sqrt(2 / 3), 1 / Math.sqrt(2));
            }
        }

        private void solve(double a, double x1, double x2, double y) {
            for (int IT = 0; IT < 100; IT++) {
                double mid = (x1 + x2) / 2;
                double sum = mid * y + mid * Math.sqrt(1 - y * y) + Math.sqrt(1 - mid * mid);
                if (sum > a) {
                    x2 = mid;
                } else {
                    x1 = mid;
                }
            }
            print((x1 + x2) / 2, y);
        }

        private void print(double x, double y) {
            print(0, 0, 0.5, x, y);
            print(0, 0.5, 0, x, y);
            print(0.5, 0, 0, x, y);
        }

        private void print(double x, double y, double z, double alpha, double beta) {
            {
                double newX = x * beta - z * Math.sqrt(1 - beta * beta);
                double newZ = x * Math.sqrt(1 - beta * beta) + z * beta;
                x = newX;
                z = newZ;
            }
            {
                double newX = x * alpha - y * Math.sqrt(1 - alpha * alpha);
                double newY = x * Math.sqrt(1 - alpha * alpha) + y * alpha;
                x = newX;
                y = newY;
            }
            out.printf("%.10f %.10f %.10f\n", x, y, z);
        }

    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
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

        public double nextDouble() {
            return Double.parseDouble(next());
        }

    }
}

