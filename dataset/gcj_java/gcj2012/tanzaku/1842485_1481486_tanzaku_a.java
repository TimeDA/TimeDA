package R2;
 import java.io.*;
 import java.math.*;
 import java.util.*;
 
 
 public class A {
 	static void start() throws IOException {
 		new A().run1();
 	}
 	
 	private final String dir = "D:\\contest\\gcj\\2012\\" + getClass().getPackage().toString().split(" ")[1] + "\\" + getClass().getSimpleName();
 	private final String inputFileName = "A-small-attempt0.in";
 //	private final String inputFileName = "C-large.in";
 	private final String outputFileName = "res.txt";
 
 	int n, D;
 	int[] d, l;
 	
 	void run() throws IOException {
 		n = IOFast.nextInt();
 		d = new int[n];
 		l = new int[n];
 		for(int i = 0; i < n; i++) {
 			d[i] = IOFast.nextInt();
 			l[i] = IOFast.nextInt();
 		}
 		D = IOFast.nextInt();
 		
 		int max = 0;
 		int[] dp = new int[n];
 		dp[0] = d[0];
 		for(int i = 0; i < n; i++) {
 			max = Math.max(d[i] + dp[i], max);
 			for(int j = i + 1; j < n; j++) {
 				if(dp[i] + d[i] >= d[j]) {
 					dp[j] = Math.min(l[j], Math.max(dp[j], d[j] - d[i]));
 				}
 			}
 		}
 		
 		IOFast.out.println(max >= D ? "YES" : "NO");
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
