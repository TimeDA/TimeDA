import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Locale;
import java.util.Random;
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
        int n = readInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = readInt();
        }
        List<Integer> a0 = new ArrayList<>();
        List<Integer> a1 = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                a0.add(a[i]);
            } else {
                a1.add(a[i]);
            }
        }
        Random rnd = new Random(322);
        for (int it = 0; it < 100; it++) {
            int i = rnd.nextInt(n);
            int j = rnd.nextInt(n);
            int z = a[i]; a[i] = a[j]; a[j] = z;
        }
        Arrays.sort(a);
        Collections.sort(a0);
        Collections.sort(a1);
        int p0 = 0;
        int p1 = 0;
        for (int i = 0; i < n; i++) {
            int b;
            if (i % 2 == 0) {
                b = a0.get(p0++);
            } else {
                b = a1.get(p1++);
            }
            if (a[i] != b) {
                out.println(i);
                return;
            }
        }
        out.println("OK");
    }

    private void solveTestSmall(int t) throws IOException {
        out.printf(Locale.US, "Case #%d: ", t);
        int n = readInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = readInt();
        }
        int[] b = a.clone();
        Arrays.sort(a);
        troubleSort(b, n);
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                out.println(i);
                return;
            }
        }
        out.println("OK");
    }

    private void troubleSort(int[] a, int n) {
        while (true) {
            boolean found = false;
            for (int i = 0; i < n - 2; i++) {
                if (a[i] > a[i + 2]) {
                    int t = a[i];
                    a[i] = a[i + 2];
                    a[i + 2] = t;
                    found = true;
                    break;
                }
            }
            if (!found) {
                return;
            }
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
