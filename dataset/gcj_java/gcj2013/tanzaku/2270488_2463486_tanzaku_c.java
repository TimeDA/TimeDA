package Qual;
 
 
 import java.io.*;
 import java.math.BigInteger;
 import java.util.*;
 
 
 
 public class C implements Runnable {
 	private static final boolean DISP_ELASPED_TIME = true;
 	private static final boolean STDIO = false;
 	private static final String BASE_DIR = "io\\Qual\\C";
 	private static final String IN_FILE = "C-small-attempt6.in";
 //	private static final String OUT_FILE = "outA.txt";
 	private static final String OUT_FILE = IN_FILE + "_out.txt";
 	
 	public long elaspedTimeMilli;
 	private IOFast in;
 	private IOFast out = new IOFast();
 	
 	
 	// Logic
 	
 	private static final int mod = (int)1e9+7;
 	
 	BigInteger A, B;
 	
 	C Init() {
 		try {
 			A = new BigInteger(in.next());
 			B = new BigInteger(in.next());
 			A = A.subtract(BigInteger.ONE);
 		}
 		catch(final Exception e) {
 			System.err.println(e);
 			throw new AssertionError();
 		}
 		return this;
 	}
 	
 	boolean isPalindrome(long x) {
 		final String s = Long.toString(x);
 		for(int i = 0; i < s.length() / 2; i++) {
 			if(s.charAt(i) != s.charAt(s.length() - 1 - i)) {
 				return false;
 			}
 		}
 		return true;
 	}
 	
 	int cmp(int[] a, int[] b) {
 		for(int i = a.length - 1; i >= 0; i--) {
 			if(a[i] != b[i]) {
 				return a[i] < b[i] ? -1 : 1;
 			}
 		}
 		return 0;
 	}
 	/*
 	boolean skip(char[] x, int n) {
 		if(n == c2.length) return false;
 		gen(x, n, 0);
 		return cmp(x, c1) >= 0;
 	}*/
 	
 	void sqr(int[] x, int[] out) {
 		Arrays.fill(out, 0);
 		for(int i = 0; i < x.length; i++) {
 			for(int j = 0; j < x.length; j++) if(i + j < out.length) {
 				out[i+j] += x[i] * x[j];
 			}
 		}
 		for(int i = out.length - 1, c = 0; i >= 0; i--) {
 			out[i] += c;
 			c = out[i] / 10;
 			out[i] %= 10;
 		}
 	}
 	
 	void gen(int[] x, int n, int bit) {
 		Arrays.fill(x, 0);
 		x[n - 1] = 1;
 		x[0] = 1;
 //		final int b0 = bit;
 		for(int i = n / 2; i < n - 1; i++, bit >>>= 1) {
 			x[i] = x[n-1-i] = bit & 1;
 		}
 //		System.err.println(Arrays.toString(x) + " " + n + " " + b0);
 	}
 	
 	int check2(int i) {
 		int res = 0;
 		final BigInteger two = BigInteger.valueOf(2);
 		BigInteger x = BigInteger.valueOf(10).pow(i - 1).multiply(two);
 		if(i != 1) x = x.add(two);
 		BigInteger sqr = x.multiply(x);
 		
 		if(A.compareTo(sqr) < 0 && sqr.compareTo(B) <= 0) {
 //			System.err.println("chk1: " + i + " " + x + " " + sqr);
 			res++;
 		}
 		
 		if(i % 2 == 1 && i != 1) {
 			x = x.add(BigInteger.TEN.pow(i / 2));
 			sqr = x.multiply(x);
 //			System.err.println("chk2: " + i + " " + x + " " + sqr);
 			if(A.compareTo(sqr) < 0 && sqr.compareTo(B) <= 0) {
 				res++;
 			}
 		}
 		
 		return res;
 	}
 	
 	long countLower(BigInteger v) {
 		if(v.equals(BigInteger.ZERO)) return 0;
 		char[] cs = v.toString().toCharArray();
 		final int n = cs.length;
 		
 		long res = 0;
 		for(int i = 1; i < n; i++) {
 			res += 1L << Math.max(0, (i - 1) / 2);
 			if(i != 1 && i % 2 == 1) {
 				res++;
 			}
 		}
 		if(n % 2 == 1 && n != 1 && cs[n / 2] == '2') {
 			res++;
 		}
 		long x = 0;
 		for(int i = (cs.length - 1) / 2; i > 0; i--) {
 			x = x * 2 + (cs[i] >= '1' ? 1 : 0);
 		}
 		x++;
 //		System.err.println("chk: " + res + " " + x + " " + v);
 		res += x + x / 2;
 		return res;
 	}
 	
 	BigInteger lower(BigInteger v) {
 		BigInteger low = BigInteger.ZERO, high = v.add(BigInteger.ONE);
 		
 		while(high.subtract(low).compareTo(BigInteger.ONE) > 0) {
 			final BigInteger mid = low.add(high).divide(BigInteger.valueOf(2));
 			final BigInteger sqr = mid.multiply(mid);
 			if(v.compareTo(sqr) >= 0) { low = mid; }
 			else { high = mid; }
 		}
 		
 		final char[] cs = low.toString().toCharArray();
 		if(cs.length % 2 == 1 && cs[cs.length / 2] == 1) {
 			cs[cs.length / 2] = 2;
 			BigInteger u = new BigInteger(new String(cs));
 			if(v.compareTo(u.multiply(u)) >= 0) {
 				low = u;
 			}
 		}
 		
 //		return low.multiply(low);
 		return low;
 	}
 	
 	BigInteger floorSim(BigInteger v) {
 		char[] cs = v.toString().toCharArray();
 		final int n = cs.length;
 		int i;
 		for(i = 0; i < n / 2; i++) {
 			if(cs[i] != '1') { cs[i] = cs[n-1-i] = '1'; break; }
 			if(cs[i] != cs[n-1-i]) {
 				if(cs[n-1-i] == '0') { cs[i] = cs[n-1-i] = '0'; }
 				else { cs[i] = cs[n-1-i] = '1'; }
 				break;
 			}
 		}
 		if(cs[0] == '0') {
 			for(int j = 1; j < n; j++) {
 				cs[j] = '1';
 			}
 			if((n - 1) % 2 == 1) {
 				cs[(n + 1) / 2] = '2';
 			}
 			return new BigInteger(new String(cs));
 		}
 		for(; i + 1 < n / 2; i++) {
 			i++;
 			cs[i] = cs[n-1-i] = '1';
 		}
 		if(n % 2 == 1) {
 			cs[i] = (char)Math.min(cs[i], '2');
 		}
 		return new BigInteger(new String(cs));
 	}
 	
 	void solve() throws IOException {
 //		for(int ii = 1; ii <= 10; ii++) {
 //			for(int jj = ii; jj <= 10; jj++) {
 //				A = BigInteger.valueOf(ii);
 //				B = BigInteger.valueOf(jj);
 				
 				long res = 0;
 				if(A.compareTo(BigInteger.valueOf(9)) >= 0) { res--; }
 				if(B.compareTo(BigInteger.valueOf(9)) >= 0) { res++; }
 				final BigInteger y1 = floorSim(lower(A));
 				final BigInteger y2 = floorSim(lower(B));
 				res += countLower(y2) - countLower(y1);
 				/*
 				System.err.println(lower(A) + " " + lower(B));
 				System.err.println(y1 + " " + y2);
 				System.err.println(countLower(y2) + " " + countLower(y1));
 				//*/
 				final int n1 = A.toString().length();
 				final int n2 = B.toString().length();
 				for(int i = 1; i <= (n2 + 1) / 2; i++) {
 					res += check2(i);
 				}
 
 				out.println(res);
 //				out.println(ii + " " + jj + " " + res);
 //			}
 //		}
 		/*
 		for(long x = 1; x < 100000000; x++) {
 			if(isPalindrome(x) && isPalindrome(x*x)) {
 				System.err.println(x + " " + x*x);
 			}
 		}*/
 	}
 	
 
 	// End Logic
 
 
 	C(){}
 	C(IOFast in){ this.in = in; }
 	
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
 			in = new IOFast();
 		}
 		else {
 			in = new IOFast(BASE_DIR, IN_FILE, OUT_FILE);
 		}
 	}
 	
 	void FinSolver() {
 		try {
 			out.close();
 			in.close();
 		} catch (IOException e) {
 			// TODO Auto-generated catch block
 			e.printStackTrace();
 		}
 	}
 	
 	public void runSolver() throws IOException, InterruptedException {
 		final long start = System.currentTimeMillis();
 		
 		InitSolver();
 		
 		int T = in.nextInt();
 //		IOFast.nextLine();
 		C[] inst = new C[T];
 		Thread[] thread = new Thread[T];
 		for(int t = 1; t <= T; t++) {
 			inst[t-1] = new C(in).Init();
 			thread[t-1] = new Thread(inst[t-1]);
 			thread[t-1].start();
 		}
 		
 		for(int t = 1; t <= T; t++) {
 			thread[t-1].join();
 			out.print("Case #" + t + ": " + inst[t-1].out.getOutput());
 			if(DISP_ELASPED_TIME) {
 				System.err.println(inst[t-1].elaspedTimeMilli + " [ms]");
 			}
 		}
 
 		FinSolver();
 		
 		if(DISP_ELASPED_TIME) {
 			final long end = System.currentTimeMillis();
 			System.err.println((end - start) + " [ms]");
 		}
 	}
 
 	public static void main(String[] args) throws IOException, InterruptedException {
 		if(!STDIO) {
 			String dir = BASE_DIR.equals("") ? "." : BASE_DIR;
 			dir += "\\";
 			System.setIn(new FileInputStream(dir + IN_FILE));
 			System.setOut(new PrintStream(new FileOutputStream(dir + OUT_FILE)));
 		}
 		new C().runSolver();
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
