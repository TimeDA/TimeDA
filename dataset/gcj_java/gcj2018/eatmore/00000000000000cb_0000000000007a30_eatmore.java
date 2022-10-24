import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Random;
import java.util.StringTokenizer;

public class Solution {

	// Discuss this round on Codeforces: http://codeforces.com/blog/entry/58775

	static void solve() throws Exception {
		int a = scanInt();
		int size = 3;
		while (size * (size + 1) < a) {
			++size;
		}
		boolean have[][] = new boolean[size][size + 1];
		Random rng = new Random(900913);
		while (true) {
			int i = rng.nextInt(size);
			int j = rng.nextInt(size + 1);
			if (have[i][j]) {
				continue;
			}
			if (i == 0) {
				++i;
			} else if (i == size - 1) {
				--i;
			}
			if (j == 0) {
				++j;
			} else if (j == size) {
				--j;
			}
			out.println((i + 1) + " " + (j + 1));
			out.flush();
			i = scanInt();
			j = scanInt();
			if (i == 0 && j == 0) {
				return;
			}
			have[i - 1][j - 1] = true;
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