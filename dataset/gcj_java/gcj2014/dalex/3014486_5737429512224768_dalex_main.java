import java.io.OutputStreamWriter;
 import java.io.BufferedWriter;
 import java.util.Locale;
 import java.io.OutputStream;
 import java.io.PrintWriter;
 import java.io.File;
 import java.io.Writer;
 import java.io.FilenameFilter;
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
 			final String regex = "A-(small|large).*[.]in";
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
 			outputStream = new FileOutputStream("a.out");
 		} catch (IOException e) {
 			throw new RuntimeException(e);
 		}
 		InputReader in = new InputReader(inputStream);
 		OutputWriter out = new OutputWriter(outputStream);
 		TaskA solver = new TaskA();
 		int testCount = Integer.parseInt(in.next());
 		for (int i = 1; i <= testCount; i++)
 			solver.solve(i, in, out);
 		out.close();
 	}
 }
 
 class TaskA {
     public void solve(int testNumber, InputReader in, OutputWriter out) {
         out.printFormat("Case #%d: ", testNumber);
         int n = in.readInt();
         int discSize = in.readInt();
         int[] a = IOUtils.readIntArray(in, n);
         TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();
         for (int i = 0; i < n; i++) {
             inc(map, a[i]);
         }
         int ans = 0;
         while (!map.isEmpty()) {
             int largest = map.lastKey();
             dec(map, largest);
             Integer floor = map.floorKey(discSize - largest);
             if (floor != null) {
                 dec(map, floor);
             }
             ans++;
         }
         out.printLine(ans);
     }
 
     private void dec(TreeMap<Integer, Integer> map, int x) {
         if (map.get(x) == 1) {
             map.remove(x);
         } else {
             map.put(x, map.get(x) - 1);
         }
     }
 
     private void inc(TreeMap<Integer, Integer> map, int x) {
         if (map.containsKey(x)) {
             map.put(x, map.get(x) + 1);
         } else {
             map.put(x, 1);
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
 
