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
//	static String INPUT = "1 3 3 WBB WBB BWW";
//	static String INPUT = "1 3 3 WWW WWW WWW";
	static String INPUT = "";
	
	// WBBB
	// WBBW
	// WBWW
	
	static void solve()
	{
		for(int T = ni(), cas = 1;T > 0;T--,cas++){
			out.print("Case #" + cas + ": ");
			int n = ni(), m = ni();
			char[][] map = nm(n, m);
			// BB    BB
			// BW or BB
			int ans = analyzeS(map);;
			ans = Math.max(ans, analyze(map));
			ans = Math.max(ans, analyze(map = rot(map)));
			ans = Math.max(ans, analyze(map = rot(map)));
			ans = Math.max(ans, analyze(map = rot(map)));
			ans = Math.max(ans, analyzeLR(map));
			ans = Math.max(ans, analyzeLR(map = rot(map)));
			ans = Math.max(ans, analyzeLR(map = rot(map)));
			ans = Math.max(ans, analyzeLR(map = rot(map)));
			
			// WB
			// BW
			ans = Math.max(ans, analyze2(map));
			ans = Math.max(ans, analyze2(map = rot(map)));
			out.println(ans);
		}
	}
	
	static int analyzeS(char[][] map)
	{
		int n = map.length, m = map[0].length;
		int ret = 0;
		for(char c : "BW".toCharArray()){
			for(int i = 0;i < n;i++){
				for(int j = 0;j < m;j++){
					
					boolean[][] ok = new boolean[n][m];
					for(int k = 0;k < n;k++){
						for(int l = 0;l < m;l++){
							ok[k][l] = map[k][l] == c;
						}
					}
					ret = Math.max(ret, go(ok));
					
				}
			}
		}
		return ret;
	}
	
	
	static int analyze(char[][] map)
	{
		int n = map.length, m = map[0].length;
		int ret = 0;
		for(char c : "BW".toCharArray()){
			boolean ex = false;
			for(int i = 0;i < n-1;i++){
				for(int j = 0;j < m-1;j++){
					if(
							map[i][j] == 'B'+'W'-c &&
							map[i][j+1] == 'B'+'W'-c &&
							map[i+1][j] == 'B'+'W'-c &&
							map[i+1][j+1] == c){
						ex = true;
					}
				}
			}
			if(!ex)continue;
			
			for(int i = 0;i < n;i++){
				for(int j = 0;j < m;j++){
					
					boolean[][] ok = new boolean[n][m];
					for(int k = 0;k < n;k++){
						for(int l = 0;l < m;l++){
							if(k >= i && l >= j){
								ok[k][l] = map[k][l] == c;
							}else{
								ok[k][l] = map[k][l] == 'B'+'W'-c;
							}
						}
					}
					ret = Math.max(ret, go(ok));
					
				}
			}
		}
		return ret;
	}
	
	static int analyzeLR(char[][] map)
	{
		int n = map.length, m = map[0].length;
		int ret = 0;
		for(char c : "BW".toCharArray()){
			boolean ex = false;
			for(int i = 0;i < n;i++){
				for(int j = 0;j < m-1;j++){
					if(
							map[i][j] == 'B'+'W'-c &&
							map[i][j+1] == c){
						ex = true;
					}
				}
			}
			if(!ex)continue;
			
			for(int j = 0;j < m;j++){
				
				boolean[][] ok = new boolean[n][m];
				for(int k = 0;k < n;k++){
					for(int l = 0;l < m;l++){
						if(l >= j){
							ok[k][l] = map[k][l] == c;
						}else{
							ok[k][l] = map[k][l] == 'B'+'W'-c;
						}
					}
				}
				ret = Math.max(ret, go(ok));
				
			}
		}
		return ret;
	}
	
	static int analyze2(char[][] map)
	{
		int n = map.length, m = map[0].length;
		int ret = 0;
		for(char c : "BW".toCharArray()){
			boolean ex = false;
			for(int i = 0;i < n-1;i++){
				for(int j = 0;j < m-1;j++){
					if(
							map[i][j] == c &&
							map[i][j+1] == 'B'+'W'-c &&
							map[i+1][j] == 'B'+'W'-c &&
							map[i+1][j+1] == c){
						ex = true;
					}
				}
			}
			if(!ex)continue;
			for(int i = 0;i < n;i++){
				for(int j = 0;j < m;j++){
					
					boolean[][] ok = new boolean[n][m];
					for(int k = 0;k < n;k++){
						for(int l = 0;l < m;l++){
							if(k >= i && l >= j || k < i && l < j){
								ok[k][l] = map[k][l] == c;
							}else{
								ok[k][l] = map[k][l] == 'B'+'W'-c;
							}
						}
					}
					ret = Math.max(ret, go(ok));
					
				}
			}
		}
		return ret;
	}
	
	static int go(boolean[][] ok)
	{
		int n = ok.length, m = ok[0].length;
		DJSet ds = new DJSet(n*m);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(j+1 < m && ok[i][j] && ok[i][j+1]){
					ds.union(i*m+j, i*m+j+1);
				}
				if(i+1 < n && ok[i][j] && ok[i+1][j]){
					ds.union(i*m+j, (i+1)*m+j);
				}
			}
		}
		int ret = 0;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(ok[i][j] && ds.upper[i*m+j] < 0){
					ret = Math.max(ret, -ds.upper[i*m+j]);
				}
			}
		}
		return ret;
	}
	
	public static void tf(boolean[]... b)
	{
		for(boolean[] r : b) {
			for(boolean x : r)System.out.print(x?'#':'.');
			System.out.println();
		}
		System.out.println();
	}

	
	public static class DJSet {
		public int[] upper;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
		}

		public int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		public boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		public boolean union(int x, int y) {
			x = root(x);
			y = root(y);
			if (x != y) {
				if (upper[y] < upper[x]) {
					int d = x;
					x = y;
					y = d;
				}
				upper[x] += upper[y];
				upper[y] = x;
			}
			return x == y;
		}

		public int count() {
			int ct = 0;
			for (int u : upper)
				if (u < 0)
					ct++;
			return ct;
		}
	}

	
	public static char[][] rot(char[][] a)
	{
		int n = a.length, m = a[0].length;
		char[][] b = new char[m][n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				b[j][n-1-i] = a[i][j];
			}
		}
		return b;
	}

	
	public static void main(String[] args) throws Exception
	{
//		int n = 20, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(100 + " ");
//		for(int rep = 0;rep < 100;rep++){
//			sb.append(n + " ");
//			sb.append(n + " ");
//			for (int i = 0; i < n; i++) {
//				for(int j = 0;j < n;j++){
//					sb.append("BW".charAt(gen.nextInt(2)));
//				}
//				sb.append("\n");
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
