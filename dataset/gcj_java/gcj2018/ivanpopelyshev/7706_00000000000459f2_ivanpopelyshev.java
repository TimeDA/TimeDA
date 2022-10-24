import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Solution implements Runnable {

	final String problem = "A";
	final String filename = problem + "-sample";

//	 final String filename= problem+"-small-attempt0";
	// final String filename= problem+"-small-attempt1";
	 //final String filename= problem+"-large";

	public void solve() throws Exception {
		int C = iread();
		int[] B = new int[C];
		int sum = 0;
		for (int i=0;i<C;i++) {
			B[i] = iread();
			sum += B[i];
		}
		if (B[0] == 0 || B[C-1] == 0 || sum != C) {
			out.write("IMPOSSIBLE\n");
			return;
		}
		int h = 0;
		char[][] field = new char[C+1][C];
		for (int i=0;i<=C; i++) {
			field[i] = new char[C];
			Arrays.fill(field[i], '.');
		}
		
		int t = 0, u = 0;
		
		while (t<C && u<C) {
			if (B[u] == 0) {
				u++;
				continue;
			}
			h = Math.max(h, Math.abs(u-t));
			int h1 = 0;
			if (t>u) {
				for (int i=t; i>u; i--) {
					field[h1++][i] = '/';
				}
			} else {
				for (int i=t; i<u; i++) {
					field[h1++][i] = '\\';
				}
			}
			B[u]--;
			t++;
		}
		h++;
		out.write(h+"\n");
		for (int i=0;i<h;i++) {
			out.write(new String(field[i])+"\n");
		}
	}

	public void solve_gcj() throws Exception {
		int tests = iread();
		for (int test = 1; test <= tests; test++) {
			out.write("Case #" + test + ": ");
			solve();
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