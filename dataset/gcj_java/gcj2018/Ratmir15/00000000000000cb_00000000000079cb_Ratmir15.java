import java.io.*;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Solution {

    public static final String IMPOSSIBLE = "IMPOSSIBLE";

    public static void main(String[] args) throws FileNotFoundException {
        InputReader sc = new InputReader(System.in);
        OutputStream outputStream = System.out;
        PrintWriter printWriter = new PrintWriter(outputStream);
        int tn = sc.nextInt();
        for (int ti = 1; ti <= tn; ti++) {
            int n = sc.nextInt();
            int [] arr = new int[n];
            int [] arr1 = new int[(n+1)/2];
            int [] arr2 = new int[n/2];
            int i1 = 0;
            int i2 = 0;
            for (int i=0;i<n;i++) {
                arr[i] = sc.nextInt();
                if (i%2==0) {
                    arr1[i1] = arr[i];
                    i1++;
                } else {
                    arr2[i2] = arr[i];
                    i2++;
                }

            }
            Arrays.sort(arr1);
            Arrays.sort(arr2);
            i1 = 0;
            i2 = 0;
            for (int i=0;i<n;i++) {
                if (i%2==0) {
                    arr[i] = arr1[i1];
                    i1++;
                } else {
                    arr[i] = arr2[i2];
                    i2++;
                }
            }

            String rr = "OK";
            for (int i=0;i<n-1;i++) {
                if (arr[i]>arr[i+1]) {
                    rr = String.valueOf(i);
                    break;
                }
            }
            String res = "Case #" + ti + ": " + rr;
            printWriter.write(res + "\n");
        }
        printWriter.close();
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
