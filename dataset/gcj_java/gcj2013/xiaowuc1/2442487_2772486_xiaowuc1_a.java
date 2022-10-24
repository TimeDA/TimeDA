import java.awt.*;
 import java.awt.event.*;
 import java.awt.geom.*;
 import java.io.*;
 import java.math.*;
 import java.text.*;
 import java.util.*;
 public class A {
 	static BufferedReader br;
 	static StringTokenizer st;
 	static PrintWriter pw;
 
 	static final int MOD = 1000002013;
 
 	static int n;
 
 	public static void main(String[] args) throws IOException {
 		br = new BufferedReader(new FileReader("a.in"));
 		pw = new PrintWriter(new BufferedWriter(new FileWriter("a.out")));
 		final int MAX_CASES = readInt();
 		for(int casenum = 1; casenum <= MAX_CASES; casenum++)	{
 			pw.printf("Case #%d: ", casenum);
 			n = readInt();
 			int m = readInt();
 			BigInteger actual = BigInteger.ZERO;
 			BigInteger best = BigInteger.ZERO;
 			ArrayList<State> list = new ArrayList<State>();
 			for(int i = 0; i < m; i++)	{
 				int s = readInt();
 				int e = readInt();
 				int count = readInt();
 				list.add(new State(s,e,count));
 				actual = actual.add(BigInteger.valueOf(cost(e-s)).multiply(BigInteger.valueOf(count)));
 			}
 			ArrayList<State> preprocess = new ArrayList<State>();
 			outer: while(!list.isEmpty())	{
 				State curr = list.remove(0);
 				for(int i = 0; i < list.size(); i++)	{
 					if(curr.end == list.get(i).start)	{
 						State now = list.remove(i);
 						int a = curr.start;
 						int b = now.start;
 						int c = curr.end;
 						int d = now.end;
 						int numEx = Math.min(curr.numHere, now.numHere);
 						State stay1 = new State(a,c,curr.numHere - numEx);
 						State stay2 = new State(b,d,now.numHere - numEx);
 						State push1 = new State(a,d,numEx);
 						curr.end = d;
 						curr.numHere = numEx;
 						if(stay1.numHere > 0)	{
 							preprocess.add(stay1);
 						}
 						if(stay2.numHere > 0)	{
 							preprocess.add(stay2);
 						}
 						preprocess.add(push1);
 						continue outer;
 					}
 				}
 				preprocess.add(curr);
 			}
 			list.addAll(preprocess);
 			Collections.sort(list);
 			while(!list.isEmpty())	{
 				ArrayList<State> temp = new ArrayList<State>();
 				State curr = list.remove(0);
 				for(int i = 0; i < list.size(); i++)	{
 					if(list.get(i).start > curr.end)	{
 						break;
 					}
 					if(list.get(i).end <= curr.end)	{
 						continue;
 					}
 					State now = list.remove(i--);
 					int a = curr.start;
 					int b = now.start;
 					int c = curr.end;
 					int d = now.end;
 					int numEx = Math.min(curr.numHere, now.numHere);
 					State stay1 = new State(a,c,curr.numHere - numEx);
 					State stay2 = new State(b,d,now.numHere - numEx);
 					State push2 = new State(b,c,numEx);
 					curr.end = d;
 					curr.numHere = numEx;
 					if(stay1.numHere > 0)	{
 						temp.add(stay1);
 					}
 					if(stay2.numHere > 0)	{
 						temp.add(stay2);
 					}
 					temp.add(push2);
 				}
 				best = best.add(BigInteger.valueOf(cost(curr.end - curr.start)).multiply(BigInteger.valueOf(curr.numHere)));
 				list.addAll(temp);
 				Collections.sort(list);
 			}
 			pw.println(actual.subtract(best).mod(BigInteger.valueOf(MOD)));
 		}
 		pw.close();
 	}
 
 	public static long cost(int x)	{
 		long a = n+1;
 		a *= x;
 		long b = x;
 		b *= (x+1);
 		b /= 2;
 		return a - b;
 	}
 
 	static class State implements Comparable<State> {
 		public int start, end, numHere;
 
 		public State(int start, int end, int numHere) {
 			super();
 			this.start = start;
 			this.end = end;
 			this.numHere = numHere;
 		}
 		public int compareTo(State i)	{
 			if(start == i.start)	{
 				return end - i.end;
 			}
 			return start - i.start;
 		}
 		public String toString()	{
 			return String.format("%d %d %d", start, end, numHere);
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
