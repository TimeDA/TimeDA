import java.io.*;
import java.util.*;

public class Solution {
	void solveTestcase(final Scanner in, final PrintWriter out) {
		int n = in.nextInt();
		int[] xs = new int[n];
		int[] xs0 = new int[(n+1)/2];
		int[] xs1 = new int[n/2];
		for (int i = 0; i < n; i++) {
			xs[i] = in.nextInt();
			if (i % 2 == 0) xs0[i/2] = xs[i];
			if (i % 2 == 1) xs1[i/2] = xs[i];
		}

		Arrays.sort(xs0);
		Arrays.sort(xs1);
		Arrays.sort(xs);
		
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0 && xs[i] != xs0[i/2] || i % 2 == 1 && xs[i] != xs1[i/2]) {
				out.println(i);
				return;
			}
		}
		
		out.println("OK");
	}
	
	void solve() {
		try (final PrintWriter out = new PrintWriter(System.out)) {
			try (final Scanner in = new Scanner(System.in)) {
				int t = in.nextInt();
				for (int i = 0; i < t; i++) {
					out.printf("Case #%d: ", i+1);
					solveTestcase(in, out);
				}
			}
		}
	}

	public static void main(String[] args) {
		new Solution().solve();
	}
	
	static int gcd(int n, int r) { return r == 0 ? n : gcd(r, n%r); }
	static long gcd(long n, long r) { return r == 0 ? n : gcd(r, n%r); }
	
	static <T> void swap(T[] x, int i, int j) { T t = x[i]; x[i] = x[j]; x[j] = t; }
	static void swap(int[] x, int i, int j) { int t = x[i]; x[i] = x[j]; x[j] = t; }
	static void swap(char[] x, int i, int j) { char t = x[i]; x[i] = x[j]; x[j] = t; }

	void printArrayLn(PrintWriter out, int[] xs) { for(int i = 0; i < xs.length; i++) out.print(xs[i] + (i==xs.length-1?"\n":" ")); }
	void printArrayLn(PrintWriter out, long[] xs) { for(int i = 0; i < xs.length; i++) out.print(xs[i] + (i==xs.length-1?"\n":" ")); }
}
