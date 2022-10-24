import java.io.*;
 import java.util.*;
 
 public class TrieSharding {
 
 	FastScanner in;
 	PrintWriter out;
 
 	final int INF = Integer.MIN_VALUE / 2;
 
 	class Trie {
 		int[][] next;
 		int states;
 
 		public Trie(String[] s) {
 			int len = 1;
 			for (String str : s) {
 				len += str.length();
 			}
 
 			next = new int[26][len];
 			states = 1;
 			for (int[] i : next) {
 				Arrays.fill(i, -1);
 			}
 
 			for (String str : s) {
 				int st = 0;
 
 				for (char c : str.toCharArray()) {
 					if (next[c - 'A'][st] == -1) {
 						next[c - 'A'][st] = states++;
 					}
 					st = next[c - 'A'][st];
 				}
 			}
 		}
 	}
 
 	void solve() {
 		int m = in.nextInt(), n = in.nextInt();
 		String[] s = new String[m];
 		for (int i = 0; i < m; i++){ 
 			s[i] = in.nextToken();
 		}
 
 		int[][] max = new int[n + 1][1 << m];
 		int[][] count = new int[n + 1][1 << m];
 
 		for (int[] i : max) {
 			Arrays.fill(i, INF);
 		}
 
 		max[0][0] = 0;
 		count[0][0] = 1;
 
 		int[] ans = new int[1 << m];
 		for (int i = 0; i < 1 << m; i++) {
 			String[] t = new String[Integer.bitCount(i)];
 			int tmp = 0;
 			for (int j = 0; j < m; j++) {
 				if ((i & (1 << j)) != 0) {
 					t[tmp++] = s[j];
 				}
 			}
 			ans[i] = new Trie(t).states;
 		}
 
 		
 		final int MOD = (int) (1e9 + 7);
 		for (int cnt = 0; cnt < n; cnt++) {
 			for (int mask = 0; mask < 1 << m; mask++) {
 				if (count[cnt][mask] == 0) {
 					continue;
 				}
 				
 				int rmn = ((1 << m) - 1) ^ mask;
 				
 				for (int submask = rmn; submask > 0; submask = (submask - 1) & rmn) {
 					int newMax = max[cnt][mask] + ans[submask];
 					int newMask = mask ^ submask;
 					
 					if (newMax > max[cnt + 1][newMask]) {
 						max[cnt + 1][newMask] = newMax;
 						count[cnt + 1][newMask] = 0;
 					}
 					if (newMax == max[cnt + 1][newMask]) {
 						count[cnt + 1][newMask] = (count[cnt + 1][newMask] + count[cnt][mask]) % MOD;
 					}
 				}
 			}
 		}
 		
 		out.println(max[n][(1 << m) - 1] + " " + count[n][(1 << m) - 1]);
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
 		new TrieSharding().run();
 	}
 }
