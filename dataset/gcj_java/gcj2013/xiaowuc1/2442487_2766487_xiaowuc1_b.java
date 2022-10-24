import java.awt.*;
 import java.awt.event.*;
 import java.awt.geom.*;
 import java.io.*;
 import java.math.*;
 import java.text.*;
 import java.util.*;
 public class B {
 	static BufferedReader br;
 	static StringTokenizer st;
 	static PrintWriter pw;
 
 	static int[][] worst;
 	static int[][] best;
 
 	public static void main(String[] args) throws IOException {
 		br = new BufferedReader(new FileReader("b.in"));
 		pw = new PrintWriter(new BufferedWriter(new FileWriter("b.out")));
 		long t = System.currentTimeMillis();
 		final int MAX_CASES = readInt();
 		worst = new int[11][1025];
 		best = new int[11][1025];
 		for (int i = 0; i < best.length; i++) {
 			Arrays.fill(best[i], 1 << 25);
 		}
 		while(System.currentTimeMillis()-t <= 210 * 1000)	{
 			for(int i = 1; i <= 10; i++)	{
 				for(int j = 1; j <= i; j++)	{
 					precompute(i);
 				}
 			}
 		}
 		for(int casenum = 1; casenum <= MAX_CASES; casenum++)	{
 			pw.printf("Case #%d: ", casenum);
 			int n = readInt();
 			int p = readInt();
 			int bestG = 1<<n;
 			int bestC = 1<<n;
 			while(worst[n][--bestG] >= p);
 			while(best[n][--bestC] >= p);
 			pw.println(bestG + " " + bestC);
 		}
 		pw.close();
 	}
 
 	public static void precompute(int n)	{
 		ArrayList<Integer> list = new ArrayList<Integer>();
 		for(int i = 0; i < 1 << n; i++)	{
 			list.add(i);
 		}
 		Collections.shuffle(list);
 		int[] order = new int[1 << n];
 		for(int k = n-1; k >= 0; k--)	{
 			HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
 			for(int out: list)	{
 				if(map.containsKey(order[out]))	{
 					int other = map.remove(order[out]);
 					order[Math.max(other, out)] |= 1 << k;
 				}
 				else	{
 					map.put(order[out], out);
 				}
 			}
 		}
 		for(int i = 0; i < 1<<n; i++)	{
 			worst[n][i] = Math.max(worst[n][i], order[i]);
 			best[n][i] = Math.min(best[n][i], order[i]);
 		}
 	}
 
 	public static int readInt() throws IOException	{
 		return Integer.parseInt(nextToken());
 	}
 
 	public static long readLong() throws IOException	{
 		return Long.parseLong(nextToken());
 	}
 
 	public static double readDouble() throws IOException	{
 		return Double.parseDouble(nextToken());
 	}
 
 	public static String nextToken() throws IOException {
 		while(st == null || !st.hasMoreTokens())	{
 			if(!br.ready())	{
 				pw.close();
 				System.exit(0);
 			}
 			st = new StringTokenizer(br.readLine());
 		}
 		return st.nextToken();
 	}
 
 	public static String readLine() throws IOException	{
 		st = null;
 		return br.readLine();
 	}
 
 }
