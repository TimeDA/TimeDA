import java.io.OutputStreamWriter;
 import java.io.BufferedWriter;
 import java.util.Locale;
 import java.io.OutputStream;
 import java.io.PrintWriter;
 import java.io.File;
 import java.io.Writer;
 import java.io.FilenameFilter;
 import java.util.Map;
 import java.io.IOException;
 import java.util.InputMismatchException;
 import java.util.TreeMap;
 import java.io.FileOutputStream;
 import java.io.FileInputStream;
 import java.util.AbstractMap;
 import java.util.NoSuchElementException;
 import java.math.BigInteger;
 import java.io.InputStream;
 
 /**
  * Built using CHelper plug-in
  * Actual solution is at the top
  */
 public class Main {
 	public static void main(String[] args) {
 		Locale.setDefault(Locale.US);
 		InputStream inputStream;
 		try {
 			final String regex = "B-(small|large).*[.]in";
 			File directory = new File(".");
 			File[] candidates = directory.listFiles(new FilenameFilter() {
 				public boolean accept(File dir, String name) {
 					return name.matches(regex);
 				}
 			});
 			File toRun = null;
 			for (File candidate : candidates) {
 				if (toRun == null || candidate.lastModified() > toRun.lastModified())
 					toRun = candidate;
 			}
 			inputStream = new FileInputStream(toRun);
 		} catch (IOException e) {
 			throw new RuntimeException(e);
 		}
 		OutputStream outputStream;
 		try {
 			outputStream = new FileOutputStream("b.out");
 		} catch (IOException e) {
 			throw new RuntimeException(e);
 		}
 		InputReader in = new InputReader(inputStream);
 		OutputWriter out = new OutputWriter(outputStream);
 		TaskB solver = new TaskB();
 		int testCount = Integer.parseInt(in.next());
 		for (int i = 1; i <= testCount; i++)
 			solver.solve(i, in, out);
 		out.close();
 	}
 }
 
 class TaskB {
     int globalMin;
 
     void rec(int[] p, int[] a, int L, int R) {
         if (L == R) {
             if (!upAndDown(p)) {
                 return;
             }
             update(p, a);
             return;
         }
         for (int i = L; i <= R; i++) {
             swap(p, i, L);
             rec(p, a, L+1, R);
             swap(p, i, L);
         }
     }
 
     private void update(int[] p, int[] aa) {
         int ans = 0;
         int[] a = aa.clone();
         for (int i = 0; i < a.length; i++) {
             int cur = p[i];
             int aIndex = -1;
             for (int j = 0; j < a.length; j++) {
                 if (a[j] == cur) {
                     aIndex = j;
                     break;
                 }
             }
             int L = i;
             int R = aIndex;
             if (L > R) {
                 throw new RuntimeException();
             }
             for (int j = R; j > L; j--) {
                 swap(a, j, j-1);
                 ans++;
             }
         }
         globalMin = Math.min(globalMin, ans);
     }
 
     private boolean upAndDown(int[] p) {
         int i = 0;
         while (i+1 < p.length && p[i] < p[i+1]) {
             i++;
         }
         while (i+1 < p.length && p[i] > p[i+1]) {
             i++;
         }
         return i == p.length - 1;
     }
 
     private void swap(int[] p, int i, int j) {
         int t = p[i];
         p[i] = p[j];
         p[j] = t;
     }
 
     public void solve(int testNumber, InputReader in, OutputWriter out) {
         out.printFormat("Case #%d: ", testNumber);
         int n = in.readInt();
         int[] a = IOUtils.readIntArray(in, n);
         compress(a);
 
         int[] p = new int[n];
         for (int i = 0; i < n; i++) {
             p[i] = i;
         }
         globalMin = Integer.MAX_VALUE;
         rec(p, a, 0, n-1);
         out.printLine(globalMin);
 
 //        System.err.println(Arrays.toString(a));
 //        int[] prefixFenwick = new int[n];
 //        int[] prefixInversions = new int[n];
 //        for (int i = 0; i < n; i++) {
 //            if (i > 0) {
 //                prefixInversions[i] = prefixInversions[i - 1];
 //            }
 //            prefixInversions[i] += getSum(prefixFenwick, a[i], n-1);
 //            inc(prefixFenwick, a[i], 1);
 //        }
 //        int[] suffixFenwick = new int[n];
 //        int[] suffixInversions = new int[n];
 //        for (int i = n-1; i >= 0; i--) {
 //            if (i < n-1) {
 //                suffixInversions[i] = suffixInversions[i + 1];
 //            }
 //            suffixInversions[i] += getSum(suffixFenwick, a[i], n-1);
 //            inc(suffixFenwick, a[i], 1);
 //        }
 //        System.err.println(Arrays.toString(prefixInversions));
 //        System.err.println(Arrays.toString(suffixInversions));
 //        int min = Integer.MAX_VALUE;
 //        for (int mid = 0; mid <= n; mid++) {
 //            int curLeft = (mid == 0) ? 0 : prefixInversions[mid - 1];
 //            int curRight = (mid == n) ? 0 : suffixInversions[mid];
 //            min = Math.min(min, curLeft + curRight);
 //        }
 //        out.printLine(min);
     }
 
     private void compress(int[] a) {
         TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
         for (int i = 0; i < a.length; i++) {
             map.put(a[i], i);
         }
         int newVal = 0;
         while (!map.isEmpty()) {
             Map.Entry<Integer, Integer> e = map.pollFirstEntry();
             a[e.getValue()] = newVal++;
         }
     }
 }
 
 class InputReader {
 
     private InputStream stream;
 	private byte[] buf = new byte[1024];
 	private int curChar;
 	private int numChars;
 	private SpaceCharFilter filter;
 
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
 
     public int readInt() {
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
 			if (c < '0' || c > '9')
 				throw new InputMismatchException();
 			res *= 10;
 			res += c - '0';
 			c = read();
 		} while (!isSpaceChar(c));
 		return res * sgn;
 	}
 
     public String readString() {
 		int c = read();
 		while (isSpaceChar(c))
 			c = read();
 		StringBuilder res = new StringBuilder();
 		do {
 			if (Character.isValidCodePoint(c))
 				res.appendCodePoint(c);
 			c = read();
 		} while (!isSpaceChar(c));
 		return res.toString();
 	}
 
 	public boolean isSpaceChar(int c) {
 		if (filter != null)
 			return filter.isSpaceChar(c);
 		return isWhitespace(c);
 	}
 
 	public static boolean isWhitespace(int c) {
 		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
 	}
 
     public String next() {
 		return readString();
 	}
 
     public interface SpaceCharFilter {
 		public boolean isSpaceChar(int ch);
 	}
 }
 
 class OutputWriter {
 	private final PrintWriter writer;
 
 	public OutputWriter(OutputStream outputStream) {
 		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
 	}
 
 	public OutputWriter(Writer writer) {
 		this.writer = new PrintWriter(writer);
 	}
 
     public void printFormat(String format, Object...objects) {
 		writer.printf(format, objects);
 	}
 
 	public void close() {
 		writer.close();
 	}
 
     public void printLine(int i) {
 		writer.println(i);
 	}
 }
 
 class IOUtils {
 
     public static int[] readIntArray(InputReader in, int size) {
 		int[] array = new int[size];
 		for (int i = 0; i < size; i++)
 			array[i] = in.readInt();
 		return array;
 	}
 
 }
 
