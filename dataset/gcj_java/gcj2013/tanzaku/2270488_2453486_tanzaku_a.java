package Qual;
 
 
 import java.io.*;
 import java.math.BigInteger;
 import java.util.*;
 
 
 
 public class A implements Runnable {
 	private static final boolean STDIO = false;
 	private static final String BASE_DIR = "io\\Qual\\A";
 	private static final String IN_FILE = "A-small-attempt0.in";
 //	private static final String OUT_FILE = "outA.txt";
 	private static final String OUT_FILE = IN_FILE + "_out.txt";
 	
 	public long elaspedTimeMilli;
 	private IOFast io;
 	
 	private static final int mod = (int)1e9+7;
 	
 	final char[][] cs = new char[4][4];
 
 	A Init(IOFast in) {
 		try {
 			io = new IOFast();
 			for(int i = 0; i < cs.length; i++) {
 				for(int j = 0; j < cs[i].length; j++) {
 					cs[i][j] = in.nextChar();
 				}
 			}
 		}
 		catch(final Exception e) {
 			System.err.println(e);
 			throw new AssertionError();
 		}
 		return this;
 	}
 	
 	void solve() throws IOException {
 		boolean fin = true;
 		final char[] ch = "OX".toCharArray();
 		for(final char c : ch) {
 			int max = 0;
 			for(int y = 0; y < cs.length; y++) {
 				int cur1 = 0, cur2 = 0, cur3 = 0, cur4 = 0;
 				for(int x = 0; x < cs[y].length; x++) {
 					if(cs[y][x] == c || cs[y][x] == 'T') { max = Math.max(max, ++cur1); }
 					else { cur1 = 0; }
 					
 					if(cs[x][y] == c || cs[x][y] == 'T') { max = Math.max(max, ++cur2); }
 					else { cur2 = 0; }
 					
 					if(cs[x][x] == c || cs[x][x] == 'T') { max = Math.max(max, ++cur3); }
 					else { cur3 = 0; }
 					
 					if(cs[3-x][x] == c || cs[3-x][x] == 'T') { max = Math.max(max, ++cur4); }
 					else { cur4 = 0; }
 					
 					if(cs[y][x] == '.') { fin = false; }
 				}
 			}
 			if(max == 4) { io.println(c + " won"); return; }
 		}
 		io.println(fin ? "Draw" : "Game has not completed");
 	}
 	
 	
 	
 	@Override
 	public void run() {
 		final long start = System.currentTimeMillis();
 		
 		try {
 			solve();
 		} catch (IOException e) {
 			// TODO Auto-generated catch block
 			e.printStackTrace();
 		}
 		
 		final long end = System.currentTimeMillis();
 		elaspedTimeMilli = end - start;
 	}
 	
 	
 	
 	
 	void InitSolver() throws IOException {
 		if(STDIO) {
 			io = new IOFast();
 		}
 		else {
 			io = new IOFast(BASE_DIR, IN_FILE, OUT_FILE);
 		}
 	}
 	
 	void FinSolver() {
 		try {
 			io.close();
 		} catch (IOException e) {
 			// TODO Auto-generated catch block
 			e.printStackTrace();
 		}
 	}
 	
 	public void runSolver() throws IOException, InterruptedException {
 		final long start = System.currentTimeMillis();
 		
 		InitSolver();
 		
 		int T = io.nextInt();
 //		IOFast.nextLine();
 		A[] inst = new A[T];
 		Thread[] thread = new Thread[T];
 		for(int t = 1; t <= T; t++) {
 			inst[t-1] = new A().Init(io);
 			thread[t-1] = new Thread(inst[t-1]);
 			thread[t-1].start();
 		}
 		
 		for(int t = 1; t <= T; t++) {
 			thread[t-1].join();
 			io.print("Case #" + t + ": " + inst[t-1].io.getOutput());
 //			inst[t-1].io.flush();
 			System.err.println(inst[t-1].elaspedTimeMilli + " [ms]");
 		}
 //		io.flush();
 
 		FinSolver();
 
 		final long end = System.currentTimeMillis();
 		System.err.println((end - start) + " [ms]");
 	}
 
 	public static void main(String[] args) throws IOException, InterruptedException {
 		if(!STDIO) {
 			String dir = BASE_DIR.equals("") ? "." : BASE_DIR;
 			dir += "\\";
 			System.setIn(new FileInputStream(dir + IN_FILE));
 			System.setOut(new PrintStream(new FileOutputStream(dir + OUT_FILE)));
 		}
 		new A().runSolver();
 	}
 
 
 
 	static public class IOFast {
 		//		private static final int BUFFER_SIZE = 50 * 200000;
 		private int pos, readLen;
 		private final char[] buffer = new char[1024 * 8];
 		private final StringBuilder buf = new StringBuilder();
 		private static boolean[] isDigit = new boolean[256];
 		private static boolean[] isSpace = new boolean[256];
 		private static boolean[] isLineSep = new boolean[256];
 		
 		private BufferedReader in;
 		private PrintWriter out;
 //		private final StringWriter sout = new StringWriter();
 //		private final PrintWriter pout = new PrintWriter(sout);
 		private StringWriter sout = new StringWriter();
 		private PrintWriter pout = new PrintWriter(sout);
 		private String dir;
 
 		public void print(String str) { pout.print(str); }
 		public void print(byte str) { pout.print(str); }
 		public void print(char str) { pout.print(str); }
 		public void print(int str) { pout.print(str); }
 		public void print(long str) { pout.print(str); }
 		public void print(float str) { pout.print(str); }
 		public void print(double str) { pout.print(str); }
 		public void print(Object str) { pout.print(str); }
 		public void println() { pout.println(); }
 		public void println(String str) { pout.println(str); }
 		public void println(byte str) { pout.println(str); }
 		public void println(char str) { pout.println(str); }
 		public void println(int str) { pout.println(str); }
 		public void println(long str) { pout.println(str); }
 		public void println(float str) { pout.println(str); }
 		public void println(double str) { pout.println(str); }
 		public void println(Object str) { pout.println(str); }
 		public void printf(String fmt, Object... args) { pout.printf(fmt, args); }
 		
 		String getOutput() { pout.flush(); return sout.toString(); }
 		void flush() {
 			pout.flush();
 			out.print(sout.toString());
 			out.flush();
 			sout.getBuffer().setLength(0);
 		}
 		
 		void close() throws IOException {
 			flush();
 			in.close();
 			out.close();
 			pout.close();
 			sout.close();
 		}
 		
 		public IOFast() {
 			this(System.in, System.out);
 			Init();
 		}
 		
 		public IOFast(InputStream in, PrintStream out) {
 			this.in = new BufferedReader(new InputStreamReader(in));
 			this.out = new PrintWriter(out);
 			Init();
 		}
 		
 		public IOFast(String dir, String in, String out) throws IOException {
 			this.dir = dir;
 			setFileIO(in, out);
 			Init();
 		}
 		
 		void setFileDir(String dir) {
 			this.dir = dir;
 		}
 		
 		private void Init() {
 			readLen = pos = 0;
 			sout = new StringWriter();
 			pout = new PrintWriter(sout);
 		}
 		
 		private void setFileIO(String ins, String outs) throws IOException {
 			try {
 				String pf = dir == null ? "" : dir + "\\";
 				if(in != null) { in.close(); }
 				if(out != null) { out.close(); }
 				in = new BufferedReader(new FileReader(pf + ins));
 				out = new PrintWriter(new FileWriter(pf + outs));
 			}
 			catch(IOException e) {
 				System.err.println(e);
 				throw e;
 			}
 		}
 		
 		static {
 			for(int i = 0; i < 10; i++) {
 				isDigit['0' + i] = true;
 			}
 			isDigit['-'] = true;
 			isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true;
 			isLineSep['\r'] = isLineSep['\n'] = true;
 		}
 
 		public int read() throws IOException {
 			if(pos >= readLen) {
 				readLen = in.read(buffer);
 				pos = 0;
 
 				if(readLen <= 0) {
 					throw new IOException();
 				}
 			}
 
 			return buffer[pos++];
 		}
 
 		public int nextInt() throws IOException {
 			return Integer.parseInt(next());
 		}
 
 		public long nextLong() throws IOException {
 			return Long.parseLong(next());
 		}
 
 		public char nextChar() throws IOException {
 			while(true) {
 				final int c = read();
 
 				if(!isSpace[c]) {
 					return (char)c;
 				}
 			}
 		}
 
 		public String nextLine() throws IOException {
 			buf.setLength(0);
 			
 			while(true) {
 				final int c = read();
 
 				if(c == -1 || isLineSep[c]) {
 					if(c == '\r') { read(); }
 					break;
 				}
 				buf.append((char)c);
 			}
 
 			return buf.toString();
 		}
 		
 		public String next() throws IOException {
 			buf.setLength(0);
 			buf.append(nextChar());
 
 			while(true) {
 				try {
 					final int c = read();
 					if(isSpace[c]) { break; }
 					buf.append((char)c);
 				}
 				catch(IOException e) {
 					break;
 				}
 			}
 
 			return buf.toString();
 		}
 
 		public double nextDouble() throws IOException {
 			return Double.parseDouble(next());
 		}
 
 	}
 
 }
