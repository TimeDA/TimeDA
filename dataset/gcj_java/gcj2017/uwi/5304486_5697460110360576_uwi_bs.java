package gcj2017.r1a;
 import java.io.File;
 import java.io.PrintWriter;
 import java.io.StringWriter;
 import java.lang.reflect.Field;
 import java.lang.reflect.Modifier;
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
 
 public class BS implements Runnable {
 	static final boolean LARGE = false;
 	static final boolean PROD = true;
 	static final int NTHREAD = 1; // Runtime.getRuntime().availableProcessors();
 	static String BASEPATH = "c:\\temp\\gcj2017\\r1a\\";
 //	static String BASEPATH = "/home/ec2-user/";
 	
 	static String INPATH = BASEPATH + BS.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
 //	static String INPATH = BASEPATH + TParallel.class.getSimpleName().charAt(0) + (LARGE ? "-large-practice.in" : "-small-practice.in");
 	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
 	
 	static String INPUT = "";
 	
 	int n, m;
 	int[][] rs;
 	int[] x;
 	
 	public void read() // not parallelized
 	{
 		n = ni(); m = ni();
 		x = na(n);
 		rs = new int[n][];
 		for(int i = 0;i < n;i++){
 			rs[i] = na(m);
 		}
 	}
 	
 	public void process() // parallelized!
 	{
 		int[][] inf = new int[n][m];
 		int[][] sup = new int[n][m];
 		// 0.9Dx <= r <= 1.1Dx
 		// r/1.1/D <= x <= r/0.9/D
 		
 		for(int i = 0;i < n;i++){
 			Arrays.sort(rs[i]);
 		}
 		for(int i = 0;i < n;i++){
 			for(int j = 0;j < m;j++){
 				inf[i][j] = (rs[i][j] * 10 + 11*x[i]-1) / (11*x[i]);
 				sup[i][j] = (rs[i][j] * 10) / (9*x[i]);
 			}
 		}
 		int[] ps = new int[n];
 		int mat = 0;
 		outer:
 		while(true){
 			for(int i = 0;i < n;i++){
 				if(ps[i] == m)break outer;
 			}
 			int linf = -1;
 			int lsup = Integer.MAX_VALUE;
 			for(int i = 0;i < n;i++){
 				linf = Math.max(linf, inf[i][ps[i]]);
 				lsup = Math.min(lsup, sup[i][ps[i]]);
 			}
 			if(linf <= lsup){
 				mat++;
 				for(int i = 0;i < n;i++)ps[i]++;
 			}else{
 				int mininf = Integer.MAX_VALUE;
 				int arg = -1;
 				for(int i = 0;i < n;i++){
 					if(inf[i][ps[i]] < mininf){
 						mininf = inf[i][ps[i]];
 						arg = i;
 					}
 				}
 				ps[arg]++;
 			}
 		}
 		out.println(mat);
 	}
 	
 	public static void preprocess()
 	{
 	}
 	
 	protected Scanner in;
 	protected PrintWriter out;
 	protected StringWriter sw;
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
 		
 		// get dump
 		StringBuilder dump = new StringBuilder();
 		for(Field f : this.getClass().getDeclaredFields()){
 			int mo = f.getModifiers();
 			if(!Modifier.isStatic(mo) && !Modifier.isProtected(mo)){
 				try {
 					dump.append(String.format("%s: %s\n", f.getName(), Arrays.deepToString(new Object[]{f.get(this)})));
 				} catch (IllegalArgumentException | IllegalAccessException e) {
 					e.printStackTrace();
 				}
 			}
 		}
 		
 		try{
 			process();
 		}catch(Throwable t){
 			// print dump
 			System.err.println(dump);
 			throw t;
 		}
 		
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
 	
 	public BS(int cas, Scanner in)
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
 		CompletionService<BS> cs = new ExecutorCompletionService<BS>(es);
 		
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
 			BS runner = new BS(i+1, in);
 			runner.read();
 			cs.submit(runner, runner);
 		}
 		es.shutdown();
 		String[] outs = new String[n];
 		for(int i = 0;i < n;i++){
 			BS runner = cs.take().get(); // not ordered
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
 			System.out.println("OUTPATH : ");
 			System.out.println(OUTPATH);
 		}
 	}
 }
