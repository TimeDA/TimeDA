
 import java.awt.*;
 import java.awt.event.*;
 import java.awt.geom.*;
 import java.io.*;
 import java.math.*;
 import java.text.*;
 import java.util.*;
 
 public class A {
 	static StringTokenizer st;
 	static BufferedReader br;
 	static PrintWriter pw;
 
 	public static void main(String[] args) throws IOException {
 		br = new BufferedReader(new InputStreamReader(System.in));
 		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
 				System.out)));
 		final int NUM_CASES = readInt();
 		for(int casenum = 1; casenum <= NUM_CASES; casenum++)	{
 			int n = readInt();
 			int[] dist = new int[n];
 			int[] len = new int[n];
 			Set<Integer>[] can = new HashSet[n];
 			for(int i = 0; i < n; i++)	{
 				dist[i] = readInt();
 				len[i] = readInt();
 				can[i] = new HashSet<Integer>();
 			}
 			int win = readInt();
 			can[0].add(0);
 			boolean ret = false;
 			outer: for(int i = 0; i < n; i++)	{
 				for(int out: can[i])	{
 					if(2 * dist[i] - out >= win)		{
 						ret = true;
 						break outer;
 					}
 					for(int j = i+1; j < n; j++)	{
 						long allow = dist[i] - out;
 						allow *= allow;
 						long actualX = dist[j] - dist[i];
 						actualX *= actualX;
 						long actualY = allow - actualX;
 						if(actualY >= 0)	{
 							int canX = Math.max(dist[j] - len[j], dist[i]);
 							can[j].add(canX);
 						}
 					}
 				}
 			}
 			pw.println("Case #" + casenum + ": " + (ret ? "YES" : "NO"));
 		}
 		pw.close();
 	}
 
 	public static long readLong() throws IOException {
 		return Long.parseLong(nextToken());
 	}
 
 	public static double readDouble() throws IOException {
 		return Double.parseDouble(nextToken());
 	}
 
 	public static int readInt() throws IOException {
 		return Integer.parseInt(nextToken());
 	}
 
 	public static String nextToken() throws IOException {
 		while (st == null || !st.hasMoreTokens()) {
 			if (!br.ready()) {
 				pw.close();
 				System.exit(0);
 			}
 			st = new StringTokenizer(br.readLine());
 		}
 		return st.nextToken();
 	}
 }
