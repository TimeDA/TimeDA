package Qual;
 import java.io.*;
 import java.math.*;
 import java.util.*;
 
 
 public class A {
 	static void start() throws IOException {
 		new A().run1();
 	}
 	
 	private final String dir = "D:\\contest\\gcj\\2012\\" + getClass().getPackage().toString().split(" ")[1] + "\\" + getClass().getSimpleName();
 	private final String inputFileName = "A-small-attempt1.in";
 	private final String outputFileName = "res.txt";
 	
 	private String[] from = new String[] {
 			"ejp mysljylc kd kxveddknmc re jsicpdrysi",
 			"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
 			"de kr kd eoya kw aej tysr re ujdr lkgc jv",
 	};
 	private String[] to = new String[] {
 			"our language is impossible to understand",
 			"there are twenty six factorial possibilities",
 			"so it is okay if you want to just give up",
 	};
 	private char[] map = new char[256];
 
 	void run() throws IOException {
 		/*
 		Set<Character> cs = new TreeSet<Character>();
 		for(char c = 'a'; c <= 'z'; c++) {
 			cs.add(c);
 		}*/
 		
 		for(int i = 0; i < from.length; i++) {
 			for(int j = 0; j < from[i].length(); j++) {
 				map[from[i].charAt(j)] = to[i].charAt(j);
 //				cs.remove(to[i].charAt(j));
 			}
 		}
 
 		map['q'] = 'z';
 		map['z'] = 'q';
 		/*
 		for(char c : cs) {
 			System.err.println(c);
 		}
 		for(char c = 'a'; c <= 'z'; c++) {
 			if(map[c] == 0) {
 				System.err.println(c);
 			}
 		}*/
 		
 		final int n = Integer.parseInt(IOFast.in.readLine());
 		for(int i = 0; i < n; i++) {
 			final String str = IOFast.in.readLine();
 			printCase();
 			for(int j = 0; j < str.length(); j++) {
 				IOFast.out.print(map[str.charAt(j)]);
 			}
 			IOFast.out.println();
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
