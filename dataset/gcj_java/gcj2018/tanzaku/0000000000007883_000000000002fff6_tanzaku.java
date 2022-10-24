
import java.io.*;
import java.util.*;

public class Solution {
	void solveTestcase(final Scanner in, final PrintWriter out) {
		int r = in.nextInt();
		int b = in.nextInt();
		int c = in.nextInt();
		int[] m = new int[c];
		int[] s = new int[c];
		int[] p = new int[c];
		for (int i = 0; i < c; i++) {
			m[i] = in.nextInt();
			s[i] = in.nextInt();
			p[i] = in.nextInt();
		}
		
		long low = 0, high = 1L<<60;
		while (high - low > 1) {
			long mid = (low + high) / 2;
			PriorityQueue<Long> processBits = new PriorityQueue<>(Comparator.reverseOrder());
			for (int i = 0; i < c; i++) {
				processBits.add(Math.min(m[i], (mid - p[i]) / s[i]));
			}
			
			long total = 0;
			for (int i = 0; i < r && total < b; i++) {
				total += processBits.poll();
			}
			if (total >= b) high = mid;
			else low = mid;
		}
		out.println(high);
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
