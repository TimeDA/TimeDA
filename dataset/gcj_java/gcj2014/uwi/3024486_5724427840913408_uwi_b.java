package gcj2014.r3;
 import java.io.File;
 import java.io.PrintWriter;
 import java.io.StringWriter;
 import java.text.SimpleDateFormat;
 import java.util.ArrayList;
 import java.util.Arrays;
 import java.util.Date;
 import java.util.HashSet;
 import java.util.List;
 import java.util.Scanner;
 import java.util.Set;
 import java.util.concurrent.CompletionService;
 import java.util.concurrent.ExecutorCompletionService;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 
 public class B implements Runnable {
 	static final boolean LARGE = false;
 	static final boolean PROD = true;
 	static final int NTHREAD = 1;
 	static String BASEPATH = "x:\\gcj\\";
 //	static String BASEPATH = "/home/ec2-user/";
 	
 	static String INPATH = BASEPATH + B.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
 //	static String INPATH = BASEPATH + TParallel.class.getSimpleName().charAt(0) + (LARGE ? "-large-practice.in" : "-small-practice.in");
 	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
 	
 	static String INPUT = "";
 	
 	int P, Q;
 	int n;
 	int[] h;
 	int[] g;
 	
 	public void read() // not parallelized
 	{
 		P = ni(); Q = ni(); n = ni();
 		h = new int[n];
 		g = new int[n];
 		for(int i = 0;i < n;i++){
 			h[i] = ni();
 			g[i] = ni();
 		}
 	}
 	
 	public void process() // parallelized!
 	{
 		dfs(0);
 		out.println(max);
 	}
 	
 	int max = 0;
 	Set<Long> cache = new HashSet<Long>();
 	
 	void dfs(int gain)
 	{
 		long hh = gain;
 		for(int v : h){
 			hh = hh * 1000000009 + v;
 		}
 		if(cache.contains(hh))return;
 		cache.add(hh);
 		
 		// she
 		boolean alive = false;
 		for(int i = 0;i < n;i++){
 			if(h[i] >= 1){
 				alive = true;
 				h[i] -= P;
 				int ngain = gain;
 				if(h[i] <= 0)ngain += g[i];
 				int x = machine();
 				dfs(ngain);
 				if(x >= 0)h[x] += Q;
 				h[i] += P;
 			}
 		}
 		if(!alive){
 			max = Math.max(max, gain);
 		}else{
 			int x = machine();
 			dfs(gain);
 			if(x >= 0)h[x] += Q;
 		}
 	}
 	
 	int machine()
 	{
 		for(int i = 0;i < n;i++){
 			if(h[i] >= 1){
 				h[i] -= Q;
 				return i;
 			}
 		}
 		return -1;
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
 	
 	public B(int cas, Scanner in)
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
 		CompletionService<B> cs = new ExecutorCompletionService<B>(es);
 		
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
 			B runner = new B(i+1, in);
 			runner.read();
 			cs.submit(runner, runner);
 		}
 		es.shutdown();
 		String[] outs = new String[n];
 		for(int i = 0;i < n;i++){
 			B runner = cs.take().get(); // not ordered
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
