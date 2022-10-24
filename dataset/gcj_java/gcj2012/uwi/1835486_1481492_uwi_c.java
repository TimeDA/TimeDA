package gcj2012.r3;
 import java.io.File;
 import java.io.PrintWriter;
 import java.text.SimpleDateFormat;
 import java.util.Arrays;
 import java.util.Comparator;
 import java.util.Date;
 import java.util.Scanner;
 
 public class C {
 	static String BASEPATH = "x:\\";
 	static boolean LARGE = false;
 	static String INPATH = BASEPATH + C.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
 	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
 	
 	static String INPUT = "";
 	
 	public void call()
 	{
 		int m = ni(), f = ni(), n = ni();
 		int[][] mi = new int[n][];
 		for(int i = 0;i < n;i++){
 			mi[i] = new int[]{ni(), ni()};
 		}
 		Arrays.sort(mi, new Comparator<int[]>() {
 			public int compare(int[] a, int[] b) {
 				return a[1] - b[1];
 			}
 		});
 		long[] ds = new long[m+2];
 		int j = n-1;
 		long min = Integer.MAX_VALUE;
 		for(int i = m+1;i >= 0;i--){
 			while(j >= 0 && mi[j][1] >= i){
 				min = Math.min(min, mi[j][0]);
 				j--;
 			}
 			ds[i] = min;
 		}
 		
 		ds[0] += f;
 		for(int i = 1;i <= m+1;i++){
 			ds[i] += ds[i-1];
 		}
 		long day = 0;
 		while(m > 0){
 			int ind = Arrays.binarySearch(ds, m);
 			if(ind == -1)break;
 			if(ind < 0)ind = -ind-2;
 			m -= ds[ind];
 			day += ind+1;
 		}
 		out.println(day);
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
