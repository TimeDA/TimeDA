import static java.lang.Double.parseDouble;
 import static java.lang.Integer.parseInt;
 import static java.lang.Long.parseLong;
 import static java.lang.Math.max;
 import static java.lang.System.exit;
 
 import java.io.BufferedReader;
 import java.io.IOException;
 import java.io.InputStreamReader;
 import java.io.OutputStreamWriter;
 import java.io.PrintWriter;
 import java.util.StringTokenizer;
 
 public class E {
 	
 	static BufferedReader in;
 	static PrintWriter out;
 	static StringTokenizer tok;
 	static int test;
 	
 //	static final Random rng = new Random(42);
 	
 	static void solve() throws Exception {
 		int n = nextInt();
 		int d = nextInt();
 //		int d = 1 << rng.nextInt(7);
 //		int n = 2 * d + rng.nextInt(40);
 		long a[] = new long[n];
 		for (int i = 0; i < n; i++) {
 			a[i] = nextLong();
 		}
 //		fill(a, rng.nextInt(10));
 //		int xxx = rng.nextInt(10);
 //		for (int i = 0; i < xxx; i++) {
 //			int dd = 1 << rng.nextInt(Integer.numberOfTrailingZeros(d) + 1);
 //			int s = rng.nextInt(2 * dd);
 //			for (int j = 0; j < n; j++) {
 //				if ((j + s) % (2 * dd) < dd) {
 //					++a[j];
 //				}
 //			}
 //		}
 		for (int i = 2 * d; i < n; i++) {
 			if (a[i] != a[i % (2 * d)]) {
 				printCase();
 				out.println("CHEATERS!");
 				return;
 			}
 		}
 		long ans = 0;
 		long cnts[] = new long[2 * d];
 		while (true) {
 			for (int i = 0; i < 2 * d; i++) {
 				long dCur = a[(i + d) % (2 * d)] - a[i];
 				long dPrev = a[(i + d - 1) % (2 * d)] - a[(i + 2 * d - 1) % (2 * d)];
 //				if ((dCur - dPrev) % 2 != 0) {
 //					printCase();
 //					out.println("CHEATERS!");
 //					return;
 //				}
 				cnts[i] = max((dCur - dPrev) / 2, 0);
 //				ans += cnts[i];
 				if (cnts[i] > 0) {
 					++ans;
 				}
 			}
 			long csum = 0;
 			for (int i = d; i < 2 * d; i++) {
 				csum += cnts[i];
 			}
 			for (int i = 0; i < 2 * d; i++) {
 				csum += cnts[i];
 				csum -= cnts[(i + d) % (2 * d)];
 				a[i] += csum;
 			}
 			for (int i = 0; i < d; i++) {
 				if (a[i] != a[i + d]) {
 					printCase();
 					out.println("CHEATERS!");
 					return;
 				}
 			}
 			if (d == 1) {
 				break;
 			}
 			d /= 2;
 		}
 		printCase();
 		out.println(ans);
 //		if (ans > xxx) {
 //			throw new AssertionError();
 //		}
 	}
 	
 	static void printCase() {
 		out.print("Case #" + test + ": ");
 	}
 	
 	static void printlnCase() {
 		out.println("Case #" + test + ":");
 	}
 	
 	static int nextInt() throws IOException {
 		return parseInt(next());
 	}
 
 	static long nextLong() throws IOException {
 		return parseLong(next());
 	}
 
 	static double nextDouble() throws IOException {
 		return parseDouble(next());
 	}
 
 	static String next() throws IOException {
 		while (tok == null || !tok.hasMoreTokens()) {
 			tok = new StringTokenizer(in.readLine());
 		}
 		return tok.nextToken();
 	}
 
 	public static void main(String[] args) {
 		try {
 			in = new BufferedReader(new InputStreamReader(System.in));
 			out = new PrintWriter(new OutputStreamWriter(System.out));
 			int tests = nextInt();
 			for (test = 1; test <= tests; test++) {
 				solve();
 			}
 			in.close();
 			out.close();
 		} catch (Throwable e) {
 			e.printStackTrace();
 			exit(1);
 		}
 	}
 }