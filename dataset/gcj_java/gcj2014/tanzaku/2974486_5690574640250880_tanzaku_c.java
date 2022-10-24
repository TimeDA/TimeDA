package qual;
 
 import java.io.*;
 import java.math.*;
 import java.util.*;
 
 
 import static java.util.Arrays.*;
 
 public class C {
 	static
 	class Config {
 		public static final boolean DISP_PROGRESS = true;
 		public static final boolean DISP_ELASPED_TIME = true;
 		public static final boolean STDIO = false;
 
 		public static final String BASE_DIR = "data\\qual\\C" ;
 		public static final String IN_FILE = "C-small-attempt2.in";
 		public static final String OUT_FILE = IN_FILE + "_out.txt";
 		public static final int MAX_THREAD = 3;
 	}
 
 	static
 	class ParallelSolver implements Runnable {
 		private static final int mod = (int)1e9+7;
 		
 		int W, H, M;
 		boolean[][] bomb;
 		boolean[][] vis;
 		public void readInput(final IOFast io) throws IOException {
 			H = io.nextInt();
 			W = io.nextInt();
 			M = io.nextInt();
 		}
 		
 		@Override
 		public void run() {
 			for(int w = 1; w <= W; w++) {
 				int sp = W * H - M;
 				bomb = new boolean[H][W];
 				vis = new boolean[H][W];
 				
 				for(boolean[] b : bomb) Arrays.fill(b, true);
 				
 				int last = Math.min(2, H);
 				int h = Math.min(H, (sp + w - 1) / w);
 				for(int x = 0; x < w; x++) {
 					for(int y = 0; y < H; y++) {
 						if(x == w - 1 && sp > 0 || y < h && sp > last) {
 							bomb[y][x] = false;
 							sp--;
 						}
 					}
 				}
 				
 				if(dfs(0, 0) + M == W * H) {
 					out.println();
 					for(int y = 0; y < H; y++) {
 						for(int x = 0; x < W; x++) {
 							if(x == 0 && y == 0) {
 								out.print('c');
 							}
 							else {
 								out.print(bomb[y][x] ? '*' : '.');
 							}
 						}
 						out.println();
 					}
 					return;
 				}
 				else if(false) {
 					out.println();
 					for(int y = 0; y < H; y++) {
 						for(int x = 0; x < W; x++) {
 							if(x == 0 && y == 0) {
 								out.print('c');
 							}
 							else {
 								out.print(bomb[y][x] ? '*' : '.');
 							}
 						}
 						out.println();
 					}
 				}
 			}
 			out.println();
 			out.println("Impossible");
 		}
 		
 		int dfs(int x, int y) {
 			if(vis[y][x]) return 0;
 			
 			vis[y][x] = true;
 			
 			int res = 1;
 			boolean ok = true;
 			for(int dy = -1; dy <= 1; dy++) {
 				for(int dx = -1; dx <= 1; dx++) {
 					int a = y + dy;
 					int b = x + dx;
 					if(a >= 0 && a < H && b >= 0 && b < W && bomb[a][b]) {
 						ok = false;
 					}
 				}
 			}
 			if(ok) {
 				for(int dy = -1; dy <= 1; dy++) {
 					for(int dx = -1; dx <= 1; dx++) {
 						int a = y + dy;
 						int b = x + dx;
 						if(a >= 0 && a < H && b >= 0 && b < W) {
 							res += dfs(b, a);
 						}
 					}
 				}
 			}
 			return res;
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
 		new C().main();
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
