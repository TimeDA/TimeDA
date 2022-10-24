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
			pw.print("Case #" + casenum + ": ");
			int n = readInt();
			int[][] g = new int[n][n];
			ArrayList<State>[] locs = new ArrayList[2*n+1];
			for(int i = 0; i < locs.length; i++) {
				locs[i] = new ArrayList<State>();
			}
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					g[i][j] = readInt()+n;
					locs[g[i][j]].add(new State(i, j));
				}
			}
			int ret = 0;
			int[] rr = new int[n];
			int[] cc = new int[n];
			for(int k = 0; k < locs.length; k++) {
				if(locs[k].isEmpty()) continue;
				Arrays.fill(rr, -1);
				Arrays.fill(cc, -1);
				int numR = 0;
				int numC = 0;
				for(State out: locs[k]) {
					if(rr[out.x] < 0) {
						rr[out.x] = numR++;
					}
					if(cc[out.y] < 0) {
						cc[out.y] = numC++;
					}
				}
				boolean[][] gg = new boolean[numR][numC];
				for(State out: locs[k]) {
					gg[rr[out.x]][cc[out.y]] = true;
				}
				ret += locs[k].size() - match(gg, new int[numR], new int[numC]);
			}
			pw.println(ret);
		}
		pw.close();
	}

	static class State {
		public int x, y;

		public State(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
		
	}
	
	public static boolean match(int i, boolean[][] w, int[] mr, int[] mc, boolean[] seen) {
		for (int j = 0; j < w[i].length; j++) {
			if (w[i][j] && !seen[j]) {
				seen[j] = true;
				if (mc[j] < 0) {
					mr[i] = j;
					mc[j] = i;
					return true;
				}
				seen[j] = false;
			}
		}
		for (int j = 0; j < w[i].length; j++) {
			if (w[i][j] && !seen[j]) {
				seen[j] = true;
				if (match(mc[j], w, mr, mc, seen)) {
					mr[i] = j;
					mc[j] = i;
					return true;
				}
			}
		}
		return false;
	}
	public static int match(boolean[][] w, int[] mr, int[] mc) {
		Arrays.fill(mr, -1);
		Arrays.fill(mc, -1);
		int ct = 0;
		for (int i = 0; i < w.length; i++) {
			boolean[] seen = new boolean[w[0].length];
			if(match(i, w, mr, mc, seen))
				ct++;
		}
		return ct;
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