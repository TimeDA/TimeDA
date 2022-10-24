import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Solution {

	// Discuss this round on Codeforces: http://codeforces.com/blog/entry/59152

	static void sortBy(int a[], int v[]) {
		int n = a.length;
		if (n == 0) {
			return;
		}
		for (int i = 1; i < n; i++) {
			int j = i;
			int ca = a[i];
			int cv = v[ca];
			do {
				int nj = (j - 1) >> 1;
				int na = a[nj];
				if (cv <= v[na]) {
					break;
				}
				a[j] = na;
				j = nj;
			} while (j != 0);
			a[j] = ca;
		}
		int ca = a[0];
		for (int i = n - 1; i > 0; i--) {
			int j = 0;
			while ((j << 1) + 2 + Integer.MIN_VALUE < i + Integer.MIN_VALUE) {
				j <<= 1;
				j += (v[a[j + 2]] > v[a[j + 1]]) ? 2 : 1;
			}
			if ((j << 1) + 2 == i) {
				j = (j << 1) + 1;
			}
			int na = a[i];
			a[i] = ca;
			ca = na;
			int cv = v[ca];
			while (j != 0 && v[a[j]] < cv) {
				j = (j - 1) >> 1;
			}
			while (j != 0) {
				na = a[j];
				a[j] = ca;
				ca = na;
				j = (j - 1) >> 1;
			}
		}
		a[0] = ca;
	}

	static void solve() throws Exception {
		int n = scanInt();
		int l = scanInt();
		int have[] = new int[l];
		int spare = n;
		for (int i = 0; i < l; i++) {
			have[i] = scanInt();
			spare -= have[i];
		}
		int nru[] = new int[n + 1];
		for (int i = n - 1; i > 0; i--) {
			int x = 200 * i;
			if (x % n != 0 && ((x / n) & 1) == 0) {
				nru[i] = nru[i + 1] + 1;
			}
		}
		int nrus[] = new int[l];
		int idx[] = new int[l];
		for (int i = 0; i < l; i++) {
			nrus[i] = nru[have[i]];
			idx[i] = i;
		}
		sortBy(idx, nrus);
		int ans = 0;
		for (int i = 0; i < l; i++) {
			int cnru = nrus[idx[i]];
			if (spare >= cnru) {
				have[idx[i]] += cnru;
				spare -= cnru;
			}
			ans += (200 * have[idx[i]] + n) / (2 * n);
		}
		int nru0 = nru[1] + 1;
		ans += ((200 * nru0 + n) / (2 * n)) * (spare / nru0);
		ans += (200 * (spare % nru0) + n) / (2 * n);
		printCase();
		out.println(ans);
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