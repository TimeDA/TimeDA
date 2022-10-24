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
 	static Semaphore processorSemaphore = new Semaphore(Runtime.getRuntime().availableProcessors());
 	static Semaphore inputSemaphore = new Semaphore(1);
 	static Semaphore outputSemaphore = new Semaphore(0);
 	static String[] output;
 	public static void main(String[] args) throws Exception {
 		br = new BufferedReader(new FileReader("c.in"));
 		pw = new PrintWriter(new BufferedWriter(new FileWriter("c.out")));
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
 			
 			int c = readInt();
 			int r = readInt();
 			int n = readInt();
 			int[] xL = new int[n];
 			int[] xR = new int[n];
 			int[] yL = new int[n];
 			int[] yR = new int[n];
 			for(int i = 0; i < n; i++) {
 				yL[i] = readInt();
 				xL[i] = readInt();
 				yR[i] = readInt();
 				xR[i] = readInt();
 			}
 			
 			/*
 			 * PUT ALL INPUT CODE BEFORE THIS COMMENT
 			 */
 			inputSemaphore.release();
 			
 			boolean[][] bad = new boolean[r][c];
 			int numV = r*c;
 			for(int i = 0; i < n; i++) {
 				for(int a = xL[i]; a <= xR[i]; a++) {
 					for(int b = yL[i]; b <= yR[i]; b++) {
 						bad[a][b] = true;
 						numV--;
 					}
 				}
 			}
 			
 			int[] dx = new int[]{-1,1,0,0};
 			int[] dy = new int[]{0,0,-1,1};
 			
 			initFlow(2*numV+2);
 			Map<State, Integer> map = new HashMap<State, Integer>();
 			for(int i = 0; i < r; i++) {
 				for(int j = 0; j < c; j++) {
 					if(!bad[i][j]) {
 						map.put(new State(i,j), map.size()+1);
 					}
 				}
 			}
 			
 			/*
 			 * 1 to n is in
 			 * n+1 to 2n is out
 			 */
 			for(int i = 0; i < r; i++) {
 				for(int j = 0; j < c; j++) {
 					if(bad[i][j]) {
 						continue;
 					}
 					int in = map.get(new State(i,j));
 					int out = in + numV;
 					addEdge(in, out, 1);
 					if(i == 0) {
 						addEdge(0, in, 1);
 					}
 					if(i == r-1) {
 						addEdge(out, 2*numV+1, 1);
 					}
 					for(int k = 0; k < dx.length; k++) {
 						State next = new State(i + dx[k], j + dy[k]);
 						if(map.containsKey(next)) {
 							addEdge(out, map.get(next), 1);
 						}
 					}
 				}
 			}
 			
 			output[casenum-1] = String.format("Case #%d: %d", casenum, getFlow(0, 2*numV+1));
 			
 			/*
 			 * PUT ALL WORK CODE BEFORE THIS COMMENT
 			 * REMEMBER TO WRITE to output[casenum-1] the exact output
 			 */
 			
 			
 			
 			outputSemaphore.release();
 			processorSemaphore.release();
 		}
 		
 		static class State {
 			public int x,y;
 
 			public State(int x, int y) {
 				super();
 				this.x = x;
 				this.y = y;
 			}
 
 			@Override
 			public int hashCode() {
 				final int prime = 31;
 				int result = 1;
 				result = prime * result + x;
 				result = prime * result + y;
 				return result;
 			}
 
 			@Override
 			public boolean equals(Object obj) {
 				if (this == obj)
 					return true;
 				if (obj == null)
 					return false;
 				if (getClass() != obj.getClass())
 					return false;
 				State other = (State) obj;
 				if (x != other.x)
 					return false;
 				if (y != other.y)
 					return false;
 				return true;
 			}
 			
 		}
 		
 		static class Edge {
 			public int from, to, cap, flow, index;
 			public Edge(int from, int to, int cap, int flow, int index) {
 				this.from = from;
 				this.to = to;
 				this.cap = cap;
 				this.flow = flow;
 				this.index = index;	
 			}
 		}
 		int N;
 		ArrayList<Edge>[] G;
 		long[] excess;
 		int[] dist, count;
 		boolean[] active;
 		Queue<Integer> Q;
 		public void initFlow(int n) {
 			N = n;
 			G = new ArrayList[n];
 			for(int i = 0; i < n; i++)
 				G[i] = new ArrayList<Edge>();
 			excess = new long[n];
 			dist = new int[n];
 			active = new boolean[n];
 			count = new int[2*n];
 			Q = new LinkedList<Integer>();
 		}
 		public void addEdge(int from, int to, int cap) {
 			if (from == to) 
 				G[from].add(new Edge(from, to, cap, 0, 1+ G[to].size()));
 			else
 				G[from].add(new Edge(from, to, cap, 0, G[to].size()));
 			G[to].add(new Edge(to, from, 0, 0, G[from].size() - 1));
 		}
 		public void enqueue(int v) { 
 			if (!active[v] && excess[v] > 0) {
 				active[v] = true; 
 				Q.add(v); 
 			} 
 		}
 		public void push(Edge e) {
 			int amt = (int) (Math.min(excess[e.from], (long) (e.cap - e.flow)));
 			if (dist[e.from] <= dist[e.to] || amt == 0)
 				return;
 			e.flow += amt;
 			G[e.to].get(e.index).flow -= amt;
 			excess[e.to] += amt;    
 			excess[e.from] -= amt;
 			enqueue(e.to);
 		}
 		public void gap(int k) {
 			for (int v = 0; v < N; v++) {
 				if (dist[v] < k)
 					continue;
 				count[dist[v]]--;
 				dist[v] = Math.max(dist[v], N+1);
 				count[dist[v]]++;
 				enqueue(v);
 			}
 		}
 		public void relabel(int v) {
 			count[dist[v]]--;
 			dist[v] = 2*N;
 			for (int i = 0; i < G[v].size(); i++) 
 				if (G[v].get(i).cap - G[v].get(i).flow > 0)
 					dist[v] = Math.min(dist[v], dist[G[v].get(i).to] + 1);
 			count[dist[v]]++;
 			enqueue(v);
 		}
 		public void discharge(int v) {
 			for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) 
 				push(G[v].get(i));
 			if (excess[v] > 0) {
 				if (count[dist[v]] == 1) 
 					gap(dist[v]); 
 				else
 					relabel(v);
 			}
 		}
 		public long getFlow(int s, int t) {
 			count[0] = N-1;
 			count[N] = 1;
 			dist[s] = N;
 			active[s] = active[t] = true;
 			for (int i = 0; i < G[s].size(); i++) {
 				excess[s] += G[s].get(i).cap;
 				push(G[s].get(i));
 			}
 
 			while (!Q.isEmpty()) {
 				int v = Q.remove();
 				active[v] = false;
 				discharge(v);
 			}
 
 			long totflow = 0;
 			for (int i = 0; i < G[s].size(); i++) totflow += G[s].get(i).flow;
 			return totflow;
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
