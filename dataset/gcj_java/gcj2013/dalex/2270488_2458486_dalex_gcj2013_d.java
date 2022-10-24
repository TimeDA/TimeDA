import java.io.*;
 import java.util.*;
 
 import static java.lang.Math.*;
 
 public class GCJ2013_D /*implements Runnable */{
 
 	BufferedReader in;
 	PrintWriter out;
 	StringTokenizer tok;
 	
 	public static void main(String[] args) {
 		//new Thread(null, new Template(), "", 64*1024*1024).start();
 		new GCJ2013_D().run();
 	}
 
 	public void run() {
 		try {
 			long t1 = 0, t2 = 0;
 			if (LOCAL) {
 				t1 = System.currentTimeMillis();
 			}
 			Locale.setDefault(Locale.US);
 			if (LOCAL) {
 				in = new BufferedReader(new FileReader("input.txt"));
 				out = new PrintWriter("output.txt");
 			} else {
 				in = new BufferedReader(new InputStreamReader(System.in));
 				out = new PrintWriter(System.out);
 			}
 			tok = new StringTokenizer("");
 			solve();
 			in.close();
 			out.close();
 			if (LOCAL) {
 				t2 = System.currentTimeMillis();
 				System.err.println("Time = " + (t2 - t1) + " ms.");
 			}
 		} catch (Throwable e) {
 			e.printStackTrace(System.err);
 			throw new RuntimeException();
 		}
 	}
 
 	String readString() throws IOException {
 		while (!tok.hasMoreTokens()) {
 			String line = in.readLine();
 			if (line == null) return null;
 			tok = new StringTokenizer(line);
 		}
 		return tok.nextToken();
 	}
 	
 	int readInt() throws IOException {
 		return Integer.parseInt(readString());
 	}
 	
 	long readLong() throws IOException {
 		return Long.parseLong(readString());
 	}
 	
 	double readDouble() throws IOException {
 		return Double.parseDouble(readString());
 	}
 	
 	static class Mergesort {
 
 		private Mergesort() {}
 
 		public static void sort(int[] a) {
 			mergesort(a, 0, a.length - 1);
 		}
 
 		public static void sort(long[] a) {
 			mergesort(a, 0, a.length - 1);
 		}
 
 		public static void sort(double[] a) {
 			mergesort(a, 0, a.length - 1);
 		}
 
 		private static final int MAGIC_VALUE = 42;
 
 		private static void mergesort(int[] a, int leftIndex, int rightIndex) {
 			if (leftIndex < rightIndex) {
 				if (rightIndex - leftIndex <= MAGIC_VALUE) {
 					insertionSort(a, leftIndex, rightIndex);
 				} else {
 					int middleIndex = (leftIndex + rightIndex) / 2;
 					mergesort(a, leftIndex, middleIndex);
 					mergesort(a, middleIndex + 1, rightIndex);
 					merge(a, leftIndex, middleIndex, rightIndex);
 				}
 			}
 		}
 
 		private static void mergesort(long[] a, int leftIndex, int rightIndex) {
 			if (leftIndex < rightIndex) {
 				if (rightIndex - leftIndex <= MAGIC_VALUE) {
 					insertionSort(a, leftIndex, rightIndex);
 				} else {
 					int middleIndex = (leftIndex + rightIndex) / 2;
 					mergesort(a, leftIndex, middleIndex);
 					mergesort(a, middleIndex + 1, rightIndex);
 					merge(a, leftIndex, middleIndex, rightIndex);
 				}
 			}
 		}
 
 		private static void mergesort(double[] a, int leftIndex, int rightIndex) {
 			if (leftIndex < rightIndex) {
 				if (rightIndex - leftIndex <= MAGIC_VALUE) {
 					insertionSort(a, leftIndex, rightIndex);
 				} else {
 					int middleIndex = (leftIndex + rightIndex) / 2;
 					mergesort(a, leftIndex, middleIndex);
 					mergesort(a, middleIndex + 1, rightIndex);
 					merge(a, leftIndex, middleIndex, rightIndex);
 				}
 			}
 		}
 
 		private static void merge(int[] a, int leftIndex, int middleIndex, int rightIndex) {
 			int length1 = middleIndex - leftIndex + 1;
 			int length2 = rightIndex - middleIndex;
 			int[] leftArray = new int[length1];
 			int[] rightArray = new int[length2];
 			System.arraycopy(a, leftIndex, leftArray, 0, length1);
 			System.arraycopy(a, middleIndex + 1, rightArray, 0, length2);
 			for (int k = leftIndex, i = 0, j = 0; k <= rightIndex; k++) {
 				if (i == length1) {
 					a[k] = rightArray[j++];
 				} else if (j == length2) {
 					a[k] = leftArray[i++];
 				} else {
 					a[k] = leftArray[i] <= rightArray[j] ? leftArray[i++] : rightArray[j++];
 				}
 			}
 		}
 
 		private static void merge(long[] a, int leftIndex, int middleIndex, int rightIndex) {
 			int length1 = middleIndex - leftIndex + 1;
 			int length2 = rightIndex - middleIndex;
 			long[] leftArray = new long[length1];
 			long[] rightArray = new long[length2];
 			System.arraycopy(a, leftIndex, leftArray, 0, length1);
 			System.arraycopy(a, middleIndex + 1, rightArray, 0, length2);
 			for (int k = leftIndex, i = 0, j = 0; k <= rightIndex; k++) {
 				if (i == length1) {
 					a[k] = rightArray[j++];
 				} else if (j == length2) {
 					a[k] = leftArray[i++];
 				} else {
 					a[k] = leftArray[i] <= rightArray[j] ? leftArray[i++] : rightArray[j++];
 				}
 			}
 		}
 
 		private static void merge(double[] a, int leftIndex, int middleIndex, int rightIndex) {
 			int length1 = middleIndex - leftIndex + 1;
 			int length2 = rightIndex - middleIndex;
 			double[] leftArray = new double[length1];
 			double[] rightArray = new double[length2];
 			System.arraycopy(a, leftIndex, leftArray, 0, length1);
 			System.arraycopy(a, middleIndex + 1, rightArray, 0, length2);
 			for (int k = leftIndex, i = 0, j = 0; k <= rightIndex; k++) {
 				if (i == length1) {
 					a[k] = rightArray[j++];
 				} else if (j == length2) {
 					a[k] = leftArray[i++];
 				} else {
 					a[k] = leftArray[i] <= rightArray[j] ? leftArray[i++] : rightArray[j++];
 				}
 			}
 		}
 
 		private static void insertionSort(int[] a, int leftIndex, int rightIndex) {
 			for (int i = leftIndex + 1; i <= rightIndex; i++) {
 				int current = a[i];
 				int j = i - 1;
 				while (j >= leftIndex && a[j] > current) {
 					a[j + 1] = a[j];
 					j--;
 				}
 				a[j + 1] = current;
 			}
 		}
 
 		private static void insertionSort(long[] a, int leftIndex, int rightIndex) {
 			for (int i = leftIndex + 1; i <= rightIndex; i++) {
 				long current = a[i];
 				int j = i - 1;
 				while (j >= leftIndex && a[j] > current) {
 					a[j + 1] = a[j];
 					j--;
 				}
 				a[j + 1] = current;
 			}
 		}
 
 		private static void insertionSort(double[] a, int leftIndex, int rightIndex) {
 			for (int i = leftIndex + 1; i <= rightIndex; i++) {
 				double current = a[i];
 				int j = i - 1;
 				while (j >= leftIndex && a[j] > current) {
 					a[j + 1] = a[j];
 					j--;
 				}
 				a[j + 1] = current;
 			}
 		}
 
 	}
 	
 	void debug(Object... o) {
 		if (LOCAL) {
 			System.err.println(Arrays.deepToString(o));
 		}
 	}
 	
 	final static boolean LOCAL = System.getProperty("ONLINE_JUDGE") == null;//System.getProperty("os.name") != null && System.getProperty("os.name").contains("Windows");//
 	
 //------------------------------------------------------------------------------
 	
 	void solve() throws IOException {
 		int t = readInt();
 		for (int i = 1; i <= t; i++) {
 			out.printf("Case #%d: ", i);
 			solveTest();
 		}
 	}
 	
 	int n;
 	int[] types;
 	int[] initialKeys;
 	int[][] keysInside;
 	boolean[] vis;
 	int[] parent;
 	int[] queue;
 	int qh, qt;
 	int[] cnts;
 	
 	private void solveTest() throws IOException {
 		initialKeys = new int[readInt()];
 		n = readInt();
 		for (int i = 0; i < initialKeys.length; i++) {
 			initialKeys[i] = readInt();
 		}
 		types = new int[n];
 		keysInside = new int[n][];
 		for (int i = 0; i < n; i++) {
 			types[i] = readInt();
 			keysInside[i] = new int[readInt()];
 			for (int j = 0; j < keysInside[i].length; j++) {
 				keysInside[i][j] = readInt();
 			}
 		}
 		compress();
 		vis = new boolean[1 << n];
 		parent = new int[1 << n];
 		Arrays.fill(parent, -1);
 		queue = new int[parent.length + 5];
 		qh = qt = 0;
 		int start = (1<<n) - 1;
 		vis[start] = true;
 		queue[qt++] = start;
 		while (qh < qt) {
 			int cur = queue[qh++];
 			Arrays.fill(cnts, 0);
 			for (int x : initialKeys) {
 				cnts[x]++;
 			}
 			for (int bit = 0; bit < n; bit++) {
 				if ((cur & (1 << bit)) == 0) {
 					cnts[types[bit]]--;
 					for (int x : keysInside[bit]) {
 						cnts[x]++;
 					}
 				}
 			}
 			for (int x : cnts) {
 				if (x < 0) {
 					throw new RuntimeException("negative cnt");
 				}
 			}
 			for (int bit = 0; bit < n; bit++) {
 				if ((cur & (1 << bit)) != 0) {
 					int needType = types[bit];
 					if (cnts[needType] > 0) {
 						int next = cur ^ (1 << bit);
 						if (!vis[next]) {
 							vis[next] = true;
 							parent[next] = cur;
 							queue[qt++] = next;
 						}
 					}
 				}
 			}
 		}
 		if (!vis[0]) {
 			out.println("IMPOSSIBLE");
 			return;
 		}
 		List<Integer> ans = new ArrayList<Integer>();
 		int k = 0;
 		while (true) {
 			if (parent[k] == -1) {
 				break;
 			}
 			int edge = k ^ parent[k];
 			ans.add(Integer.numberOfTrailingZeros(edge));
 			k = parent[k];
 		}
 		Collections.reverse(ans);
 		for (int i = 0; i < ans.size(); i++) {
 			out.print(ans.get(i) + 1);
 			if (i == ans.size() - 1) out.println(); else out.print(' ');
 		}
 	}
 
 	private void compress() {
 		Map<Integer, Integer> map = new TreeMap<Integer, Integer>();
 		for (int x : initialKeys) {
 			if (!map.containsKey(x)) {
 				int s = map.size();
 				map.put(x, s);
 			}
 		}
 		for (int[] a : keysInside) {
 			for (int x : a) {
 				if (!map.containsKey(x)) {
 					int s = map.size();
 					map.put(x, s);
 				}
 			}
 		}
 		for (int x : types) {
 			if (!map.containsKey(x)) {
 				int s = map.size();
 				map.put(x, s);
 			}
 		}
 		for (int i = 0; i < initialKeys.length; i++) {
 			initialKeys[i] = map.get(initialKeys[i]);
 		}
 		for (int i = 0; i < n; i++) {
 			for (int j = 0; j < keysInside[i].length; j++) {
 				keysInside[i][j] = map.get(keysInside[i][j]);
 			}
 		}
 		for (int i = 0; i < n; i++) {
 			types[i] = map.get(types[i]);
 		}
 		cnts = new int[map.size()];
 	}
 	
 }
