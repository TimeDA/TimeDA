import java.io.*;
 import java.util.*;
 
 import static java.lang.Math.*;
 
 public class A implements Runnable {
 
 	BufferedReader in;
 	PrintWriter out;
 	StringTokenizer tok;
 	
 	public static void main(String[] args) {
 		new Thread(null, new A(), "", 64*1024*1024).start();
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
 	
 	final static boolean LOCAL = System.getProperty("ONLINE_JUDGE") == null;
 	
 	private void solve() throws IOException {
 		int t = readInt();
 		for (int i = 1; i <= t; i++) {
 			out.printf("Case #%d: ", i);
 			solveTest();
 		}
 	}
 	
 //------------------------------------------------------------------------------
 
 	final long mod = 1000002013L;
 	
 	class End implements Comparable<End> {
 		int end;
 		int count;
 		
 		public End(int end, int count) {
 			this.end = end;
 			this.count = count;
 		}
 		
 		@Override
 		public int compareTo(End o) {
 			if (end < o.end) return -1;
 			if (end > o.end) return 1;
 			if (count < o.count) return -1;
 			if (count > o.count) return 1;
 			return 0;
 		}
 
 		@Override
 		public String toString() {
 			return "End [end=" + end + ", count=" + count + "]";
 		}
 	}
 	
 	class Price implements Comparable<Price> {
 		int price;
 		int count;
 		
 		public Price(int price, int count) {
 			this.price = price;
 			this.count = count;
 		}
 		
 		@Override
 		public int compareTo(Price o) {
 			if (price > o.price) return -1;
 			if (price < o.price) return 1;
 			if (count < o.count) return -1;
 			if (count > o.count) return 1;
 			return 0;
 		}
 
 		@Override
 		public String toString() {
 			return "Price [price=" + price + ", count=" + count + "]";
 		}
 	}
 	
 	Map<Integer, Integer> ids = new HashMap<Integer, Integer>();
 	
 	int getID(int x) {
 		if (ids.containsKey(x)) {
 			return ids.get(x);
 		}
 		int y = ids.size();
 		ids.put(x, y);
 		return y;
 	}
 	
 	private void solveTest() throws IOException {
 		ids.clear();
 		int n = readInt();
 		int m = readInt();
 		int[] start = new int[m];
 		int[] end = new int[m];
 		int[] cnt = new int[m];
 		long totalPrice = 0;
 		for (int i = 0; i < m; i++) {
 			start[i] = readInt() - 1;
 			end[i] = readInt() - 1;
 			cnt[i] = readInt();
 			int length = end[i] - start[i];
 			totalPrice += getCost(n, length) * cnt[i];
 			totalPrice %= mod;
 		}
 		TreeSet<Integer> idsSet = new TreeSet<Integer>();
 		for (int i = 0; i < m; i++) {
 			idsSet.add(start[i]);
 			idsSet.add(end[i]);
 		}
 		List<Integer> idsList = new ArrayList<Integer>();
 		while (!idsSet.isEmpty()) {
 			idsList.add(idsSet.pollFirst());
 		}
 		int[] diff = new int[idsList.size() - 1];
 		for (int i = 0; i < idsList.size() - 1; i++) {
 			diff[i] = idsList.get(i+1) - idsList.get(i);
 		}
 		for (int x : idsList) {
 			getID(x);
 		}
 		for (int i = 0; i < m; i++) {
 			start[i] = getID(start[i]);
 			end[i] = getID(end[i]);
 		}
 		List<End>[] startsToEnds = new List[ids.size()];
 		for (int i = 0; i < startsToEnds.length; i++) {
 			startsToEnds[i] = new ArrayList<End>();
 		}
 		for (int i = 0; i < m; i++) {
 			startsToEnds[start[i]].add(new End(end[i], cnt[i]));
 		}
 		for (int i = 0; i < startsToEnds.length; i++) {
 			Collections.sort(startsToEnds[i]);
 		}
 		List<Price> prices = new ArrayList<Price>();
 		List<End> ends = new ArrayList<End>();
 		long sum = 0;
 		for (int t = 0; t < ids.size(); t++) {
 			for (End e : startsToEnds[t]) {
 				prices.add(new Price(n, e.count));
 				ends.add(new End(e.end, e.count));
 			}
 			Collections.sort(prices);
 			Collections.sort(ends);
 			List<Price> newPrices = new ArrayList<Price>();
 			List<End> newEnds = new ArrayList<End>();
 			for (int i = 0, j = 0; i < prices.size() && j < ends.size(); ) {
 				int pCnt = prices.get(i).count;
 				int eCnt = ends.get(j).count;
 				int minCnt = min(pCnt, eCnt);
 				newPrices.add(new Price(prices.get(i).price, minCnt));
 				newEnds.add(new End(ends.get(j).end, minCnt));
 				if (minCnt == pCnt) {
 					i++;
 				} else {
 					prices.get(i).count -= minCnt;
 				}
 				if (minCnt == eCnt) {
 					j++;
 				} else {
 					ends.get(j).count -= minCnt;
 				}
 			}
 			prices = newPrices;
 			ends = newEnds;
 			newPrices = new ArrayList<Price>();
 			newEnds = new ArrayList<End>();
 			int j = 0;
 			while (j < ends.size() && ends.get(j).end == t) {
 				j++;
 			}
 			for (int i = j; i < prices.size(); i++) {
 				newPrices.add(prices.get(i));
 				newEnds.add(ends.get(i));
 			}
 			prices = newPrices;
 			ends = newEnds;
 			for (int i = 0; i < prices.size(); i++) {
 				sum += getCost(prices.get(i).price, diff[t]) * prices.get(i).count;
 				sum %= mod;
 				prices.get(i).price -= diff[t];
 			}
 		}
 		out.println((totalPrice - sum + mod) % mod);
 	}
 
 	private long getCost(int n, int length) {
 		if (length == 0) {
 			return 0;
 		}
 		return (long)(n + n - length + 1) * length / 2;
 	}
 	
 }
