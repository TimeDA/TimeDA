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
			int a = readInt();
			int r = 4;
			int c = a/4;
			Set<State> need = new HashSet<State>();
			LinkedList<State> q = new LinkedList<State>();
			for(int aa = 1; aa <= r; aa++) {
				for(int bb = 1; bb <= c; bb++) {
					need.add(new State(aa, bb));
				}
			}
			for(int i = 2; i + 1 <= r; i++) {
				for(int j = 2; j + 1 <= c; j++) {
					q.add(new State(i, j));
				}
			}
			while(true) {
				State best = null;
				int amt = -1;
				LinkedList<State> next = new LinkedList<State>();
				while(!q.isEmpty()) {
					State curr = q.removeFirst();
					int cnt = 0;
					for(int dx = -1; dx <= 1; dx++) {
						for(int dy = -1; dy <= 1; dy++) {
							if(need.contains(new State(curr.x + dx, curr.y + dy))) {
								cnt++;
							}
						}
					}
					if(cnt > 0) {
						next.add(curr);
					}
					if(cnt > amt) {
						amt = cnt;
						best = curr;
					}
				}
				q = next;
				System.out.println(best.x + " " + best.y);
				System.out.flush();
				int x = readInt();
				int y = readInt();
				if(x == 0 && y == 0) break;
				need.remove(new State(x, y));
			}
		}
		pw.close();
	}

	static class State {
		public int x, y;
		public State(int a, int b) {
			x=a;
			y=b;
		}
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
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