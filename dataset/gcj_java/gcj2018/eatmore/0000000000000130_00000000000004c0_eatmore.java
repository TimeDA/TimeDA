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
		int n = scanInt();
		int p[] = new int[n];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			p[i] = scanInt();
			sum += p[i];
		}
		printCase();
		while (sum > 0) {
			int max = 0, halves = 0;
			for (int i = 0; i < n; i++) {
				if (p[i] > p[max]) {
					max = i;
				}
				if (p[i] * 2 == sum) {
					++halves;
				}
			}
			if (halves == 2) {
				int half = sum / 2;
				for (int i = 0; i < n; i++) {
					if (p[i] == half) {
						out.print((char) ('A' + i));
						--p[i];
						--sum;
					}
				}
			} else {
				out.print((char) ('A' + max));
				--p[max];
				--sum;
			}
			out.print(' ');
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