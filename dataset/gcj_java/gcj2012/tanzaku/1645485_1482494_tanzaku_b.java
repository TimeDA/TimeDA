package R1A;
 import java.io.*;
 import java.math.*;
 import java.util.*;
 
 import R1A.A.IOFast;
 
 
 public class B {
 	static void start() throws IOException {
 		new B().run1();
 	}
 	
 	private final String dir = "D:\\contest\\gcj\\2012\\" + getClass().getPackage().toString().split(" ")[1] + "\\" + getClass().getSimpleName();
 //	private final String inputFileName = "sample.txt";
 	private final String inputFileName = "B-small-attempt4.in";
 	private final String outputFileName = "res.txt";
 
 	
 	void solve() throws IOException {
 		final int n = IOFast.nextInt();
 		final int[][] a = new int[n][2];
 		
 		for(int i = 0; i < n; i++) {
 			for(int j = 0; j < 2; j++) {
 				a[i][j] = IOFast.nextInt();
 			}
 		}
 
 		Arrays.sort(a, new Comparator<int[]>() {
 			@Override
 			public int compare(int[] o1, int[] o2) {
 				if(o1[1] != o2[1]) return o1[1] - o2[1];
 				return o2[0] - o1[0];
 			}
 		});
 		
 		int res = 0;
 		for(int i = 0, s = 0; i < n; i++) {
 			for(int j = n - 1; j >= i && s < a[i][1]; j--) {
 				if(s >= a[j][0]) {
 					s++;
 					res++;
 					a[j][0] = Integer.MAX_VALUE;
 					j = n;
 				}
 			}
 			if(s < a[i][1]) {
 				IOFast.out.printf("Too Bad\r\n");
 				return;
 			}
 			s += 1 + (a[i][0] != Integer.MAX_VALUE ? 1 : 0);
 			res++;
 		}
 		
 		IOFast.out.printf("%d\r\n", res);
 	}
 	
 	void run() throws IOException {
 		int T = IOFast.nextInt();
 		while(T-- != 0) {
 			printCase();
 			solve();
 		}
 	}
 
 	void run1() throws IOException {
 		IOFast.setReader(new FileReader(dir + "\\" + inputFileName));
 		IOFast.setWriter(new FileWriter(dir + "\\" + outputFileName));
 		run();
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
