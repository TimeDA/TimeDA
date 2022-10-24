import java.io.*;
import java.util.*;

public class Solution {
	void solveTestcase(final Scanner in, final PrintWriter out) {
		h = in.nextInt();
		w = in.nextInt();
		int cutH = in.nextInt();
		int cutV = in.nextInt();
		map = new char[h][];
		for (int y = 0; y < h; y++) {
			map[y] = in.next().toCharArray();
			for (int x = 0; x < w; x++) {
				numChip += map[y][x] == '@' ? 1 : 0;
			}
		}
		
		sum = new int[h+1][w+1];
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				sum[y+1][x+1] = sum[y+1][x] + (map[y][x] == '@' ? 1 : 0);
			}
		}
		for (int x = 0; x <= w; x++) {
			for (int y = 0; y < h; y++) {
				sum[y+1][x] += sum[y][x];
			}
		}
		
		numChip /= (cutH + 1) * (cutV + 1);
		memo = new int[w+1][w+1][cutV + 1];
		boolean ok = false;
		for (int y = 1; y < h; y++) {
			for (int[][] x : memo) for (int[] mo : x) Arrays.fill(mo, 0);
			ok |= canV(0, 1, y, cutH, cutV);
		}
		out.println(ok ? "POSSIBLE" : "IMPOSSIBLE");
	}
	
	int numChip;
	int w, h;
	char[][] map;
	int[][] sum;
	TreeSet<Integer> cutPosV = new TreeSet<>();
	int[][][] memo;
	boolean canV(int px, int x, int y, int cutH, int cutV) {
		if (memo[x][px][cutV] == 0) {
			if (cutV == 0) {
				cutPosV.add(w);
				if (canH(y, cutH)) {
					return (memo[x][px][cutV] = 1) > 0;
				}
				cutPosV.remove(w);
				return (memo[x][px][cutV] = -1) > 0;
			}
			if (x >= w) {
				return (memo[x][px][cutV] = -1) > 0;
			}
			if (canV(px, x + 1, y, cutH, cutV)) {
				return (memo[x][px][cutV] = 1) > 0;
			}
			cutPosV.add(x);
			if (canH(y, cutH) && canV(x, x + 1, y, cutH, cutV - 1)) {
				return (memo[x][px][cutV] = 1) > 0;
			}
			cutPosV.remove(x);
			return (memo[x][px][cutV] = -1) > 0;
		}
		return memo[x][px][cutV] > 0;
	}
	
	boolean canH(int y0, int cutH) {
		int py = 0;
		for (int y = y0; y <= h; y++) {
			int px = 0;
			boolean ok = true;
			boolean all0 = true;
			for (int x : cutPosV) {
				all0 &= sum[y][x] - sum[y][px] - sum[py][x] + sum[py][px] == 0;
				ok &= sum[y][x] - sum[y][px] - sum[py][x] + sum[py][px] == numChip;
				px = x;
			}
			if (y == y0 && !ok) {
//				dump("ng1", cutPosV, cutH);
				return false;
			}
//			if (y0 == 2 && cutPosV.contains(3)) {
//				dump("???", py, y, cutPosV, ok, all0);
//			}
			if (all0) {
				py = y;
			}
			if (ok) {
				cutH--;
				py = y;
			}
		}
//		dump("check", cutPosV, y0, cutH, py, cutH == -1 && py == h);
		return cutH == -1 && py == h;
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
