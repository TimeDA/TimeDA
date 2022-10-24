import static java.lang.Double.parseDouble;
 import static java.lang.Integer.parseInt;
 import static java.lang.Long.parseLong;
 import static java.lang.System.exit;
 import static java.util.Arrays.fill;
 
 import java.io.BufferedReader;
 import java.io.IOException;
 import java.io.InputStreamReader;
 import java.io.OutputStreamWriter;
 import java.io.PrintWriter;
 import java.util.ArrayList;
 import java.util.HashMap;
 import java.util.List;
 import java.util.Map;
 import java.util.StringTokenizer;
 
 public class C {
 	
 	static BufferedReader in;
 	static PrintWriter out;
 	static StringTokenizer tok;
 	static int test;
 	
 	static class Edge {
 		final int to;
 		Edge pair;
 		boolean filled;
 		
 		Edge(int to, boolean filled) {
 			this.to = to;
 			this.filled = filled;
 		}
 	}
 	
 	static Edge createEdge(List<Edge> net[], int a, int b) {
 		Edge ea = new Edge(b, false);
 		Edge eb = new Edge(a, true);
 		ea.pair = eb;
 		eb.pair = ea;
 		net[a].add(ea);
 		net[b].add(eb);
 		return ea;
 	}
 	
 	static boolean pushFlow(List<Edge> net[], boolean seen[], boolean terminal[], int cur, boolean inverse) {
 		if (seen[cur]) {
 			return false;
 		}
 		seen[cur] = true;
 		if (terminal[cur]) {
 			return true;
 		}
 		for (Edge e: net[cur]) {
 			if ((inverse ? e.pair : e).filled) {
 				continue;
 			}
 			if (pushFlow(net, seen, terminal, e.to, inverse)) {
 				e.filled = !inverse;
 				e.pair.filled = inverse;
 				return true;
 			}
 		}
 		return false;
 	}
 	
 	static void solve() throws Exception {
 		int n = nextInt();
 //		int n = 1000;
 		List<Edge> net[] = new List[n * n + n + 2];
 		for (int i = 0; i < net.length; i++) {
 			net[i] = new ArrayList<>();
 		}
 		final int source = n * n + n;
 		final int sink = n * n + n + 1;
 		final int event = n * n;
 		Edge peopleEdges[] = new Edge[n];
 		for (int person = 0; person < n; person++) {
 			createEdge(net, source, n * person);
 			for (int i = 0; i < n - 1; i++) {
 				createEdge(net, n * person + i, n * person + i + 1);
 			}
 			peopleEdges[person] = createEdge(net, n * person + n - 1, sink);
 		}
 		Map<Integer, Integer> idmap = new HashMap<>();
 		boolean leaves[] = new boolean[n];
 		Edge eventEdges[] = new Edge[n];
 		for (int i = 0; i < n; i++) {
 			boolean leave = next().charAt(0) != 'E';
 //			boolean leave = false;
 			leaves[i] = leave;
 			int id = nextInt();
 //			int id = 0;
 			if (id == 0) {
 				for (int person = 0; person < n; person++) {
 					if (leave) {
 						createEdge(net, n * person + i, event + i);
 					} else {
 						createEdge(net, event + i, n * person + i);
 					}
 				}
 			} else {
 				if (idmap.containsKey(id)) {
 					id = idmap.get(id);
 				} else {
 					idmap.put(id, id = idmap.size());
 				}
 				if (leave) {
 					createEdge(net, n * id + i, event + i);
 				} else {
 					createEdge(net, event + i, n * id + i);
 				}
 			}
 			if (leave) {
 				eventEdges[i] = createEdge(net, event + i, sink);
 			} else {
 				eventEdges[i] = createEdge(net, source, event + i);
 			}
 		}
 		boolean terminal[] = new boolean[net.length];
 		boolean seen[] = new boolean[net.length];
 		terminal[source] = true;
 		terminal[sink] = true;
 		for (int i = 0; i < n; i++) {
 			if (!eventEdges[i].filled) {
 				seen[source] = false;
 				seen[sink] = false;
 				if (!pushFlow(net, seen, terminal, event + i, leaves[i])) {
 					fill(seen, false);
 					if (!pushFlow(net, seen, terminal, event + i, leaves[i])) {
 						printCase();
 						out.println("CRIME TIME");
 						return;
 					}
 				}
 				eventEdges[i].filled = true;
 			} else {
 				eventEdges[i].pair.filled = true;
 			}
 		}
 		terminal[sink] = false;
 		while (true) {
 			seen[source] = false;
 			seen[sink] = false;
 			if (!pushFlow(net, seen, terminal, sink, false)) {
 				fill(seen, false);
 				if (!pushFlow(net, seen, terminal, sink, false)) {
 					break;
 				}
 			}
 		}
 		int ans = 0;
 		for (Edge e: peopleEdges) {
 			if (e.filled) {
 				++ans;
 			}
 		}
 		printCase();
 		out.println(ans);
 	}
 	
 	static void printCase() {
 		out.print("Case #" + test + ": ");
 	}
 	
 	static void printlnCase() {
 		out.println("Case #" + test + ":");
 	}
 	
 	static int nextInt() throws IOException {
 		return parseInt(next());
 	}
 
 	static long nextLong() throws IOException {
 		return parseLong(next());
 	}
 
 	static double nextDouble() throws IOException {
 		return parseDouble(next());
 	}
 
 	static String next() throws IOException {
 		while (tok == null || !tok.hasMoreTokens()) {
 			tok = new StringTokenizer(in.readLine());
 		}
 		return tok.nextToken();
 	}
 
 	public static void main(String[] args) {
 		try {
 			in = new BufferedReader(new InputStreamReader(System.in));
 			out = new PrintWriter(new OutputStreamWriter(System.out));
 			int tests = nextInt();
 			for (test = 1; test <= tests; test++) {
 				solve();
 			}
 			in.close();
 			out.close();
 		} catch (Throwable e) {
 			e.printStackTrace();
 			exit(1);
 		}
 	}
 }