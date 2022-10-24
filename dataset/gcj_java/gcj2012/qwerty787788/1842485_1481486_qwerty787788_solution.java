import java.util.*;
 import java.io.*;
 
 public class Solution {
 	FastScanner in;
 	PrintWriter out;
 
 	public void solve() throws IOException {
 		int numberCases = in.nextInt();
 		for (int test = 1; test <= numberCases; test++) {
 			int ans = 0;
 			int N = in.nextInt();
 			int d[] = new int[N];
 			int l[] = new int[N];
 			int use[] = new int[N];
 			for (int i = 0; i < N; i++) {
 				d[i] = in.nextInt();
 				l[i] = in.nextInt();
 				if (i == 0) use[i] = Math.min(l[i], d[i]); else
 					use[i] = -1;
 			}
 			int D = in.nextInt();
 			for (int i = 0; i < N; i++) {
 				int l1 = use[i];
 				if (l1 == -1) continue;
 				if (d[i] + l1 >= D) ans = 1;
 				for (int j = i + 1; j < N; j++) {
 					if (d[j] - d[i] <= l1) {
 						use[j] = Math.max(use[j], Math.min(l[j], d[j] - d[i]));
 					}
 				}
 			}
 			out.print("Case #");
 			out.print(test);
 			out.print(": ");
 			if (ans == 1)
 				out.println("YES"); else
 				out.println("NO");
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