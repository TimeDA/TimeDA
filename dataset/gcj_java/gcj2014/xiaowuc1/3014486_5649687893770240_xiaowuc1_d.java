import java.awt.*;
 import java.awt.event.*;
 import java.awt.geom.*;
 import java.io.*;
 import java.math.*;
 import java.text.*;
 import java.util.*;
 import java.util.concurrent.*;
 public class D {
 	static BufferedReader br;
 	static StringTokenizer st;
 	static PrintWriter pw;
 	
 	static String[] list;
 	static int best = 0;
 	static int count = 0;
 	
 	public static void main(String[] args) throws Exception {
 		br = new BufferedReader(new FileReader("d.in"));
 		pw = new PrintWriter(new BufferedWriter(new FileWriter("d.out")));
 		final int MAX_CASES = readInt();
 		for(int casenum = 1; casenum <= MAX_CASES; casenum++) {
 			pw.printf("Case #%d: ", casenum);
 			int n = readInt();
 			int m = readInt();
 			best = 0;
 			count = 0;
 			list = new String[n];
 			for(int i = 0; i < n; i++) {
 				list[i] = nextToken();
 			}
 			dfs(0, new int[n], m);
 			pw.println(best + " " + count);
 		}
 		pw.close();
 	}
 
 	public static void dfs(int index, int[] assign, int max) {
 		if(index == assign.length) {
 			count(assign, max);
 			return;
 		}
 		int ret = Integer.MAX_VALUE;
 		for(int i = 0; i < max; i++) {
 			assign[index] = i;
 			dfs(index+1, assign, max);
 		}
 	}
 	
 	public static void count(int[] assign, int max) {
 		counter = 0;
 		Node[] listN = new Node[max];
 		for(int i = 0; i < max; i++) {
 			listN[i] = new Node();
 		}
 		int[] counta = new int[max];
 		for(int i = 0; i < assign.length; i++) {
 			counta[assign[i]]++;
 			listN[assign[i]].addWord(list[i]);
 		}
 		for(int out: counta) {
 			if(out == 0) {
 				counter--;
 			}
 		}
 		if(counter > best) {
 			best = counter;
 			count = 0;
 		}
 		if(counter == best) {
 			count++;
 		}
 	}
 	
 	static int counter = 0;
 	
 	static class Node {
 		public Node[] list;
 		public Node() {
 			counter++;
 			list = new Node[26];
 		}
 		public void addWord(String s) {
 			if(s.length() == 0) {
 				return;
 			}
 			int index = s.charAt(0) - 'A';
 			if(list[index] == null) {
 				list[index] = new Node();
 			}
 			list[index].addWord(s.substring(1));
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
