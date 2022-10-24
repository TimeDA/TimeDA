package r2;
 
 import java.io.*;
 import java.math.*;
 import java.util.*;
 
 import r2.B.ParallelSolver.BIT;
 import static java.util.Arrays.*;
 
 public class B {
 	static
 	class Config {
 		public static final boolean DISP_PROGRESS = true;
 		public static final boolean DISP_ELASPED_TIME = true;
 		public static final boolean STDIO = false;
 
 		public static final String BASE_DIR = "data\\r2\\B" ;
 //		public static final String IN_FILE = "sample.txt";
 		public static final String IN_FILE = "B-small-attempt3.in";
 //		public static final String IN_FILE = "B-large.in";
 		public static final String OUT_FILE = IN_FILE + "_out.txt";
 		public static final int MAX_THREAD = 3;
 	}
 
 	static
 	class ParallelSolver implements Runnable {
 		private static final int mod = (int)1e9+7;
 		
 		int n;
 		int[] x;
 		int[] ix;
 		BIT bitL;
 		BIT bitR;
 		public void readInput(final IOFast io) throws IOException {
 			n = io.nextInt();
 			x = io.nextIntArray(n);
 			ix = new int[n];
 			bitL = new BIT(n);
 			bitR = new BIT(n);
 		}
 		
 		int[] shrink(int[] xs) {
 			int[] ys = xs.clone();
 			int[] zs = new int[xs.length];
 			Arrays.sort(ys);
 			for(int i = 0; i < xs.length; i++) {
 				zs[i] = Arrays.binarySearch(ys, xs[i]);
 			}
 			return zs;
 		}
 		
 		int inverse(int[] xs) {
 			BIT bit = new BIT(xs.length);
 			int ans = 0;
 			xs = shrink(xs);
 			for(int i = 0; i < xs.length; i++) {
 				ans += i - bit.sum(xs[i]);
 				bit.add(xs[i] + 1, 1);
 			}
 			return ans;
 		}
 
 		int[][] memo = new int[1000][1000];
 		boolean[][] done = new boolean[1000][1000];
 		int func(int idx, int L, int R) {
 			if(idx == n) return 0;
 			if(done[L][R]) return memo[L][R];
 			done[L][R] = true;
 			
 			int ans = Integer.MAX_VALUE;
 			bitL.add(x[idx] + 1, 1);
 			bitR.add(n - 1 - x[idx] + 1, 1);
 			ans = Math.min(ans, L - bitL.sum(x[idx]) + func(idx + 1, L + 1, R + 0));
 			ans = Math.min(ans, R - bitR.sum(n - 1 - x[idx]) + func(idx + 1, L + 0, R + 1));
 			bitL.add(x[idx] + 1, -1);
 			bitR.add(n - 1 - x[idx] + 1, -1);
 			return memo[L][R] = ans;
 		}
 		
 		@Override
 		public void run() {
 //			int idx = 0;
 //			for(int i = 0; i < n; i++) if(x[i] > x[idx]) idx = i;
 //			
 //			int[] ys = x.clone();
 //			Arrays.sort(ys);
 //			for(int i = 0; i < n; i++) x[i] = Arrays.binarySearch(ys, x[i]);
 //			for(int i = 0; i < n; i++) ix[x[i]] = i;
 //
 //			bitL.clear();
 //			bitR.clear();
 //			for(boolean[] d : done) Arrays.fill(d, false);
 //			out.println(func(0, 0, 0));
 			
 			x = shrink(x);
 			int ans = Integer.MAX_VALUE;
 			int[] v = new int[n];
 			for(int i = 0; i < 1 << n; i++) {
 				for(int j = 0, k = 0; j < n; j++) {
 					if((i>>>j&1) == 1) v[k++] = x[j];
 					else v[k++] = 100 * n - x[j];
 				}
 //				System.err.println(Arrays.toString(v) + " " + inverse(v));
 				ans = Math.min(ans, inverse(v));
 			}
 			out.println(ans);
 		}
 		
 	    private static int[] LIS(int[] ys) {
 	        final int n = ys.length;
 	        final int[] res = new int[n];
 	    	Arrays.fill(res, Integer.MAX_VALUE);
 	        for (int i = 0; i < n; i++) {
 	            res[lowerBound(res, ys[i])] = ys[i];
 	        }
 	        return res;
 	    }
 	    
 	    private static int lowerBound(final int[] xs, final int x)
 	    {
 	        int low = 0, high = xs.length;
 	        while (low < high) {
 	        	final int mid = (low + high) / 2;
 	            final int cmp = xs[mid] < x ? -1 : xs[mid] == x ? 0 : 1;
 	            if (cmp >= 0) high = mid;
 	            else low = mid + 1;
 	        }
 	        return low;
 	    }
 
 		
 		static
 		class BIT {
 			final int n;
 			final int[] bit;
 
 			public BIT(int size) {
 				n = size;
 				bit = new int[n + 1];
 			}
 			
 			public void clear() { Arrays.fill(bit, 0); }
 
 			public int lowerBoundIndex(int x) {
 				int i = Integer.highestOneBit(bit.length - 1);
 				int sum = 0;
 				int cur = 0;
 				int ans = Integer.MAX_VALUE;
 				int ansIndex = 0;
 				for(; i > 0; i >>= 1) {
 					cur ^= i;
 					if(cur < bit.length && sum + bit[cur] < x) {
 						sum += bit[cur];
 					}
 					else {
 						if(cur < bit.length && ans > sum + bit[cur]) {
 							ans = sum + bit[cur];
 							ansIndex = cur;
 						}
 						
 						cur ^= i;
 					}
 				}
 				return ansIndex;
 			}
 			
 			public int lowerBound(int x) {
 				int i = Integer.highestOneBit(bit.length - 1);
 				int sum = 0;
 				int cur = 0;
 				int ans = Integer.MAX_VALUE;
 				int ansIndex = 0;
 				for(; i > 0; i >>= 1) {
 					cur ^= i;
 					if(cur < bit.length && sum + bit[cur] < x) {
 						sum += bit[cur];
 					}
 					else {
 						if(cur < bit.length && ans > sum + bit[cur]) {
 							ans = sum + bit[cur];
 							ansIndex = cur;
 						}
 						
 						cur ^= i;
 					}
 				}
 				return ans;
 			}
 
 			// [i, j)
 			public int sum(int i, int j) {
 				return sum(j) - sum(i);
 			}
 
 			public int sum(int i) {
 				int res = 0;
 				for (; i > 0; i -= i & -i) {
 					res += bit[i];
 //					while(res >= mod) res -= mod;
 				}
 				return res;
 			}
 
 			// 1<=i<=n
 			public void add(int i, int x) {
 				if(i == 0) throw new RuntimeException();
 				for (; i <= n; i += i & -i) {
 					bit[i] += x;
 //					while(bit[i] >= mod) bit[i] -= mod;
 				}
 			}
 		}
 		
 
 		final Random random = new Random(0);
 		final StringWriter sw = new StringWriter();
 		final PrintWriter out = new PrintWriter(sw);
 		
 		@Override
 		public String toString() {
 			out.flush();
 			return sw.toString();
 		}
 		
 		public ParallelSolver init(final IOFast io) throws IOException {
 			readInput(io);
 			return this;
 		}
 	}
 
 	
 	
 	
 	
 	//////////////////////////////////////////
 	final IOFast io = new IOFast();
 	
 	
 	public long elaspedTimeMilli;
 	
 	public void run() throws IOException, InterruptedException {
 		
 		if(!Config.STDIO) {
 			io.setFileDir(Config.BASE_DIR);
 			io.setFileIO(Config.IN_FILE, Config.OUT_FILE);
 		}
 		
 		int T = io.nextInt();
 //		IOFast.nextLine();
 		Runnable[] inst = new Runnable[Config.MAX_THREAD];
 		Thread[] thread = new Thread[Config.MAX_THREAD];
 		final long start = System.currentTimeMillis();
 		for(int t = 0, cur = 0; cur < T; ) {
 			if(t >= T || t >= Config.MAX_THREAD) {
 				final int th = cur % Config.MAX_THREAD;
 				thread[th].join();
 				io.out.print("Case #" + (cur+1) + ": " + inst[th]);
 				inst[th] = null;
 				thread[th] = null;
 				
 				if(Config.DISP_PROGRESS) {
 					System.err.println("Case #" + (cur+1) + ": DONE");
 				}
 				cur++;
 			}
 			if(t < T) {
 				final int th = t % Config.MAX_THREAD;
 				inst[th] = new ParallelSolver().init(io);
 				thread[th] = new Thread(inst[th]);
 				thread[th].start();
 				t++;
 			}
 		}
 		final long end = System.currentTimeMillis();
 		elaspedTimeMilli = end - start;
 		System.err.println(elaspedTimeMilli + " [ms]");
 	}
 
 	static void arrayIntSort(int[][] x, int key) {
 		Arrays.sort(x, new IntArrayComparator(key));
 	}
 	
 	static class IntArrayComparator implements Comparator<int[]> {
 		final int KEY;
 		
 		public IntArrayComparator(int key) {
 			KEY = key;
 		}
 		
 		@Override
 		public int compare(int[] o1, int[] o2) {
 			return o1[KEY] - o2[KEY];
 		}
 	}
 	
 	void main() throws IOException, InterruptedException {
 		//		IOFast.setFileIO("rle-size.in", "rle-size.out");
 		try {
 			run();
 		}
 		catch (EndOfFileRuntimeException e) { }
 		io.out.flush();
 	}
 
 	public static void main(String[] args) throws IOException, InterruptedException {
 		new B().main();
 	}
 	
 	static class EndOfFileRuntimeException extends RuntimeException {
 		private static final long serialVersionUID = -8565341110209207657L; }
 
 	static
 	public class IOFast {
 		private BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
 		private PrintWriter out = new PrintWriter(System.out);
 		private String _dir;
 		
 		void setFileDir(String dir) {
 			this._dir = dir;
 		}
 
 		void setFileIn(String ins) throws IOException {
 			String pf = _dir == null ? "" : _dir + "\\";
 			in = new BufferedReader(new FileReader(pf + ins));
 		}
 
 		void setFileOut(String outs) throws IOException {
 			String pf = _dir == null ? "" : _dir + "\\";
 			out = new PrintWriter(new FileWriter(pf + outs));
 		}
 
 		void setFileIO(String ins, String outs) throws IOException {
 			setFileIn(ins);
 			setFileOut(outs);
 		}
 
 		//		private static final int BUFFER_SIZE = 50 * 200000;
 		private static int pos, readLen;
 		private static final char[] buffer = new char[1024 * 8];
 		private static final char[] str = new char[500000*8*2];
 		private static boolean[] isDigit = new boolean[256];
 		private static boolean[] isSpace = new boolean[256];
 		private static boolean[] isLineSep = new boolean[256];
 
 		static {
 			for(int i = 0; i < 10; i++) { isDigit['0' + i] = true; }
 			isDigit['-'] = true;
 			isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true;
 			isLineSep['\r'] = isLineSep['\n'] = true;
 		}
 
 		public int read() throws IOException {
 			if(pos >= readLen) {
 				pos = 0;
 				readLen = in.read(buffer);
 				if(readLen <= 0) { throw new EndOfFileRuntimeException(); }
 			}
 			return buffer[pos++];
 		}
 
 		public int nextInt() throws IOException {
 			return Integer.parseInt(nextString());
 		}
 
 		public long nextLong() throws IOException {
 			return Long.parseLong(nextString());
 		}
 
 		public char nextChar() throws IOException {
 			while(true) {
 				final int c = read();
 				if(!isSpace[c]) { return (char)c; }
 			}
 		}
 		
 		int reads(char[] cs, int len, boolean[] accept) throws IOException {
 			try {
 				while(true) {
 					final int c = read();
 					if(accept[c]) { break; }
 					cs[len++] = (char)c;
 				}
 			}
 			catch(EndOfFileRuntimeException e) { ; }
 			
 			return len;
 		}
 
 		public char[] nextLine() throws IOException {
 			int len = 0;
 			str[len++] = nextChar();
 			len = reads(str, len, isLineSep);
 			
 			try {
 				if(str[len-1] == '\r') { len--; read(); }
 			}
 			catch(EndOfFileRuntimeException e) { ; }
 			
 			return Arrays.copyOf(str, len);
 		}
 
 		public String nextString() throws IOException {
 			return new String(next());
 		}
 
 		public char[] next() throws IOException {
 			int len = 0;
 			str[len++] = nextChar();
 			len = reads(str, len, isSpace);
 			return Arrays.copyOf(str, len);
 		}
 
 		public double nextDouble() throws IOException {
 			return Double.parseDouble(nextString());
 		}
 
 		public long[] nextLongArray(final int n) throws IOException {
 			final long[] res = new long[n];
 			for(int i = 0; i < n; i++) {
 				res[i] = nextLong();
 			}
 			return res;
 		}
 
 		public int[] nextIntArray(final int n) throws IOException {
 			final int[] res = new int[n];
 			for(int i = 0; i < n; i++) {
 				res[i] = nextInt();
 			}
 			return res;
 		}
 
 		public int[][] nextIntArray2D(final int n, final int k) throws IOException {
 			final int[][] res = new int[n][];
 			for(int i = 0; i < n; i++) {
 				res[i] = nextIntArray(k);
 			}
 			return res;
 		}
 
 		public double[] nextDoubleArray(final int n) throws IOException {
 			final double[] res = new double[n];
 			for(int i = 0; i < n; i++) {
 				res[i] = nextDouble();
 			}
 			return res;
 		}
 
 	}
 
 }
