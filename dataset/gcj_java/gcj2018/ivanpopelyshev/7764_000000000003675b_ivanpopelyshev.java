import java.io.*;

import java.awt.geom.Point2D;
import java.text.*;
import java.math.*;
import java.util.*;

public class Solution implements Runnable {

	final String filename = "";

	int INF = -10000000;
	
	public void solve() throws Exception {
		int T = iread();
		for (int test = 1; test <= T; test++) {
			int S = iread();

			int[] D = new int[S], A = new int[S], B = new int[S];
		
			for (int i = 0; i < S; i++) {
				D[i] = iread(); A[i] = iread(); B[i] = iread();
			}

			int max = 1, N = S;
			int left = -1;

			for (int i=0;i+1<S;i++) {
				int j = i+1;
				while (j<S && D[i]+A[i] == D[j]+A[j] && D[i]-B[i] == D[j]-B[j]) {
					j++;
				}

				if (j==S) {
					if (j-i>max) {
						max = j-i;
						N = 1;
					} else if (j-i==max) {
						N++;
					}
					continue;
				}

				int a = INF, b = INF;
				
				if (D[i] + A[i] != D[j]+A[j] &&
						D[i] - B[i] != D[j] -B[j]) {
					
					a = D[i] + A[i];
					b = D[j] - B[j];
					
					int j0 = j;
					
					while (j < S) {
						if (D[j] + A[j] == a || D[j]-B[j] == b) {
							j++;
							continue;
						}
						break;
					}
					
					if (j-i>max) {
						max = j-i;
						N = 1;
					} else if (j-i==max) {
						N++;
					}
					
					j = j0;

					a = D[j] + A[j];
					b = D[i] - B[i];
					
					while (j < S) {
						if (D[j] + A[j] == a || D[j]-B[j] == b) {
							j++;
							continue;
						}
						break;
					}
					
					if (j-i>max) {
						max = j-i;
						N = 1;
					} else if (j-i==max) {
						N++;
					}
					
					continue;
				}
				
				if (D[i]+A[i] == D[j]+A[j]) {
					a = D[i]+A[i];
				} else {
					b = D[i]-B[i];
				}
				
				while (j < S) {
					if (D[j] + A[j] == a || D[j]-B[j] == b) {
						j++;
						continue;
					}
					if (a==INF) {
						a = D[j] + A[j];
						j++;
						continue;
					}
					if (b==INF) {
						b = D[j] - B[j];
						j++;
						continue;
					}
					break;
				}
				
				if (j-i>max) {
					max = j-i;
					N = 1;
				} else if (j-i==max) {
					N++;
				}
			}
			
			if (max==1) {
				N = S;
			}			

			out.write("Case #" + test + ": " + max+" "+N);

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
