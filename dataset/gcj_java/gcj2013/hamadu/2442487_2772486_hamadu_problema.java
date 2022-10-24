import java.io.PrintWriter;
 import java.util.Arrays;
 import java.util.HashMap;
 import java.util.HashSet;
 import java.util.Map;
 import java.util.Scanner;
 import java.util.Set;
 
 
 public class ProblemA {
 	static long MOD = 1000002013L;
 	
 	static long N;
 	/**
 	 * @param args
 	 */
 	public static void main(String[] args) {
 		Scanner in = new Scanner(System.in);
 		PrintWriter out = new PrintWriter(System.out);
 		
 		int T = in.nextInt();
 		for (int cn = 1 ; cn <= T ; cn++) {
 			N = in.nextLong();
 			int M = in.nextInt();
 			long[][] span = new long[M][3];
 			for (int i = 0 ; i < M ; i++) {
 				span[i][0] = in.nextLong();
 				span[i][1] = in.nextLong();
 				span[i][2] = in.nextLong();
 			}
 			out.println("Case #" + cn + ": " + solve(M, span));
 		}
 		out.flush();
 	}
 
 	private static long calc(long dist) {
 		long a = (dist * N) % MOD;
 		long b = (dist * (dist - 1) / 2) % MOD;
 		if (a < b) {
 			return a - b + MOD;
 		}
 		return a - b;
 	}
 	
 	private static long solve(int M, long[][] span) {
 		long base = 0;
 		for (int i = 0 ; i < M ; i++) {
 			long dist = span[i][1] - span[i][0];
 			long pas = (calc(dist) * span[i][2]) % MOD;
 			base += pas;
 			base %= MOD;
 		}
 		
 		Set<Long> pos = new HashSet<Long>();
 		for (long[] sp : span) {
 			pos.add(sp[0]-1);
 			pos.add(sp[0]);
 			pos.add(sp[1]);
 			pos.add(sp[1]+1);
 		}
 		pmap = new long[pos.size()];
 		Map<Long,Integer> pc = new HashMap<Long,Integer>();
 		int pidx = 0;
 		for (long p : pos) {
 			pmap[pidx++] = p;
 		}
 		Arrays.sort(pmap);
 		for (int i = 0 ; i < pidx ; i++) {
 			pc.put(pmap[i], i);
 		}
 		
 		long[] imos = new long[pidx+1];
 		for (int i = 0 ; i < M ; i++) {
 			int f = pc.get(span[i][0]);
 			int t = pc.get(span[i][1]);
 			imos[f] += span[i][2];
 			imos[t] -= span[i][2];
 		}
 		for (int i = 0 ; i < pidx ; i++) {
 			imos[i+1] += imos[i];
 		}
 		
 		long modi = dfs(0, pidx, imos);
 		
 		
 		return (base >= modi) ? base - modi : (base - modi + MOD);
 	}
 	static long[] pmap;
 	
 	public static long dfs(int f, int t, long[] im) {
 		while (im[f] == 0 && f < t) {
 			f++;
 		}
 		while (im[t-1] == 0 && f < t) {
 			t--;
 		}
 		if (f == t) {
 			return 0;
 		}
 		
 		long ret = 0;
 		int now = f;
 		while (now < t) {
 			long ma = im[now];
 			for (int i = now+1 ; i <= t ; i++) {
 				if (im[i] == 0) {
 					for (int j = now ; j < i ; j++) {
 						im[j] -= ma;
 					}
 					long dist = (calc(pmap[i] - pmap[now]) * ma) % MOD;
 					ret += dist;
 					ret %= MOD;
 					now = i;
 					break;
 				}
 				ma = Math.min(im[i], ma);
 			}
 			while (now < t && im[now] == 0) {
 				now++;
 			}
 		}
 		ret += dfs(f, t, im);
 		ret %= MOD;
 		return ret;
 	}
 
 
 	public static void debug(Object... o) {
 		System.err.println(Arrays.deepToString(o));
 	}
 }
