import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Locale;
import java.util.StringTokenizer;

public class Solution implements Runnable {
    private void solve() throws IOException {
        int T = readInt();
        for (int t = 1; t <= T; t++) {
            solveTest(t);
        }
    }

    private void solveTest(int t) throws IOException {
        out.printf(Locale.US, "Case #%d:\n", t);
        double needS = readDouble();
        double left = 0.0;
        double right = Math.PI / 4.0;
        for (int it = 0; it < 322; it++) {
            double angle = (left + right) / 2.0;
            double S = Math.sin(angle) + Math.cos(angle);
            if (S < needS) {
                left = angle;
            } else {
                right = angle;
            }
        }
        double angle = (left + right) / 2.0;
        Point p1 = new Point(0.5, 0.0);
        Point p2 = new Point(0.0, 0.5);
        out.println(p1.rotate(angle) + " 0.0");
        out.println(p2.rotate(angle) + " 0.0");
        out.println("0.0 0.0 0.5");
    }

    static class Point {
        double x, y;

        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }

        Point rotate(double angle) {
            double newX = x * Math.cos(angle) - y * Math.sin(angle);
            double newY = x * Math.sin(angle) + y * Math.cos(angle);
            return new Point(newX, newY);
        }

        @Override
        public String toString() {
            return String.format(Locale.US, "%.15f %.15f", x, y);
        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public static void main(String[] args) {
        new Thread(null, new Solution(), "", 128 * (1L << 20)).start();
    }

    private static final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
    private BufferedReader reader;
    private StringTokenizer tokenizer;
    private PrintWriter out;

    @Override
    public void run() {
        try {
            if (ONLINE_JUDGE || !new File("input.txt").exists()) {
                reader = new BufferedReader(new InputStreamReader(System.in));
                out = new PrintWriter(System.out);
            } else {
                reader = new BufferedReader(new FileReader("input.txt"));
                out = new PrintWriter("output.txt");
            }
            solve();
        } catch (IOException e) {
            throw new RuntimeException(e);
        } finally {
            try {
                reader.close();
            } catch (IOException e) {
                // nothing
            }
            out.close();
        }
    }

    private String readString() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    @SuppressWarnings("unused")
    private int readInt() throws IOException {
        return Integer.parseInt(readString());
    }

    @SuppressWarnings("unused")
    private long readLong() throws IOException {
        return Long.parseLong(readString());
    }

    @SuppressWarnings("unused")
    private double readDouble() throws IOException {
        return Double.parseDouble(readString());
    }
}
