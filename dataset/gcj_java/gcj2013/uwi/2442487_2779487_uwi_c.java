package gcj2013.r2;
 import java.io.File;
 import java.io.PrintWriter;
 import java.text.SimpleDateFormat;
 import java.util.ArrayList;
 import java.util.Arrays;
 import java.util.Date;
 import java.util.List;
 import java.util.Scanner;
 
 public class C {
 	static String BASEPATH = "x:\\gcj\\";
 	static boolean LARGE = false;
 	static String INPATH = BASEPATH + C.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt1.in");
 	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
 	
 	static String INPUT = "";
 	
 	public void call()
 	{
 		int n = ni();
 		a = new int[n];
 		for(int i = 0;i < n;i++){
 			a[i] = ni();
 		}
 		b = new int[n];
 		for(int i = 0;i < n;i++){
 			b[i] = ni();
 		}
 		boolean[][] g = new boolean[n][n]; // bigger
 		for(int i = 0;i < n;i++){
 			boolean l = true;
 			for(int j = i-1;j >= 0;j--){
 				if(a[j] >= a[i]){
 					g[i][j] = true;
 				}
 				if(a[j] == a[i]-1 && l){
 					g[j][i] = true;
 					l = false;
 				}
 			}
 		}
 		for(int i = 0;i < n;i++){
 			boolean l = true;
 			for(int j = i+1;j < n;j++){
 				if(b[i] <= b[j]){
 					g[i][j] = true;
 				}
 				if(b[j] == b[i]-1 && l){
 					g[j][i] = true;
 					l = false;
 				}
 			}
 		}
 		
 		for(int k = 0;k < n;k++){
 			for(int i = 0;i < n;i++){
 				for(int j = 0;j < n;j++){
 					g[i][j] |= g[i][k] & g[k][j];
 				}
 			}
 		}
 //		for(int i = 0;i < n;i++){
 //			tr(g[i]);
 //		}
 		
 		int[] inf = new int[n];
 		int[] sup = new int[n];
 		for(int i = 0;i < n;i++){
 			sup[i] = n;
 			inf[i] = 1;
 			for(int j = 0;j < n;j++){
 				if(g[i][j]){
 					sup[i]--;
 				}
 				if(g[j][i]){
 					inf[i]++;
 				}
 			}
 		}
 		tr(inf);
 		tr(sup);
 		hist = new int[n];
 		dfs(inf, sup, 0, 0);
 	}
 	
 	int[] hist;
 	int[] a, b;
 	
 	public boolean dfs(int[] inf, int[] sup, int pos, int mask){
 		int n = inf.length;
 		if(pos == n){
 			int[] dp = new int[n];
 			for(int i = 0;i < n;i++){
 				int max = 0;
 				for(int j = 0;j < i;j++){
 					if(hist[j] < hist[i]){
 						max = Math.max(max, dp[j]);
 					}
 				}
 				dp[i] = max + 1;
 				if(dp[i] != a[i])return false;
 			}
 			Arrays.fill(dp, 0);
 			for(int i = n-1;i >= 0;i--){
 				int max = 0;
 				for(int j = i+1;j < n;j++){
 					if(hist[i] > hist[j]){
 						max = Math.max(max, dp[j]);
 					}
 				}
 				dp[i] = max + 1;
 				if(dp[i] != b[i])return false;
 			}
 			for(int i = 0;i < hist.length;i++){
 				if(i > 0)out.print(" ");
 				out.print(hist[i]);
 			}
 			out.println();
 			return true;
 		}
 		
 		for(int i = inf[pos];i <= sup[pos];i++){
 			if(mask<<31-(i-1)>=0){
 				hist[pos] = i;
 				boolean res = dfs(inf, sup, pos+1, mask|1<<(i-1));
 				if(res)return true;
 			}
 		}
 		return false;
 	}
 	
 	List<int[]> make(int L, int[] a)
 	{
 		List<int[]> ll = new ArrayList<int[]>();
 		if(L == 0){
 			ll.add(new int[0]);
 			return ll;
 		}
 		int[] ol = new int[L];
 		for(int i = 0;i < L;i++)ol[i] = i;
 		outer:
 		do{
 			int[] dp = new int[L];
 			for(int i = 0;i < L;i++){
 				int base = 0;
 				for(int j = 0;j < i;j++){
 					if(ol[j] < ol[i]){
 						base = Math.max(base, dp[j]);
 					}
 				}
 				dp[i] = base + 1;
 				if(dp[i] != a[i])continue outer;
 			}
 			ll.add(Arrays.copyOf(ol, L));
 		}while(nextPermutation(ol));
 		return ll;
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
