
import java.io.*;
import java.util.*;

public class Solution {
	void run() {
		int n = in.nextInt();
		int[] x = new int[n];
		int[] y = new int[n];
		int[] h = new int[n];
		int p = 0;
		for (int i = 0; i < n; i++) {
			x[i] = in.nextInt();
			y[i] = in.nextInt();
			h[i] = in.nextInt();
//			if (x[i] < x[p] || x[i] == x[p] && y[i] < y[p]) {
//				p = i;
//			}
			if (h[i] > h[p]) {
				p = i;
			}
		}
		int q = -1;
		for (int i = 0; i < n; i++) {
			if (i == p) {
				continue;
			}
			if (q == -1) {
				q = i;
				continue;
			}
			if (h[i] == h[p]) {
				q = i;
				break;
			}
			if (above(
					x[p], y[p], h[p],
					x[p], y[p] + 1, h[p],
					x[q], y[q], h[q],
					x[i], y[i], h[i]
					)) {
				q = i;
			}
		}
		int[] ans = new int[n];
		ans[n - 1] = p;
		ans[n - 2] = q;
		boolean[] used = new boolean[n];
		used[p] = used[q] = true;
		for (int step = n - 3; step >= 0; step--) {
			int r = -1;
			for (int i = 0; i < n; i++) {
				if (used[i]) {
					continue;
				}
				if (r == -1) {
					r = i;
					continue;
				}
				if (above(
						x[p], y[p], h[p],
						x[q], y[q], h[q],
						x[r], y[r], h[r],
						x[i], y[i], h[i]
						)) {
					r = i;
				}
			}
			ans[step] = r;
			used[r] = true;
			p = q;
			q = r;
		}
		for (int i = 0; i < n; i++) {
			out.print(" " + (ans[i] + 1));
		}
		out.println();
	}
	
	static boolean above(int x0, int y0, int z0, int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3) {
		int ori2d = orientation(x0, y0, x1, y1, x2, y2);
		int ori3d = orientation3D(x0, y0, z0, x1, y1, z1, x2, y2, z2, x3, y3, z3);
		return ori2d == ori3d; //?
	}
	
	static int orientation(long xA, long yA, long xB, long yB, long xC, long yC) {
		return Long.signum(
				xA * yB - xB * yA +
				xB * yC - xC * yB +
				xC * yA - xA * yC
				);
	}
	
	static int orientation3D(int x0, int y0, int z0, int x1, int y1, int z1, int x2, int y2, int z2, int x3, int y3, int z3) {
		long a0 = x1 - x0;
		long a1 = x2 - x0;
		long a2 = x3 - x0;
		long b0 = y1 - y0;
		long b1 = y2 - y0;
		long b2 = y3 - y0;
		long c0 = z1 - z0;
		long c1 = z2 - z0;
		long c2 = z3 - z0;
		long det =
				a0 * b1 * c2 - a0 * b2 * c1 +
				a1 * b2 * c0 - a1 * b0 * c2 +
				a2 * b0 * c1 - a2 * b1 * c0;
		return Long.signum(det);
	}

	static MyScanner in;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		boolean stdStreams = true;
		String fileName = Solution.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
		String inputFileName = fileName + ".in";
		String outputFileName = fileName + ".out";
		
		Locale.setDefault(Locale.US);
		BufferedReader br;
		if (stdStreams) {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		} else {
			br = new BufferedReader(new FileReader(inputFileName));
			out = new PrintWriter(outputFileName);
		}
		in = new MyScanner(br);
		int tests = in.nextInt();
		for (int test = 0; test < tests; test++) {
			out.print("Case #" + (test + 1) + ":");
			new Solution().run();
		}
		br.close();
		out.close();
	}
	
	static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		MyScanner(BufferedReader br) {
			this.br = br;
		}
		
		void findToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
		}
		
		String next() {
			findToken();
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		
		long nextLong() {
			return Long.parseLong(next());
		}
		
		double nextDouble() {
			return Double.parseDouble(next());
		}
	}
}
