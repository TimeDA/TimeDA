import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Solution implements Runnable {
    private void solve() throws IOException {
        int T = readInt();
        for (int t = 1; t <= T; t++) {
            solveTest(t);
        }
    }

    private void solveTest(int t) throws IOException {
        int a = readInt();
        boolean[][] ok = new boolean[10][10];
        int attempts = 0;
        while (true) {
            for (int r = 3; r <= 4; r++) {
                for (int c = 3; c <= 5; c++) {
                    out.println(r + " " + c);
                    out.flush();
                    attempts++;
                    int x = readInt();
                    int y = readInt();
                    if (x == -1 && y == -1) {
                        throw new RuntimeException();
                    }
                    if (x == 0 && y == 0) {
                        return;
                    }
                    if (attempts > 1000) {
                        throw new RuntimeException();
                    }
                    ok[x][y] = true;
                }
            }
        }
        //throw new RuntimeException();
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public static void main(String[] args) {
//        new Thread(null, new Solution(), "", 128 * (1L << 20)).start();
        new Solution().run();
    }

    private static final boolean ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null;
    private BufferedReader reader;
    private StringTokenizer tokenizer;
    private PrintWriter out;

    @Override
    public void run() {
        try {
            if (true || ONLINE_JUDGE || !new File("input.txt").exists()) {
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
