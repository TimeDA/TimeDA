import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Solution {

	static void solve() throws Exception {
		int l = scanInt(), r = scanInt();
		scanInt();
		while (l + 1 < r) {
			int mid = (l + r + 1) >>> 1;
			out.println(mid);
			out.flush();
			switch (scanString()) {
			case "TOO_SMALL":
				l = mid;
				continue;
			case "TOO_BIG":
				r = mid - 1;
				continue;
			case "CORRECT":
				return;
			default:
				throw new AssertionError();
			}
		}
		out.println(r);
		out.flush();
		if (!"CORRECT".equals(scanString())) {
			throw new AssertionError();
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