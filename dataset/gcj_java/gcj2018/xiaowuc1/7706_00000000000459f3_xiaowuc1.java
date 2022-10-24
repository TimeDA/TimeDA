import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Solution {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		//int qq = Integer.MAX_VALUE;
		int qq = readInt();
		int[] rr = new int[qq];
		int[] bb = new int[qq];
		for(int a = 0; a < rr.length; a++) {
			rr[a] = readInt();
			bb[a] = readInt();
		}
		int[] ret = new int[qq];
		int r = 500;
		int b = 500;
		int[][] dp = new int[r+1][b+1];
		for(int i = 0; i < dp.length; i++) {
			Arrays.fill(dp[i], -1);
		}
		dp[0][0] = 0;
		int[][] cheat = new int[r+1][b+1];
		for(int rMin = 0; rMin <= r; rMin++) {
			int[][] next = new int[r+1][b+1];
			for(int i = 0; i < next.length; i++) {
				Arrays.fill(next[i], -1);
			}
			for(int i = 0; i <= r; i++) {
				for(int j = 0; j <= b; j++) {
					if(dp[i][j] < 0) continue;
					for(int k = 0; i + (rMin*k) <= r && j + need(k, rMin != 0) <= b; k++) {
						next[i+rMin*k][j+need(k, rMin!=0)] = Math.max(next[i+rMin*k][j+need(k, rMin!=0)], dp[i][j] + k);
					}
				}
			}
			for(int i = 0; i <= r; i++) {
				for(int j = 0; j <= b; j++) {
					cheat[i][j] = dp[i][j];
					if(i > 0) {
						cheat[i][j] = Math.max(cheat[i][j], cheat[i-1][j]);
					}
					if(j > 0) {
						cheat[i][j] = Math.max(cheat[i][j], cheat[i][j-1]);
					}
				}
			}
			for(int a = 0; a < qq; a++) {
				ret[a] = Math.max(ret[a], cheat[rr[a]][bb[a]]);
			}
			dp = next;
		}
		for(int casenum = 1; casenum <= qq; casenum++) {
			pw.print("Case #" + casenum + ": ");
			pw.println(ret[casenum-1]);
		}
		pw.close();
	}

	public static int need(int n, boolean canZero) {
		if(!canZero) {
			return n*(n+1)/2;
		}
		return n*(n-1)/2;
	}
	
	private static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private static String nextLine() throws IOException  {
		String s = br.readLine();
		if(s == null) {
			exitImmediately();
		}
		st = null;
		return s;
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			st = new StringTokenizer(nextLine().trim());
		}
		return st.nextToken();
	}

}