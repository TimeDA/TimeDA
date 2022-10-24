package gcj2012.r2;
 import java.io.File;
 import java.io.PrintWriter;
 import java.text.SimpleDateFormat;
 import java.util.Arrays;
 import java.util.Date;
 import java.util.Random;
 import java.util.Scanner;
 
 public class C {
 	static String BASEPATH = "x:\\gcj\\";
 	static boolean LARGE = false;
 	static String INPATH = BASEPATH + C.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt3.in");
 	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
 	
 	static String INPUT = "";
 	
 	public void call()
 	{
 		int n = ni();
 		int[] v = new int[n-1];
 		for(int i = 0;i < n-1;i++)v[i] = ni();
 		Random gen = new Random();
 		int[] h = new int[n];
 		outer:
 		for(int u = 0;u < 1000000;u++){
 			for(int i = n-1, w = 2;i >= 0;i--,w*=4){
 				int ch;
 				inner:
 				for(ch = 0;ch < 10;ch++){
 					h[i] = gen.nextInt(w)*(1<<(11+i-(n-1))*2)+1;
 					if(i == n-1)break;
 					int max = i+1;
 					for(int j = i+2;j < n;j++){
 						int num = h[j]-h[i];
 						int den = j-i;
 						// y/x<num/den
 						// y*den-num*x<0
 						if((long)(h[max]-h[i]) * den - (long)num * (max-i) < 0){
 							max = j;
 						}
 					}
 					if(max+1 != v[i])continue inner;
 					break;
 				}
 				if(ch == 10)continue outer;
 			}
 			
 			for(int i = 0;i < n;i++){
 				if(i > 0)out.print(" ");
 				out.print(h[i]);
 			}
 			out.println();
 			return;
 		}
 		out.println("Impossible");
 	}
 	
 	Scanner in;
 	PrintWriter out;
 	int cas;
 	
 	public C(int cas, Scanner in, PrintWriter out)
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
 			new C(i+1, in, out).call();
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
