import java.io.*;
 
 import java.awt.geom.Point2D;
 import java.text.*;
 import java.math.*;
 import java.util.*;
 
 public class Main implements Runnable {
 
 	final String problem = "A";
 //	final String filename = problem + "-sample";
 
 	 final String filename= problem+"-small-attempt0";
 	// final String filename= problem+"-small-attempt1";
 	// final String filename = problem + "-large";
 
 	final int MOD = 1000002013;
 
 	public void solve() throws Exception {
 		int N = iread();
 		int M = iread();
 		int[] u = new int[M], v = new int[M], p = new int[M];
 		TreeSet<Integer> sets = new TreeSet<Integer>();
 		long goodAns = 0;
 		for (int i = 0; i < M; i++) {
 			u[i] = iread();
 			v[i] = iread();
 			p[i] = iread();
 			sets.add(u[i]);
 			sets.add(v[i]);
 			long d = Math.abs(u[i] - v[i]);
 			goodAns = (goodAns + ((2 * N - d + 1) * d / 2) % MOD * p[i]) % MOD;
 		}
 		Integer[] x = sets.toArray(new Integer[] {});
 		int n = x.length;
 		int[] balance = new int[n];
 		for (int i = 0; i < M; i++) {
 			balance[Arrays.binarySearch(x, u[i])] += p[i];
 			balance[Arrays.binarySearch(x, v[i])] -= p[i];
 		}
 		long badAns = 0;
 		int bal = 0;
 		for (int i = 1; i < n; i++) {
 			for (int j = i - 1; j >= 0; j--) {
 				if (balance[i] * balance[j] < 0) {
 					if (balance[i] < 0) {
 						long k = Math.min(balance[j], -balance[i]);
 						long d = x[i] - x[j];
 						badAns = (badAns + ((2 * N - d + 1) * d / 2) % MOD * k)
 								% MOD;
 						balance[j] -= k;
 						balance[i] += k;
 					} else {
 						long k = Math.min(-balance[j], balance[i]);
 						long d = x[i] - x[j];
 						badAns += (badAns + ((2 * N - d + 1) * d / 2) % MOD * k)
 								% MOD;
 						balance[j] += k;
 						balance[i] -= k;
 					}
 				}
 			}
 		}
 		out.write((goodAns - badAns) + "");
 	}
 
 	public void solve_gcj() throws Exception {
 		int tests = iread();
 		for (int test = 1; test <= tests; test++) {
 			out.write("Case #" + test + ": ");
 			solve();
 			out.write("\n");
 		}
 	}
 
 	public void run() {
 		try {
 			// in = new BufferedReader(new InputStreamReader(System.in));
 			// out = new BufferedWriter(new OutputStreamWriter(System.out));
 			in = new BufferedReader(new FileReader(filename + ".in"));
 			out = new BufferedWriter(new FileWriter(filename + ".out"));
 			solve_gcj();
 			out.flush();
 		} catch (Exception e) {
 			e.printStackTrace();
 			System.exit(1);
 		}
 	}
 
 	public int iread() throws Exception {
 		return Integer.parseInt(readword());
 	}
 
 	public double dread() throws Exception {
 		return Double.parseDouble(readword());
 	}
 
 	public long lread() throws Exception {
 		return Long.parseLong(readword());
 	}
 
 	BufferedReader in;
 
 	BufferedWriter out;
 
 	public String readword() throws IOException {
 		StringBuilder b = new StringBuilder();
 		int c;
 		c = in.read();
 		while (c >= 0 && c <= ' ')
 			c = in.read();
 		if (c < 0)
 			return "";
 		while (c > ' ') {
 			b.append((char) c);
 			c = in.read();
 		}
 		return b.toString();
 	}
 
 	public static void main(String[] args) {
 		try {
 			Locale.setDefault(Locale.US);
 		} catch (Exception e) {
 
 		}
 		new Thread(new Main()).start();
 		// new Thread(null, new Main(), "1", 1<<25).start();
 	}
 }