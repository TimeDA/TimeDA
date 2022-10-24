package gcj2013.r2;
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
 		int n = ni(), m = ni();
 		int[][] rs = new int[m*1000][];
 		for(int i = 0;i < m;i++){
 			rs[i] = new int[]{ni(), ni(), ni()};
 		}
 		int p = m;
 		Queue<int[]> q = new ArrayDeque<int[]>();
 		for(int i = 0;i < m;i++){
 			for(int j = i+1;j < m;j++){
 				if(ok(rs[i], rs[j])){
 					q.add(new int[]{i, j});
 				}
 			}
 		}
 		int mod = 1000002013;
 		long x = 0;
 		while(!q.isEmpty()){
 			if(q.size() % 100000 == 0)tr(q.size());
 			int[] cur = q.poll();
 			if(rs[cur[0]][2] > 0 && rs[cur[1]][2] > 0 && Math.max(rs[cur[0]][0], rs[cur[1]][0]) <= Math.min(rs[cur[0]][1], rs[cur[1]][1])){
 				if(rs[cur[0]][0] <= rs[cur[1]][0] && rs[cur[1]][1] <= rs[cur[0]][1])continue;
 				if(rs[cur[1]][0] <= rs[cur[0]][0] && rs[cur[0]][1] <= rs[cur[1]][1])continue;
 				int sw = Math.min(rs[cur[0]][2], rs[cur[1]][2]);
 				long B = Math.min(rs[cur[0]][1], rs[cur[1]][1]) - Math.max(rs[cur[0]][0], rs[cur[1]][0]);
 				long C = rs[cur[1]][1]-rs[cur[1]][0]-B;
 				long A = rs[cur[0]][1]-rs[cur[0]][0]-B;
 				long o = (A+B+C)*(A+B+C-1)/2+B*(B-1)/2-(A+B)*(A+B-1)/2-(B+C)*(B+C-1)/2;
 				x = (x + o * sw)%mod;
 				rs[cur[0]][2] -= sw;
 				rs[cur[1]][2] -= sw;
 				rs[p++] = new int[]{Math.min(rs[cur[0]][0], rs[cur[1]][0]), Math.max(rs[cur[0]][1], rs[cur[1]][1]), sw};
 				rs[p++] = new int[]{Math.max(rs[cur[0]][0], rs[cur[1]][0]), Math.min(rs[cur[0]][1], rs[cur[1]][1]), sw};
 				for(int i = 0;i < p-2;i++){
 					if(ok(rs[i], rs[p-2]))q.add(new int[]{i, p-2});
 					if(ok(rs[i], rs[p-1]))q.add(new int[]{i, p-1});
 				}
 			}
 		}
 		out.println(x);
 	}
 	
 	boolean ok(int[] a, int[] b){
 		if(a[2] > 0 && b[2] > 0 && Math.max(a[0], b[0]) <= Math.min(a[1], b[1])){
 			if(a[0] <= b[0] && b[1] <= a[1])return false;
 			if(b[0] <= a[0] && a[1] <= b[1])return false;
 			return true;
 		}
 		return false;
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
 //		{
 //			int n = 100, m = 100;
 //			Random gen = new Random();
 //			StringBuilder sb = new StringBuilder("1\r\n");
 //			sb.append(100 + " ");
 //			sb.append(n + " ");
 //			for(int i = 0;i < n;i++){
 //				int a = gen.nextInt(100)+1;
 //				int b = gen.nextInt(100)+1;
 //				if(a > b){
 //					int d = a; a = b; b = d;
 //				}
 //				sb.append(a + " ");
 //				sb.append(b + " ");
 //				sb.append(gen.nextInt(100)+1 + " ");
 //			}
 //			INPUT = sb.toString();
 //		}
 		
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
