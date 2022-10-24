import java.awt.*;
 import java.awt.event.*;
 import java.awt.geom.*;
 import java.io.*;
 import java.math.*;
 import java.text.*;
 import java.util.*;
 public class C {
 	static BufferedReader br;
 	static StringTokenizer st;
 	static PrintWriter pw;
 
 	public static void main(String[] args) throws IOException {
 		br = new BufferedReader(new FileReader("c.in"));
 		pw = new PrintWriter(new BufferedWriter(new FileWriter("c.out")));
 		final int MAX_CASES = readInt();
 		for(int casenum = 1; casenum <= MAX_CASES; casenum++)	{
 			pw.printf("Case #%d: ", casenum);
 			int n = readInt();
 			int[] a = new int[n];
 			int[] b = new int[n];
 			for (int i = 0; i < b.length; i++) {
 				a[i] = readInt();
 			}
 			for (int i = 0; i < b.length; i++) {
 				b[i] = readInt();
 			}
 			LinkedList<Integer>[] edges = new LinkedList[n];
 			for (int i = 0; i < edges.length; i++) {
 				edges[i] = new LinkedList<Integer>();
 			}
 			for(int i = 0; i < a.length; i++)	{
 				for(int j = i-1; j >= 0; j--)	{
 					if(a[i] == a[j])	{
 						edges[j].add(i);
 						break;
 					}
 				}
 			}
 			for(int i = 0; i < a.length; i++)	{
 				for(int j = i-1; j >= 0; j--)	{
 					if(b[i] == b[j])	{
 						edges[i].add(j);
 						break;
 					}
 				}
 			}
 			ArrayList<Integer> avail = new ArrayList<Integer>();
 			for(int i = 1; i <= n; i++)	{
 				avail.add(i);
 			}
 			int[] ret = new int[n];
 			for(int k = 0; k < n; k++)	{
 				boolean[] seen = new boolean[n];
 				seen[k] = true;
 				LinkedList<Integer> q = new LinkedList<Integer>();
 				q.add(k);
 				while(!q.isEmpty())	{
 					int curr = q.removeFirst();
 					for(int out: edges[curr])	{
 						if(!seen[out])	{
 							seen[out] = true;
 							q.addLast(out);
 						}
 					}
 				}
 				int index = 0;
 				for(int c = k+1; c < n; c++)	{	
 					if(seen[c])		{
 						index++;
 					}
 				}
 				ret[k] = avail.remove(index);
 			}
 			StringBuilder sb = new StringBuilder();
 			for(int out: ret)	{
 				sb.append(out + " ");
 			}
 			pw.println(sb.toString().trim());
 		}
 		pw.close();
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
