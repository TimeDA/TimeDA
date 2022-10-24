
import java.io.*;
import java.util.*;
import java.util.stream.IntStream;

public class Solution {
	char[][] ans = new char[110][100];
	
	void solveTestcase(final Scanner in, final PrintWriter out) {
//		final Random random = new Random(0);
//		LOOP: while (true) {
			int c = in.nextInt();
			int[] b = new int[c];
			for (int i = 0; i < c; i++) {
				b[i] = in.nextInt();
			}
//			int c = random.nextInt(4)+2;
//			int[] b = new int[c];
//			for (int i = 0; i < c; i++) {
//				b[i] = random.nextInt(c);
//			}
//			if (IntStream.of(b).sum() != c) continue;
			
			if (b[0] == 0 || b[c-1] == 0) {
				out.println("IMPOSSIBLE");
				return;
//				continue LOOP;
			}
			
			for (char[] a : ans) Arrays.fill(a, '.');
			for (int i = 0, l = 0; i < c; i++) {
				int x = b[i];
				if (x > 0) {
					for (int j = Math.min(l, i); j < i || x > 0; j++) {
						ans[Math.abs(i - j)][j] = j == i ? '.' : j < i ? '\\' : '/';
						if (j >= l && x > 0) {
							l++;
							x--;
						}
					}
				}
			}
			int h = check(c, b, ans);
//			if (verify(c, b) != h) {
//				dump(c, b, h, verify(c, b));
//			}
			if (h < 0) {
				out.println("IMPOSSIBLE");
				return;
//				continue LOOP;
			}
			out.println(h);
			for (int y = 0; y < h; y++) out.println(new String(ans[h-1-y], 0, c));
//		}
	}
	
	int check(int c, int[] b, char[][] ans) {
		int h;
		for (h = 1; ; h++) {
			if (ans[h][0] != '.' || ans[h][c-1] != '.') return -1;
			boolean find = false;
			for (int x = 0; x < c; x++) {
				find |= ans[h][x] != '.';
			}
			if (!find) {
				break;
			}
		}
		b = b.clone();
		for (int x = 0; x < c; x++) {
			int cx = x;
			for (int y = h - 1; y > 0; y--) {
				if (ans[y][cx] == '/') cx--;
				if (ans[y][cx] == '\\') cx++;
			}
			if (--b[cx] < 0) {
				return -1;
			}
		}
		return h;
	}
	
	int verify(int c, int[] b) {
		char[][] ans = new char[5][5];
		for (char[] a : ans) Arrays.fill(a, '.');
		
		int res = Integer.MAX_VALUE;
		int p3 = 1;
		for (int i = 0; i < 9; i++) p3 *= 3;
		for (int i = 0; i < p3; i++) {
			int v = i;
			for (int y = 0; y < 3; y++) {
				for (int x = 0; x < 3; x++) {
					ans[y+1][x+1] = "/\\.".charAt(v % 3);
					v /= 3;
				}
			}
			int h = check(c, b, ans);
			if (h != -1) {
				res = Math.min(res, h);
//				for (char[] a : ans) System.out.println(new String(a));
			}
		}
		if (res == Integer.MAX_VALUE) res = -1;
		return res;
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
