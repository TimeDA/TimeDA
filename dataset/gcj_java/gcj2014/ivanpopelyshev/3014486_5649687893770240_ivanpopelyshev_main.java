import java.io.*;
 
 import java.awt.geom.Point2D;
 import java.text.*;
 import java.math.*;
 import java.util.*;
 
 public class Main implements Runnable {
 
 	final String problem = "D";
 //	 final String filename = problem + "-sample";
 	//	final String filename = problem + "-small-attempt0";
 	 final String filename = problem + "-small-attempt2";
 	// final String filename= problem+"-large";
 
 	String[] s;
 	int N;
 
 	public int lcm(int num1, int num2) {
 		if (num1 < 0 || num2 < 0)
 			return 0;
 		if (cache[num1][num2] >= 0) {
 			return cache[num1][num2];
 		}
 		int j;
 		for (j = 0; j < s[num1].length() && j < s[num2].length(); j++)
 			if (s[num1].charAt(j) != s[num2].charAt(j)) {
 				break;
 			}
 		cache[num1][num2] = j;
 		return j;
 	}
 
 	long MOD = 1000000007;
 
 	int[][] cache;
 
 	public void solve() throws Exception {
 		int M = iread();
 		N = iread();
 		s = new String[M];
 		for (int i = 0; i < M; i++)
 			s[i] = readword();
 		cache = new int[M][M];
 		for (int i = 0; i < M; i++)
 			Arrays.fill(cache[i], -1);
 		Arrays.sort(s);
 
 		long[] res = new long[N + 1];
 		int ans = 0;
 		for (int N1 = N; N1 > 0; N1--) {
 			int ans1 = 0;
 			long ans2 = 1;
 			for (int i = 0; i < M; i++) {
 				int x = lcm(i, i - N1);
 				int y = 1;
 				for (int k = i - N1 + 1; k < i; k++)
 					if (lcm(i, k) == x)
 						y++;
 					else
 						break;
 				ans1 += s[i].length() - x;
 				ans2 = (ans2 * y) % MOD;
 			}
 			if (N1 < N && ans != ans1)
 				break;
 			ans = ans1;
 			res[N1] = ans2;
 		}
 		long[][] C = new long[N + 1][N + 1];
 		for (int i = 0; i <= N; i++) {
 			C[i][0] = C[i][i] = 1;
 			for (int j = 1; j < i; j++)
 				C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
 		}
 		long res0 = 0;
 		int t = 1;
 		for (int i = N; i > 0; i--) {
 			res0 = (res0 + t * res[i] * C[N][i]) % MOD;
 			t *= -1;
 		}
 		if (res0 < 0)
 			res0 += MOD;
 		ans += N;
 
 		dummy();
 		if (dummy_ans != ans || dummy_res != res0) {
 			System.out.println("BUG");
 		}
 
 //		out.write(ans + " " + res0);
 		out.write(dummy_ans + " " + dummy_res);
 	}
 
 	public void dummy() {
 		test = new int[s.length];
 		dummy_ans = dummy_res = 0;
 		rec(0);
 	}
 
 	int[] test;
 	int dummy_ans;
 	int dummy_res;
 
 	public void rec(int m) {
 		if (m < s.length) {
 			for (int i = 0; i < N; i++) {
 				test[m] = i;
 				rec(m + 1);
 			}
 			return;
 		}
 		cycle: for (int i = 0; i < N; i++) {
 			for (int j = 0; j < s.length; j++)
 				if (test[j] == i) {
 					continue cycle;
 				}
 			return;
 		}
 		int ans = N;
 		int[] test2 = new int[N];
 		Arrays.fill(test2, -1);
 		for (int i = 0; i < s.length; i++) {
 			int k = test[i];
 			ans += s[i].length() - lcm(i, test2[k]);
 			test2[k] = i;
 		}
 		if (ans > dummy_ans) {
 			dummy_ans = ans;
 			dummy_res = 1;
 		} else if (ans == dummy_ans)
 			dummy_res++;
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