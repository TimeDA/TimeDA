package gcj2013.r2;
 import java.io.File;
 import java.io.PrintWriter;
 import java.text.SimpleDateFormat;
 import java.util.Arrays;
 import java.util.Date;
 import java.util.Scanner;
 
 public class B {
 	static String BASEPATH = "x:\\gcj\\";
 	static boolean LARGE = false;
 	static String INPATH = BASEPATH + B.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
 	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
 	
 	static String INPUT = "";
 	
 	public void call()
 	{
 		int n = ni(), P = ni();
 		out.println(count(n, P) + " " + count2(n, P));
 	}
 	
 	public int count(int n, int P)
 	{
 //		tr(n, P);
 		for(int j = (1<<n)-1;j >= 0;j--){
 			int k = 1;
 			for(int i = 1, f = j, l = 1<<n-1;;i *= 2, k += l, l /= 2){
 				if(f-i >= 0){
 					f -= i;
 				}else{
 					break;
 				}
 			}
 //			tr("s", j, k);
 			if(k <= P){
 				return j;
 			}
 		}
 		return 0;
 	}
 	
 	public int count2(int n, int P)
 	{
 //		tr(n, P);
 		for(int j = 0;j < 1<<n;j++){
 			int k = 1<<n;
 			for(int i = 1, f = (1<<n)-1-j;;i *= 2, k /= 2){
 				if(f-i >= 0){
 					f -= i;
 				}else{
 					break;
 				}
 			}
 //			tr("s", j, k);
 			if(k > P){
 				return j-1;
 			}
 		}
 		return (1<<n)-1;
 	}
 	
 	static boolean nextPermutation(int[] src) {
 		int i;
 		for(i = src.length - 2;i >= 0 && src[i] > src[i + 1];i--)
 			;
 		if(i == -1)
 			return false;
 		int j;
 		for(j = i + 1;j < src.length && src[i] < src[j];j++)
 			;
 		int d = src[i];
 		src[i] = src[j - 1];
 		src[j - 1] = d;
 		for(int p = i + 1, q = src.length - 1;p < q;p++, q--){
 			d = src[p];
 			src[p] = src[q];
 			src[q] = d;
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
