package gcj2012.r2;
 import java.io.File;
 import java.io.PrintWriter;
 import java.text.SimpleDateFormat;
 import java.util.ArrayDeque;
 import java.util.Arrays;
 import java.util.Date;
 import java.util.Queue;
 import java.util.Scanner;
 
 public class A {
 	static String BASEPATH = "x:\\gcj\\";
 	static boolean LARGE = false;
 	static String INPATH = BASEPATH + A.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
 	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
 	
 	static String INPUT = "";
 	
 	public void call()
 	{
 		int n = ni();
 		int[][] v = new int[n][2];
 		for(int i = 0;i < n;i++){
 			v[i][0] = ni();
 			v[i][1] = ni();
 		}
 		int g = ni();
 		
 		Queue<int[]> q = new ArrayDeque<int[]>();
 		if(g <= v[0][0] * 2){
 			out.println("YES");
 			return;
 		}
 		boolean[][] ved = new boolean[n][n];
 		for(int i = 1;i < n;i++){
 			if(v[i][0] <= v[0][0] * 2){
 				q.add(new int[]{0, i});
 				ved[0][i] = true;
 			}
 		}
 		
 		while(!q.isEmpty()){
 			int[] cur = q.poll();
 			int w = Math.min(v[cur[1]][0]-v[cur[0]][0], v[cur[1]][1]);
 			for(int i = cur[1];i < n;i++){
 				if(v[i][0] <= v[cur[1]][0] + w && !ved[cur[1]][i]){
 					ved[cur[1]][i] = true;
 					q.add(new int[]{cur[1], i});
 				}
 			}
 			if(g <= v[cur[1]][0] + w){
 				out.println("YES");
 				return;
 			}
 		}
 		out.println("NO");
 		return;
 	}
 	
 	Scanner in;
 	PrintWriter out;
 	int cas;
 	
 	public A(int cas, Scanner in, PrintWriter out)
 	{
 		this.cas = cas;
 		this.in = in;
 		this.out = out;
 	}
 	
 	int ni() { return Integer.parseInt(in.next()); }
 	long nl() { return Long.parseLong(in.next()); }
 	double nd() { return Double.parseDouble(in.next()); }
 	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
 	
 	public static void main(String[] args) throws Exception
 	{
 		long start = System.currentTimeMillis();
 		boolean real = INPUT.isEmpty();
 		
 		if(real){
 			System.out.println("INPATH : " + INPATH);
 			System.out.println("OUTPATH : " + OUTPATH);
 		}
 		Scanner in = real ? new Scanner(new File(INPATH)) : new Scanner(INPUT);
 		PrintWriter out = real ? new PrintWriter(new File(OUTPATH)) : new PrintWriter(System.out);
 		int n = in.nextInt();
 		in.nextLine();
 		
 		for(int i = 0;i < n;i++){
 			out.printf("Case #%d: ", i+1);
 			new A(i+1, in, out).call();
 			out.flush();
 			if(real)System.err.println("case " + (i + 1) + " solved.\t");
 		}
 		
 		long end = System.currentTimeMillis();
 		System.out.println((end - start) + "ms");
 		if(real){
 			System.out.println("INPATH : " + INPATH);
 			System.out.println("OUTPATH : " + OUTPATH);
 		}
 	}
 }
