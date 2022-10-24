import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.Scanner;

// Solution
public class Solution {
	static Scanner in;
	static PrintWriter out;
	static String INPUT = "";
	
	static Map<Integer, int[][]> cache;
	
	static void solve()
	{
		cache = new HashMap<>();
		for(int T = ni(), cas = 1;T > 0;T--,cas++){
//			out.print("Case #" + cas + ": ");
			int L = ni(), U = ni();
			if(L == -1)return;
			int num = L;
			
			if(!cache.containsKey(num)){
				cache.put(num, makeGraph(num));
			}
			
			int[][] g = cache.get(num);
			int[] hey = ba(g);
			
			out.println(num);
			out.flush();
			for(int i = 0;i < num;i++){
				for(int e : g[i]){
					if(i < e){
						out.println((i+1) + " " + (e+1));
					}
				}
			}
			out.flush();
			
			int u = ni();
			if(u == -1)return;
			int[] from = new int[2*u];
			int[] to = new int[2*u];
			for(int i = 0;i < 2*u;i++){
				from[i] = ni()-1;
				to[i] = ni()-1;
			}
			int[][] h = packU(u, from, to);
			
			int[] my = ba(h);
			
			for(int i = 0;i < num;i++){
				if(i > 0)out.print(" ");
				for(int j = 0;j < num;j++){
					if(hey[i] == my[j]){
						out.print(j+1);
					}
				}
			}
			out.println();
			out.flush();
		}
	}
	
	static int[][] makeGraph(int num)
	{
		if(num <= 12){
			Random gen = new Random();
			outer:
			while(true){
				boolean[][] bg = new boolean[num][num];
				int[] deg = new int[num];
				int dead = 0;
				for(int i = 0;i < 2*num;i++){
					while(true){
						if(++dead >= 100000)continue outer;
						int x = gen.nextInt(num);
						int y = gen.nextInt(num);
						if(x != y && !bg[x][y] && deg[x] < 4 && deg[y] < 4){
							deg[x]++;
							deg[y]++;
							bg[x][y] = bg[y][x] = true;
							break;
						}
					}
				}
				int[][] g = new int[num][4];
				for(int i = 0;i < num;i++){
					int p = 0;
					for(int j = 0;j < num;j++){
						if(bg[i][j]){
							g[i][p++] = j;
						}
					}
				}
				
				// simplicity
				for(int i = 0;i < num;i++){
					for(int j = 0;j < 4;j++){
						for(int k = j+1;k < 4;k++){
							if(g[i][j] == g[i][k])continue outer;
						}
					}
				}
				
				// connectivity
				DJSet ds = new DJSet(num);
				for(int i = 0;i < num;i++){
					for(int e : g[i]){
						ds.union(i, e);
					}
				}
				if(ds.count() > 1)continue outer;
				
				// bisimulation
				int[] hey = ba(g);
				for(int i = 0;i < num;i++){
					for(int j = i+1;j < num;j++){
						if(hey[i] == hey[j])continue outer;
					}
				}
				
				return g;
			}
		}else{
			Random gen = new Random();
			outer:
			while(true){
				int n = gen.nextInt(10)+3;
				int m = gen.nextInt(10)+3;
				if(num > n*m)continue;
//				if(2*Math.max(n, m) > 
				int[][] t = new int[n][m];
				for(int i = 0;i < n;i++){
					Arrays.fill(t[i], -1);
				}
				for(int i = 0;i < num;i++){
					while(true){
						int r = gen.nextInt(n);
						int c = gen.nextInt(m);
						if(t[r][c] == -1){
							t[r][c] = i;
							break;
						}
					}
				}
				int[][] g = new int[num][];
				int[] dr = { 1, 0, -1, 0 };
				int[] dc = { 0, 1, 0, -1 };
				for(int i = 0;i < n;i++){
					for(int j = 0;j < m;j++){
						if(t[i][j] != -1){
							int[] row = new int[4];
							for(int k = 0;k < 4;k++){
								for(int l = 1;;l++){
									int ni = i + dr[k]*l,
											nj = j + dc[k]*l;
									ni %= n;
									if(ni < 0)ni += n;
									nj %= m;
									if(nj < 0)nj += m;
									if(t[ni][nj] != -1){
										if(t[ni][nj] == t[i][j]){
											continue outer;
										}
										row[k] = t[ni][nj];
										break;
									}
								}
							}
							g[t[i][j]] = row;
						}
					}
				}
				
				// simplicity
				for(int i = 0;i < num;i++){
					for(int j = 0;j < 4;j++){
						for(int k = j+1;k < 4;k++){
							if(g[i][j] == g[i][k])continue outer;
						}
					}
				}
				
				// connectivity
				DJSet ds = new DJSet(num);
				for(int i = 0;i < num;i++){
					for(int e : g[i]){
						ds.union(i, e);
					}
				}
				if(ds.count() > 1)continue outer;
				
				// bisimulation
				int[] hey = ba(g);
				for(int i = 0;i < num;i++){
					for(int j = i+1;j < num;j++){
						if(hey[i] == hey[j])continue outer;
					}
				}
				
				return g;
			}
		}
	}
	
	public static class DJSet {
		public int[] upper;

		public DJSet(int n) {
			upper = new int[n];
			Arrays.fill(upper, -1);
		}

		public int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		public boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		public boolean union(int x, int y) {
			x = root(x);
			y = root(y);
			if (x != y) {
				if (upper[y] < upper[x]) {
					int d = x;
					x = y;
					y = d;
				}
				upper[x] += upper[y];
				upper[y] = x;
			}
			return x == y;
		}

		public int count() {
			int ct = 0;
			for (int u : upper)
				if (u < 0)
					ct++;
			return ct;
		}
	}
	
	static int[] ba(int[][] g)
	{
		int n = g.length;
		int[][] M = new int[n][n];
		for(int i = 0;i < n;i++){
			for(int e : g[i]){
				M[e][i] = 1;
			}
		}
		
		long[] hs = new long[n];
		for(int i = 0;i < n;i++){
			int[] v = new int[n];
			v[i] = 1;
			v = pow(M, v, 114514);
			
			Arrays.sort(v);
			for(int j = 0;j < n;j++){
				hs[i] = hs[i] * 1000000009L + v[j];
			}
		}
		
		long[] is = Arrays.copyOf(hs, n);
		Arrays.sort(is);
		is = uniq(is);
		
		int[] ids = new int[n];
		for(int i = 0;i < n;i++){
			ids[i] = Arrays.binarySearch(is, hs[i]);
		}
		
		// bisimulation
		
		while(true){
			int[] mhs = new int[n];
			for(int i = 0;i < n;i++){
				int[] lhs = new int[4];
				int p = 0;
				for(int e : g[i]){
					lhs[p++] = ids[e];
				}
				Arrays.sort(lhs);
				
				mhs[i] = Arrays.hashCode(lhs);
			}
			
			int[] oids = Arrays.copyOf(ids, n);
			int[][] as = new int[n][];
			for(int i = 0;i < n;i++){
				as[i] = new int[]{ids[i], mhs[i], i};
			}
			Arrays.sort(as, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					if(a[0] != b[0])return a[0] - b[0];
					return Integer.compare(a[1], b[1]);
				}
			});
			
			int nid = 0;
			for(int i = 0;i < n;){
				int j = i;
				while(j < n && as[j][0] == as[i][0] && as[j][1] == as[i][1]){
					j++;
				}
				
				for(int k = i;k < j;k++){
					ids[as[k][2]] = nid;
				}
				nid++;
				
				i = j;
			}
			if(Arrays.equals(oids, ids))break;
		}
		
		return ids;
	}
	
	///////// begin
	public static final int mod = 1000000007;
	public static final long m2 = (long)mod*mod;
	public static final long BIG = 8L*m2;
	
	// A^e*v
	public static int[] pow(int[][] A, int[] v, long e)
	{
		for(int i = 0;i < v.length;i++){
			if(v[i] >= mod)v[i] %= mod;
		}
		int[][] MUL = A;
		for(;e > 0;e>>>=1) {
			if((e&1)==1)v = mul(MUL, v);
			MUL = p2(MUL);
		}
		return v;
	}
	
	// int matrix*int vector
	public static int[] mul(int[][] A, int[] v)
	{
		int m = A.length;
		int n = v.length;
		int[] w = new int[m];
		for(int i = 0;i < m;i++){
			long sum = 0;
			for(int k = 0;k < n;k++){
				sum += (long)A[i][k] * v[k];
				if(sum >= BIG)sum -= BIG;
			}
			w[i] = (int)(sum % mod);
		}
		return w;
	}
	
	// int matrix^2 (be careful about negative value)
	public static int[][] p2(int[][] A)
	{
		int n = A.length;
		int[][] C = new int[n][n];
		for(int i = 0;i < n;i++){
			long[] sum = new long[n];
			for(int k = 0;k < n;k++){
				for(int j = 0;j < n;j++){
					sum[j] += (long)A[i][k] * A[k][j];
					if(sum[j] >= BIG)sum[j] -= BIG;
				}
			}
			for(int j = 0;j < n;j++){
				C[i][j] = (int)(sum[j] % mod);
			}
		}
		return C;
	}
	
	public static int[] shrink(int[] a) {
		int n = a.length;
		long[] b = new long[n];
		for (int i = 0; i < n; i++)
			b[i] = (long) a[i] << 32 | i;
		Arrays.sort(b);
		int[] ret = new int[n];
		int p = 0;
		for (int i = 0; i < n; i++) {
			if (i > 0 && (b[i] ^ b[i - 1]) >> 32 != 0)
				p++;
			ret[(int) b[i]] = p;
		}
		return ret;
	}

	
	public static long[] uniq(long[] a)
	{
		int n = a.length;
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i == 0 || a[i] != a[i-1])a[p++] = a[i];
		}
		return Arrays.copyOf(a, p);
	}
	
	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int t : to)
			p[t]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]];
		for (int i = 0; i < from.length; i++) {
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
	}

	
	public static void main(String[] args) throws Exception
	{
//		int n = 50, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(30 + " ");
//		for(int u = 0;u < 30;u++){
//			sb.append(10 + " ");
//			sb.append(50 + " ");
//			int[][] g = {
//					{43, 20, 13, 49}, {17, 38, 8, 40}, {36, 21, 18, 44}, {23, 26, 47, 38}, {6, 15, 38, 43}, {8, 35, 34, 32}, {9, 31, 4, 12}, {24, 40, 10, 18}, {1, 16, 5, 10}, {38, 48, 6, 28}, {7, 8, 11, 37}, {10, 45, 24, 36}, {28, 6, 43, 30}, {0, 25, 28, 17}, {25, 47, 42, 48}, {31, 42, 20, 4}, {49, 46, 35, 8}, {21, 13, 1, 33}, {2, 7, 27, 26}, {35, 29, 49, 34}, {15, 41, 48, 0}, {34, 49, 17, 2}, {47, 39, 23, 31}, {22, 24, 3, 25}, {11, 33, 7, 23}, {41, 23, 14, 13}, {44, 18, 37, 3}, {18, 32, 36, 39}, {13, 9, 12, 46}, {30, 43, 46, 19}, {46, 12, 29, 35}, {48, 22, 15, 6}, {40, 5, 45, 27}, {45, 17, 40, 24}, {5, 19, 21, 45}, {16, 30, 19, 5}, {27, 11, 2, 42}, {26, 10, 39, 47}, {4, 3, 9, 1}, {37, 27, 44, 22}, {33, 1, 32, 7}, {42, 44, 25, 20}, {14, 36, 41, 15}, {12, 4, 0, 29}, {39, 2, 26, 41}, {32, 34, 33, 11}, {29, 28, 30, 16}, {3, 37, 22, 14}, {20, 14, 31, 9}, {19, 0, 16, 21}
//				};
//			n = 10;//g.length;
//			sb.append(n + " ");
//			for (int i = 0; i < n; i++) {
//	//			for(int e : g[i]){
//	//				if(i < e){
//	//					sb.append((i+1) + " " + (e+1) + "\n");
//	//				}
//	//			}
//				for(int j = 0;j < 2;j++){
//					sb.append((i+1) + " " + ((i+j+1)%n+1) + "\n");
//				}
//			}
//		}
//		INPUT = sb.toString();
		
		long S = System.currentTimeMillis();
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
		long G = System.currentTimeMillis();
		tr(G-S+"ms");
	}
	
	static int ni() { return Integer.parseInt(in.next()); }
	static void tr(Object... o) { if(!INPUT.isEmpty())System.out.println(Arrays.deepToString(o)); }
}
