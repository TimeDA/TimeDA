
import java.io.*;
import java.util.*;
import java.util.stream.IntStream;

public class Solution {
//	static short[][] memoRB = new short[501][501][501];
//	static int[] memoS = new int[501];
//	
//	static {
//		for (short[] me : memoRB) Arrays.fill(me, -1);
//		Arrays.fill(memoS, -1);
//		memoS[0] = 0;
//		memoS[1] = memoS[2] = 1;
//	}
//	
//	int recS(int v) {
//		if (memoS[v] == -1) {
//			for (int i = 1, sum = 0; ; i++) {
//				sum += i;
//				if (sum >= v) {
//					memoS[v] = 1 + recS(v - i);
//					break;
//				}
//			}
//		}
//		return memoS[v];
//	}
//	
	static int[][][] memoRB = new int[51][51][1<<10];
	static {
		for (int[][] me : memoRB) for (int[] mo : me) Arrays.fill(mo, -1);
	}
	int recRB(int a, int b, int sum) {
		if (memoRB[a][b][sum] == -1) {
			int ans = 0;
			for (int i = 1; i < 1<<(sum+1); i++) {
				int x = a, y = b;
				for (int j = 0; j <= sum; j++) {
					if ((i>>>j&1) == 1) {
						x -= j;
						y -= sum - j;
					}
				}
				if (x < 0 || y < 0) continue;
				ans = Math.max(ans, recRB(x, y, sum + 1) + Integer.bitCount(i));
			}
			memoRB[a][b][sum] = ans;
		}
		return memoRB[a][b][sum];
	}
	
	void solveTestcase(final Scanner in, final PrintWriter out) {
		int R = in.nextInt();
		int B = in.nextInt();
		
//		int ans = 0;
//		for (int sum = 1; ; sum++) {
//			for (int r = 0; r <= sum; r++) {
//				if (R >= r && B >= sum-r) {
//					R -= r;
//					B -= sum-r;
//					ans++;
//				}
//			}
//			if (R <= sum && B <= sum) {
//				break;
//			}
//		}
		
		out.println(recRB(R, B, 1));
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
