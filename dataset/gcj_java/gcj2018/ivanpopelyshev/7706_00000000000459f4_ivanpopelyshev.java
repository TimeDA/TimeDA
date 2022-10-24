import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Solution implements Runnable {

	final String problem = "D";
	final String filename = problem + "-sample";

	// final String filename= problem+"-small-attempt0";
	// final String filename= problem+"-small-attempt1";
	// final String filename= problem+"-large";

	public void solve() throws Exception {
		R = iread();
		C = iread();
		int[][] field = new int[R][C];
		for (int i = 0; i < R; i++) {
			String s = readword();
			for (int j = 0; j < C; j++) {
				field[i][j] = s.charAt(j) == 'W' ? 1 : 0;
			}
		}

		int[] existPat = new int[16];
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				existPat[15 * field[i][j]] = 1;
		for (int i = 0; i < R; i++)
			for (int j = 0; j + 1 < C; j++) {
				int mask = field[i][j];
				mask += field[i][j + 1] << 1;
				mask += field[i][j] << 2;
				mask += field[i][j + 1] << 3;
				existPat[mask] = 1;
			}
		for (int i = 0; i + 1 < R; i++)
			for (int j = 0; j < C; j++) {
				int mask = field[i][j];
				mask += field[i][j] << 1;
				mask += field[i + 1][j] << 2;
				mask += field[i + 1][j] << 3;
				existPat[mask] = 1;
			}
		for (int i = 0; i + 1 < R; i++)
			for (int j = 0; j + 1 < C; j++) {
				int mask = field[i][j];
				mask += field[i][j + 1] << 1;
				mask += field[i + 1][j] << 2;
				mask += field[i + 1][j + 1] << 3;
				existPat[mask] = 1;
			}

		fNew = new int[R][C];
		int ans = 0;
		for (int pat = 0; pat < 16; pat++) {
			if (existPat[pat] == 0)
				continue;

			for (int r = 0; r <= R; r++) {
				for (int c = 0; c <= C; c++) {
					for (int i = 0; i < R; i++) {
						for (int j = 0; j < C; j++) {
							int val = (pat & (1<<((i < r ? 0 : 2) + (j < c ? 0 : 1))))>0 ? 1 : 0;
							fNew[i][j] = field[i][j] == val ? 1 : 0;
						}
					}

					for (int i = 0; i < R; i++) {
						for (int j = 0; j < C; j++) {
							ans = Math.max(ans, dfs(i, j));
						}
					}
				}
			}
		}
		out.write(ans + "");
	}

	int R, C;
	int[][] fNew;

	int dfs(int x, int y) {
		if (fNew[x][y] == 0)
			return 0;
		fNew[x][y] = 0;
		int c = 1;
		if (x + 1 < R) {
			c += dfs(x + 1, y);
		}
		if (x > 0) {
			c += dfs(x - 1, y);
		}
		if (y + 1 < C) {
			c += dfs(x, y + 1);
		}
		if (y > 0) {
			c += dfs(x, y - 1);
		}
		return c;
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