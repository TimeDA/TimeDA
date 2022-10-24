import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Solution implements Runnable {

	final String filename = "";

	int floor(int N, int x) {
		return (int) (x * 100L / N);
	}
	
	int round (int N, int x)  {
		int c = (int) (x * 200L / N);
		if (c%2==1) c++;
		return c/2;
	}
	
	int nextRoundUp(int N, int x) {
		int per = (int) (x * 100L / N);
		int per2 = (int) (x * 200L / N);
		if (per2 > 2*per) {
			return x;
		}
		int nxt = (int)((N * (2*per + 1) + 199) / 200);
		int nxt2 = (int)((N * (per + 1) + 99) / 100);
		if (nxt < nxt2) {
			return nxt;
		}
		
		while (x < N && per2 == 2*per) {
			x++;
			per = (int) (x * 100L / N);
			per2 = (int) (x * 200L / N);
		}
		return x;
	}
	
	public void solve() throws Exception {
		int T = iread();
		for (int test = 1; test <= T; test++) {
			int N = iread();
			int L = iread();
			
			int y = (int)N;
			
			int total = 0;
			long[] a = new long[L];
			for (int i=0;i<L;i++) {
				int x = iread();
				y-=x;
				a[i] = (nextRoundUp(N, x) - x) * (long)N + x;
			}
			int empty = nextRoundUp(N, 0);
			Arrays.sort(a);
			
			int j;
			for (j=0; j<L; j++) {
				int c = (int)(a[j] / N);
				int x = (int)(a[j] % N);
				
				if (c >= empty) {
					break;
				}
				if (y < c) break;
				
				y -= c;
				total += round(N, x + c);
			}
			while (j<L) {
				total += round(N, (int)(a[j] % N));
				j++;
			}
			
			total += round(N, empty) * (y / empty);
			y%=empty;
			total += round(N, y);

			out.write("Case #" + test + ": "+total);

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
