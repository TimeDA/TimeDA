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
		for(int casenum = 1; casenum <= qq; casenum++) {
			int l = readInt();
			int u = readInt();
			boolean[][] g = gen(u);
			pw.println(u);
			for(int i = 0; i < g.length; i++) {
				for(int j = 0; j < i; j++) {
					if(g[i][j]) {
						pw.println((i+1) + " " + (j+1));
					}
				}
			}
			pw.flush();
			int k = readInt();
			String[] orig = gen(g);
			g = new boolean[k][k];
			for(int i = 0; i < 2*k; i++) {
				int a = readInt()-1;
				int b = readInt()-1;
				g[a][b] = true;
				g[b][a] = true;
			}
			String[] curr = gen(g);
			StringBuilder sb = new StringBuilder();
			for(int i = 0; i < orig.length; i++) {
				for(int j = 0; j < curr.length; j++) {
					if(orig[i].equals(curr[j])) {
						sb.append((j+1));
						sb.append(" ");
						break;
					}
				}
			}
			pw.println(sb.toString().trim());
			pw.flush();
		}
		pw.close();
	}

	public static String[] gen(boolean[][] gen) {
		int[][] dp = new int[gen.length][gen[0].length];
		for(int i = 0; i < dp.length; i++) {
			Arrays.fill(dp[i], 1 << 25);
			dp[i][i] = 0;
			for(int j = 0; j < gen[i].length; j++) {
				if(gen[i][j]) {
					dp[i][j] = 1;
				}
			}
		}
		for(int k = 0; k < dp.length; k++) {
			for(int i = 0; i < dp.length; i++) {
				for(int j = 0; j < dp[i].length; j++) {
					dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
		String[] ret = new String[gen.length];
		for(int i = 0; i < dp.length; i++) {
			Arrays.sort(dp[i]);
			ret[i] = Arrays.toString(dp[i]);
		}
		return ret;
	}
	
	public static boolean[][] gen(int s) {
		boolean[][] ret = new boolean[s][s];
		for(int i = 0; i < s; i++) {
			for(int j = 1; j <= 2; j++) {
				int curr = (i+j)%s;
				ret[i][curr] = true;
				ret[curr][i] = true;
			}
		}
		while(!valid(ret)) {
			boolean passed = false;
			int a = -1, b = -1;
			ArrayList<Integer> x = null, y = null;
			int xx = -1, yy = -1;
			while(!passed) {
				a = (int)(s*Math.random());
				b = (int)(s*Math.random());
				while(a == b) {
					b = (int)(s*Math.random());
				}
				x = new ArrayList<Integer>();
				y = new ArrayList<Integer>();
				for(int i = 0; i < s; i++) {
					if(ret[a][i]) {
						x.add(i);
					}
					if(ret[b][i]) {
						y.add(i);
					}
				}
				Collections.shuffle(x);
				Collections.shuffle(y);
				xx = 0;
				yy = 0;
				int iter = 0;
				while(++iter <= 10 && !valid(ret,a,b,x.get(xx),y.get(yy))) {
					xx = (int)(4 * Math.random());
					yy = (int)(4 * Math.random());
				}
				if(valid(ret,a,b,x.get(xx),y.get(yy))) passed = true;
			}
			int c = x.get(xx);
			int d = y.get(yy);
			ret[a][c] = false;
			ret[c][a] = false;
			ret[b][d] = false;
			ret[d][b] = false;
			ret[a][d] = true;
			ret[d][a] = true;
			ret[b][c] = true;
			ret[c][b] = true;
		}
		return ret;
	}

	public static boolean valid(boolean[][] ret, int a, int b, int c, int d) {
		if(a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d) {
			return !ret[a][d] && !ret[d][a] && !ret[b][c] && !ret[c][b]; 
		}
		return false;
	}

	public static boolean valid(boolean[][] gen) {
		int[][] dp = new int[gen.length][gen[0].length];
		for(int i = 0; i < dp.length; i++) {
			Arrays.fill(dp[i], 1 << 25);
			dp[i][i] = 0;
			for(int j = 0; j < gen[i].length; j++) {
				if(gen[i][j]) {
					dp[i][j] = 1;
				}
			}
		}
		for(int k = 0; k < dp.length; k++) {
			for(int i = 0; i < dp.length; i++) {
				for(int j = 0; j < dp[i].length; j++) {
					dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);
				}
			}
		}
		Set<String> all = new HashSet<String>();
		for(int i = 0; i < dp.length; i++) {
			Arrays.sort(dp[i]);
			if(!all.add(Arrays.toString(dp[i]))) {
				return false;
			}
		}
		return true;
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