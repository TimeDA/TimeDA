import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Solution implements Runnable {

	final String filename = "";

	public void solve() throws Exception {
		int T = iread();
		for (int test = 1; test <= T; test++) {
			int A = iread(); // its 20
			int[][] done = new int[60][60];

			int w = 4, h = 5;
			if (A == 200) {
				w = 40;
				h = 50;
			}

			int cnt = 0;

			while (cnt < A) {
				int tx = 0, ty = 0, tm = 0;
				for (int i = 2; i < w; i++) {
					for (int j = 2; j < h; j++) {
						int cover = 0;
						for (int dx = -1; dx <= 1; dx++) {
							for (int dy = -1; dy <= 1; dy++) {
								if (done[i + dx][j + dy] == 0) {
									cover++;
								}
							}
						}
						if (cover > tm) {
							tm = cover;
							tx = i;
							ty = j;
						}
					}
				}
				out.write(tx + " " + ty + "\n");
				out.flush();
				int ii = iread(), jj = iread();
				if (ii == 0 && jj == 0)
					break;
				if (done[ii][jj] == 0) {
					done[ii][jj] = 1;
					cnt++;
				}
			}
		}
	}

	DecimalFormat df = new DecimalFormat("0.00000000");

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new BufferedWriter(new OutputStreamWriter(System.out));
			// in = new BufferedReader(new FileReader(filename+".in"));
			// out = new BufferedWriter(new FileWriter(filename+".out"));
			solve();
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
		// new Thread(new Main()).start();
		new Thread(null, new Solution(), "1", 1 << 25).start();
	}
}
