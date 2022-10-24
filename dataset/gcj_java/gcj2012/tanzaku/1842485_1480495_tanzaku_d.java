package R2;
 import java.io.*;
 import java.math.*;
 import java.util.*;
 
 
 public class D {
 	static void start() throws IOException {
 		new D().run1();
 	}
 
 	private final String dir = "D:\\contest\\gcj\\2012\\" + getClass().getPackage().toString().split(" ")[1] + "\\" + getClass().getSimpleName();
 	private final String inputFileName = "D-small-attempt0.in";
 	//	private final String inputFileName = "C-large.in";
 	private final String outputFileName = "res.txt";
 
 	int w, h, m;
 	int[] n;
 	boolean[] luc;
 	char[][] mp;
 	boolean[][] vis;
 
 	private static final int[] dx = new int[] { 1, 0, -1 };
 	private static final int[] dy = new int[] { 0, 1, 0 };
 
 	int move(int[][] pos, int d, int di) {
 		int flag = 0;
 		for(int i = 0; i < pos.length; i++) {
 			if(tx == 2 && ty == 2 && di == 1 && false) {
 				System.err.print("chk3: ");
 				System.err.println(Arrays.toString(pos[i]));
 			}
 			for(int j = 0; j < di; j++) {
 				pos[i][0] += dx[d];
 				pos[i][1] += dy[d];
 				if(mp[pos[i][1]][pos[i][0]] == '#') {
 					pos[i][0] -= dx[d];
 					pos[i][1] -= dy[d];
 				}
 				else if(vis[pos[i][1]][pos[i][0]]) {
 					flag = 1;
 				}
 				else {
 					return 2;
 				}
 			}
 		}
 		if(tx == 2 && ty == 2 && false) {
 			System.err.println("ret: " + flag);
 			for(int j = 0; j < pos.length; j++) {
 				System.err.print(Arrays.toString(pos[j]) + " ");
 			}
 			System.err.println("");
 		}
 		return flag;
 	}
 	
 	int tx, ty;
 	boolean dfs(int[][] pos) {
 		if(tx == 2 && ty == 2 && false) {
 			System.err.print("chk1: ");
 			for(int j = 0; j < pos.length; j++) {
 				System.err.print(Arrays.toString(pos[j]) + " ");
 			}
 			System.err.println("");
 		}
 		boolean ok = true;
 		int[][] tmp = new int[pos.length][2];
 		for(int i = 0; i < pos.length; i++) {
 			tmp[i][0] = pos[i][0];
 			tmp[i][1] = pos[i][1];
 			ok &= pos[i][0] == tx && pos[i][1] == ty;
 		}
 		if(ok) return true;
 
 		if(move(pos, 0, 10) == 2) {
 			for(int i = 0; i < pos.length; i++) {
 				pos[i][0] = tmp[i][0];
 				pos[i][1] = tmp[i][1];
 			}
 			return false;
 		}
 
 		int[][] tmp2 = new int[pos.length][2];
 
 		for(int i = 0; i < 10; i++) {
 			for(int j = 0; j < pos.length; j++) {
 				tmp2[j][0] = pos[j][0];
 				tmp2[j][1] = pos[j][1];
 			}
 			ok = true;
 			for(int j = 0; j < pos.length; j++) {
 				ok &= pos[j][0] == tx && pos[j][1] == ty;
 			}
 			if(ok) return true;
 			if(tx == 2 && ty == 2 && false) {
 				System.err.print("chk2: ");
 				for(int j = 0; j < pos.length; j++) {
 					System.err.print(Arrays.toString(pos[j]) + " ");
 				}
 				System.err.println("");
 			}
 			final int mv = move(pos, 1, 1);
 			if(tx == 2 && ty == 2 && false) {
 				System.err.println("mv: " + mv);
 			}
 			if(mv == 1 && dfs(pos)) {
 				return true;
 			}
 			for(int j = 0; j < pos.length; j++) {
 				pos[j][0] = tmp2[j][0];
 				pos[j][1] = tmp2[j][1];
 			}
 			if(move(pos, 2, 1) == 0) {
 				break;
 			}
 		}
 		return false;
 	}
 
 	void solve(int x, int y) {
 		tx = x; ty = y;
 		m++;
 		int cnt = 0;
 		vis = new boolean[h][w];
 		Queue<Integer> q = new LinkedList<Integer>();
 		q.add(x*100+y);
 		vis[y][x] = true;
 		while(!q.isEmpty()) {
 			int v = q.poll();
 			cnt++;
 			int xx = v/100;
 			int yy = v%100;
 			for(int i = 0; i < dx.length; i++) {
 				int x0 = xx - dx[i];
 				int y0 = yy - dy[i];
 				if(vis[y0][x0] || mp[y0][x0] == '#') {
 					continue;
 				}
 				vis[y0][x0] = true;
 				q.add(x0*100+y0);
 			}
 		}
 
 		int[][] pos = new int[cnt][];
 		for(int i = 0, k = 0; i < h; i++)
 			for(int j = 0; j < w; j++)
 				if(vis[i][j])
 					pos[k++] = new int[] { j, i };
 
 		n[mp[y][x] - '0'] = cnt;
 		luc[mp[y][x] - '0'] = dfs(pos);
 	}
 
 	void run() throws IOException {
 		h = IOFast.nextInt();
 		w = IOFast.nextInt();
 		mp = new char[h][w];
 
 		m = 0;
 		n = new int[10];
 		luc = new boolean[10];
 
 		for(int i = 0; i < h; i++)
 			mp[i] = IOFast.next().toCharArray();
 
 		for(int i = 0; i < h; i++)
 			for(int j = 0; j < w; j++)
 				if(Character.isDigit(mp[i][j])) {
 					solve(j, i);
 				}
 
 		IOFast.out.println();
 		for(int i = 0; i < m; i++) {
 			IOFast.out.printf("%d: %d %s\n", i, n[i], luc[i]?"Lucky":"Unlucky");
 		}
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
