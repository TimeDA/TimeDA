import java.io.*;
import java.util.*;

public class Solution {
	void run() {
		int n = in.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		int inf = 3000000;
		for (int i = 0; i < n; i++) {
			int d = in.nextInt();
			a[i] = d + in.nextInt();
			b[i] = d - in.nextInt();
		}
		int low = 0;
		int high = 0;
		TreeMap<Integer, Integer> countA = new TreeMap<>();
		TreeMap<Integer, Integer> countB = new TreeMap<>();
		TreeMap<Long, Integer> countPair = new TreeMap<>();
		int ans = 0;
		int ansCount = 0;
		int aPrev = inf;
		int aPrevAbsent = -1;
		int bPrev = inf;
		int bPrevAbsent = -1;
		while (high < n) {
			int aHigh = a[high];
			int bHigh = b[high];
			high++;
			countA.put(aHigh, countA.getOrDefault(aHigh, 0) + 1);
			countB.put(bHigh, countB.getOrDefault(bHigh, 0) + 1);
			long pairHigh = pair(aHigh, bHigh);
			countPair.put(pairHigh, countPair.getOrDefault(pairHigh, 0) + 1);
			int aAbsent = high - 2;
			int bAbsent = high - 2;
			if (aPrev == aHigh) aAbsent = aPrevAbsent;
			if (bPrev == bHigh) bAbsent = bPrevAbsent;
//			int t = high - 2;
//			while (t >= 0 && (a[t] == aHigh || b[t] == aHigh)) {
//				t--;
//			}
//			if (t != aAbsent) {
//				for (;;);
//			}
//			t = high - 2;
//			while (t >= 0 && (a[t] == bHigh || b[t] == bHigh)) {
//				t--;
//			}
//			if (t != bAbsent) {
//				for (;;);
//			}
			while (low < high) {
				int aLow = a[low];
				int bLow = b[low];
				int len = high - low;
//				int cc = Integer.MAX_VALUE;
//				int dd = cc;
				
				boolean good = false;
				if (aAbsent == -1 || bAbsent == -1) {
//					cc = aHigh; dd = bHigh;
					good = true;
				} else {
					int[] v1 = new int[] {aHigh, b[aAbsent]};
					int[] v2 = new int[] {a[bAbsent], bHigh};
//					for (int c : new int[]{a[aAbsent], b[aAbsent], a[bAbsent], b[bAbsent]}) {
//						for (int d : new int[] {aHigh, bHigh}) {
					{
						for (int[] array : new int[][] {v1, v2}) {
							int c = array[0];
							int d = array[1];
							int covered = countA.get(c) + countB.get(d) - countPair.getOrDefault(pair(c, d), 0);
//							if (c == d) {
//								covered = count.get(c);
//							} else {
//								covered = count.get(c) + count.get(d) - countPair.getOrDefault(pair(c, d), 0);
//							}
//							int c2 = 0;
//							for (int i = low; i < high; i++) {
//								if (a[i] == c || a[i] == d || b[i] == c || b[i] == d) {
//									c2++;
//								}
//							}
//							if (c2 != covered) {
//								for (;;);
//							}
							
							if (covered == len) {
								good = true;
//								cc = c;
//								dd = d;
							}
						}
					}
				}
				
				if (good) {
					if (len > ans) {
						ans = len;
						ansCount = 1;
					} else if (len == ans) {
						ansCount++;
					}
//					for (int i = low; i < high; i++) {
//						if (a[i] != cc && b[i] != cc && a[i] != dd && b[i] != dd) {
//							System.out.println(low + " " + high);
//							for (;;);
//						}
//					}
					break;
				}
				countA.put(aLow, countA.get(aLow) - 1);
				countB.put(bLow, countB.get(bLow) - 1);
				long pairLow = pair(aLow, bLow);
				countPair.put(pairLow, countPair.get(pairLow) - 1);
				low++;
			}
			aPrev = aHigh;
			bPrev = bHigh;
			aPrevAbsent = aAbsent;
			bPrevAbsent = bAbsent;
		}
		out.println(ans + " " + ansCount);
	}
	
	static long pair(int a, int b) {
		return a * (1L << 32) + b;
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
