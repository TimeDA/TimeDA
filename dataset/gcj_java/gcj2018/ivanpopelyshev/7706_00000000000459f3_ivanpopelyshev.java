import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Solution implements Runnable {

	final String problem = "A";
	final String filename = problem + "-sample";

	// final String filename= problem+"-small-attempt0";
	// final String filename= problem+"-small-attempt1";
	// final String filename= problem+"-large";

	public void solve() throws Exception {
		int R = iread(), B = iread();
		out.write((res[R][B]-1) + "");
	}

	int[][][] tbl;
	int[][] res;
	int MAX = 501;
	int MAX2 = 40;

	public void init() {
		tbl = new int[MAX2][MAX][MAX];
		res = new int[MAX][MAX];

		for (int i = 0; i < MAX2; i++)
			for (int j = 0; j < MAX; j++)
				Arrays.fill(tbl[i][j], -1);
		tbl[0][0][0] = 0;

		for (int x = 0; x + 1 < MAX2; x++)
			for (int R = 0; R < MAX; R++)
				for (int C = 0; C < MAX; C++) {
					int t = tbl[x][R][C];
					if (t < 0)
						continue;
					for (int i = 0; i < MAX2; i++) {
						int R1 = R + x * i, C1 = C + i * (i - 1) / 2;
						int t1 = t + i;
						if (R1 >= MAX || C1 >= MAX)
							break;
						if (tbl[x + 1][R1][C1] < t1) {
							tbl[x + 1][R1][C1] = t1;
							if (res[R1][C1] < t1) {
								res[R1][C1] = t1;
							}
						}
					}
				}
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (res[i][j] < res[j][i]) {
					res[i][j] = res[j][i];
				}
			}
		}
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				if (i > 0 && res[i][j] < res[i - 1][j]) {
					res[i][j] = res[i - 1][j];
				}
				if (j > 0 && res[i][j] < res[i][j - 1]) {
					res[i][j] = res[i][j - 1];
				}
			}
		}
	}

	public void solve_gcj() throws Exception {
		init();

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