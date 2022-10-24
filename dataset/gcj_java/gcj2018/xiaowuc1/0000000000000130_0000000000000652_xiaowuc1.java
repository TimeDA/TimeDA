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
			TreeMap<Long, Long> dp = new TreeMap<Long, Long>();
			long n = readLong();
			dp.put(n, 1L);
			long k = readLong()-1;
			while(k > 0) {
				k -= update(dp, k);
			}
			long key = dp.lastKey();
			long a = key / 2;
			long b = key-1-a;
			pw.println(a + " " + b);
		}
		pw.close();
	}

	public static long update(TreeMap<Long, Long> dp, long amt) {
		long lastKey = dp.lastKey();
		long upd = Math.min(dp.get(lastKey), amt);
		long a = (lastKey-1)/2;
		long b = (lastKey-1)-a;
		change(dp, a, upd);
		change(dp, b, upd);
		change(dp, lastKey, -upd);
		return upd;
	}
	
	public static void change(Map<Long, Long> m, long k, long v) {
		if(!m.containsKey(k)) m.put(k, 0L);
		long nv = v + m.get(k);
		if(nv == 0) m.remove(k);
		else m.put(k, nv);
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