import java.io.PrintWriter;
import java.util.Scanner;

public class Solution {
	void solveTestcase(final Scanner in, final PrintWriter out) {
		int D = in.nextInt();
		char[] cs = in.next().toCharArray();
		int n = cs.length;
		
		for (int t = 0; t < n * n; t++) {
			long life = D;
			long shoot = 1;
			for (char c : cs) {
				if (c == 'C') shoot *= 2;
				else life -= shoot;
			}
			if (life >= 0) {
				out.println(t);
				return;
			}
			
			for (int i = n - 2; i >= 0; i--) {
				if (cs[i] == 'C' && cs[i+1] == 'S') {
					swap(cs, i, i + 1);
					break;
				}
			}
		}
		out.println("IMPOSSIBLE");
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
