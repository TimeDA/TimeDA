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
			long D = iread();
			String s = readword();

			out.write("Case #" + test + ": ");

			int n = s.length();
			int pos = -1;

			for (int i = 0; i < n; i++) {
				if (s.charAt(i) == 'C') {
					pos = i;
					break;
				}
			}

			if (pos == -1) {
				if (n > D) {
					out.write("IMPOSSIBLE");
				} else {
					out.write("0");
				}
			} else {
				if (n - 1 > D) {
					out.write("IMPOSSIBLE");
				} else {
					int k = 0;
					while (pos < n) {
						if (2 * (n - pos - 1) + pos <= D) {
							out.write(k + "");
							break;
						}
						k++;
						pos++;
					}
				}
			}

			out.write("\n");
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
