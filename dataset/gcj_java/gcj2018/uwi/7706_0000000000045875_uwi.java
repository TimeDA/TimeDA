import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

// Solution
public class Solution {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static void solve()
	{
		for(int T = ni(), cas = 1;T > 0;T--,cas++){
			out.print("Case #" + cas + ": ");
			int n = ni();
			int[][] a = new int[n][];
			for(int i = 0;i < n;i++){
				a[i] = na(n);
			}
			int[] from = new int[n*n];
			int[] to = new int[n*n];
			int ans = n*n;
			for(int i = -n;i <= n;i++){
				int p = 0;
				for(int j = 0;j < n;j++){
					for(int k = 0;k < n;k++){
						if(a[j][k] == i){
							from[p] = j;
							to[p] = k;
							p++;
						}
					}
				}
				if(p == 0)continue;
				int[][] g = packD(n, from, to, p);
				int mat = doBipartiteMatchingHK(g, n);
				ans -= mat;
			}
			out.println(ans);
		}
	}
	
	public static int[][] packD(int n, int[] from, int[] to){ return packD(n, from, to, from.length);}
	public static int[][] packD(int n, int[] from, int[] to, int sup)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < sup;i++){
			g[from[i]][--p[from[i]]] = to[i];
		}
		return g;
	}

	
	
	
	public static int doBipartiteMatchingHK(int[][] g, int m)
	{
		int n = g.length;
		if(n == 0)return 0;
		int[] from = new int[m];
		int[] to = new int[n];
		Arrays.fill(to, -1);
		Arrays.fill(from, n);
		
		int[] d = new int[n+1];
		int mat = 0;
		while(true){
			Arrays.fill(d, -1);
			int[] q = new int[n];
			int r = 0;
			for(int i = 0;i < n;i++){
				if(to[i] == -1){
					d[i] = 0;
					q[r++] = i;
				}
			}
			
			for(int p = 0;p < r;p++) {
				int cur = q[p];
				for(int adj : g[cur]){
					int nex = from[adj];
					if(d[nex] == -1) {
						if(nex != n)q[r++] = nex;
						d[nex] = d[cur] + 1;
					}
				}
			}
			if(d[n] == -1)break;
			
			for(int i = 0;i < n;i++){
				if(to[i] == -1){
					if(dfsHK(d, g, n, m, to, from, i))mat++;
				}
			}
		}
		return mat;
	}
	
	static boolean dfsHK(int[] d, int[][] g, int n, int m, int[] to, int[] from, int cur)
	{
		if(cur == n)return true;
		for(int adj : g[cur]){
			int nex = from[adj];
			if(d[nex] == d[cur] + 1 && dfsHK(d, g, n, m, to, from, nex)){
				to[cur] = adj;
				from[adj] = cur;
				return true;
			}
		}
		d[cur] = -1;
		return false;
	}
	
	public static void main(String[] args) throws Exception
	{
//		int n = 100, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(100 + " ");
//		for(int o = 0;o < 100;o++){
//			sb.append(n + " ");
//			for (int i = 0; i < n*n; i++) {
//				sb.append((gen.nextInt(n)+1)*(gen.nextBoolean()  ? -1 : 1) + " ");
//			}
//		}
//		INPUT = sb.toString();

		
		long S = System.currentTimeMillis();
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
		long G = System.currentTimeMillis();
		tr(G-S+"ms");
	}
	
	private static boolean eof()
	{
		if(lenbuf == -1)return true;
		int lptr = ptrbuf;
		while(lptr < lenbuf)if(!isSpaceChar(inbuf[lptr++]))return false;
		
		try {
			is.mark(1000);
			while(true){
				int b = is.read();
				if(b == -1){
					is.reset();
					return true;
				}else if(!isSpaceChar(b)){
					is.reset();
					return false;
				}
			}
		} catch (IOException e) {
			return true;
		}
	}
	
	private static byte[] inbuf = new byte[1024];
	static int lenbuf = 0, ptrbuf = 0;
	
	private static int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private static boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
//	private static boolean isSpaceChar(int c) { return !(c >= 32 && c <= 126); }
	private static int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private static double nd() { return Double.parseDouble(ns()); }
	private static char nc() { return (char)skip(); }
	
	private static String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private static char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private static char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private static int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private static int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private static long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private static void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}
