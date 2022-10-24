import java.io.*;
 import java.awt.geom.Point2D;
 import java.text.*;
 import java.math.*;
 import java.util.*;
 
 public class Main implements Runnable {
 
 	final String problem = "F";
 	// final String filename = problem + "-sample";
 
 //	final String filename = problem + "-small-attempt0";
 
 	 final String filename= problem+"-small-attempt1";
 	// final String filename= problem+"-large";
 
 	public void solve() throws Exception {
 		int N = iread(), R = iread(), G = iread();
 		double[] P = new double[N];
 		for (int i = 0; i < N; i++) {
 			P[i] = dread();
 		}
 		double ans = 0.0;
 		Arrays.sort(P);
 		int best = -1;
 
 		R *= G;
 		for (int num = 0; num < N; num++) {
 			double P1 = 0.0, P2 = 0.0;
 			for (int i = 0; i < num; i++)
 				P1 += P[i];
 			for (int i = num; i < N; i++)
 				P2 += P[i];
 
 			double[][] A = new double[R + 2][R + 2];
 			A[R + 1][R + 1] = 1;
 			for (int R1 = 0; R1 <= R; R1++) {
 				int RR = R1;
 				double p = 1.0;
 				while (RR >= G) {
 					A[R1][RR] = p * (N - num) * 1.0 / N;
 					A[R1][R + 1] += p * P2 / N;
 					p *= num * 1.0 / N;
 					RR -= G;
 				}
 				A[R1][RR] = p;
 				A[R1][R + 1] += p * (P1 + P2) / N;
 			}
 
 			double[][] inc = new double[R + 2][R + 2];
 			for (int R1 = 0; R1 <= R; R1++) {
 				inc[R1][Math.min(R, R1 + 1)] += 1.0;
 			}
 			inc[R + 1][R + 1] += 1.0;
 			double[][] C = A;// pow(A, G);
 			C = mult(C, inc);
 			// C = div(C, G);
 			// System.out.println(100 * Math.log(10) / Math.log(2));
 			for (int i = 0; i < 300; i++) {
 				C = div(mult(C, C), 2);
 				C = norm(C);
 				for (int a = 0; a <= R + 1; a++)
 					for (int b = 0; b <= R + 1; b++)
 						if (C[a][b] >= 1.5)
 							System.out.println(i);
 			}
 			double res = C[R][R + 1];
 			if (res > ans) {
 				ans = res;
 				best = num;
 			}
 		}
 		out.write(df.format(ans));
 		// System.out.println("ans=" + ans + " best=" + best);
 	}
 
 	double[][] mult(double[][] A, double[][] B) {
 		int N = A.length;
 		double[][] C = new double[N][N];
 		for (int i = 0; i < N; i++)
 			for (int j = 0; j < N; j++)
 				for (int k = 0; k < N; k++)
 					C[i][j] += A[i][k] * B[k][j];
 		return C;
 	}
 
 	double[][] norm(double[][] A) {
 		int N = A.length;
 		double[][] C = new double[N][N];
 		for (int i = 0; i < N; i++)
 			for (int j = 0; j < N; j++)
 				C[i][j] = A[i][j];
 		for (int i = 0; i + 1 < N; i++) {
 			double sum = 0.0;
 			for (int j = 0; j + 1 < N; j++) {
 				sum += C[i][j];
 			}
 			for (int j = 0; j < N; j++) {
 				C[i][j] /= sum;
 			}
 		}
 		return C;
 	}
 
 	double[][] pow(double[][] A, long k) {
 		double[][] C = E(A.length);
 		while (k > 0) {
 			if (k % 2 == 1)
 				C = mult(C, A);
 			A = mult(A, A);
 			k /= 2;
 		}
 		return C;
 	}
 
 	double[][] div(double[][] A, double d) {
 		int N = A.length;
 		double[][] C = new double[N][N];
 		for (int i = 0; i < N; i++)
 			for (int j = 0; j < N; j++)
 				if (i == N - 1 || j < N - 1)
 					C[i][j] = A[i][j];
 				else
 					C[i][j] = A[i][j] / d;
 		return C;
 	}
 
 	double[][] E(int N) {
 		double[][] C = new double[N][N];
 		for (int i = 0; i < N; i++)
 			C[i][i] = 1;
 		return C;
 	}
 
 	DecimalFormat df = new DecimalFormat("0.00000000000");
 
 	public void solve_gcj() throws Exception {
 		int tests = iread();
 		for (int test = 1; test <= tests; test++) {
 			long t = System.currentTimeMillis();
 			out.write("Case #" + test + ": ");
 			solve();
 			out.write("\n");
 			long t1 = System.currentTimeMillis() - t;
 			System.out.println("Test " + test + " done " + t1 + "ms");
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