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
			int maxR = readInt();
			int total = readInt();
			int n = readInt();
			long[] m = new long[n];
			long[] s = new long[n];
			long[] p = new long[n];
			for(int i = 0; i < n; i++) {
				m[i] = readInt();
				s[i] = readInt();
				p[i] = readInt();
			}
			long lhs = 0;
			long rhs = (long)4e18;
			while(lhs != rhs) {
				long mid = (lhs+rhs)/2;
				TreeMap<Long, Long> dp = new TreeMap<>();
				for(int i = 0; i < n; i++) {
					long best = s[i] * m[i] + p[i];
					long maximal = Math.min(1, mid / best);
					if(maximal > 0) {
						dp.put(m[i], dp.getOrDefault(m[i], 0L) + maximal);
					}
					else {
						long left = mid % best;
						if(left >= p[i]) {
							left = (left-p[i]) / s[i];
							if(left > 0) {
								dp.put(left, dp.getOrDefault(left, 0L) + 1);
							}
						}
					}
				}
				long amtLeft = maxR;
				long used = 0;
				while(amtLeft > 0 && !dp.isEmpty() && used < total) {
					long lastKey = dp.lastKey();
					long can = Math.min(amtLeft, dp.remove(lastKey));
					used += can * lastKey;
					amtLeft -= can;
				}
				if(used >= total) {
					rhs = mid;
				}
				else {
					lhs = mid+1;
				}
			}
			pw.println(lhs);
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