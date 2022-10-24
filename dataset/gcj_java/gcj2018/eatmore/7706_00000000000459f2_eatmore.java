import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.min;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Solution {

	// Discuss this round on Codeforces: http://codeforces.com/blog/entry/59547

	static void solve() throws Exception {
		int n = scanInt();
		int c[] = new int[n];
		for (int i = 0; i < n; i++) {
			c[i] = scanInt();
		}
		if (c[0] == 0 || c[n - 1] == 0) {
			printCase();
			out.println("IMPOSSIBLE");
			return;
		}
		List<char[]> ans = new ArrayList<>();
		char l[] = new char[n];
		fill(l, '.');
		ans.add(l.clone());
		int cNew[] = new int[n];
		while (true) {
			boolean need = false;
			fill(cNew, 0);
			fill(l, '.');
			for (int i = 0, j = 0; i < n; j += c[i], i++) {
				if (j < i) {
					cNew[i - 1] += min(i - j, c[i]);
					l[i - 1] = '\\';
					need = true;
				}
				if (j <= i && j + c[i] >= i + 1) {
					++cNew[i];
				}
				if (j + c[i] > i + 1) {
					cNew[i + 1] += min(j + c[i] - i - 1, c[i]);
					l[i + 1] = '/';
					need = true;
				}
			}
			if (!need) {
				break;
			}
			ans.add(l.clone());
			int t[] = c;
			c = cNew;
			cNew = t;
		}
		printCase();
		out.println(ans.size());
		for (int i = ans.size() - 1; i >= 0; i--) {
			out.println(ans.get(i));
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