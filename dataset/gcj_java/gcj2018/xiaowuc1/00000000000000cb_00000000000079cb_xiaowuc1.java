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
			ArrayList<Integer> even = new ArrayList<Integer>();
			ArrayList<Integer> odd = new ArrayList<Integer>();
			for(int i = 0; i < n; i++) {
				if(i%2==0) {
					even.add(readInt());
				}
				else {
					odd.add(readInt());
				}
			}
			Collections.sort(even);
			Collections.sort(odd);
			String ret = "OK";
			for(int i = 0; i < n-1; i++) {
				int rhs = get(even, odd, i);
				int lhs = get(even, odd, i+1);
				if(rhs > lhs) {
					ret = Integer.toString(i);
					break;
				}
			}
			pw.println(ret);
		}
		pw.close();
	}

	public static int get(ArrayList<Integer> e, ArrayList<Integer> o, int i) {
		if(i%2 == 0) return e.get(i/2);
		else return o.get(i/2);
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