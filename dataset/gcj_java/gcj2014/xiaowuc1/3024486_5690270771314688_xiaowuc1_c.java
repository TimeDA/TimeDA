import java.awt.*;
 import java.awt.event.*;
 import java.awt.geom.*;
 import java.io.*;
 import java.math.*;
 import java.text.*;
 import java.util.*;
 import java.util.concurrent.*;
 public class C {
 	static BufferedReader br;
 	static StringTokenizer st;
 	static PrintWriter pw;
 	public static void main(String[] args) throws Exception {
 		br = new BufferedReader(new FileReader("c.in"));
 		pw = new PrintWriter(new BufferedWriter(new FileWriter("c.out")));
 		final int MAX_CASES = readInt();
 		for(int casenum = 1; casenum <= MAX_CASES; casenum++) {
 			pw.printf("Case #%d: ", casenum);
 			int[] enter = new int[2001];
 			int[] leave = new int[2001];
 			Arrays.fill(enter, -1);
 			Arrays.fill(leave, -1);
 			TreeSet<Integer> enters = new TreeSet<Integer>();
 			TreeSet<Integer> leaves = new TreeSet<Integer>();
 			int n = readInt();
 			boolean[] in = new boolean[n];
 			int[] id = new int[n];
 			int[] delta = new int[n+1];
 			int absoluteMin = 0;
 			for(int i = 0; i < n; i++) {
 				in[i] = nextToken().equals("E");
 				id[i] = readInt();
 				delta[i+1] = delta[i];
 				if(in[i]) {
 					delta[i+1]++;
 				}
 				else {
 					delta[i+1]--;
 					absoluteMin = Math.min(absoluteMin, delta[i+1]);
 				}
 			}
 			boolean bad = false;
 			for(int i = 0; !bad && i < n; i++) {
 				if(id[i] == 0) {
 					if(in[i]) {
 						enters.add(i);
 					}
 					else {
 						leaves.add(i);
 					}
 				}
 				else {
 					int currId = id[i];
 					if(in[i]) {
 						if(enter[currId] == -1) {
 							enter[currId] = i;
 							leave[currId] = -1;
 						}
 						else {
 							if(leaves.isEmpty() || leaves.last() <= enter[currId]) {
 								bad = true;
 							}
 							else {
 								leaves.remove(leaves.higher(enter[currId]));
 								enter[currId] = i;
 								leave[currId] = -1;
 							}
 						}
 					}
 					else {
 						if(leave[currId] == -1) {
 							leave[currId] = i;
 							enter[currId] = -1;
 						}
 						else {
 							if(enters.isEmpty() || enters.last() <= leave[currId]) {
 								bad = true;
 							}
 							else {
 								enters.remove(enters.higher(leave[currId]));
 								leave[currId] = i;
 								enter[currId] = -1;
 							}
 						}
 					}
 				}
 			}
 			if(bad) {
 				pw.println("CRIME TIME");
 			}
 			else {
 				pw.println(delta[n] - absoluteMin);
 			}
 		}
 		pw.close();
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
