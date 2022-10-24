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
			int r = readInt();
			int c = readInt();
			int h = readInt();
			int v = readInt();
			boolean[][] in = new boolean[r][c];
			int have = 0;
			for(int i = 0; i < r; i++) {
				String s = nextToken();
				for(int j = 0; j < c; j++) {
					in[i][j] = s.charAt(j) == '@';
					if(in[i][j]) {
						have++;
					}
				}
			}
			if(have%((h+1)*(v+1)) != 0) {
				pw.println("IMPOSSIBLE");
				continue;
			}
			ArrayList<Integer> hh = new ArrayList<>(); // le
			ArrayList<Integer> vv = new ArrayList<>(); // le
			boolean good = true;
			{
				int horizWant = have / (h+1);
				int currHave = 0;
				for(int i = 0; i < r; i++) {
					for(int j = 0; j < c; j++) {
						if(in[i][j]) {
							currHave++;
						}
					}
					if(currHave > horizWant) {
						good = false;
					}
					if(currHave == horizWant) {
						currHave = 0;
						hh.add(i);
					}
				}
			}
			{
				int currHave = 0;
				int vertWant = (have) / (v+1);
				for(int j = 0; j < c; j++) {
					for(int i = 0; i < r; i++) {
						if(in[i][j]) {
							currHave++;
						}
					}
					if(currHave > vertWant) {
						good = false;
					}
					if(currHave == vertWant) {
						currHave = 0;
						vv.add(j);
					}
				}
			}
			int expect = have / ((h+1)*(v+1));
			for(int i = 0; i < hh.size(); i++) {
				int lowR = i == 0 ? 0 : hh.get(i-1) + 1;
				int highR = hh.get(i);
				for(int j = 0; j < vv.size()-1; j++) {
					int lowC = j == 0 ? 0 : vv.get(j-1) + 1;
					int highC = vv.get(j);
					int get = 0;
					for(int a = lowR; a <= highR; a++) {
						for(int b = lowC; b <= highC; b++) {
							if(in[a][b]) {
								get++;
							}
						}
					}
					if(get != expect) {
						good = false;
					}
				}
			}
			if(good) {
				pw.println("POSSIBLE");
			}
			else {
				pw.println("IMPOSSIBLE");
			}
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