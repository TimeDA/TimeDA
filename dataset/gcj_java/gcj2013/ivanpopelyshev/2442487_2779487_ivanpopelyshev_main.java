import java.io.*;
 
 import java.awt.geom.Point2D;
 import java.text.*;
 import java.math.*;
 import java.util.*;
 
 public class Main implements Runnable {
 
 	final String problem = "C";
 //	 final String filename = problem + "-sample";
 
 	//	final String filename = problem + "-small-attempt0";
 
 	 final String filename= problem+"-small-attempt1";
 	// final String filename = problem + "-large";
 
 	public void solve() throws Exception {
 		int N = iread();
 		int[] A = new int[N];
 		int[] B = new int[N];
 		int[] val = new int[N];
 		int[] L = new int[N], R = new int[N];
 		for (int i = 0; i < N; i++) {
 			A[i] = iread();
 			L[i] = 1;
 			R[i] = N;
 		}
 		for (int i = 0; i < N; i++) {
 			B[i] = iread();
 		}
 		for (int i = 0; i < N; i++) {
 			int c = 0;
 			for (int j = 0; j < N; j++)
 				if (val[j] == 0 && i != j && A[j] <= A[i] && B[j] <= B[i]
 						&& L[j] == L[i]) {
 					c++;
 				}
 			val[i] = L[i] + c;
 			for (int j = 0; j < N; j++)
 				if (val[j] == 0 && L[j] == L[i] && i != j) {
 					if (A[j] <= A[i] && B[j] <= B[i])
 						R[j] = val[i] - 1;
 					else
 						L[j] = val[i] + 1;
 				}
 			L[i] = val[i];
 			R[i] = val[i];
 		}
 		for (int i = 0; i < N; i++) {
 			out.write(val[i] + "");
 			if (i < N - 1)
 				out.write(" ");
 		}
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
 			// in = new BufferedReader(new InputStreamReader(System.in));
 			// out = new BufferedWriter(new OutputStreamWriter(System.out));
 			in = new BufferedReader(new FileReader(filename + ".in"));
 			out = new BufferedWriter(new FileWriter(filename + ".out"));
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
 		new Thread(new Main()).start();
 		// new Thread(null, new Main(), "1", 1<<25).start();
 	}
 }