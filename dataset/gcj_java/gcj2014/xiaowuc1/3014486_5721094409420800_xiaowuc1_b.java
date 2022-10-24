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
 		br = new BufferedReader(new FileReader("b.in"));
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
 		
 		int ret;
 		
 		public void run() {
 			
 			
 			int n = readInt();
 			int[] list = new int[n];
 			for(int i = 0; i < n; i++) {
 				list[i] = readInt();
 			}
 			/*
 			 * PUT ALL INPUT CODE BEFORE THIS COMMENT
 			 */
 			inputSemaphore.release();
 			
 			
 			ret = Integer.MAX_VALUE;
 			dfs(new int[n], new boolean[n], 0, list);
 			
 			/*
 			 * PUT ALL WORK CODE BEFORE THIS COMMENT
 			 * REMEMBER TO WRITE to output[casenum-1] the exact output
 			 */
 			
 			output[casenum-1] = String.format("Case #%d: %d", casenum, ret);
 			
 			outputSemaphore.release();
 			processorSemaphore.release();
 		}
 		
 		public boolean valid(int[] list) {
 			int index = 1;
 			while(index < list.length && list[index] > list[index-1]) {
 				index++;
 			}
 			for(int i = index; i + 1 < list.length; i++) {
 				if(list[i] < list[i+1]) {
 					return false;
 				}
 			}
 			return true;
 		}
 		
 		public void count(int[] a, int[] b) {
 			Map<Integer, Integer> map = new HashMap<Integer, Integer>();
 			for(int i = 0; i < b.length; i++) {
 				map.put(b[i], i);
 			}
 			int[] go = new int[a.length];
 			for(int i = 0; i < a.length; i++) {
 				go[i] = map.get(a[i]);
 			}
 			int ans = 0;
 			for(int i = 0; i < a.length; i++) {
 				for(int j = 0; j + 1 < a.length; j++) {
 					if(go[j] > go[j+1]) {
 						swap(go, j, j+1);
 						ans++;
 					}
 				}
 			}
 			ret = Math.min(ret, ans);
 		}
 		
 		public void dfs(int[] per, boolean[] used, int index, int[] list) {
 			if(index == per.length && valid(per)) {
 				count(per, list);
 			}
 			for(int i = 0; i < used.length; i++) {
 				if(!used[i]) {
 					used[i] = true;
 					per[index] = list[i];
 					dfs(per, used, index+1, list);
 					used[i] = false;
 				}
 			}
 		}
 		public void swap(int[] list, int a, int b) {
 			int c = list[a];
 			list[a] = list[b];
 			list[b] = c;
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
