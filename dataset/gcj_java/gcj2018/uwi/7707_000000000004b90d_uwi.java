
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
			
			int[][] co = new int[n][];
			
			for(int i = 0;i < n;i++){
				co[i] = new int[]{ni(), ni(), ni(), i};
			}
			if(n <= 3){
				for(int i = 1;i <= n;i++){
					if(i > 1)out.print(" ");
					out.print(i);
				}
				continue;
			}
			
			int[][] my = Arrays.copyOf(co, 4);
			for(int i = 3;i < n;i++){
				my[3] = co[i];
				if(above(my))continue;
				{int[] d = my[0]; my[0] = my[3]; my[3] = d;}
				if(above(my))continue;
				{int[] d = my[0]; my[0] = my[3]; my[3] = d;}
				{int[] d = my[1]; my[1] = my[3]; my[3] = d;}
				if(above(my))continue;
				{int[] d = my[1]; my[1] = my[3]; my[3] = d;}
				{int[] d = my[2]; my[2] = my[3]; my[3] = d;}
				if(above(my))continue;
				{int[] d = my[2]; my[2] = my[3]; my[3] = d;}
//				throw new RuntimeException();
				return;
			}
			
			boolean[] used = new boolean[n];
			int[][] anss = new int[n][];
			for(int i = 0;i < 3;i++){
				used[my[i][3]] = true;
				anss[n-1-i] = my[i];
			}
			for(int i = 3;i < n;i++){
				inner:
				for(int j = 0;j < n;j++){
					if(!used[j]){
						my[i%3] = co[j];
						for(int k = 0;k < n;k++){
							if(!used[k] && j != k){
								my[3] = co[k];
								if(!above(my))continue inner;
							}
						}
						
						used[j] = true;
						anss[n-1-i] = co[j];
						break;
					}
				}
			}
			
			for(int i = 0;i < n;i++){
				if(i > 0)out.print(" ");
				out.print(anss[i][3]+1);
			}
			out.println();
		}
	}
	
	static boolean above(int[][] co)
	{
		// a(x1,y1)+b(x2,y2)=(x,y)
		// (x1 x2)
		// (y1 y2)
		
		double x1 = co[1][0] - co[0][0];
		double y1 = co[1][1] - co[0][1];
		double z1 = co[1][2] - co[0][2];
		double x2 = co[2][0] - co[0][0];
		double y2 = co[2][1] - co[0][1];
		double z2 = co[2][2] - co[0][2];
		double x = co[3][0] - co[0][0];
		double y = co[3][1] - co[0][1];
		double D = x1*y2-x2*y1;
		if(Math.abs(D) < 1e-10)D = 1;
		double A = (y2*x-x2*y)/D;
		double B = (-y1*x+x1*y)/D;
		
		return z1*A+z2*B+co[0][2] > co[3][2];
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
