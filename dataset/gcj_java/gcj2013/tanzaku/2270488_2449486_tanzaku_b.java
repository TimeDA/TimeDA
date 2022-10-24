package Qual;
 
 
 import java.io.*;
 import java.math.BigInteger;
 import java.util.*;
 
 
 
 public class B implements Runnable {
 	private static final boolean STDIO = false;
 	private static final String BASE_DIR = "io\\Qual\\B";
 	private static final String IN_FILE = "B-small-attempt0.in";
 //	private static final String OUT_FILE = "outA.txt";
 	private static final String OUT_FILE = IN_FILE + "_out.txt";
 	
 	public long elaspedTimeMilli;
 	private IOFast io = new IOFast();
 	
 	private static final int mod = (int)1e9+7;
 	
 	int w, h;
 	int[][] xs, ys;
 
 	B Init(IOFast in) {
 		try {
 			h = in.nextInt();
 			w = in.nextInt();
 			xs = new int[h][w];
 			ys = new int[h][w];
 			for(int i = 0; i < h; i++) {
 				for(int j = 0; j < w; j++) {
 					xs[i][j] = in.nextInt();
 					ys[i][j] = Integer.MAX_VALUE;
 				}
 			}
 		}
 		catch(final Exception e) {
 			System.err.println(e);
 			throw new AssertionError();
 		}
 		return this;
 	}
 	
 	void rec(int x_, int y_, int dx, int dy) {
 		for(int s = -1; s <= 1; s += 2) {
 			for(int x = x_, y = y_; ; x += s * dx, y += s * dy) {
 				if(x < 0 || x >= w || y < 0 || y >= h) {
 					break;
 				}
 				if(xs[y][x] > xs[y_][x_]) { return; }
 			}
 		}
 		for(int s = -1; s <= 1; s += 2) {
 			for(int x = x_, y = y_; ; x += s * dx, y += s * dy) {
 				if(x < 0 || x >= w || y < 0 || y >= h) {
 					break;
 				}
 				ys[y][x] = Math.min(ys[y][x], xs[y_][x_]);
 			}
 		}
 	}
 	
 	void solve() throws IOException {
 		for(int i = 0; i < h; i++)
 			for(int j = 0; j < w; j++) {
 				rec(j, i, 1, 0);
 				rec(j, i, 0, 1);
 			}
 //		System.err.println(Arrays.deepToString(ys));
 		io.println(Arrays.deepEquals(xs, ys) ? "YES" : "NO");
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
 		B[] inst = new B[T];
 		Thread[] thread = new Thread[T];
 		for(int t = 1; t <= T; t++) {
 			inst[t-1] = new B().Init(io);
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
 		new B().runSolver();
 	}
 
 
 
 	static public class IOFast {
 		//		private static final int BUFFER_SIZE = 50 * 200000;
 		private int pos, readLen;
 		private final char[] buffer = new char[1024 * 8];
 		private final StringBuilder buf = new StringBuilder();
 		private static boolean[] isDigit = new boolean[256];
 		private static boolean[] isSpace = new boolean[256];
 		private static boolean[] isLineSep = new boolean[256];
 		
 		private BufferedReader _in;
 		private PrintWriter _out;
 //		private final StringWriter sout = new StringWriter();
 //		private final PrintWriter pout = new PrintWriter(sout);
 		private StringWriter _sout = new StringWriter();
 		private PrintWriter _pout = new PrintWriter(_sout);
 		private String _dir;
 
 		public void print(String str) { _pout.print(str); }
 		public void print(byte str) { _pout.print(str); }
 		public void print(char str) { _pout.print(str); }
 		public void print(int str) { _pout.print(str); }
 		public void print(long str) { _pout.print(str); }
 		public void print(float str) { _pout.print(str); }
 		public void print(double str) { _pout.print(str); }
 		public void print(Object str) { _pout.print(str); }
 		public void println() { _pout.println(); }
 		public void println(String str) { _pout.println(str); }
 		public void println(byte str) { _pout.println(str); }
 		public void println(char str) { _pout.println(str); }
 		public void println(int str) { _pout.println(str); }
 		public void println(long str) { _pout.println(str); }
 		public void println(float str) { _pout.println(str); }
 		public void println(double str) { _pout.println(str); }
 		public void println(Object str) { _pout.println(str); }
 		public void printf(String fmt, Object... args) { _pout.printf(fmt, args); }
 		
 		String getOutput() { _pout.flush(); return _sout.toString(); }
 		void flush() {
 			_pout.flush();
 			_out.print(_sout.toString());
 			_out.flush();
 			_sout.getBuffer().setLength(0);
 		}
 		
 		void close() throws IOException {
 			flush();
 			_in.close();
 			_out.close();
 			_pout.close();
 			_sout.close();
 		}
 		
 		public IOFast() {
 			this(System.in, System.out);
 			Init();
 		}
 		
 		public IOFast(InputStream in, PrintStream out) {
 			this._in = new BufferedReader(new InputStreamReader(in));
 			this._out = new PrintWriter(out);
 			Init();
 		}
 		
 		public IOFast(String dir, String in, String out) throws IOException {
 			this._dir = dir;
 			setFileIO(in, out);
 			Init();
 		}
 		
 		void setFileDir(String dir) {
 			this._dir = dir;
 		}
 		
 		private void Init() {
 			readLen = pos = 0;
 			_sout = new StringWriter();
 			_pout = new PrintWriter(_sout);
 		}
 		
 		private void setFileIO(String ins, String outs) throws IOException {
 			try {
 				String pf = _dir == null ? "" : _dir + "\\";
 				if(_in != null) { _in.close(); }
 				if(_out != null) { _out.close(); }
 				_in = new BufferedReader(new FileReader(pf + ins));
 				_out = new PrintWriter(new FileWriter(pf + outs));
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
 				readLen = _in.read(buffer);
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
