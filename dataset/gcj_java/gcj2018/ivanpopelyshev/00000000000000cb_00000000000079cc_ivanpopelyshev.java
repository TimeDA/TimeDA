

import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Solution implements Runnable {

	final String filename = "";

	public void solve() throws Exception {
		int T = iread();
		for (int test=1;test<=T; test++){
		double A = dread();
        double x = Math.asin(A / Math.sqrt(2.0)) - Math.PI / 4.0;
        
        out.write("Case #"+test+":\n");
        out.write(df.format(Math.cos(x) * 0.5) + " " + df.format(Math.sin(x)* 0.5) + " "+df.format(0)+"\n");
        out.write(df.format(- Math.sin(x) * 0.5) + " " + df.format(Math.cos(x)* 0.5) + " "+df.format(0)+"\n");
        out.write(df.format(0.0) + " " + df.format(0.0) + " "+df.format(0.5) + "\n");
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
