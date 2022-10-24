import java.io.*;
 import java.util.*;
 import static java.lang.Math.*;
 
 /**
  * Google Code Jam 2012
  * Round 2
  * Problem A
  * @author dalex
  */
 public class A implements Runnable {
 	
 	BufferedReader in;
 	PrintWriter out;
 	StringTokenizer tok;
 
 	public static void main(String[] args) {
 		new Thread(null, new A(), "", 256 * (1L << 20)).start();
 	}
 
 	@Override
 	public void run() {
 		try {
 			in = new BufferedReader(new FileReader("input.txt"));
 			out = new PrintWriter("output.txt");
 			Locale.setDefault(Locale.US);
 			tok = new StringTokenizer("");
 			int tests = readInt();
 			int p = tests / 10;
 			long startTime = System.currentTimeMillis();
 			for (int test = 1; test <= tests; test++) {
 				out.printf("Case #%d: ", test);
 				solveTest();
 				if (p == 0 || test % p == 0 || test == tests) {
 					long newTime = System.currentTimeMillis();
 					System.err.printf("Test %d of %d completed, time = %d\n", test, tests, newTime - startTime);
 				}
 			}
 			in.close();
 			out.close();
 		} catch (Throwable t) {
 			t.printStackTrace(System.err);
 			System.exit(-1);
 		}
 	}
 
 	String readString() throws IOException {
 		while (!tok.hasMoreTokens()) {
 			tok = new StringTokenizer(in.readLine());
 		}
 		return tok.nextToken();
 	}
 
 	int readInt() throws IOException {
 		return Integer.parseInt(readString());
 	}
 
 	long readLong() throws IOException {
 		return Long.parseLong(readString());
 	}
 
 	double readDouble() throws IOException {
 		return Double.parseDouble(readString());
 	}
 	
 	void debug(Object... o) {
 		System.err.println(Arrays.deepToString(o));
 	}
 
 	// solution
 	
 	class SegmentTree {
 		
 		long[] a;
 		long[] t;
 		int[] idx;
 		int n;
 		
 		SegmentTree(long[] a) {
 			n = a.length;
 			this.a = a;
 			t = new long[4*n + 1];
 			build(1, 0, n-1, a);
 		}
 
 		private void build(int i, int l, int r, long[] a) {
 			if (l == r) {
 				t[i] = a[l];
 				idx[i] = l;
 				return;
 			}
 			int m = (l + r) / 2;
 			build(2*i, l, m, a);
 			build(2*i+1, m+1, r, a);
 			combine(i, 2*i, 2*i+1);
 			t[i] = max(t[2*i], t[2*i+1]);
 		}
 		
 		private void combine(int i, int l, int r) {
 			if (t[l] > t[r]) {
 				t[i] = t[l];
 				idx[i] = idx[l];
 			} else {
 				t[i] = t[r];
 				idx[i] = idx[r];
 			}
 		}
 
 		int getMaxIndex(int i, int l, int r, int L, int R) {
 			if (l == L && r == R) {
 				return idx[i];
 			}
 			int m = (l + r) / 2;
 			if (R <= m) {
 				return getMaxIndex(2*i, l, m, L, R);
 			} else if (m < L) {
 				return getMaxIndex(2*i+1, m+1, r, L, R);
 			} else {
 				int il = getMaxIndex(2*i, l, m, L, m);
 				int ir = getMaxIndex(2*i+1, m+1, r, m+1, R);
 				if (a[il] > a[ir]) {
 					return il;
 				} else {
 					return ir;
 				}
 			}
 		}
 	}
 	
 	void solveTest() throws IOException {
 		int n = readInt();
 		long[] x = new long[n];
 		long[] len = new long[n];
 		for (int i = 0; i < n; i++) {
 			x[i] = readLong();
 			len[i] = readLong();
 		}
 		long totalLen = readLong();
 		long[] maxRight = new long[n];
 		for (int i = 0; i < n; i++) {
 			maxRight[i] = x[i] + len[i];
 		}
 		//SegmentTree tree = new SegmentTree(maxRight);
 		long[] lowestLevel = new long[n];
 		lowestLevel[0] = x[0];
 		for (int i = 0; i < n; i++) {
 			long ropeLen = min(len[i], lowestLevel[i]);
 			if (x[i] + ropeLen >= totalLen) {
 				out.println("YES");
 				return;
 			}
 			for (int j = i+1; j < n; j++) {
 				long newX = x[i] + ropeLen;
 				if (newX < x[j]) {
 					break;
 				}
 				long low = min(len[j], x[j] - x[i]);
 				if (low > lowestLevel[j]) {
 					lowestLevel[j] = low;
 				}
 			}
 		}
 		out.println("NO");
 	}
 
 }
