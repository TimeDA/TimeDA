import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Long.signum;
import static java.lang.Math.abs;
import static java.lang.Math.min;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Solution {

	// Discuss this round on Codeforces: http://codeforces.com/blog/entry/59152

	static void solve() throws Exception {
		int n = scanInt();
		long formula[][] = new long[n][n];
		for (int i = 0; i < n; i++) {
			++formula[i][scanInt() - 1];
			++formula[i][scanInt() - 1];
		}
		long amount[] = new long[n];
		long limit = 1;
		for (int i = 0; i < n; i++) {
			amount[i] = scanLong();
			limit += amount[i];
		}
		limit *= 2;
		long claim[] = new long[n];
		claim[0] = 1;
		long ans = 0;
		ans: while (true) {
			long can = Long.MAX_VALUE;
			for (int i = 0; i < n; i++) {
				if (claim[i] != 0) {
					can = min(can, amount[i] / claim[i]);
				}
			}
			ans += ++can;
			for (int i = 0; i < n; i++) {
				amount[i] -= can * claim[i];
			}
			neg: while (true) {
				for (int i = 0; i < n; i++) {
					long amt = amount[i], clm = claim[i], form[] = formula[i];
					if (amt >= 0) {
						continue;
					}
					if (form[i] != 0) {
						--ans;
						break ans;
					}
					formula[i] = null;
					amount[i] = claim[i] = 0;
					for (int j = 0; j < n; j++) {
						if (form[j] != 0) {
							amount[j] += mul(amt, form[j], limit);
							claim[j] += mul(clm, form[j], limit);
						}
						long f2[] = formula[j];
						if (f2 != null && f2[i] != 0) {
							long f2i = f2[i];
							f2[i] = 0;
							for (int k = 0; k < n; k++) {
								if (form[k] != 0) {
									f2[k] += mul(f2i, form[k], limit);
								}
							}
						}
					}
					continue neg;
				}
				break;
			}
		}
		printCase();
		out.println(ans);
	}

	static long mul(long a, long b, long limit) {
		long m = a * b;
		if (abs(m) >= limit || (b != 0 && m / b != a)) {
			m = limit * signum(a) * signum(b);
		}
		return m;
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