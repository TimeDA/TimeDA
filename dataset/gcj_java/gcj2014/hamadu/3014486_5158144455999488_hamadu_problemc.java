import java.io.PrintWriter;
 import java.util.ArrayList;
 import java.util.Arrays;
 import java.util.HashMap;
 import java.util.List;
 import java.util.Map;
 import java.util.Scanner;
 
 public class ProblemC {
 
 	/**
 	 * @param args
 	 */
 	public static void main(String[] args) {
 		Scanner in = new Scanner(System.in);
 		PrintWriter out = new PrintWriter(System.out);
 
 		int T = in.nextInt();
 		for (int cn = 1; cn <= T; cn++) {
 			int W = in.nextInt();
 			int H = in.nextInt();
 			int B = in.nextInt();
 			boolean[][] f = new boolean[H][W];
 			for (int b = 0 ; b < B ; b++) {
 				int x0 = in.nextInt();
 				int y0 = in.nextInt();
 				int x1 = in.nextInt();
 				int y1 = in.nextInt();
 				for (int i = y0; i <= y1; i++) {
 					for (int j = x0; j <= x1; j++) {
 						f[i][j] = true;
 					}
 				}
 			}
 			out.println(String.format("Case #%d: %s", cn, solve(f)));
 		}
 		out.flush();
 	}
 
 	
 	static int H;
 	static int W;
 	
 	static int[] dx = {1, 0, -1, 0};
 	static int[] dy = {0, 1, 0, -1};
 	
 	private static Object solve(boolean[][] f) {
 		
 		int h = f.length;
 		int w = f[0].length;
 		H = h;
 		W = w;
 		
 		init(h*w*2+2);
 		
 		int source = h*w*2;
 		int sink = h*w*2+1;
 		
 		for (int i = 0 ; i < w ; i++) {
 			edge(source, inID(0, i), 1);
 			edge(outID(h-1, i), sink, 1);
 		}
 		for (int i = 0 ; i < h ; i++) {
 			for (int j = 0 ; j < w ; j++) {
 				if (!f[i][j]) {
 					edge(inID(i, j), outID(i, j), 1);
 				}
 			}
 		}
 		for (int i = 0 ; i < h ; i++) {
 			for (int j = 0 ; j < w ; j++) {
 				for (int d = 0 ; d < 4 ; d++) {
 					int ti = i+dy[d];
 					int tj = j+dx[d];
 					if (0 <= ti && ti < h && 0 <= tj && tj < w) {
 						if (!f[i][j] && !f[ti][tj]) {
 							edge(outID(i, j), inID(ti, tj), 1);
 						}
 					}
 				}
 			}
 		}
 		return max_flow(source, sink);
 	}
 	
 	static int inID(int h, int w) {
 		return (h*W+w)*2;
 	}
 
 	static int outID(int h, int w) {
 		return (h*W+w)*2+1;
 	}
 
 	public static class Edge {
 		int to;
 		int cap;
 		int rev;
 
 		public Edge(int _to, int _cap, int _rev) {
 			to = _to;
 			cap = _cap;
 			rev = _rev;
 		}
 	}
 
 	public static Map<Integer, List<Edge>> graph = new HashMap<Integer, List<Edge>>();
 	public static boolean[] used;
 
 	public static void init(int size) {
 		for (int i = 0; i < size; i++) {
 			graph.put(i, new ArrayList<Edge>());
 		}
 		used = new boolean[size];
 	}
 
 	public static void edge(int from, int to, int cap) {
 		graph.get(from).add(new Edge(to, cap, graph.get(to).size()));
 		graph.get(to).add(new Edge(from, 0, graph.get(from).size() - 1));
 	}
 
 	public static int dfs(int v, int t, int f) {
 		if (v == t)
 			return f;
 		used[v] = true;
 		for (int i = 0; i < graph.get(v).size(); i++) {
 			Edge e = graph.get(v).get(i);
 			if (!used[e.to] && e.cap > 0) {
 				int d = dfs(e.to, t, Math.min(f, e.cap));
 				if (d > 0) {
 					e.cap -= d;
 					graph.get(e.to).get(e.rev).cap += d;
 					return d;
 				}
 			}
 		}
 		return 0;
 	}
 
 	public static int max_flow(int s, int t) {
 		int flow = 0;
 		while (true) {
 			used = new boolean[graph.size()];
 			int f = dfs(s, t, Integer.MAX_VALUE);
 			if (f == 0) {
 				break;
 			}
 			flow += f;
 		}
 		return flow;
 	}
 
 	public static void debug(Object... o) {
 		System.err.println(Arrays.deepToString(o));
 	}
 }
