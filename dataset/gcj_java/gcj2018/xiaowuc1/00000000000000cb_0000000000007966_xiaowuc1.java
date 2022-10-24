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
			max = readLong();
			String s = nextToken();
			ans = Integer.MAX_VALUE;
			seen = new HashSet<>();
			bfs(s);
			if(ans == Integer.MAX_VALUE) {
				pw.println("IMPOSSIBLE");
			}
			else {
				pw.println(ans);
			}
		}
		pw.close();
	}

	static long max;
	static Set<String> seen;
	static int ans;

	public static void bfs(String curr) {
		LinkedList<State> q = new LinkedList<State>();
		q.add(new State(curr, 0));
		while(!q.isEmpty()) {
			State now = q.removeFirst();
			if(eval(now.s) <= max) {
				ans = now.x;
				return;
			}
			for(int i = 0; i < now.s.length()-1; i++) {
				if(now.s.charAt(i) == 'S' || now.s.charAt(i+1) == 'C') continue;
				String next = now.s.substring(0, i) + now.s.charAt(i+1) + "" + now.s.charAt(i) + now.s.substring(i+2);
				if(seen.add(next)) {
					q.add(new State(next, now.x+1));
				}
			}
		}
	}

	static class State {
		public String s;
		public int x;
		public State(String a, int b) {
			s=a;
			x=b;
		}
	}

	public static long eval(String s) {
		long ret = 0;
		long curr = 1;
		for(int i = 0; i < s.length(); i++) {
			if(s.charAt(i) == 'C') curr *= 2;
			else ret += curr;
		}
		return ret;
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