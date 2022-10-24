import java.awt.*;
 import java.awt.event.*;
 import java.awt.geom.*;
 import java.io.*;
 import java.math.*;
 import java.text.*;
 import java.util.*;
 import java.util.concurrent.*;
 public class B {
 	static BufferedReader br;
 	static StringTokenizer st;
 	static PrintWriter pw;
 	static Semaphore processorSemaphore = new Semaphore(Runtime.getRuntime().availableProcessors());
 	static Semaphore inputSemaphore = new Semaphore(1);
 	static Semaphore outputSemaphore = new Semaphore(0);
 	static String[] output;
 	public static void main(String[] args) throws Exception {
 		br = new BufferedReader(new InputStreamReader(System.in));
 		pw = new PrintWriter(new BufferedWriter(new FileWriter("b.out")));
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
 
 		public WorkThread(int casenum) {
 			super();
 			this.casenum = casenum;
 		}
 		public void run() {
 			
 			
 			
 			int n = readInt();
 			int k = readInt();
 			
 			double[] p = new double[n];
 			for(int i = 0; i < n; i++) {
 				p[i] = readDouble();
 			}
 			
 			/*
 			 * PUT ALL INPUT CODE BEFORE THIS COMMENT
 			 */
 			inputSemaphore.release();
 			
 			double ret = 0;
 			for(int mask = 0; mask < 1<<n; mask++) {
 				if(Integer.bitCount(mask) != k) continue;
 				double[] dp = new double[k+1];
 				dp[0] = 1;
 				for(int i = 0; i < n; i++) {
 					if((mask&(1<<i)) == 0) {
 						continue;
 					}
 					double[] next = new double[k+1];
 					for(int a = 0; a <= k; a++) {
 						if(a+1 < next.length) {
 							next[a+1] += dp[a] * p[i];
 						}
 						next[a] += dp[a] * (1 - p[i]);
 					}
 					dp = next;
 				}
 				ret = Math.max(ret, dp[k/2]);
 			}
 			
 			/*
 			 * PUT ALL WORK CODE BEFORE THIS COMMENT
 			 * REMEMBER TO WRITE to output[casenum-1] the exact output
 			 */
 			
 			output[casenum-1] = "Case #" + casenum + ": " + ret;
 			
 			outputSemaphore.release();
 			processorSemaphore.release();
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
