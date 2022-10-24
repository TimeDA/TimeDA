import java.util.*;
 import java.io.*;
 
 public class Solution {
 	FastScanner in;
 	PrintWriter out;
 
 	int a[];
 	int high[];
 	int N;
 	
 	public void solve() throws IOException {
 		int numberCases = in.nextInt();
 		for (int test = 1; test <= numberCases; test++) {
 			int ans = 1;
 			N = in.nextInt();
 			a = new int[N - 1];
 			high = new int[N];
 			int right[] = new int[N];
 			
 			for (int i = 0; i < N - 1; i++)
 				a[i] = in.nextInt();
 			
 			for (int i = 0; i < N - 1; i++) {
 				for (int j = i + 1; j < a[i] - 1; j++)
 					if (a[j] > a[i]) ans = 0;
 			}
 			
 			if (ans != 0) {
 				boolean ok = false;
 				while (!ok) {
 					ok = true;
 					for (int i = 0; i < N - 1; i++) {
 						int best = i + 1;
 						for (int j = i + 1; j < N; j++) {
 							int x1 = best - i;
 							int x2 = j - i;
 							int y1 = high[best] - high[i];
 							int y2 = high[j] - high[i];
 							if (y2 * x1 > y1 * x2) {
 								best = j;
 							}
 						}
 						if (best != a[i] - 1) {
 							ok = false;
 							high[a[i] - 1]++;
 						}
 					}
 				}
 			}			
 			out.print("Case #");
 			out.print(test);
 			out.print(": ");
 			if (ans == 0)
 				out.println("Impossible"); else {
 					for (int i = 0; i < N; i++) {
 						out.print(high[i]);
 						out.print(" ");
 					}	
 					out.println();
 				}
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
 		new Solution().run();
 	}
 }