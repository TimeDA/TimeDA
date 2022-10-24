
import java.io.*;
import java.util.*;
import java.util.stream.IntStream;

public class Solution {
	void solveTestcase(final Scanner in, final PrintWriter out) {
		int n = in.nextInt();
		int[][] m = new int[n][n];

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				int c = in.nextInt();
				if (c > 0) c--;
				c += n;
				m[y][x] = c;
			}
		}
		
		int ans = n*n;
		for (int i = 0; i < 1<<(n*n); i++) {
			int[][] vis1 = new int[n][2*n];
			int[][] vis2 = new int[n][2*n];
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < n; l++) {
					if ((i>>>(k*n+l)&1) == 1) {
						vis1[k][m[k][l]]++;
						vis2[l][m[k][l]]++;
					}
				}
			}
			boolean ok = true;
			for (int[] v : vis1) ok &= IntStream.of(v).max().getAsInt() <= 1;
			for (int[] v : vis2) ok &= IntStream.of(v).max().getAsInt() <= 1;
			if (ok) ans = Math.min(ans, n*n - Integer.bitCount(i));
		}
		out.println(ans);
		
//		int S = 4 * n, T = S + 1;
//		PushRelabelBaseMaxFlow flow = new PushRelabelBaseMaxFlow(T + 1);
//		boolean[][] mat1 = new boolean[n][2*n];
//		boolean[][] mat2 = new boolean[n][2*n];
//		for (int y = 0; y < n; y++) {
//			flow.addEdge(S, y, 1<<29);
//			flow.addEdge(y+n, T, 1<<29);
//			for (int x = 0; x < n; x++) {
//				int c = in.nextInt();
//				if (c > 0) c--;
//				c += n;
//				mat1[y][c] = mat2[x][c] = true;
//			}
//		}
//		for (int y = 0; y < n; y++) {
//			for (int c = 0; c < 2 * n; c++) {
//				if (mat1[y][c]) flow.addEdge(y, c, 1);
//				if (mat2[y][c]) flow.addEdge(c, y+n, 1);
//			}
//		}
//		out.println(n*n - flow.relabelToFront(S, T));
	}
	
	static void solve() {
		try (final PrintWriter out = new PrintWriter(System.out)) {
			try (final Scanner in = new Scanner(System.in)) {
				int t = in.nextInt();
				for (int i = 0; i < t; i++) {
					out.printf("Case #%d: ", i+1);
					new Solution().solveTestcase(in, out);
				}
			}
		}
	}
	
	public class PushRelabelBaseMaxFlow {
	    int V;
	    Vertex[] vertices;
	
	    public PushRelabelBaseMaxFlow(int V) {
	        this.V = V;
			vertices = new Vertex[V];
			for (int i = 0; i < V; i++) vertices[i] = new Vertex(i);
	    }
	
	    public void addEdge(int s, int t, int cap) {
	        Edge e1 = new Edge(vertices[s], vertices[t], cap);
	        Edge e2 = new Edge(vertices[t], vertices[s], 0);
	        e1.rev = e2;
	        e2.rev = e1;
	    }
		
		void initializePreflow(Vertex S) {
			for (Vertex v : vertices) { v.clear(); }
			S.height = V;
			for (Edge e : S.edges) {
				e.v.excessFlow += e.capacity;
				e.u.excessFlow -= e.capacity;
				e.rev.capacity += e.capacity;
				e.capacity = 0;
			}
		}
		
		long relabelToFront(int s, int t) {
			initializePreflow(vertices[s]);
			Vertex[] L = new Vertex[V - 1];
			for (int i = 0, j = 0; i < V; i++) {
				if (i != s && i != t) L[j++] = vertices[i];
			}
			
			int i = 0;
			Vertex cur = L[i];
			while (cur != null) {
				int h0 = cur.height;
				cur.discharge();
				if (cur.height > h0) {
					L[i = 0] = cur;
				}
				Vertex tmp = L[++i];
				L[i] = cur;
				cur = tmp;
			}
			
			return vertices[t].excessFlow;
		}
		
		class Edge {
			Vertex u, v;
			Edge rev;
			long capacity;
			
			public Edge(Vertex s, Vertex t, long cap) {
				u = s;
				v = t;
				capacity = cap;
				s.edges.add(this);
			}
			
			boolean canPush() {
				return capacity > 0 && u.height == v.height + 1 && u.isOverflow();
			}
			
			void push() {
				final long f = Math.min(u.excessFlow, capacity);
				capacity -= f;
				rev.capacity += f;
				u.excessFlow -= f;
				v.excessFlow += f;
			}
			
			@Override
			public String toString() {
				return String.format("[Edge u=%d(%d), v=%d(%d), c=%d]", u.id, u.height, v.id, v.height, capacity);
			}
		}
		
		class Vertex {
			final int id;
			int height;
			long excessFlow;
			List<Edge> edges = new ArrayList<>();
			
			public Vertex(int id) {
				this.id = id;
			}
	
			void clear() {
				height = 0;
				excessFlow = 0;
			}
			
			boolean isOverflow() { return excessFlow > 0; }
			
			void relabel() {
				final int h = edges.stream().filter(e->e.capacity > 0)
											.map(a->a.v.height)
											.min(Comparator.naturalOrder())
											.get();
				if (!isOverflow() || height > h) {
					throw new RuntimeException();
				}
				height = h + 1;
			}
			
			void discharge() {
				while (isOverflow()) {
					for (Edge e : edges) {
						while (e.canPush()) e.push();
						if (!isOverflow()) return;
					}
					relabel();
				}
			}
			
			@Override
			public String toString() {
				return String.format("[Vertex id=%d, h=%d, ex=%d, es=%s]", id, height, excessFlow, edges);
			}
		}
	}

	public static void main(String[] args) {
		solve();
	}
	
	static int gcd(int n, int r) { return r == 0 ? n : gcd(r, n%r); }
	static long gcd(long n, long r) { return r == 0 ? n : gcd(r, n%r); }
	
	static <T> void swap(T[] x, int i, int j) { T t = x[i]; x[i] = x[j]; x[j] = t; }
	static void swap(int[] x, int i, int j) { int t = x[i]; x[i] = x[j]; x[j] = t; }
	static void swap(char[] x, int i, int j) { char t = x[i]; x[i] = x[j]; x[j] = t; }

	void printArrayLn(PrintWriter out, int[] xs) { for(int i = 0; i < xs.length; i++) out.print(xs[i] + (i==xs.length-1?"\n":" ")); }
	void printArrayLn(PrintWriter out, long[] xs) { for(int i = 0; i < xs.length; i++) out.print(xs[i] + (i==xs.length-1?"\n":" ")); }
	
	static void dump(Object... o) { System.err.println(Arrays.deepToString(o)); }
}
