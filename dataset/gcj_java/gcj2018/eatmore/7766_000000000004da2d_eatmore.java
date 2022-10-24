import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.fill;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Solution {

	// Discuss this round on Codeforces: https://codeforces.com/blog/entry/61114
	
	static int time;
	static int counts[] = new int[26];
	static int curCounts[] = new int[26];
	static boolean possible[] = new boolean[26];
	
	static final int batchSize = 100;
	
	static void testSingle(int val) throws IOException {
		for (int it = 0; it < batchSize; it++) {
			out.println(val);
		}
		out.flush();
		for (int it = 0; it < batchSize; it++) {
			if (scanInt() != 0) {
				for (int i = 2; i <= 25; i++) {
					if (possible[i] && curCounts[i] >= 0) {
						++curCounts[i];
					}
				}
			}
			++time;
			for (int i = 2; i <= 25; i++) {
				if (possible[i] && time % i == 0) {
					if (counts[i] < 0) {
						counts[i] = curCounts[i];
					} else if (counts[i] != curCounts[i]) {
						possible[i] = false;
						continue;
					}
					curCounts[i] = 0;
				}
			}
		}
	}
	
	static int resNum, resDen;
	static void testMulti(int val) throws IOException {
		for (int i = 2; i <= 25; i++) {
			if (possible[i]) {
				counts[i] = -1;
				curCounts[i] = time % i == 0 ? 0 : -1;
			}
		}
		tests: while (true) {
			testSingle(val);
			int myNum = -1, myDen = -1;
			for (int i = 2; i <= 25; i++) {
				if (possible[i]) {
					if (counts[i] < 0) {
						continue tests;
					}
					int newNum = counts[i], newDen = i;
					int g = gcd(newNum, newDen);
					newNum /= g;
					newDen /= g;
					if (myNum < 0) {
						myNum = newNum;
						myDen = newDen;
					} else if (myNum != newNum || myDen != newDen) {
						continue tests;
					}
				}
			}
			if (myNum < 0) {
				throw new AssertionError();
			}
			resNum = myNum;
			resDen = myDen;
			return;
		}
	}
	
	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	
	static int lcm(int a, int b) {
		return a / gcd(a, b) * b;
	}

	static void solve() throws Exception {
		scanInt();
		time = 0;
		fill(possible, true);
		int ans = 1;
		int curNum = 0, curDen = 1;
		int curQ = 1000001;
		while (curNum != 1 || curDen != 1) {
			int l = 1, r = curQ;
			int newNum = 1, newDen = 1;
			while (l + 1 < r) {
				int mid = (l + r) >> 1;
				testMulti(mid);
				ans = lcm(ans, resDen);
				if (resNum != curNum || resDen != curDen) {
					l = mid;
					newNum = resNum;
					newDen = resDen;
				} else {
					r = mid;
				}
			}
			curQ = l;
//			System.err.println(curQ + " " + newNum + "/" + newDen);
			curNum = newNum;
			curDen = newDen;
		}
		out.println(-ans);
		out.flush();
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