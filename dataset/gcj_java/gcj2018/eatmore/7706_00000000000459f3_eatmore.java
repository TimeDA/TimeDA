import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Solution {

	// Discuss this round on Codeforces: http://codeforces.com/blog/entry/59547

	static int ans[][] = new int[111][501];
	static {
		for (int i = 1; i < ans.length; i++) {
			fill(ans[i], Integer.MAX_VALUE);
		}
		int maxi = 0;
		for (int di = 0; di <= 31; di++) {
			for (int dj = 0; dj <= 31; dj++) {
				if (di == 0 && dj == 0) {
					continue;
				}
				for (int i = maxi; i >= 0; i--) {
					for (int j = 0; j <= 500 - di; j++) {
						if (ans[i][j] <= 500 - dj) {
							ans[i + 1][j + di] = min(ans[i + 1][j + di], ans[i][j] + dj);
							maxi = max(maxi, i + 1);
						}
					}
				}
			}
		}
	}

	static void solve() throws Exception {
		int i = scanInt(), j = scanInt();
		for (int a = ans.length - 1;; a--) {
			if (ans[a][i] <= j) {
				printCase();
				out.println(a);
				return;
			}
		}
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static String scanString() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			tok = new StringTokenizer(in.readLine());
		}
		return tok.nextToken();
	}

	static void printCase() {
		out.print("Case #" + test + ": ");
	}

	static void printlnCase() {
		out.println("Case #" + test + ":");
	}

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;

	public static void main(String[] args) {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			int tests = scanInt();
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