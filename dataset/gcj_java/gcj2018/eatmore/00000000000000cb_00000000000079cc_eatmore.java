import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.atan;
import static java.lang.Math.cos;
import static java.lang.Math.sin;
import static java.lang.Math.sqrt;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class Solution {

	// Discuss this round on Codeforces: http://codeforces.com/blog/entry/58775

	static void solve() throws Exception {
		double a = scanDouble();
		double l = 0;
		double r = atan(sqrt(2));
		for (int i = 0; i < 53; i++) {
			double mid = (l + r) / 2;
			double /*x1 = 0, y1 = 0.5 * cos(mid),*/ z1 = 0.5 * sin(mid);
			double x2 = -0.5 * sqrt(0.5), /*y2 = -0.5 * sqrt(0.5) * sin(mid),*/ z2 = 0.5 * sqrt(0.5) * cos(mid);
			double xA = 2 * x2, zA = z1, zB = z1 + 2 * z2;
			double area = 2 * (-xA) * (zA + zB);
			if (area > a) {
				r = mid;
			} else {
				l = mid;
			}
		}
		double ans = (l + r) / 2;
		double x1 = 0, y1 = 0.5 * cos(ans), z1 = 0.5 * sin(ans);
		double x2 = -0.5 * sqrt(0.5), y2 = -0.5 * sqrt(0.5) * sin(ans), z2 = 0.5 * sqrt(0.5) * cos(ans);
		printlnCase();
		out.printf(Locale.US, "%.9f %.9f %.9f\n", x1, y1, z1);
		out.printf(Locale.US, "%.9f %.9f %.9f\n", x2, y2, z2);
		out.printf(Locale.US, "%.9f %.9f %.9f\n", -x2, y2, z2);
	}

	static int scanInt() throws IOException {
		return parseInt(scanString());
	}

	static long scanLong() throws IOException {
		return parseLong(scanString());
	}

	static double scanDouble() throws IOException {
		return parseDouble(scanString());
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