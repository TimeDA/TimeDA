
 import java.awt.*;
 import java.awt.event.*;
 import java.awt.geom.*;
 import java.io.*;
 import java.math.*;
 import java.text.*;
 import java.util.*;
  
 public class B {
 	static StringTokenizer st;
 	static BufferedReader br;
 	static PrintWriter pw;
 
 	final static int THRESHOLD = 100;
 	
 	static int w,l;
 	
 	public static void main(String[] args) throws IOException {
 		br = new BufferedReader(new InputStreamReader(System.in));
 		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
 				System.out)));
 		final int NUM_CASES = readInt();
 		for(int casenum = 1; casenum <= NUM_CASES; casenum++)	{
 			int n = readInt();
 			w = readInt();
 			l = readInt();
 			int[] list = new int[n];
 			for(int i = 0; i < n; i++)
 				list[i] = readInt();
 			pw.print("Case #" + casenum + ":");
 			while(!place(list, new double[n], new double[n], 0));
 		}
 		pw.close();
 	}
 
 	public static boolean place(int[] r, double[] x, double[] y, int index)	{
 		if(index == r.length)	{
 			/*
 			for(int i = 0; i < x.length; i++)	{
 				for(int j = i+1; j < x.length; j++)	{
 					double dist = dist(x[i], y[i], x[j], y[j]);
 					if(dist <= r[i] + r[j])
 						return false;
 				}
 			}*/
 			for(int i = 0; i < x.length; i++)	{
 				pw.print(" " + x[i] + " " + y[i]);
 			}
 			pw.println();
 			pw.flush();
 			return true;
 		}
 		outer: for(int qq = 0; qq < THRESHOLD; qq++)	{
 			x[index] = Math.random() * w;
 			y[index] = Math.random() * l;
 			for(int i = 0; i <= index; i++)	{
 				for(int j = i+1; j <= index; j++)	{
 					double dist = dist(x[i], y[i], x[j], y[j]);
 					if(dist <= r[i] + r[j])
 						continue outer;
 				}
 			}
 			if(place(r,x,y,index+1))
 				return true;
 		}
 		return false;
 	}
 	
 	public static double dist(double a, double b, double c, double d)	{
 		double x = a-c;
 		double y = b-d;
 		return Math.sqrt(x*x+y*y);
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
