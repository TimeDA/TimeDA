
 import java.awt.*;
 import java.awt.event.*;
 import java.awt.geom.*;
 import java.io.*;
 import java.math.*;
 import java.text.*;
 import java.util.*;
 
 public class C {
 	static StringTokenizer st;
 	static BufferedReader br;
 	static PrintWriter pw;
 	static int n;
 	static int[] ret;
 	public static void main(String[] args) throws IOException {
 		br = new BufferedReader(new InputStreamReader(System.in));
 		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
 				System.out)));
 		final int NUM_CASES = readInt();
 		for(int casenum = 1; casenum <= NUM_CASES; casenum++)	{
 			n = readInt();
 			int[] high = new int[n-1];
 			for(int i = 0; i < n-1; i++)
 				high[i] = readInt()-1;
 			int[] heights = new int[n];
 			Arrays.fill(heights, -1);
 			double[] max = new double[n];
 			Arrays.fill(max, n);
 			boolean win = dfs(0, heights, high, max);
 			if(win)	{
 				pw.print("Case #" + casenum + ":");
 				for(int out: ret)
 					pw.print(" " + out);
 				pw.println();
 			}
 			else	{
 				pw.println("Case #" + casenum + ": Impossible");
 			}
 		}
 		pw.close();
 	}
 
 	public static String get(double[] list)	{
 		StringBuilder sb = new StringBuilder();
 		for(double out: list)
 			sb.append(out + " ");
 		return sb.toString();
 	}
 
 	public static String get(int[] list)	{
 		StringBuilder sb = new StringBuilder();
 		for(int out: list)
 			sb.append(out + " ");
 		return sb.toString();
 	}
 
 	public static boolean valid(int[] heights, double[] max)	{
 		for(int i = 0; i < heights.length; i++)
 			if(heights[i] > max[i])
 				return false;
 		return true;
 	}
 	
 	public static void updateMax(int[] heights, double[] max, int a, int b)	{
 		double slope = heights[b] - heights[a];
 		slope /= (b-a);
 		for(int i = a+1; i < n; i++){
 			if(i == b)
 				continue;
 			double now = slope * (i-a) + heights[a];
 			if(i < b)
 				now -= 1e-5;
 			max[i] = Math.min(max[i], now);
 		}
 	}
 
 	public static boolean dfs(int index, int[] heights, int[] high, double[] max)	{
 		if(!valid(heights, max))
 			return false;
 		if(index == heights.length) {
 			ret = heights;
 			return true;
 		}
 		if(index == high.length)	{
 			if(max[index] >= 0)	{
 				if(heights[index] == -1)
 					heights[index] = 0;
 				return dfs(index+1, heights, high, max);
 			}
 			else	{
 				return false;
 			}
 		}
 		int otherIndex = high[index];
 		if(heights[index] == -1 && heights[otherIndex] == -1)	{
 			for(int i = 0; i <= max[index]; i++)	{
 				for(int j = 0; j <= max[otherIndex]; j++)	{
 					int[] newHeight = new int[n];
 					double[] newMax = new double[n];
 					for(int a = 0; a < n; a++)	{
 						newHeight[a] = heights[a];
 						newMax[a] = max[a];
 					}
 					newHeight[index] = i;
 					newHeight[otherIndex] = j;
 					updateMax(newHeight, newMax, index, otherIndex);
 					if(dfs(index+1, newHeight, high, newMax))
 						return true;
 				}
 			}
 		}
 		if(heights[index] == -1 && heights[otherIndex] != -1)	{
 			for(int i = 0; i <= max[index]; i++)	{
 				int[] newHeight = new int[n];
 				double[] newMax = new double[n];
 				for(int a = 0; a < n; a++)	{
 					newHeight[a] = heights[a];
 					newMax[a] = max[a];
 				}
 				newHeight[index] = i;
 				updateMax(newHeight, newMax, index, otherIndex);
 				if(dfs(index+1, newHeight, high, newMax))
 					return true;
 			}
 		}
 		if(heights[index] != -1 && heights[otherIndex] == -1)	{
 			for(int j = 0; j <= max[otherIndex]; j++)	{
 				int[] newHeight = new int[n];
 				double[] newMax = new double[n];
 				for(int a = 0; a < n; a++)	{
 					newHeight[a] = heights[a];
 					newMax[a] = max[a];
 				}
 				newHeight[otherIndex] = j;
 				updateMax(newHeight, newMax, index, otherIndex);
 				if(dfs(index+1, newHeight, high, newMax))
 					return true;
 			}
 		}
 		if(heights[index] != -1 && heights[otherIndex] != -1)	{
 			int[] newHeight = new int[n];
 			double[] newMax = new double[n];
 			for(int a = 0; a < n; a++)	{
 				newHeight[a] = heights[a];
 				newMax[a] = max[a];
 			}
 			if(dfs(index+1, newHeight, high, newMax))
 				return true;
 		}
 		return false;
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
