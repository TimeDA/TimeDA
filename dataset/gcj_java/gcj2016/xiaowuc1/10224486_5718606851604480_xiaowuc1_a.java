import java.awt.*;
 import java.awt.event.*;
 import java.awt.geom.*;
 import java.io.*;
 import java.math.*;
 import java.text.*;
 import java.util.*;
 import java.util.concurrent.*;
 public class A {
 	static BufferedReader br;
 	static StringTokenizer st;
 	static PrintWriter pw;
 	static Semaphore processorSemaphore = new Semaphore(Runtime.getRuntime().availableProcessors());
 	static Semaphore inputSemaphore = new Semaphore(1);
 	static Semaphore outputSemaphore = new Semaphore(0);
 	static String[] output;
 	public static void main(String[] args) throws Exception {
 		br = new BufferedReader(new InputStreamReader(System.in));
 		pw = new PrintWriter(new BufferedWriter(new FileWriter("a.out")));
 		final int MAX_CASES = readInt();
 		output = new String[MAX_CASES];
 		for(int casenum = 1; casenum <= MAX_CASES; casenum++) {
 			processorSemaphore.acquire();
 			inputSemaphore.acquire();
 			new WorkThread(casenum).start();
 		}
 		for(int casenum = 1; casenum <= MAX_CASES; casenum++) {
 			outputSemaphore.acquire();
 		}
 		for(String out: output) {
 			pw.println(out);
 		}
 		pw.close();
 	}
 
 	static class WorkThread extends Thread {
 		public int casenum;
 
 		String ret;
 		
 		public WorkThread(int casenum) {
 			super();
 			this.casenum = casenum;
 		}
 		public void run() {
 
 			int n = readInt();
 			int r = readInt();
 			int p = readInt();
 			int s = readInt();
 			
 			
 			/*
 			 * PUT ALL INPUT CODE BEFORE THIS COMMENT
 			 */
 			inputSemaphore.release();
 			
 			
 			ret = null;
 			dfs("", p, r, s);
 			if(ret == null) {
 				ret = "IMPOSSIBLE";
 			}
 			
 			/*
 			 * PUT ALL WORK CODE BEFORE THIS COMMENT
 			 * REMEMBER TO WRITE to output[casenum-1] the exact output
 			 */
 			
 			output[casenum-1] = "Case #" + casenum + ": " + ret;
 			
 			outputSemaphore.release();
 			processorSemaphore.release();
 		}
 		
 		public void dfs(String a, int p, int r, int s) {
 			if(ret != null) return;
 			if(p+r+s == 0) {
 				validate(a);
 			}
 			if(p > 0) {
 				dfs(a + "P", p-1, r, s);
 			}
 			if(r > 0) {
 				dfs(a + "R", p, r-1, s);
 			}
 			if(s > 0) {
 				dfs(a + "S", p, r, s-1);
 			}
 		}
 
 		public void validate(String a) {
 			String orig = new String(a);
 			while(a.length() > 1) {
 				String b = "";
 				for(int i = 0; i < a.length(); i+=2) {
 					if(a.charAt(i) == a.charAt(i+1)) return;
 					if(a.charAt(i) != 'P' && a.charAt(i+1) != 'P') {
 						b += "R";
 						continue;
 					}
 					if(a.charAt(i) != 'R' && a.charAt(i+1) != 'R') {
 						b += "S";
 						continue;
 					}
 					if(a.charAt(i) != 'S' && a.charAt(i+1) != 'S') {
 						b += "P";
 						continue;
 					}
 					throw new RuntimeException();
 				}
 				a = b;
 			}
 			ret = orig;
 		}
 		
 	}
 	
 	public static int readInt() {
 		return Integer.parseInt(nextToken());
 	}
 
 	public static long readLong() {
 		return Long.parseLong(nextToken());
 	}
 
 	public static double readDouble() {
 		return Double.parseDouble(nextToken());
 	}
 
 	public static String nextToken() {
 		while(st == null || !st.hasMoreTokens())	{
 			try {
 				if(!br.ready())	{
 					pw.close();
 					System.exit(0);
 				}
 				st = new StringTokenizer(br.readLine());
 			}
 			catch(IOException e) {
 				System.err.println(e);
 				System.exit(1);
 			}
 		}
 		return st.nextToken();
 	}
 
 	public static String readLine()	{
 		st = null;
 		try {
 			return br.readLine();
 		}
 		catch(IOException e) {
 			System.err.println(e);
 			System.exit(1);
 			return null;
 		}
 	}
 
 }
