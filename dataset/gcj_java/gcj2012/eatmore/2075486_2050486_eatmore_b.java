import static java.lang.Double.isInfinite;
 import static java.lang.Double.parseDouble;
 import static java.lang.Integer.parseInt;
 import static java.lang.Long.parseLong;
 import static java.lang.System.exit;
 import static java.util.Arrays.fill;
 import static java.util.Arrays.sort;
 
 import java.io.BufferedReader;
 import java.io.IOException;
 import java.io.InputStreamReader;
 import java.io.OutputStreamWriter;
 import java.io.PrintWriter;
 import java.util.Comparator;
 import java.util.StringTokenizer;
 
 public class B {
 	
 	static BufferedReader in;
 	static PrintWriter out;
 	static StringTokenizer tok;
 	static int test;
 	
 	static final double EPS = 1e-9;
 	
 	static void solve() throws Exception {
 		// XXX
 		int n = nextInt();
 		int k = nextInt();
 		int cntSum = 0;
 		double p[] = new double[n];
 		int cnt[] = new int[n];
 		for (int i = 0; i < n; i++) {
 			p[i] = nextDouble() / nextDouble();
 			cnt[i] = nextInt();
 			cntSum += cnt[i];
 		}
 		Integer idx[] = new Integer[n];
 		for (int i = 0; i < n; i++) {
 			idx[i] = i;
 		}
 		{
 			final double op[] = p;
 			sort(idx, new Comparator<Integer>() {
 				public int compare(Integer o1, Integer o2) {
 					return op[o2] > op[o1] ? 1 : op[o2] < op[o1] ? -1 : 0;
 				}
 			});
 		}
 		{
 			double np[] = new double[cntSum];
 			for (int i = 0, jj = 0; i < n; i++) {
 				for (int j = 0; j < cnt[idx[i]]; j++) {
 					np[j + jj] = p[idx[i]];
 				}
 				jj += cnt[idx[i]];
 			}
 			p = np;
 			n = cntSum;
 		}
 		double probSleep[][] = new double[k + 1][n + 1];
 		double probAwaken[][] = new double[k + 1][n + 1];
 		for (double t[]: probSleep) {
 			fill(t, Double.POSITIVE_INFINITY);
 		}
 		for (double t[]: probAwaken) {
 			fill(t, Double.POSITIVE_INFINITY);
 		}
 		probSleep[0][0] = 0;
 		probAwaken[0][0] = 0;
 		for (int i = 0; i <= k; i++) {
 			for (int j = 0; j < n; j++) {
 				if (isInfinite(probAwaken[i][j])) {
 					continue;
 				}
 				if (probAwaken[i][j + 1] > probAwaken[i][j] || probAwaken[i][j + 1] + EPS > probAwaken[i][j] && probSleep[i][j + 1] > probSleep[i][j]) {
 					probSleep[i][j + 1] = probSleep[i][j];
 					probAwaken[i][j + 1] = probAwaken[i][j];
 				}
 				if (i < k) {
 					double cp = p[j];
 					double oldSleep = probSleep[i][j];
 					double oldAwaken = probAwaken[i][j];
 					double oldGood = 1 - oldSleep - oldAwaken;
 //					double newGood = oldGood * cp;
 					double newSleep = (oldGood + oldSleep) * (1 - cp);
 					double newAwaken = oldAwaken + oldSleep * cp;
 					if (probAwaken[i + 1][j + 1] > newAwaken || probAwaken[i + 1][j + 1] + EPS > newAwaken && probSleep[i + 1][j + 1] > newSleep) {
 						probSleep[i + 1][j + 1] = newSleep;
 						probAwaken[i + 1][j + 1] = newAwaken;
 					}
 				}
 			}
 		}
 		printCase();
 		out.println(probAwaken[k][n]);
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
 			tok = new StringTokenizer(in.readLine(), " /");
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