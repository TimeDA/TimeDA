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
		outer:
		for(int T = ni(), cas = 1;T > 0;T--,cas++){
			out.print("Case #" + cas + ": ");
			int R = ni(), C = ni(), H = ni(), V = ni();
			char[][] map = nm(R, C);
			int at = 0;
			for(int i = 0;i < R;i++){
				for(int j = 0;j < C;j++){
					if(map[i][j] == '@'){
						at++;
					}
				}
			}
			if(at % ((H+1)*(V+1)) != 0){
				out.println("IMPOSSIBLE");
				continue;
			}
			at /= (H+1)*(V+1);
			int[] cutsh = new int[H+2];
			int[] cutsv = new int[V+2];
			{
				int num = 0;
				int cut = 0;
				cutsh[cut++] = -1;
				for(int i = 0;i < R;i++){
					for(int j = 0;j < C;j++){
						if(map[i][j] == '@')num++;
					}
					if(num == at * (V+1)){
						cutsh[cut++] = i;
						if(cut > H)break;
						num = 0;
					}
				}
				cutsh[H+1] = R-1;
			}
			{
				int num = 0;
				int cut = 0;
				cutsv[cut++] = -1;
				for(int i = 0;i < C;i++){
					for(int j = 0;j < R;j++){
						if(map[j][i] == '@')num++;
					}
					if(num == at * (H+1)){
						cutsv[cut++] = i;
						if(cut > V)break;
						num = 0;
					}
				}
				cutsv[V+1] = C-1;
			}
			
			for(int i = 0;i <= H;i++){
				for(int j = 0;j <= V;j++){
					int my = 0;
					for(int k = cutsh[i]+1;k <= cutsh[i+1];k++){
						for(int l = cutsv[j]+1;l <= cutsv[j+1];l++){
							if(map[k][l] == '@')my++;
						}
					}
					if(my != at){
						out.println("IMPOSSIBLE");
						continue outer;
					}
				}
			}
			out.println("POSSIBLE");
		}
	}
	
	public static void main(String[] args) throws Exception
	{
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
