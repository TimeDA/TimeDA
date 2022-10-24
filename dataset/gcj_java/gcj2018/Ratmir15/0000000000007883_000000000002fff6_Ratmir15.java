
import java.io.*;
import java.util.*;

public class Solution {

    public static final String POSSIBLE = "POSSIBLE";
    public static final String IMPOSSIBLE = "IMPOSSIBLE";

    public static class Cashier {
        public final long m,s,p;

        public Cashier(long m, long s, long p) {
            this.m = m;
            this.s = s;
            this.p = p;
        }

        public long maxAvail () {
            long maxP = p / s;
            return Math.min(m, maxP);
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        InputReader sc = new InputReader(System.in);
        OutputStream outputStream = System.out;
        PrintWriter printWriter = new PrintWriter(outputStream);
        int tn = sc.nextInt();
        for (int ti = 1; ti <= tn; ti++) {
            int r = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            int [] m = new int[c];
            int [] s = new int[c];
            int [] p = new int[c];
            List<Cashier> cs = new ArrayList<Cashier>();

            for (int i=0;i<c;i++) {
                m[i] = sc.nextInt();
                s[i] = sc.nextInt();
                p[i] = sc.nextInt();
                cs.add(new Cashier(m[i],s[i],p[i]));
            }
            long mn = getMn(r, b, c, cs);
            String res = "Case #" + ti + ": " + mn;
            printWriter.write(res + "\n");
        }
        printWriter.close();
    }

    public static boolean testValue(int r, int b, int c, List<Cashier> cs, long value) {
        List<Cashier> csl = new ArrayList<Cashier>();
        for (Cashier cashier : cs) {
            if (cashier.p<value) {
                csl.add(new Cashier(cashier.m, cashier.s, value - cashier.p));
            }
        }
        Collections.sort(csl, new Comparator<Cashier>() {
            @Override
            public int compare(Cashier o1, Cashier o2) {
                return -Long.compare(o1.maxAvail(), o2.maxAvail());
            }
        });
        long used = 0;
        int i1 = Math.min(r, csl.size());
        for (int i=0;i< i1;i++) {
            used += csl.get(i).maxAvail();
        }
        return used>=b;
    }

    public static long getMn(int r, int b, int c, List<Cashier> cs) {
        long mn = 0;
        long mx = Long.MAX_VALUE;
        while (mx-mn>1) {
            long tv = mn + (mx-mn)/2;
            boolean b1 = testValue(r, b, c, cs, tv);
            if (!b1) {
                mn = tv;
            } else {
                mx = tv;
            }
        }
        return mx;
    }

}

class InputReader {

    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buf[curChar++];
    }

    public int nextInt() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public int nextChar() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        return c;
    }

    public long nextLong() {
        int c = read();
        while (isSpaceChar(c))
            c = read();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public boolean isSpaceChar(int c) {
        return isWhitespace(c);
    }

    public static boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }

}

