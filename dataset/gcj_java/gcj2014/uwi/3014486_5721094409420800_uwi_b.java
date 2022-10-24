package gcj2014.r2;
 import java.io.File;
 import java.io.PrintWriter;
 import java.io.StringWriter;
 import java.text.SimpleDateFormat;
 import java.util.ArrayDeque;
 import java.util.ArrayList;
 import java.util.Arrays;
 import java.util.Date;
 import java.util.List;
 import java.util.Queue;
 import java.util.Scanner;
 import java.util.concurrent.CompletionService;
 import java.util.concurrent.ExecutorCompletionService;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 
 public class B implements Runnable {
 	static final boolean LARGE = false;
 	static final boolean PROD = false;
 	static final int NTHREAD = 1;
 	static String BASEPATH = "x:\\gcj\\";
 //	static String BASEPATH = "/home/ec2-user/";
 	
 	static String INPATH = BASEPATH + B.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
 //	static String INPATH = BASEPATH + TParallel.class.getSimpleName().charAt(0) + (LARGE ? "-large-practice.in" : "-small-practice.in");
 	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
 	
 	static String INPUT = "";
 	int n;
 	int[] a;
 	
 	public void read() // not parallelized
 	{
 		n = ni();
 		a = new int[n];
 		for(int i = 0;i < n;i++){
 			a[i] = ni();
 		}
 	}
 	
 	public static int encPerm(int[] a)
 	{
 		int n = a.length;
 		int used = 0;
 		int ret = 0;
 		for(int i = 0;i < n;i++){
 			ret = ret * (n - i) + a[i] - Integer.bitCount(used & ((1<<a[i]) - 1));
 			used |= 1<<a[i];
 		}
 		return ret;
 	}
 	
 	public static int[] decPerm(int c, int n)
 	{
 		int[] a = new int[n];
 		for(int i = n - 1;i >= 0;c /= n - i, i--){
 			int v = c % (n - i);
 			a[i] = v;
 			for(int j = i + 1;j <= n - 1;j++){
 				if(v <= a[j])a[j]++;
 			}
 		}
 		return a;
 	}
 	
 	public void process() // parallelized!
 	{
 		Queue<Integer> q = new ArrayDeque<Integer>();
 		q.add(0);
 		int[] d = new int[3628800];
 		Arrays.fill(d, 9999999);
 		d[0] = 0;
 		int min = 9999999;
 		while(!q.isEmpty()){
 			int cur = q.poll();
 			int[] ord = decPerm(cur, n);
 			
 			int u = 0, v = n-1;
 			for(;u < n-1 && a[ord[u]] < a[ord[u+1]];u++);
 			for(;v > 0 && a[ord[v]] < a[ord[v-1]];v--);
 			if(u >= v){
 				min = Math.min(min, d[cur]);
 			}
 			
 			for(int i = 0;i < n-1;i++){
 				{int x = ord[i]; ord[i] = ord[i+1]; ord[i+1] = x;}
 				int code = encPerm(ord);
 				if(d[code] > d[cur] + 1){
 					d[code] = d[cur] + 1;
 					q.add(code);
 				}
 				{int x = ord[i]; ord[i] = ord[i+1]; ord[i+1] = x;}
 			}
 		}
 		out.println(min);
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
