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
			ret = new StringBuilder();
			int n = readInt();
			l = new State[n];
			for(int i = 0; i < n; i++) {
				l[i] = new State(readInt(), readInt(), readInt());
			}
			ArrayList<Integer> shuffle = new ArrayList<Integer>();
			for(int i = 0; i < n; i++) {
				shuffle.add(i);
			}
			Collections.shuffle(shuffle);
			dfs(new int[n], new boolean[n], shuffle, 0);
			pw.print("Case #" + casenum + ": ");
			pw.println(ret);
		}
		pw.close();
	}

	static State[] l;
	static StringBuilder ret;

	public static void validate(int[] order) {
		for(int i = 0; i + 3 <= order.length; i++) {
			for(int j = 0; j < i; j++) {
				double a = l[order[i+1]].x - l[order[i]].x;
				double b = l[order[i+2]].x - l[order[i]].x;
				double c = l[order[j]].x - l[order[i]].x;
				double d = l[order[i+1]].y - l[order[i]].y;
				double e = l[order[i+2]].y - l[order[i]].y;
				double f = l[order[j]].y - l[order[i]].y;
				double[] amt = solve(a,b,c,d,e,f);
				double h = l[order[i]].z + amt[0] * (l[order[i+1]].z - l[order[i]].z) + amt[1] * (l[order[i+2]].z - l[order[i]].z);
				if(h <= l[order[j]].z) return;
			}
		}
		for(int out: order) {
			ret.append(out+1);
			ret.append(" ");
		}
		ret.deleteCharAt(ret.length()-1);
	}
	
	public static double[] solve(double a, double b, double c, double d, double e, double f) {
		// ax + by == c
		// dx + ey == f
		/*
		c b
		f e
		 */
		/*
		a c
		d f
		 */
		double det = a*e - b*d;
		double x1 = c*e-b*f;
		double x2 = a*f-c*d;
		return new double[] {x1/det,x2/det};
	}
	
	public static void dfs(int[] order, boolean[] used, ArrayList<Integer> cheap, int idx) {  
		if(idx == order.length) {
			validate(order);
		}
		for(int i = 0; i < used.length && ret.length() == 0; i++) {
			if(!used[i]) {
				order[idx] = cheap.get(i);
				used[i] = true;
				dfs(order, used, cheap, idx+1);
				used[i] = false;
			}
		}
	}
	
	static class State {
		public long x, y, z;

		public State(long x, long y, long z) {
			super();
			this.x = x;
			this.y = y;
			this.z = z;
		}

		@Override
		public int hashCode() {
			final int prime = 3137;
			int result = 1;
			result = prime * result + (int) (x ^ (x >>> 32));
			result = prime * result + (int) (y ^ (y >>> 32));
			result = prime * result + (int) (z ^ (z >>> 32));
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			State other = (State) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			if (z != other.z)
				return false;
			return true;
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