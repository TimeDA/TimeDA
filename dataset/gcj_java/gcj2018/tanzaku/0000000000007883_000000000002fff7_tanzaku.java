
import java.io.*;
import java.util.*;

public class Solution {
	final double eps = 1e-9;
	
	static final Random random = new Random(0);
	
	void solveTestcase(final Scanner in, final PrintWriter out) {
		int n = in.nextInt();
		long p = in.nextInt();
//		int n = 100;
//		long p = 100000000;
		long p0 = 0;
		List<double[]> range = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			long w = in.nextInt();
			long h = in.nextInt();
//			long w = random.nextInt(10)+240;
//			long h = random.nextInt(10)+240;
			if (w > h) { long t = w; w = h; h = t; }
			p0 += 2 * (w + h);
			double low = 2 * w;
			double high = 2 * Math.sqrt(w*w+h*h);
			for (int j = range.size() - 1; j >= 0; j--) {
				double[] r = range.get(j);
				range.add(new double[] {r[0]+low, r[1]+high});
			}
			range.add(new double[] {low, high});
			for (int j = range.size() - 1; j >= 0; j--) {
				for (int k = j - 1; k >= 0; k--) {
					double[] r0 = range.get(j);
					double[] r1 = range.get(k);
					if (Math.max(r0[0], r1[0]) <= Math.min(r0[1], r1[1]) + eps) {
						r1[0] = Math.min(r0[0], r1[0]);
						r1[1] = Math.max(r0[1], r1[1]);
						range.set(j, range.get(range.size() - 1));
						range.remove(range.size() - 1);
						break;
					}
				}
			}
		}
		double ans = p0;
		for (double[] r : range) {
			for (int i = 0; i < 2; i++) if (p0 + r[i] <= p) {
				if (Math.abs(ans - p) > Math.abs(p0 + r[i] - p)) {
					ans = p0 + r[i];
				}
			}
			if (p >= p0 + r[0] && p <= p0 + r[1]) {
				ans = p;
			}
		}
		ans = Math.min(ans, p);
		out.printf("%.10f\n", ans);
	}
	
	static void solve() {
		try (final PrintWriter out = new PrintWriter(System.out)) {
			try (final Scanner in = new Scanner(System.in)) {
				int t = in.nextInt();
				for (int i = 0; i < t; i++) {
					out.printf("Case #%d: ", i+1);
					new Solution().solveTestcase(in, out);
				}
			}
		}
	}
	
	public static void main(String[] args) {
		solve();
	}
	
	static int gcd(int n, int r) { return r == 0 ? n : gcd(r, n%r); }
	static long gcd(long n, long r) { return r == 0 ? n : gcd(r, n%r); }
	
	static <T> void swap(T[] x, int i, int j) { T t = x[i]; x[i] = x[j]; x[j] = t; }
	static void swap(int[] x, int i, int j) { int t = x[i]; x[i] = x[j]; x[j] = t; }
	static void swap(char[] x, int i, int j) { char t = x[i]; x[i] = x[j]; x[j] = t; }

	void printArrayLn(PrintWriter out, int[] xs) { for(int i = 0; i < xs.length; i++) out.print(xs[i] + (i==xs.length-1?"\n":" ")); }
	void printArrayLn(PrintWriter out, long[] xs) { for(int i = 0; i < xs.length; i++) out.print(xs[i] + (i==xs.length-1?"\n":" ")); }
	
	static void dump(Object... o) { System.err.println(Arrays.deepToString(o)); }
}
