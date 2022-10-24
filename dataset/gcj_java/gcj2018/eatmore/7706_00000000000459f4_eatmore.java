import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Solution {

	// Discuss this round on Codeforces: http://codeforces.com/blog/entry/59547

	static void solve() throws Exception {
		n = scanInt();
		m = scanInt();
		boolean map[][] = new boolean[n][m];
		boolean blocks[] = new boolean[16];
		for (int i = 0; i < n; i++) {
			String l = in.readLine();
			for (int j = 0; j < m; j++) {
				switch (l.charAt(j)) {
				case 'B':
					map[i][j] = true;
					break;
				case 'W':
					break;
				default:
					throw new AssertionError();
				}
				blocks[map[i][j] ? 15 : 0] = true;
				if (i > 0) {
					blocks[(map[i - 1][j] ? 3 : 0) | (map[i][j] ? 12 : 0)] = true;
					if (j > 0) {
						blocks[(map[i - 1][j - 1] ? 1 : 0) | (map[i - 1][j] ? 2 : 0) |
						       (map[i][j - 1] ? 4 : 0) | (map[i][j] ? 8 : 0)] = true;
					}
				}
				if (j > 0) {
					blocks[(map[i][j - 1] ? 5 : 0) | (map[i][j] ? 10 : 0)] = true;
				}
			}
		}
		omap = new boolean[n][m];
		int ans = 0;
		for (int bl = 0; bl < 16; bl++) {
			if (!blocks[bl]) {
				continue;
			}
			int ilim = (bl & 3) == (bl >> 2) ? 1 : n;
			int jlim = (bl & 5) == ((bl & 10) >> 1) ? 1 : m;
			for (int i = 0; i < ilim; i++) {
				for (int j = 0; j < jlim; j++) {
					boolean v = (bl & 1) != 0;
					for (int ii = 0; ii < i; ii++) {
						for (int jj = 0; jj < j; jj++) {
							omap[ii][jj] = map[ii][jj] == v;
						}
					}
					v = (bl & 2) != 0;
					for (int ii = 0; ii < i; ii++) {
						for (int jj = j; jj < m; jj++) {
							omap[ii][jj] = map[ii][jj] == v;
						}
					}
					v = (bl & 4) != 0;
					for (int ii = i; ii < n; ii++) {
						for (int jj = 0; jj < j; jj++) {
							omap[ii][jj] = map[ii][jj] == v;
						}
					}
					v = (bl & 8) != 0;
					for (int ii = i; ii < n; ii++) {
						for (int jj = j; jj < m; jj++) {
							omap[ii][jj] = map[ii][jj] == v;
						}
					}
					for (int ii = 0; ii < n; ii++) {
						for (int jj = 0; jj < m; jj++) {
							if (omap[ii][jj]) {
								ans = max(ans, dfs(ii, jj));
							}
						}
					}
				}
			}
		}
		printCase();
		out.println(ans);
	}

	static int n, m;
	static boolean omap[][];
	static int dfs(int i, int j) {
		int res = 1;
		omap[i][j] = false;
		if (i > 0 && omap[i - 1][j]) {
			res += dfs(i - 1, j);
		}
		if (i < n - 1 && omap[i + 1][j]) {
			res += dfs(i + 1, j);
		}
		if (j > 0 && omap[i][j - 1]) {
			res += dfs(i, j - 1);
		}
		if (j < m - 1 && omap[i][j + 1]) {
			res += dfs(i, j + 1);
		}
		return res;
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