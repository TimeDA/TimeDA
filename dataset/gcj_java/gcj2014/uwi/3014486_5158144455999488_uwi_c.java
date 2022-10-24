package gcj2014.r2;
 import java.io.File;
 import java.io.PrintWriter;
 import java.io.StringWriter;
 import java.text.SimpleDateFormat;
 import java.util.ArrayList;
 import java.util.Arrays;
 import java.util.Date;
 import java.util.List;
 import java.util.Scanner;
 import java.util.concurrent.CompletionService;
 import java.util.concurrent.ExecutorCompletionService;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 
 public class C implements Runnable {
 	static final boolean LARGE = false;
 	static final boolean PROD = true;
 	static final int NTHREAD = 4;
 //	static String BASEPATH = "x:\\gcj\\";
 	static String BASEPATH = "/home/ec2-user/";
 	
 	static String INPATH = BASEPATH + C.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
 //	static String INPATH = BASEPATH + TParallel.class.getSimpleName().charAt(0) + (LARGE ? "-large-practice.in" : "-small-practice.in");
 	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
 	
 	static String INPUT = "";
 	int w, h;
 	int b;
 	boolean[][] blocked;
 	
 	public void read() // not parallelized
 	{
 		w = ni();
 		h = ni();
 		b = ni();
 		blocked = new boolean[h][w];
 		for(int i = 0;i < b;i++){
 			int x1 = ni(), y1 = ni(), x2 = ni(), y2 = ni();
 			for(int x = x1;x <= x2;x++){
 				for(int y = y1;y <= y2;y++){
 					blocked[y][x] = true;
 				}
 			}
 		}
 	}
 	
 	int[] dr = { 1, 0, -1, 0 };
 	int[] dc = { 0, 1, 0, -1 };
 	
 	public void process() // parallelized!
 	{
 		List<Edge> edges = new ArrayList<Edge>();
 		int src = 2*h*w, sink = 2*h*w+1;
 		for(int i = 0;i < h;i++){
 			for(int j = 0;j < w;j++){
 				if(!blocked[i][j]){
 					edges.add(new Edge(i*w+j, i*w+j+h*w, 1));
 					for(int k = 0;k < 4;k++){
 						int nr = i + dr[k], nc = j + dc[k];
 						if(nr >= 0 && nr < h && nc >= 0 && nc < w && !blocked[nr][nc]){
 							edges.add(new Edge(i*w+j+h*w, nr*w+nc, 9999999));
 						}
 					}
 					
 					if(i == 0){
 						edges.add(new Edge(src, i*w+j, 1));
 					}
 					if(i == h-1){
 						edges.add(new Edge(i*w+j+h*w, sink, 9999999));
 					}
 				}
 			}
 		}
 		out.println(maximumFlowDinic(compileWD(sink+1, edges), src, sink));
 	}
 	
 	public static class Edge
 	{
 		public int from, to;
 		public int capacity;
 		public int flow;
 		public Edge complement;
 		// public int iniflow;
 		
 		public Edge(int from, int to, int capacity) {
 			this.from = from;
 			this.to = to;
 			this.capacity = capacity;
 		}
 	}
 	
 	public static Edge[][] compileWD(int n, List<Edge> edges)
 	{
 		Edge[][] g = new Edge[n][];
 		// cloning
 		for(int i = edges.size()-1;i >= 0;i--){
 			Edge origin = edges.get(i);
 			Edge clone = new Edge(origin.to, origin.from, origin.capacity);
 			clone.flow = origin.capacity;
 			clone.complement = origin;
 			origin.complement = clone;
 			edges.add(clone);
 		}
 		
 		int[] p = new int[n];
 		for(Edge e : edges)p[e.from]++;
 		for(int i = 0;i < n;i++)g[i] = new Edge[p[i]];
 		for(Edge e : edges)g[e.from][--p[e.from]] = e;
 		return g;
 	}
 	
 	public static Edge[][] compileWU(int n, List<Edge> edges)
 	{
 		Edge[][] g = new Edge[n][];
 		// cloning
 		for(int i = edges.size()-1;i >= 0;i--){
 			Edge origin = edges.get(i);
 			Edge clone = new Edge(origin.to, origin.from, origin.capacity*2);
 			origin.flow = origin.capacity;
 			clone.flow = origin.capacity;
 			clone.complement = origin;
 			origin.complement = clone;
 			origin.capacity *= 2;
 			edges.add(clone);
 		}
 		
 		int[] p = new int[n];
 		for(Edge e : edges)p[e.from]++;
 		for(int i = 0;i < n;i++)g[i] = new Edge[p[i]];
 		for(Edge e : edges)g[e.from][--p[e.from]] = e;
 		return g;
 	}	
 	
 	public static long maximumFlowDinic(Edge[][] g, int source, int sink)
 	{
 		int n = g.length;
 		int[] d = new int[n];
 		int[] q = new int[n];
 		long ret = 0;
 		while(true){
 			Arrays.fill(d, -1);
 			q[0] = source;
 			int r = 1;
 			d[source] = 0;
 			
 			for(int v = 0;v < r;v++){
 				int cur = q[v];
 				for(int i = 0;i < g[cur].length;i++){
 					Edge ne = g[cur][i];
 					if(d[ne.to] == -1 && ne.capacity - ne.flow > 0) {
 						q[r++] = ne.to;
 						d[ne.to] = d[cur] + 1;
 					}
 				}
 			}
 			if(d[sink] == -1)break;
 			int[] sp = new int[n];
 			for(int i = 0;i < n;i++)sp[i] = g[i].length - 1;
 			ret += dfsDinic(d, g, sp, source, sink, Long.MAX_VALUE);
 		}
 		
 		return ret;
 	}
 	
 	private static long dfsDinic(int[] d, Edge[][] g, int[] sp, int cur, int sink, long min)
 	{
 		if(cur == sink)return min;
 		long left = min;
 		for(int i = sp[cur];i >= 0;i--){
 			Edge ne = g[cur][i];
 			if(d[ne.to] == d[cur]+1 && ne.capacity - ne.flow > 0){
 				long fl = dfsDinic(d, g, sp, ne.to, sink, Math.min(left, ne.capacity - ne.flow));
 				if(fl > 0){
 					left -= fl;
 					ne.flow += fl;
 					ne.complement.flow -= fl;
 					if(left == 0){
 						sp[cur] = i;
 						return min;
 					}
 				}
 			}
 		}
 		sp[cur] = -1;
 		return min-left;
 	}
 	
 	public static void preprocess()
 	{
 	}
 	
 	Scanner in;
 	PrintWriter out;
 	StringWriter sw;
 	int cas;
 	static List<Status> running = new ArrayList<Status>();
 	
 	@Override
 	public void run()
 	{
 		long S = System.nanoTime();
 		// register
 		synchronized(running){
 			Status st = new Status();
 			st.id = cas;
 			st.S = S;
 			running.add(st);
 		}
 		process();
 		// deregister
 		synchronized(running){
 			for(Status st : running){
 				if(st.id == cas){
 					running.remove(st);
 					break;
 				}
 			}
 		}
 		long G = System.nanoTime();
 		
 		if(PROD){
 			System.err.println("case " + cas + " solved. [" + (G-S)/1000000 + "ms]");
 			synchronized(running){
 				StringBuilder sb = new StringBuilder("running : ");
 				for(Status st : running){
 					sb.append(st.id + ":" + (G-st.S)/1000000 + "ms, ");
 				}
 				System.err.println(sb);
 			}
 		}
 	}
 	
 	private static class Status {
 		public int id;
 		public long S;
 	}
 	
 	public C(int cas, Scanner in)
 	{
 		this.cas = cas;
 		this.in = in;
 		this.sw = new StringWriter();
 		this.out = new PrintWriter(this.sw);
 	}
 	
 	private int ni() { return Integer.parseInt(in.next()); }
 	private long nl() { return Long.parseLong(in.next()); }
 	private int[] na(int n) { int[] a = new int[n]; for(int i = 0;i < n;i++)a[i] = ni(); return a; }
 	private double nd() { return Double.parseDouble(in.next()); }
 	private void tr(Object... o) { if(!PROD)System.out.println(Arrays.deepToString(o)); }
 	
 	public static void main(String[] args) throws Exception
 	{
 		long start = System.nanoTime();
 		
 		ExecutorService es = Executors.newFixedThreadPool(NTHREAD);
 		CompletionService<C> cs = new ExecutorCompletionService<C>(es);
 		
 		if(PROD){
 			System.out.println("INPATH : " + INPATH);
 			System.out.println("OUTPATH : " + OUTPATH);
 		}
 		Scanner in = PROD ? new Scanner(new File(INPATH)) : new Scanner(INPUT);
 		PrintWriter out = PROD ? new PrintWriter(new File(OUTPATH)) : new PrintWriter(System.out);
 		int n = in.nextInt();
 		in.nextLine();
 		
 		preprocess();
 		for(int i = 0;i < n;i++){
 			C runner = new C(i+1, in);
 			runner.read();
 			cs.submit(runner, runner);
 		}
 		es.shutdown();
 		String[] outs = new String[n];
 		for(int i = 0;i < n;i++){
 			C runner = cs.take().get(); // not ordered
 			runner.out.flush();
 			runner.out.close();
 			outs[runner.cas-1] = runner.sw.toString();
 		}
 		for(int i = 0;i < n;i++){
 			out.printf("Case #%d: ", i+1);
 			out.append(outs[i]);
 			out.flush();
 		}
 		
 		long end = System.nanoTime();
 		System.out.println((end - start)/1000000 + "ms");
 		if(PROD){
 			System.out.println("INPATH : " + INPATH);
 			System.out.println("OUTPATH : " + OUTPATH);
 		}
 	}
 }
