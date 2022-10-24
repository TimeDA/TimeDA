import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Solution implements Runnable {

	final String problem = "C";
	final String filename = problem + "-sample";

	// final String filename= problem+"-small-attempt0";
	// final String filename= problem+"-small-attempt1";
	// final String filename= problem+"-large";

	public void solve() throws Exception {
		int N = iread();
		int[][] a = new int[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				a[i][j] = iread();
				if (a[i][j] > 0) {
					a[i][j]--;
				} else {
					a[i][j] = 2 * N + a[i][j];
				}
			}
		}

		int bad = 0;
		grid = new boolean[N][N];
		M = new int[N];
		was = new boolean[N];

		Set<Integer> rows = new TreeSet<Integer>();
		Set<Integer> cols = new TreeSet<Integer>();
		int[] cntCol = new int[N], cntRow = new int[N];
		for (int color = 0; color < 2 * N; color++) {
			rows.clear();
			cols.clear();
			Arrays.fill(cntCol, 0);
			Arrays.fill(cntRow, 0);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (a[i][j] == color) {
						cntRow[i]++;
						cntCol[j]++;
					}
				}
			}
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (a[i][j] == color) {
						if (cntRow[i] > 1 || cntCol[j] > 1) {
							rows.add(i);
							cols.add(j);
						}
					}
				}
			}

			Integer[] rowIndex = rows.toArray(new Integer[0]);
			Integer[] colIndex = cols.toArray(new Integer[0]);
			A = rowIndex.length;
			B = colIndex.length;
			for (int i = 0; i < A; i++)
				for (int j = 0; j < B; j++) {
					grid[i][j] = a[rowIndex[i]][colIndex[j]] == color;
					if (grid[i][j]) {
						bad++;
					}
				}
			Arrays.fill(M, -1);
			for (int i = 0; i < A; i++) {
				Arrays.fill(was, false);
				if (khun(i))
					bad--;
			}
		}

		out.write(bad + "");
	}

	int A, B;
	int[] M;
	boolean[][] grid;
	boolean[] was;

	boolean khun(int x) {
		if (was[x])
			return false;
		was[x] = true;
		for (int y = 0; y < B; y++) {
			if (grid[x][y] && (M[y] == -1 || khun(M[y]))) {
				M[y] = x;
				return true;
			}
		}
		return false;
	}

	public void solve_gcj() throws Exception {
		int tests = iread();
		for (int test = 1; test <= tests; test++) {
			out.write("Case #" + test + ": ");
			solve();
			out.write("\n");
		}
	}

	public void run() {
		try {
			 in = new BufferedReader(new InputStreamReader(System.in));
			 out = new BufferedWriter(new OutputStreamWriter(System.out));
//			in = new BufferedReader(new FileReader(filename + ".in"));
//			out = new BufferedWriter(new FileWriter(filename + ".out"));
			solve_gcj();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	public int iread() throws Exception {
		return Integer.parseInt(readword());
	}

	public double dread() throws Exception {
		return Double.parseDouble(readword());
	}

	public long lread() throws Exception {
		return Long.parseLong(readword());
	}

	BufferedReader in;

	BufferedWriter out;

	public String readword() throws IOException {
		StringBuilder b = new StringBuilder();
		int c;
		c = in.read();
		while (c >= 0 && c <= ' ')
			c = in.read();
		if (c < 0)
			return "";
		while (c > ' ') {
			b.append((char) c);
			c = in.read();
		}
		return b.toString();
	}

	public static void main(String[] args) {
		try {
			Locale.setDefault(Locale.US);
		} catch (Exception e) {

		}
		new Thread(new Solution()).start();
		// new Thread(null, new Main(), "1", 1<<25).start();
	}
}