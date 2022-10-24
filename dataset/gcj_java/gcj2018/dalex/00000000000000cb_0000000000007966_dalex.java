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
        out.printf(Locale.US, "Case #%d: ", t);
        int d = readInt();
        char[] p = readString().toCharArray();
        if (can(d, p)) {
            out.println(0);
            return;
        }
        int n = p.length;
        int ans = 0;
        while (true) {
            boolean found = false;
            for (int i = n - 1; i > 0; i--) {
                if (p[i] == 'S' && p[i - 1] == 'C') {
                    char z = p[i]; p[i] = p[i - 1]; p[i - 1] = z;
                    ans++;
                    if (can(d, p)) {
                        out.println(ans);
                        return;
                    }
                    found = true;
                    break;
                }
            }
            if (!found) {
                break;
            }
        }
        out.println("IMPOSSIBLE");
    }


    private void solveTestSmall(int t) throws IOException {
        out.printf(Locale.US, "Case #%d: ", t);
        int d = readInt();
        char[] p = readString().toCharArray();
        int posC = -1;
        for (int i = 0; i < p.length; i++) {
            if (p[i] == 'C') posC = i;
        }
        if (posC == -1) {
            if (can(d, p)) {
                out.println(0);
            } else {
                out.println("IMPOSSIBLE");
            }
            return;
        }
        for (int diff = 0; diff <= p.length; diff++) {
            if (posC - diff >= 0) {
                char[] s = new char[p.length];
                Arrays.fill(s, 'S');
                s[posC - diff] = 'C';
                if (can(d, s)) {
                    out.println(diff);
                    return;
                }
            }
            if (posC + diff < p.length) {
                char[] s = new char[p.length];
                Arrays.fill(s, 'S');
                s[posC + diff] = 'C';
                if (can(d, s)) {
                    out.println(diff);
                    return;
                }
            }
        }
        out.println("IMPOSSIBLE");
    }

    private boolean can(int dInt, char[] s) {
        BigInteger d = BigInteger.valueOf(dInt);
        BigInteger now = BigInteger.ONE;
        for (char c : s) {
            if (c == 'C') {
                now = now.shiftLeft(1);
            } else {
                d = d.subtract(now);
            }
            if (d.compareTo(BigInteger.ZERO) < 0) {
                return false;
            }
        }
        return true;
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
