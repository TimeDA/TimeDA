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
			int s = 0;
			for(int i = 0; i < n; i++) {
				s += l[i] = readInt();
			}
			StringBuilder sb = new StringBuilder();
			if(s%2 == 1) {
				s--;
				int best = 0;
				for(int i = 1; i < n; i++) {
					if(l[i] > l[best]) {
						best = i;
					}
				}
				sb.append((char)(best+'A') + " ");
				l[best]--;
			}
			while(s > 0) {
				int best = 0;
				for(int i = 1; i < n; i++) {
					if(l[i] > l[best]) {
						best = i;
					}
				}
				int best2 = best==0 ? 1 : 0;
				for(int i = 0; i < n; i++) {
					if(i == best || i == best2) continue;
					if(l[i] > l[best2]) {
						best2 = i;
					}
				}
				sb.append((char)(best+'A'));
				sb.append((char)(best2+'A'));
				sb.append(" ");
				l[best]--;
				l[best2]--;
				s -= 2;
			}
			pw.println(sb.toString().trim());
		}
		pw.close();
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