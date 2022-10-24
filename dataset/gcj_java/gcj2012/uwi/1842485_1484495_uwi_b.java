package gcj2012.r2;
 import java.awt.geom.Point2D;
 import java.io.File;
 import java.io.PrintWriter;
 import java.text.SimpleDateFormat;
 import java.util.Arrays;
 import java.util.Comparator;
 import java.util.Date;
 import java.util.Random;
 import java.util.Scanner;
 
 public class B {
 	static String BASEPATH = "x:\\gcj\\";
 	static boolean LARGE = false;
 	static String INPATH = BASEPATH + B.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt2.in");
 	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
 	
 	static String INPUT = "";
 //	static String INPUT = "2\r\n2 6 6 1 1 3 320 2 4 3 2";
 	
 	public void call()
 	{
 		int n = ni();
 		int w = ni(), l = ni();
 		int[][] r = new int[n][2];
 		for(int i = 0;i < n;i++){
 			r[i][0] = ni();
 			r[i][1] = i;
 		}
 		
 		Arrays.sort(r, new Comparator<int[]>() {
 			public int compare(int[] a, int[] b) {
 				return -(a[0] - b[0]);
 			}
 		});
 		
 		Random gen = new Random();
 		double[][] co = new double[n][2];
 		outer:
 		for(int u = 0;u < 1000000;u++){
 			middle:
 			for(int i = 0;i < n;i++){
 				inner:
 				for(int j = 0;j < 100;j++){
 					co[i][0] = gen.nextDouble() * w;
 					co[i][1] = gen.nextDouble() * l;
 					for(int k = 0;k < i;k++){
 						if(
 								(co[i][0] - co[k][0])*(co[i][0] - co[k][0]) +
 								(co[i][1] - co[k][1])*(co[i][1] - co[k][1]) 
 								<= (double)(r[i][0] + r[k][0]) * (r[i][0] + r[k][0]) + 1E-5){
 							continue inner;
 						}
 					}
 					continue middle;
 				}
 				continue outer;
 			}
 		
 			double[][] oco = new double[n][];
 			for(int i = 0;i < n;i++){
 				oco[r[i][1]] = co[i];
 			}
 			for(int i = 0;i < n;i++){
 				if(i > 0)out.print(" ");
 				out.printf("%.12f %.12f", oco[i][0], oco[i][1]);
 			}
 			out.println();
 			return;
 		}
 		out.println("DEAD!!!!!!");
 		tr("DEAD!");
 	}
 	
 	boolean check(double[][] co, int w, int l, int[] r)
 	{
 		int n = co.length;
 		for(int i = 0;i < n;i++){
 			if(co[i][0] >= 0 && co[i][0] <= w && co[i][1] >= 0 && co[i][1] <= l){
 			}else{
 				return false;
 			}
 		}
 		for(int i = 0;i < n;i++){
 			for(int j = i+1;j < n;j++){
 				if(Point2D.distance(co[i][0], co[i][1], co[j][0], co[j][1]) <= r[i] + r[j] + 1E-9){
 					return false;
 				}
 			}
 		}
 		return true;
 	}
 	
 	Scanner in;
 	PrintWriter out;
 	int cas;
 	
 	public B(int cas, Scanner in, PrintWriter out)
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
 			new B(i+1, in, out).call();
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
