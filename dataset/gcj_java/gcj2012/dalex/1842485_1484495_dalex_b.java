import java.io.*;
 import java.util.*;
 import static java.lang.Math.*;
 
 /**
  * Google Code Jam 2012
  * Round 2
  * Problem B
  * @author dalex
  */
 public class B implements Runnable {
 	
 	BufferedReader in;
 	PrintWriter out;
 	StringTokenizer tok;
 
 	public static void main(String[] args) {
 		new Thread(null, new B(), "", 256 * (1L << 20)).start();
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
 	
 	final double EPS = 1e-9;
 	
 	boolean intersects(double x1, double y1, double r1, double x2, double y2, double r2) {
 		double dx = x1 - x2;
 		double dy = y1 - y2;
 		return dx*dx + dy*dy <= (r1+r2)*(r1+r2) - EPS;
 	}
 	
 	void solveTest() throws IOException {
 		int n = readInt();
 		int W = readInt();
 		int H = readInt();
 		double[] r = new double[n];
 		for (int i = 0; i < n; i++) {
 			r[i] = readDouble();
 		}
 		double[] x = new double[n];
 		double[] y = new double[n];
 		Random rnd = new Random(739375923752L);
 		while (true) {
 			for (int i = 0; i < n; i++) {
 				x[i] = rnd.nextInt(W+1);
 				y[i] = rnd.nextInt(H+1);
 			}
 			if (ok(x, y, r, n)) {
 				for (int i = 0; i < n; i++) {
 					out.printf("%.12f %.12f", x[i], y[i]);
 					if (i == n-1) out.println(); else out.print(" ");
 				}
 				break;
 			}
 		}
 	}
 
 	private boolean ok(double[] x, double[] y, double[] r, int n) {
 		for (int i = 0; i < n; i++) {
 			for (int j = i+1; j < n; j++) {
 				if (intersects(x[i], y[i], r[i], x[j], y[j], r[j])) {
 					return false;
 				}
 			}
 		}
 		return true;
 	}
 
 }
