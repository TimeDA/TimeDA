import java.io.PrintWriter;
 import java.util.ArrayList;
 import java.util.Arrays;
 import java.util.HashSet;
 import java.util.List;
 import java.util.Scanner;
 import java.util.Set;
 
 
 public class ProblemD {
 	/**
 	 * @param args
 	 */
 	
 	static int MOD = 1000000007;
 	
 	public static void main(String[] args) {
 		Scanner in = new Scanner(System.in);
 		PrintWriter out = new PrintWriter(System.out);
 		
 		int T = in.nextInt();
 		for (int cn = 1 ; cn <= T ; cn++) {
 			int M = in.nextInt();
 			int N = in.nextInt();
 			String[] str = new String[M];
 			for (int i = 0 ; i < M ; i++) {
 				str[i] = in.next();
 			}
 			int[] r = solve(N, str);
 			out.println(String.format("Case #%d: %d %d", cn, r[0], r[1]));
 		}
 		out.flush();
 	}
 	
 	private static int[] solve(int n, String[] str) {
 		int m = str.length;
 		memo = new int[n+1][1<<m];
 		for (int i = 0 ; i <= n ; i++) {
 			Arrays.fill(memo[i], -1);
 		}
 		memo2 = new int[1<<m];
 		Arrays.fill(memo2, -1);
 		
 		
 		int worst = dfs(n, m, str, 0, 0);
 		int wp = 0;
 		
 		int allP = (int)Math.pow(n, m);
 		for (int p = 0 ; p < allP ; p++) {
 			int[] ptns = new int[n];
 			int P = p;
 			for (int d = 0 ; d < m ; d++) {
 				int to = P % n;
 				P /= n;
 				ptns[to] |= (1<<d);
 			}
 			int sum = 0;
 			for (int a = 0 ; a < n ; a++) {
 				sum += buildTrie(m, str, ptns[a]);
 			}
 			if (sum == worst) {
 				wp++;
 			}
 		}
 		return new int[]{ worst, wp % MOD};
 	}
 
 	
 	static int[][] memo;
 	private static int dfs(int n, int m, String[] s, int i, int set) {
 		if (i == n) {
 			if (set == ((1<<m)-1)) {
 				return 0;
 			}
 			return -1000000;
 		}
 		if (memo[i][set] != -1) {
 			return memo[i][set];
 		}
 		int max = 0;
 		for (int p = 1 ; p < (1<<m) ; p++) {
 			if ((p & set) == 0) {
 				int tset = set | p;
 				max = Math.max(max, dfs(n, m, s, i+1, tset) + buildTrie(m, s, p));
 			}
 		}
 		memo[i][set] = max;
 		return max;
 	}
 	
 	
 	static int[] memo2;
 	public static int buildTrie(int m, String[] str, int ptn) {
 		if (memo2[ptn] != -1) {
 			return memo2[ptn];
 		}
 		Set<String> nodes = new HashSet<String>();
 		for (int p = 0 ; p < m ; p++) {
 			if ((ptn & (1<<p)) >= 1) {
 				int l = str[p].length();
 				for (int i = 0 ; i <= l ; i++) {
 					nodes.add(str[p].substring(0, i));
 				}
 			}
 		}
 		memo2[ptn] = nodes.size();
 		return memo2[ptn];
 	}
 
 	public static void debug(Object... o) {
 		System.err.println(Arrays.deepToString(o));
 	}
 }
