import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Solution {

	// Discuss this round on Codeforces: https://codeforces.com/blog/entry/59910

	static long p4(int x1, int y1, int z1,
	               int x2, int y2, int z2,
	               int x3, int y3, int z3,
	               int x4, int y4, int z4) {
		x2 -= x1;
		y2 -= y1;
		z2 -= z1;
		x3 -= x1;
		y3 -= y1;
		z3 -= z1;
		x4 -= x1;
		y4 -= y1;
		z4 -= z1;
		long v1 = ((long) y2 * z3 - (long) z2 * y3) * x4;
		long v2 = ((long) z2 * x3 - (long) x2 * z3) * y4;
		long v3 = ((long) x2 * y3 - (long) y2 * x3) * z4;
		long low = (v1 & 0xffffffffL) + (v2 & 0xffffffffL) + (v3 & 0xffffffffL);
		long high = (v1 >> 32) + (v2 >> 32) + (v3 >> 32) + (low >> 32);
		return high < 0 ? -1 : 1;
	}

	static void solve() throws Exception {
		int n = scanInt();
		int x[] = new int[n];
		int y[] = new int[n];
		int z[] = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = scanInt();
			y[i] = scanInt();
			z[i] = scanInt();
		}
		boolean used[] = new boolean[n];
		int ans[] = new int[n];
		int p1 = -1, x1 = 0, y1 = 0;
		for (int i = 0; i < n; i++) {
			int cx = x[i], cy = y[i];
			if (p1 < 0 || cx < x1 || (cx == x1 && cy < y1)) {
				p1 = i;
				x1 = cx;
				y1 = cy;
			}
		}
		ans[n - 1] = p1;
		used[p1] = true;
		int p2 = -1, x2 = 0, y2 = 0;
		for (int i = 0; i < n; i++) {
			if (i == p1) {
				continue;
			}
			int cx = x[i], cy = y[i];
			if (p2 < 0 || (long) (cy - y1) * (x2 - x1) < (long) (cx - x1) * (y2 - y1)) {
				p2 = i;
				x2 = cx;
				y2 = cy;
			}
		}
		ans[n - 2] = p2;
		used[p2] = true;
		int z1 = z[p1], z2 = z[p2];
		for (int pi = n - 3; pi >= 0; pi--) {
			int p3 = -1, x3 = 0, y3 = 0, z3 = 0;
			boolean dir3 = false;
			for (int i = 0; i < n; i++) {
				if (used[i]) {
					continue;
				}
				int cx = x[i], cy = y[i], cz = z[i];
				if ((long) (cy - y1) * (x2 - x1) > (long) (cx - x1) * (y2 - y1)) {
					if (dir3 || (p3 >= 0 && p4(x1, y1, z1, x2, y2, z2, x3, y3, z3, cx, cy, cz) < 0)) {
						continue;
					}
				} else {
					if (dir3 && p4(x1, y1, z1, x2, y2, z2, x3, y3, z3, cx, cy, cz) > 0) {
						continue;
					}
					dir3 = true;
				}
				p3 = i;
				x3 = cx;
				y3 = cy;
				z3 = cz;
			}
			ans[pi] = p3;
			used[p3] = true;
			p1 = p2; x1 = x2; y1 = y2; z1 = z2;
			p2 = p3; x2 = x3; y2 = y3; z2 = z3;
		}
		printCase();
		for (int i = 0; i < n; i++) {
			if (i > 0) {
				out.print(' ');
			}
			out.print(ans[i] + 1);
		}
		out.println();
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