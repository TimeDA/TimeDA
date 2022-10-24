import java.io.*;
import java.util.*;

public class Solution {
	void solveTestcase(final Scanner in, final PrintWriter out) {
		int A = in.nextInt();
		
		int h = -1, w = -1;
		for (int i = (int)Math.sqrt(A); ; i--) {
			if (A % i == 0) {
				h = i;
				w = A / i;
				break;
			}
		}
		
		int[][] done = new int[h][w];
		while (true) {
			int min = 10;
			int tx = -1, ty = -1;
			for (int y = 1; y < h - 1; y++) {
				for (int x = 1; x < w - 1; x++) {
					int cnt = 0;
					for (int dy = -1; dy <= 1; dy++) {
						for (int dx = -1; dx <= 1; dx++) {
							cnt += done[y+dy][x+dx];
						}
					}
					if (min > cnt) {
						min = cnt;
						tx = x + 1;
						ty = y + 1;
					}
				}
			}
//			dump(A, w, h, min, tx, ty);
			out.println(tx + " " + ty);
			out.flush();

			int rx = in.nextInt() - 1;
			int ry = in.nextInt() - 1;
//			dump(A, w, h, min, tx, ty, rx, ry);
			if (rx < 0 || ry < 0) break;
			done[ry][rx] = 1;
		}
	}
	
	void solve() {
		try (final PrintWriter out = new PrintWriter(System.out)) {
			try (final Scanner in = new Scanner(System.in)) {
				int t = in.nextInt();
				for (int i = 0; i < t; i++) {
//					out.printf("Case #%d: ", i+1);
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
	
	static void dump(Object... o) { System.err.println(Arrays.deepToString(o)); }
}
