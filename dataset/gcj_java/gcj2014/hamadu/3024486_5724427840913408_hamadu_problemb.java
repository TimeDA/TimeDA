import java.io.PrintWriter;
 import java.util.ArrayList;
 import java.util.Arrays;
 import java.util.Collections;
 import java.util.List;
 import java.util.Scanner;
 
 
 public class ProblemB {
 	/**
 	 * @param args
 	 */
 	public static void main(String[] args) {
 		Scanner in = new Scanner(System.in);
 		PrintWriter out = new PrintWriter(System.out);
 
 		int T = in.nextInt();
 		for (int cn = 1 ; cn <= T ; cn++) {
 			int p = in.nextInt();
 			int q = in.nextInt();
 			int N = in.nextInt();
 			int[] h = new int[N];
 			int[] g = new int[N];
 			for (int i = 0 ; i < N ; i++) {
 				h[i] = in.nextInt();
 				g[i] = in.nextInt();
 			}
 			out.println(String.format("Case #%d: %d", cn, solve(p, q, h, g)));
 		}
 		out.flush();
 	}
 	
 
 	private static int solve(int p, int q, int[] h, int[] g) {
 		int n = h.length;
 		int[] need = new int[n];
 		for (int i = 0 ; i < n ; i++) {
 			int mod = (h[i] % q);
 			if (mod == 0) {
 				mod = q;
 			}
 			need[i] = (mod + p - 1) / p;
 			
 			int thp = h[i];
 			for (int j = 0 ; j < need[i] - 1 ; j++) {
 				thp -= p;
 				thp -= q;
 			}
 			if (thp <= 0) {
 				need[i] = 10000;
 			}
 		}
 		
 		int[][][] dp = new int[2][n+1][2000];
 		for (int i = 0 ; i <= 1 ; i++) {
 			for (int j = 0 ; j <= n ; j++) {
 				Arrays.fill(dp[i][j], -1);
 			}
 		}
 		dp[0][0][0] = 0;
 		
 		for (int i = 0 ; i < n ; i++) {
 			for (int f = 0 ; f <= 1 ; f++) {
 				for (int t = 0 ; t < 2000 ; t++) {
 					if (dp[f][i][t] == -1) {
 						continue;
 					}
 					
 					int base = dp[f][i][t];
 					// take down first
 					for (int ut = 0 ; ut <= Math.min(t, 10) ; ut++) {
 						int hp = h[i] - ut * p;
 						int tt = t - ut;
 						if (hp <= 0) {
 							dp[f][i+1][tt] = Math.max(dp[f][i+1][tt], base + g[i]);
 							break;
 						}
 						if (f == 1) {
 							hp -= q;
 						}
 						if (hp <= 0) {
 							dp[0][i+1][t] = Math.max(dp[0][i+1][t], base);
 							continue;
 						}
 
 						// take
 						{
 							int shp = hp;
 							for (int c = 0 ; c < need[i]-1 ; c++) {
 								shp -= p;
 								if (shp <= 0) {
 									int use = 0;
 									int earn = 0;
 									int ttt = tt - use + earn;
 									if (ttt >= 0) {
 										dp[1][i+1][ttt] = Math.max(dp[1][i+1][ttt], base + g[i]);
 									}
 									break;
 								}
 								shp -= q;
 							}
 							if (shp > 0) {
 								int use = need[i]-1;
 								int earn = (shp + q - 1) / q;
 								int ttt = tt - use + earn;
 								if (ttt >= 0) {
 									dp[1][i+1][ttt] = Math.max(dp[1][i+1][ttt], base + g[i]);
 								}
 							}
 						}
 						
 						// not take
 						{
 							int time = (hp + q - 1) / q;
 							if (tt+time >= 0 && tt+time < 2000) {
 								dp[0][i+1][tt+time] = Math.max(dp[0][i+1][tt+time], base);
 							}
 						}						
 					}
 				}
 			}
 		}
 		
 		
 		int max = 0;
 		for (int f = 0 ; f <= 1 ; f++) {
 			for (int t = 0 ; t < 2000 ; t++) {
 				max = Math.max(max, dp[f][n][t]);
 			}
 		}
 		return max;
 	}
 	
 
 
 	public static void debug(Object... o) {
 		System.err.println(Arrays.deepToString(o));
 	}
 }
