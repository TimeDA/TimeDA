import java.io.*;
 import java.util.*;
 
 public class CookieClickerAlpha {
 
 	FastScanner in;
 	PrintWriter out;
 
 	void solve() {
 		double c = in.nextDouble(), f = in.nextDouble(), x = in.nextDouble();
 		double ans = Double.MAX_VALUE;
 		
 		double curRate = 2;
 		double curTime = 0;
 		while (x / curRate + curTime < ans) {
 			ans = Math.min(x / curRate + curTime, ans);
 			
 			curTime += c / curRate;
 			curRate += f;
 		}
 		
 		out.printf(Locale.US, "%.12f\n", ans);
 	}
 
 	void run() {
 		try {
 			in = new FastScanner("input.txt");
 			out = new PrintWriter("output.txt");
 			int T = in.nextInt();
 			for (int i = 1; i <= T; i++) {
 				long time = System.currentTimeMillis();
 				out.printf("Case #%d: ", i);
 				solve();
 				System.err.println("Test #" + i + " done in " + (System.currentTimeMillis() - time)
 						+ " ms");
 			}
 			out.close();
 		} catch (Exception e) {
 			e.printStackTrace();
 		}
 	}
 
 	class FastScanner {
 		BufferedReader br;
 		StringTokenizer st;
 
 		public FastScanner(String s) {
 			try {
 				br = new BufferedReader(new FileReader(s));
 			} catch (FileNotFoundException e) {
 				// TODO Auto-generated catch block
 				e.printStackTrace();
 			}
 		}
 
 		String nextToken() {
 			while (st == null || !st.hasMoreElements()) {
 				try {
 					st = new StringTokenizer(br.readLine());
 				} catch (IOException e) {
 					// TODO Auto-generated catch block
 					e.printStackTrace();
 				}
 			}
 			return st.nextToken();
 		}
 
 		int nextInt() {
 			return Integer.parseInt(nextToken());
 		}
 
 		long nextLong() {
 			return Long.parseLong(nextToken());
 		}
 
 		double nextDouble() {
 			return Double.parseDouble(nextToken());
 		}
 	}
 
 	public static void main(String[] args) {
 		new CookieClickerAlpha().run();
 	}
 }
