import java.awt.geom.Line2D;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

// Solution
public class Solution {
	static InputStream is;
	static PrintWriter out;
	static String INPUT = "";
	
	static void solve()
	{
		for(int T = ni(), cas = 1;T > 0;T--,cas++){
			out.println("Case #" + cas + ":");
			double d = nd();
			
			double[][] xs = new double[11][];
			int p = 0;
			for(int i = -1;i <= 1;i+=2){
				for(int j = -1;j <= 1;j+=2){
					for(int k = -1;k <= 1;k+=2){
						xs[p++] = new double[]{i*0.5, j*0.5, k*0.5};
					}
				}
			}
			xs[p++] = new double[]{0.5, 0, 0};
			xs[p++] = new double[]{0, 0.5, 0};
			xs[p++] = new double[]{0, 0, 0.5};
			
			double[] ax = new double[]{1/Math.sqrt(2), 0, 1/Math.sqrt(2)};
			double low = 0, high = Math.PI/4;
			for(int rep = 0;rep < 50;rep++){
				double h = low + (high-low)/2;
				double[][] nx = rotateWithAxis(xs, ax, h);
				
				double[][] xz = new double[8][];
				for(int i = 0;i < 8;i++){
					xz[i] = new double[]{nx[i][0], nx[i][2]};
				}
				double ls = areaPoly(convexHull(xz));
				if(ls > d){
					high = h;
				}else{
					low = h;
				}
			}
			
			double[][] nx = rotateWithAxis(xs, ax, high);
			for(int i = 8;i < 11;i++){
				out.printf("%.14f %.14f %.14f\n", nx[i][0], nx[i][1], nx[i][2]);
			}
//			double[][] hull = convexHull(Arrays.copyOf(nx, 8));
//			tr(areaPoly(hull));
//			for(int i = 8;i < 11;i++){
//				for(int j = 8;j < 11;j++){
//					tr(i, j, dot(nx[i], nx[j]));
//				}
//			}
		}
	}
	
	public static double norm(double[] a) { return dot(a, a);}
	public static double dot(double[] a, double[] b) {return a[0]*b[0]+a[1]*b[1]+a[2]*b[2];}

	
	public static double areaPoly(double[][] poly)
	{
		int n = poly.length;
		double s = 0;
		for(int i = 0;i < n - 1;i++){
			s += (poly[i][0]*poly[i+1][1]-poly[i+1][0]*poly[i][1]) / 2;
		}
		s += (poly[n-1][0]*poly[0][1]-poly[0][0]*poly[n-1][1]) / 2;
		return Math.abs(s);
	}


	
	public static double[][] convexHull(double[][] co)
	{
		int n = co.length;
		if(n <= 1)return co;
		Arrays.sort(co, new Comparator<double[]>(){
			public int compare(double[] a, double[] b){
				if(a[0] - b[0] != 0)return (int)Math.signum(a[0] - b[0]);
				return (int)Math.signum(a[1] - b[1]);
			}
		});
		
		int[] inds = new int[n + 1];
		int p = 0;
		for(int i = 0;i < n;i++){
			if(p >= 1 && co[inds[p-1]][0] == co[i][0] && co[inds[p-1]][1] == co[i][1])continue;
			while(p >= 2 && Line2D.relativeCCW(
					co[inds[p-2]][0], co[inds[p-2]][1],
					co[inds[p-1]][0], co[inds[p-1]][1],
					co[i][0], co[i][1]) == 1)p--;
			inds[p++] = i;
		}
		
		int inf = p + 1;
		for(int i = n - 2;i >= 0;i--){
			if(co[inds[p-1]][0] == co[i][0] && co[inds[p-1]][1] == co[i][1])continue;
			while(p >= inf && Line2D.relativeCCW(
					co[inds[p-2]][0], co[inds[p-2]][1],
					co[inds[p-1]][0], co[inds[p-1]][1],
					co[i][0], co[i][1]) == 1)p--;
			inds[p++] = i;
		}
		
		double[][] ret = new double[p-1][];
		for(int i = 0;i < p-1;i++)ret[i] = co[inds[i]];
		return ret;
	}

	
	public static double[][] rotateWithAxis(double[][] xs, double[] axis, double angle)
	{
		double[][] ret = new double[xs.length][3];
		
		double ncos = Math.cos(angle);
		double nsin = Math.sin(angle);
		double scos = 1.0 - ncos;
		
		double sxy = axis[0] * axis[1] * scos;
		double syz = axis[1] * axis[2] * scos;
		double sxz = axis[0] * axis[2] * scos;
		double sz = nsin * axis[2];
		double sy = nsin * axis[1];
		double sx = nsin * axis[0];
		
		int p = 0;
		for(double[] x : xs){
			ret[p][0] = (ncos+axis[0]*axis[0]*scos)*x[0] + (-sz+sxy)*x[1]+(sy+sxz)*x[2];
			ret[p][1] = (sz+sxy)*x[0]+(ncos+axis[1]*axis[1]*scos)*x[1]+(-sx+syz)*x[2];
			ret[p][2] = (-sy+sxz)*x[0]+(sx+syz)*x[1]+(ncos+axis[2]*axis[2]*scos)*x[2];
			p++;
		}
		return ret;
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
