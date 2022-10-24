import java.io.*;
 import java.util.*;
 
 public class D {
 	FastScanner in;
 	PrintWriter out;
 
 	int count(String[] s, int mask) {
 		HashSet<String> hs = new HashSet<>();
 		for (int i = 0; i < s.length; i++)
 			if (((1 << i) & mask) != 0) {
 				String ss = s[i];
 				for (int j = 0; j <= ss.length(); j++) {
 					hs.add(ss.substring(0, j));
 				}
 			}
 		return hs.size();
 	}
 
 	void solveTestCase() {
 		int m = in.nextInt();
 		int n = in.nextInt();
 		String[] s = new String[m];
 		for (int i = 0; i < m; i++) {
 			s[i] = in.next();
 		}
 		int[][] dp = new int[n + 1][1 << m];
 		int[][] cnt = new int[n + 1][1 << m];
 		cnt[0][0] = 1;
 		final int MOD = (int) 1e9 + 7;
 		for (int i = 0; i < n; i++) {
 			for (int st = 0; st < 1 << m; st++)
 				for (int sub = 0; sub < 1 << m; sub++)
 					if (((sub) & st) == sub) {
 						int curDp = dp[i][st ^ sub] + count(s, sub);
 						if (curDp > dp[i + 1][st]) {
 							dp[i + 1][st] = curDp;
 							cnt[i + 1][st] = 0;
 						}
 						if (curDp == dp[i + 1][st])
 							cnt[i + 1][st] = (cnt[i + 1][st] + cnt[i][st ^ sub])
 									% MOD;
 					}
 		}
 		out.println(dp[n][(1 << m) - 1] + " " + cnt[n][(1 << m) - 1]);
 	}
 
 	void solve() {
 		int testNumber = in.nextInt();
 		for (int test = 1; test <= testNumber; test++) {
 			System.err.println(test);
 			out.print("Case #" + test + ": ");
 			solveTestCase();
 		}
 	}
 
 	void run() {
 		try {
 			in = new FastScanner(new File("D.in"));
 			out = new PrintWriter(new File("D.out"));
 
 			solve();
 
 			out.close();
 		} catch (FileNotFoundException e) {
 			e.printStackTrace();
 		}
 	}
 
 	void runIO() {
 
 		in = new FastScanner(System.in);
 		out = new PrintWriter(System.out);
 
 		solve();
 
 		out.close();
 	}
 
 	class FastScanner {
 		BufferedReader br;
 		StringTokenizer st;
 
 		public FastScanner(File f) {
 			try {
 				br = new BufferedReader(new FileReader(f));
 			} catch (FileNotFoundException e) {
 				e.printStackTrace();
 			}
 		}
 
 		public FastScanner(InputStream f) {
 			br = new BufferedReader(new InputStreamReader(f));
 		}
 
 		String next() {
 			while (st == null || !st.hasMoreTokens()) {
 				String s = null;
 				try {
 					s = br.readLine();
 				} catch (IOException e) {
 					e.printStackTrace();
 				}
 				if (s == null)
 					return null;
 				st = new StringTokenizer(s);
 			}
 			return st.nextToken();
 		}
 
 		boolean hasMoreTokens() {
 			while (st == null || !st.hasMoreTokens()) {
 				String s = null;
 				try {
 					s = br.readLine();
 				} catch (IOException e) {
 					e.printStackTrace();
 				}
 				if (s == null)
 					return false;
 				st = new StringTokenizer(s);
 			}
 			return true;
 		}
 
 		int nextInt() {
 			return Integer.parseInt(next());
 		}
 
 		long nextLong() {
 			return Long.parseLong(next());
 		}
 
 		double nextDouble() {
 			return Double.parseDouble(next());
 		}
 	}
 
 	public static void main(String[] args) {
 		new D().run();
 	}
 }
