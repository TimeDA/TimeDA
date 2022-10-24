package R2;
 import java.io.*;
 import java.math.*;
 import java.util.*;
 
 
 public class B {
 	static void start() throws IOException {
 		new B().run1();
 	}
 	
 	private final String dir = "D:\\contest\\gcj\\2012\\" + getClass().getPackage().toString().split(" ")[1] + "\\" + getClass().getSimpleName();
 	private final String inputFileName = "B-small-attempt1.in";
 //	private final String inputFileName = "C-large.in";
 	private final String outputFileName = "res.txt";
 
 	int n, count;
 	long W, L;
 	long[] r;
 	int[][] rr;
 	boolean[] used;
 	long[] x, y;
 	
 	void dfs(long x0, long y0, long x1, long y1) {
 //		System.err.println(x0 + " " + y0 + ": " + x1 + " " + y1);
 		if(x0 > x1 || y0 > y1) return;
 //		final int mulx = x0 == 0 ? 1 : 2;
 //		final int muly = y0 == 0 ? 1 : 2;
 		for(int i = 0; i < used.length; i++) {
 			if(used[i]) continue;
 			
 			int mulx = 2;
 			if(x0 == 0 && x1 == W) {
 				mulx = 0;
 			}
 			else if(x0 == 0 || x1 == W) {
 				mulx = 1;
 			}
 			
 			int muly = 2;
 			if(y0 == 0 && y1 == L) {
 				muly = 0;
 			}
 			else if(y0 == 0 || y1 == L) {
 				muly = 1;
 			}
 			
 			if(x1 - x0 >= mulx * r[i] && y1 - y0 >= muly * r[i]) {
 				x[i] = x0 + (x0 == 0 ? 0 : r[i]);
 				y[i] = y0 + (y0 == 0 ? 0 : r[i]);
 				if(x[i] > W || y[i] > L) continue;
 				used[i] = true;
 				final int mx = x0 == 0 ? 1 : 2;
 				final int my = y0 == 0 ? 1 : 2;
 				dfs(x0+mx*r[i], y0,           x1,           y0+my*r[i]);
 				dfs(x0,           y0+my*r[i], x0+mx*r[i], y1);
 				dfs(x0+mx*r[i], y0+my*r[i], x1, y1);
 				return;
 			}
 		}
 	}
 	
 	void run() throws IOException {
 		n = IOFast.nextInt();
 		W = IOFast.nextLong();
 		L = IOFast.nextLong();
 		rr = new int[n][2];
 		int[] rev = new int[n];
 		r = new long[n];
 		x = new long[n];
 		y = new long[n];
 		used = new boolean[n];
 		for(int i = 0; i < n; i++) {
 			rr[i][1] = i;
 			rr[i][0] = IOFast.nextInt();
 		}
 		Arrays.sort(rr, new Comparator<int[]>() {
 			@Override
 			public int compare(int[] arg0, int[] arg1) {
 				return arg1[0] - arg0[0];
 			}
 		});
 		
 		for(int i = 0; i < n; i++) {
 			r[i] = rr[i][0];
 			rev[rr[i][1]] = i;
 		}
 		
 		Random random = new Random();
 		LOOP: while(true) {
 			dfs(0, 0, W, L);
 			for(int i = 0; i < n; i++) {
 				if(!used[i]) {
 //					System.err.println("CANNOT!!!!");
 //					IOFast.out.println("");
 //					if(true) return;
 					for(int j = 0; j < 10; j++) {
 						final int a = random.nextInt(n);
 						final int b = random.nextInt(n);
 						long t = r[a]; r[a] = r[b]; r[b] = t;
 						int[] u = rr[a]; rr[a] = rr[b]; rr[b] = u;
 						int v = rev[a]; rev[a] = rev[b]; rev[b] = v;
 					}
 					Arrays.fill(used, false);
 					continue LOOP;
 				}
 			}
 			break;
 		}
 		
 		for(int i = 0; i < n; i++) {
 			if(x[i] < 0 || x[i] > W || y[i] < 0 || y[i] > L) {
 				IOFast.out.println("CRAZY!!! " + rev[i] + " " + x[i] + " " + y[i]);
 			}
 			for(int j = i + 1; j < n; j++) {
 				if(Math.abs(x[i]-x[j]) < r[i] + r[j] && Math.abs(y[i]-y[j]) < r[i] + r[j]) {
 					IOFast.out.println("CRAZY!!! " + rev[i] + " " + rev[j] + ": " + x[i] + " " + y[i] + " = " + x[j] + " " + y[j]);
 				}
 			}
 			
 			IOFast.out.print(x[rev[i]] + " " + y[rev[i]]);
 			if(i != n-1) {
 				IOFast.out.print(" ");
 			}
 		}
 		IOFast.out.println("");
 	}
 
 	void run1() throws IOException {
 		IOFast.setReader(new FileReader(dir + "\\" + inputFileName));
 		IOFast.setWriter(new FileWriter(dir + "\\" + outputFileName));
 		int T = IOFast.nextInt();
 		while(T-- != 0) {
 			printCase();
 			run();
 		}
 	}
 	
 	private static int CASE;
 	private static void printCase() {
 		IOFast.out.print("Case #" + ++CASE + ": ");
 		System.err.println("Done: Case #" + CASE);
 	}
 	
 	public static void main(String[] args) throws IOException {
 		start();
 		IOFast.out.flush();
 		IOFast.in.close();
 		IOFast.out.close();
 	}
 
 	static
 	public class IOFast {
 		private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
 		private static PrintWriter out = new PrintWriter(System.out);
 
 		//	private static final int BUFFER_SIZE = 50 * 200000;
 		private static final StringBuilder buf = new StringBuilder();
 		private static boolean[] isDigit = new boolean[256];
 		private static boolean[] isSpace = new boolean[256];
 
 		static {
 			for(int i = 0; i < 10; i++) {
 				isDigit['0' + i] = true;
 			}
 			isDigit['-'] = true;
 			isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true;
 		}
 
 		static boolean endInput;
 		
 		public static void setReader(Reader r) { in = new BufferedReader(r); }
 		public static void setWriter(Writer w) { out = new PrintWriter(w); }
 
 		private static int nextInt() throws IOException {
 			boolean plus = false;
 			int ret = 0;
 			while(true) {
 				final int c = in.read();
 
 				if(c == -1) {
 					endInput = true;
 					return Integer.MIN_VALUE;
 				}
 
 				if(isDigit[c]) {
 					if(c != '-') {
 						plus = true;
 						ret = c - '0';
 					}
 					break;
 				}
 			}
 
 			while(true) {
 				final int c = in.read();
 				if(c == -1 || !isDigit[c]) {
 					break;
 				}
 				ret = ret * 10 + c - '0';
 			}
 
 			return plus ? ret : -ret;
 		}
 
 		private static long nextLong() throws IOException {
 			boolean plus = false;
 			long ret = 0;
 			while(true) {
 				final int c = in.read();
 
 				if(c == -1) {
 					endInput = true;
 					return Integer.MIN_VALUE;
 				}
 
 				if(isDigit[c]) {
 					if(c != '-') {
 						plus = true;
 						ret = c - '0';
 					}
 					break;
 				}
 			}
 
 			while(true) {
 				final int c = in.read();
 				if(c == -1 || !isDigit[c]) {
 					break;
 				}
 				ret = ret * 10 + c - '0';
 			}
 
 			return plus ? ret : -ret;
 		}
 
 
 
 		private static String next() throws IOException {
 			buf.setLength(0);
 
 			while(true) {
 				final int c = in.read();
 
 				if(c == -1) {
 					endInput = true;
 					return "-1";
 				}
 
 				if(!isSpace[c]) {
 					buf.append((char)c);
 					break;
 				}
 			}
 
 			while(true) {
 				final int c = in.read();
 
 				if(c == -1 || isSpace[c]) {
 					break;
 				}
 				buf.append((char)c);
 			}
 
 			return buf.toString();
 		}
 
 		private static double nextDouble() throws IOException {
 			return Double.parseDouble(next());
 		}
 
 	}
 }
