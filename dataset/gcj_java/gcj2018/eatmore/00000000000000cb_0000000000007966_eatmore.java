import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Solution {

	// Discuss this round on Codeforces: http://codeforces.com/blog/entry/58775

	static void solve() throws Exception {
		long d = scanLong();
		String s = scanString();
		int pows[] = new int[s.length() + 1];
		int count = 0;
		long cur = 0;
		int power = 0;
		for (int i = 0; i < s.length(); i++) {
			switch (s.charAt(i)) {
			case 'C':
				++power;
				break;
			case 'S':
				++count;
				cur += 1L << power;
				++pows[power];
				break;
			default:
				throw new AssertionError();
			}
		}
		if (d < count) {
			printCase();
			out.println("IMPOSSIBLE");
			return;
		}
		int ans = 0;
		while (cur > d) {
			if (pows[power] == 0) {
				--power;
			} else {
				++ans;
				--pows[power];
				++pows[power - 1];
				cur -= 1L << (power - 1);
			}
		}
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