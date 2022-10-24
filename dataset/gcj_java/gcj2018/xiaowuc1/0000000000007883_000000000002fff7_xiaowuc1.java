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
			goal = readInt();
			int[] w = new int[n];
			int[] h = new int[n];
			int curr = 0;
			ArrayList<State> inc = new ArrayList<>();
			for(int i = 0; i < n; i++) {
				w[i] = readInt();
				h[i] = readInt();
				curr += 2 * w[i] + 2 * h[i];
				inc.add(new State(2 * Math.min(w[i], h[i]), 2 * Math.sqrt(w[i]*w[i]+h[i]*h[i])));
			}
			Collections.sort(inc);
			maxPref = new double[inc.size()+1];
			for(int i = 0; i < inc.size(); i++) {
				maxPref[i+1] = maxPref[i];
				maxPref[i+1] += inc.get(i).r;
			}
			pw.println(solve(inc, inc.size()-1, curr, curr));
		}
		pw.close();
	}

	static int goal;
	static double[] maxPref;

	public static double solve(ArrayList<State> l, int idx, double currL, double currR) {
		if(idx < 0) {
			return currR;
		}
		if(currL + maxPref[idx+1] <= goal && currR + maxPref[idx+1] >= goal) {
			return goal;
		}
		if(currR + maxPref[idx+1] <= goal) {
			return currR + maxPref[idx+1];
		}
		double low = currL + l.get(idx).l;
		double high = currR + l.get(idx).r;
		if(low <= goal && high >= goal) {
			return goal;
		}
		double ret = solve(l, idx-1, currL, currR);
		if(low <= goal) {
			ret = Math.max(ret, solve(l, idx-1, low, high));
		}
		return ret;
	}


	static class State implements Comparable<State> {
		public double l, r;
		public State(double a, double b) {
			l=a;
			r=b;
		}
		public String toString() {
			return l + " " + r;
		}
		public int compareTo(State s) {
			return Double.compare(l, s.l);
		}
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