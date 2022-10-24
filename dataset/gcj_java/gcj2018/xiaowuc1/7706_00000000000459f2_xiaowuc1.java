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
			int[] l = new int[n];
			int max = 0;
			for(int i = 0; i < n; i++) {
				max = Math.max(max, l[i] = readInt());
			}
			if(l[0] == 0 || l[n-1] == 0) {
				pw.println("IMPOSSIBLE");
				continue;
			}
			Map<State, Character> dp = new HashMap<State, Character>();
			int numR = 0;
			int currIdx = 0;
			for(int i = 0; i < n; i++) {
				while(l[currIdx] == 0) {
					currIdx++;
				}
				l[currIdx]--;
				int rr = 0;
				int cc = i;
				while(cc != currIdx) {
					if(cc < currIdx) {
						dp.put(new State(rr, cc++), '\\');
					}
					else {
						dp.put(new State(rr, cc--), '/');
					}
					rr++;
				}
				numR = Math.max(numR, rr);
			}
			pw.println(numR + 1);
			for(int i = 0; i <= numR; i++) {
				for(int j = 0; j < n; j++) {
					pw.print(dp.getOrDefault(new State(i, j), '.'));
				}
				pw.println();
			}
		}
		pw.close();
	}

	static class State {
		public int r, c;

		public State(int r, int c) {
			super();
			this.r = r;
			this.c = c;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + c;
			result = prime * result + r;
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
			if (c != other.c)
				return false;
			if (r != other.r)
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