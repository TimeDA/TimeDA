import java.io.*;
import java.util.*;

public class Solution {
	static int[][] ans;
	
	static {
		int max = 512;
		int[][] a = new int[max + 1][max + 1];
		int[][] b = new int[max + 1][max + 1];
		for (int i = 0; i <= max; i++) {
			Arrays.fill(a[i], -1);
		}
		a[0][0] = 0;
		ans = new int[max + 1][max + 1];
		for (int k = 0; k <= max; k++) {
			for (int i = 0; i <= max; i++) {
				Arrays.fill(b[i], -1);
			}
			for (int i = 0; i <= max; i++) {
				for (int j = 0; j <= max; j++) {
					int count = a[i][j];
					if (count == -1) {
						continue;
					}
					ans[i][j] = Math.max(ans[i][j], a[i][j]);
					int ii = i;
					int jj = j;
					for (int x = 0;; x++) {
						b[ii][jj] = Math.max(b[ii][jj], count + x);
						ii += k;
						jj += x;
						if (ii > max || jj > max) {
							break;
						}
					}
				}
			}
			int[][] t = a; a = b; b = t;
		}
		for (int i = 0; i <= max; i++) {
			for (int j = 0; j <= max; j++) {
				if (i > 0) {
					ans[i][j] = Math.max(ans[i][j], ans[i - 1][j]);
				}
				if (j > 0) {
					ans[i][j] = Math.max(ans[i][j], ans[i][j - 1]);
				}
			}
		}
		for (int i = 0; i <= max; i++) {
			for (int j = 0; j <= max; j++) {
				if (ans[i][j] != ans[j][i]) {
					throw new RuntimeException();
				}
			}
		}
	}
	
	void run() {
		int a = in.nextInt();
		int b = in.nextInt();
		out.println(ans[a][b] - 1);
	}

	static MyScanner in;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		boolean stdStreams = true;
		String fileName = Solution.class.getSimpleName().replaceFirst("_.*", "").toLowerCase();
		String inputFileName = fileName + ".in";
		String outputFileName = fileName + ".out";
		
		Locale.setDefault(Locale.US);
		BufferedReader br;
		if (stdStreams) {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		} else {
			br = new BufferedReader(new FileReader(inputFileName));
			out = new PrintWriter(outputFileName);
		}
		in = new MyScanner(br);
		int tests = in.nextInt();
		for (int test = 0; test < tests; test++) {
			out.print("Case #" + (test + 1) + ": ");
			new Solution().run();
		}
		br.close();
		out.close();
	}
	
	static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		MyScanner(BufferedReader br) {
			this.br = br;
		}
		
		void findToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
		}
		
		String next() {
			findToken();
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		
		long nextLong() {
			return Long.parseLong(next());
		}
		
		double nextDouble() {
			return Double.parseDouble(next());
		}
	}
}
