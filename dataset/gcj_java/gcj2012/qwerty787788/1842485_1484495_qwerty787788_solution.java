import java.util.*;
 import java.io.*;
 
 public class Solution {
 	FastScanner in;
 	PrintWriter out;
 	
 	public void solve() throws IOException {
 		int numberCases = in.nextInt();
 		for (int test = 1; test <= numberCases; test++) {
 			int N = in.nextInt();
 			long W = in.nextInt();
 			long L = in.nextInt();
 			int perm[] = new int[N];
 			long x[] = new long[N];
 			long y[] = new long[N];
 			long r[] = new long[N];
 			
 			for (int i = 0; i < N; i++)
 				perm[i] = i;
 			Random rnd = new Random();
 			for (int i = 0; i < N; i++) {
 				int k = Math.abs(rnd.nextInt() % (i + 1));
 				int z = perm[i];
 				perm[i] = perm[k];
 				perm[k] = z; 
 			}
 			for (int i = 0; i < N; i++) {
 				r[i] = in.nextInt();
 			}
 			
 			for (int i = 0; i < N; i++) {
 				int c = perm[i];
 				long ri = r[c];
 				long xl = 0;
 				long xr = W;
 				for (int it = 0; it < 60; it++) {
 					long xm = (xl + xr) / 2;
 					boolean ok1 = false;
 					for (long ny = 0; ny <= L; ny += Math.max(L / 100, 1)) {
 						boolean ok = true;
 						for (int j = 0; j < i; j++) {
 							double x1 = x[perm[j]];
 							double y1 = y[perm[j]];
 							double r1 = r[perm[j]];
 							double d2 = (xm - x1) * (xm - x1) + (ny - y1) * (ny - y1);
 							if (d2 < (r1 + ri) * (r1 + ri)) {
 								ok = false;
 								break;
 							}		
 						}
 						if (ok) {
 							ok1 = true;
 							break;
 						}
 					}
 					if (ok1) xr = xm; else xl = xm;
 				}
 				long y_1 = 0;
 				for (long ny = 0; ny <= L; ny += Math.max( L / 100, 1)) {
 					boolean ok = true;
 					for (int j = 0; j < i; j++) {
 						double x1 = x[perm[j]];
 						double y1 = y[perm[j]];
 						double r1 = r[perm[j]];
 						double d2 = (xr - x1) * (xr - x1) + (ny - y1) * (ny - y1);
 						if (d2 < (r1 + ri) * (r1 + ri)) {
 							ok = false;
 							break;
 						}		
 					}
 					if (ok) {
 						y_1 = ny;
 						break;
 					}
 				}
 				x[perm[i]] = xr;
 				y[perm[i]] = y_1;
 			}
 			boolean ok = true;
 			for (int i = 0; i < N; i++)
 				for (int j = i + 1; j < N; j++) {
 					long d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
 					long d2 = (r[i] + r[j]) * (r[i] + r[j]); 
 					if (d < d2) {
 						ok = false;
 					}
 				}
 			out.print("Case #");
 			out.print(test);
 			out.print(": ");
 			if (!ok) out.print("FAIL!!! ");
 			for (int i = 0; i < N; i++) {
 				out.print(x[i]);
 				out.print(" ");
 				out.print(y[i]);
 				out.print(" ");
 			}
 			out.println();
 		}
 	}
 
 	public void run() {
 		try {
 			in = new FastScanner(new File("a.in"));
 			out = new PrintWriter(new File("a.out"));
 
 			//in = new FastScanner(System.in);
 			//out = new PrintWriter(System.out);
 
 			solve();
 
 			out.close();
 		} catch (IOException e) {
 			e.printStackTrace();
 		}
 	}
 
 	class FastScanner {
 		BufferedReader br;
 		StringTokenizer st;
 
 		FastScanner(File f) {
 			try {
 				br = new BufferedReader(new FileReader(f));
 			} catch (FileNotFoundException e) {
 				e.printStackTrace();
 			}
 		}
 
 		FastScanner(InputStream f) {
 			br = new BufferedReader(new InputStreamReader(f));
 		}
 
 		String next() {
 			while (st == null || !st.hasMoreTokens()) {
 				try {
 					st = new StringTokenizer(br.readLine());
 				} catch (IOException e) {
 					e.printStackTrace();
 				}
 			}
 			return st.nextToken();
 		}
 
 		int nextInt() {
 			return Integer.parseInt(next());
 		}
 
 		long nextLong() {
 			return Long.parseLong(next());
 		}
 
 		double nextDouble() {
 			return Double.parseDouble(next());
 		}
 
 		String nextString() {
 			try {
 				return br.readLine();
 			} catch (IOException e) {
 				e.printStackTrace();
 			}
 			return null;
 		}
 	}
 
 	public static void main(String[] arg) {
 		Locale.setDefault(Locale.US);
 		new Solution().run();
 	}
 }