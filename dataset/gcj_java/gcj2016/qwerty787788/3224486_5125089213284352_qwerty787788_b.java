import java.io.*;
 import java.util.*;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 
 public class B {
 	FastScanner in;
 	PrintWriter out;
 
 	class Vertex {
 		int id;
 		int prev;
 		char cc;
 		ArrayList<Vertex> next;
 
 		int size;
 		double cnt;
 
 		public Vertex(int id, int prev, char cc) {
 			super();
 			this.id = id;
 			this.cc = cc;
 			this.prev = prev;
 			next = new ArrayList<>();
 		}
 
 		int go() {
 			size = 1;
 			cnt = 1;
 			for (Vertex v : next) {
 				int prSize = size - 1;
 				size += v.go();
 				cnt *= c[size - 1][prSize];
 			}
 			return size;
 		}
 
 	}
 
 	final int ITERS = 1000;
 
 	final int MAX = 111;
 	double[][] c = new double[MAX][MAX];
 	int done = 0;
 
 	double getCnt(ArrayList<Vertex> roots) {
 		int tot = 0;
 		double res = 1;
 		for (Vertex v : roots) {
 			tot += v.size;
 			res *= v.cnt;
 			res *= c[tot][v.size];
 		}
 		return res;
 	}
 
 	class Solver implements Runnable {
 
 		Random rnd = new Random(123);
 
 		int id;
 
 		Solver(int id) {
 			this.id = id;
 			int n = in.nextInt();
 			Vertex[] a = new Vertex[n];
 			for (int i = 0; i < n; i++) {
 				a[i] = new Vertex(i, in.nextInt() - 1, 'a');
 			}
 			String s = in.next();
 			for (int i = 0; i < n; i++) {
 				a[i].cc = s.charAt(i);
 			}
 			roots = new ArrayList<>();
 			for (int i = 0; i < n; i++) {
 				if (a[i].prev == -1) {
 					roots.add(a[i]);
 				} else {
 					a[a[i].prev].next.add(a[i]);
 				}
 			}
 			for (Vertex v : roots) {
 				v.go();
 			}
 			int m = in.nextInt();
 			need = new String[m];
 			for (int i = 0; i < m; i++) {
 				need[i] = in.next();
 			}
 			sumPr = 0;
 			pr = new double[m];
 			res = new double[m];
 		}
 
 		ArrayList<Vertex> roots;
 		double sumPr;
 		double[] pr;
 		String[] need;
 		double[] res;
 
 		@Override
 		public void run() {
 			System.err.println("start " + id);
 			double totCnt = getCnt(roots);
 			go(roots, "", totCnt, ITERS);
 			for (int i = 0; i < res.length; i++) {
 				res[i] = pr[i] / ITERS;
 			}
 			System.err.println("done " + (done++));
 		}
 
 		void go(ArrayList<Vertex> roots, String now, double totCnt, int sz) {
 			if (roots.size() == 0) {
 				for (int i = 0; i < need.length; i++) {
 					if (now.contains(need[i])) {
 						pr[i] += sz;
 					}
 				}
 			} else {
 				double[] prs = new double[roots.size()];
 				for (int i = 0; i < roots.size(); i++) {
 					Vertex v = roots.get(i);
 					ArrayList<Vertex> next = new ArrayList<>();
 					for (Vertex u : v.next) {
 						next.add(u);
 					}
 					for (Vertex u : roots) {
 						if (u != v) {
 							next.add(u);
 						}
 					}
 					double nextCnt = getCnt(next);
 					prs[i] = nextCnt / totCnt;
 				}
 				int[] count = new int[roots.size()];
 				for (int i = 0; i < sz; i++) {
 					double P = rnd.nextDouble();
 					for (int j = 0; j < roots.size(); j++) {
 						P -= prs[j];
 						if (P <= 0) {
 							count[j]++;
 							break;
 						}
 					}
 				}
 				int it = 0;
 				for (Vertex v : roots) {
 					ArrayList<Vertex> next = new ArrayList<>();
 					for (Vertex u : v.next) {
 						next.add(u);
 					}
 					for (Vertex u : roots) {
 						if (u != v) {
 							next.add(u);
 						}
 					}
 					double nextCnt = getCnt(next);
 					if (count[it] > 0) {
 						go(next, now + v.cc, nextCnt, count[it]);
 					}
 					it++;
 				}
 			}
 		}
 	}
 
 	void solve() {
 		long START = System.currentTimeMillis();
 		for (int i = 0; i < MAX; i++) {
 			c[i][0] = 1;
 			if (i != 0)
 				for (int j = 1; j < MAX; j++) {
 					c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
 				}
 		}
 		int tc = in.nextInt();
 		Solver[] solv = new Solver[tc];
 		for (int t = 0; t < tc; t++) {
 			solv[t] = new Solver(t);
 		}
 		ExecutorService executor = Executors.newFixedThreadPool(5);
 		for (int i = 0; i < tc; i++) {
 			executor.execute(solv[i]);
 		}
 		executor.shutdown();
 		while (!executor.isTerminated()) {
 		}
 		for (int t = 0; t < tc; t++) {
 			out.print("Case #" + (t + 1) + ": ");
 			for (int i = 0; i < solv[t].res.length; i++) {
 				out.printf("%.6f ", solv[t].res[i]);
 			}
 			out.println();
 		}
 		System.err.println(System.currentTimeMillis() - START);
 	}
 
 	void run() {
 		try {
 			in = new FastScanner(new File("B.in"));
 			out = new PrintWriter(new File("B.out"));
 
 			solve();
 
 			out.close();
 		} catch (FileNotFoundException e) {
 			e.printStackTrace();
 		}
 	}
 
 	void runIO() {
 		in = new FastScanner(System.in);
 		out = new PrintWriter(System.out);
 
 		solve();
 
 		out.close();
 	}
 
 	class FastScanner {
 		BufferedReader br;
 		StringTokenizer st;
 
 		public FastScanner(File f) {
 			try {
 				br = new BufferedReader(new FileReader(f));
 			} catch (FileNotFoundException e) {
 				e.printStackTrace();
 			}
 		}
 
 		public FastScanner(InputStream f) {
 			br = new BufferedReader(new InputStreamReader(f));
 		}
 
 		String next() {
 			while (st == null || !st.hasMoreTokens()) {
 				String s = null;
 				try {
 					s = br.readLine();
 				} catch (IOException e) {
 					e.printStackTrace();
 				}
 				if (s == null)
 					return null;
 				st = new StringTokenizer(s);
 			}
 			return st.nextToken();
 		}
 
 		boolean hasMoreTokens() {
 			while (st == null || !st.hasMoreTokens()) {
 				String s = null;
 				try {
 					s = br.readLine();
 				} catch (IOException e) {
 					e.printStackTrace();
 				}
 				if (s == null)
 					return false;
 				st = new StringTokenizer(s);
 			}
 			return true;
 		}
 
 		int nextInt() {
 			return Integer.parseInt(next());
 		}
 
 		long nextLong() {
 			return Long.parseLong(next());
 		}
 
 		double nextDouble() {
 			return Double.parseDouble(next());
 		}
 	}
 
 	public static void main(String[] args) {
 		new B().run();
 	}
 }