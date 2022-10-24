package com.g0510.c;
 
 import java.io.*;
 import java.util.ArrayList;
 import java.util.StringTokenizer;
 import java.util.TreeSet;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 import java.util.concurrent.TimeUnit;
 
 public class Test {
 
 	// private static final String TASK = "sample";
 	private static final String TASK = "C-small-attempt1";
 	// private static final String TASK = "A-large";
 
 	private int c;
 	private int d;
 	private int v;
 	private ArrayList<Integer> coinList0 = new ArrayList<Integer>();
 	
 	public Test(InputReader reader) throws IOException {
 		c = reader.nextInt(); // ނ̃RCgėǂ(smallł1)
 		d = reader.nextInt(); // RC̎
 		v = reader.nextInt(); // i̒li
 		
 		for (int i = 0; i < d; i ++) {
 			coinList0.add(reader.nextInt());
 		}
 	}
 
 	private String solve() throws Exception {
 		int ret = 0;
 		
 		int plus = 0;
 
 		{
 			ArrayList<Integer> coinList = new ArrayList<Integer>(coinList0);
 			ArrayList<Integer> addList = new ArrayList<Integer>();
 			if(getHoge(coinList, addList)) {
 				return "" + plus;
 			}
 		}
 		
 		
 		plus++;
 		for (int i1 = 0; i1 <= v; i1 ++) {
 			ArrayList<Integer> coinList = new ArrayList<Integer>(coinList0);
 			ArrayList<Integer> addList = new ArrayList<Integer>();
 			addList.add(i1);
 			if(getHoge(coinList, addList)) {
 				return "" + plus;
 			}
 		}
 
 		plus++;
 		for (int i1 = 0; i1 <= v; i1 ++) {for (int i2 = i1+1; i2 <= v; i2 ++) {
 			ArrayList<Integer> coinList = new ArrayList<Integer>(coinList0);
 			ArrayList<Integer> addList = new ArrayList<Integer>();
 			addList.add(i1);addList.add(i2);
 			if(getHoge(coinList, addList)) {
 				return "" + plus;
 			}
 		}}
 
 		plus++;
 		for (int i1 = 0; i1 <= v; i1 ++) {for (int i2 = i1+1; i2 <= v; i2 ++) {for (int i3 = i2+1; i3 <= v; i3 ++) {
 			ArrayList<Integer> coinList = new ArrayList<Integer>(coinList0);
 			ArrayList<Integer> addList = new ArrayList<Integer>();
 			addList.add(i1);addList.add(i2);addList.add(i3);
 			if(getHoge(coinList, addList)) {
 				return "" + plus;
 			}
 		}}}
 		
 		plus++;
 		for (int i1 = 0; i1 <= v; i1 ++) {for (int i2 = i1+1; i2 <= v; i2 ++) {for (int i3 = i2+1; i3 <= v; i3 ++) {for (int i4 = i3+1; i4 <= v; i4 ++) {
 			ArrayList<Integer> coinList = new ArrayList<Integer>(coinList0);
 			ArrayList<Integer> addList = new ArrayList<Integer>();
 			addList.add(i1);addList.add(i2);addList.add(i3);addList.add(i4);
 			if(getHoge(coinList, addList)) {
 				return "" + plus;
 			}
 		}}}}
 		
 		plus++;
 		for (int i1 = 0; i1 <= v; i1 ++) {for (int i2 = i1+1; i2 <= v; i2 ++) {for (int i3 = i2+1; i3 <= v; i3 ++) {for (int i4 = i3+1; i4 <= v; i4 ++) {for (int i5 = i4+1; i5 <= v; i5 ++) {
 			ArrayList<Integer> coinList = new ArrayList<Integer>(coinList0);
 			ArrayList<Integer> addList = new ArrayList<Integer>();
 			addList.add(i1);addList.add(i2);addList.add(i3);addList.add(i4);addList.add(i5);
 			if(getHoge(coinList, addList)) {
 				return "" + plus;
 			}
 		}}}}}
 		
 		plus++;
 		for (int i1 = 0; i1 <= v; i1 ++) {for (int i2 = i1+1; i2 <= v; i2 ++) {for (int i3 = i2+1; i3 <= v; i3 ++) {for (int i4 = i3+1; i4 <= v; i4 ++) {for (int i5 = i4+1; i5 <= v; i5 ++) {for (int i6 = i5+1; i6 < v; i6 ++) {
 			ArrayList<Integer> coinList = new ArrayList<Integer>(coinList0);
 			ArrayList<Integer> addList = new ArrayList<Integer>();
 			addList.add(i1);addList.add(i2);addList.add(i3);addList.add(i4);addList.add(i5);addList.add(i6);
 			if(getHoge(coinList, addList)) {
 				return "" + plus;
 			}
 		}}}}}}
 		
 		plus++;
 		for (int i1 = 0; i1 <= v; i1 ++) {for (int i2 = i1+1; i2 <= v; i2 ++) {for (int i3 = i2+1; i3 <= v; i3 ++) {for (int i4 = i3+1; i4 <= v; i4 ++) {for (int i5 = i4+1; i5 <= v; i5 ++) {for (int i6 = i5+1; i6 < v; i6 ++) {for (int i7 = i6+1; i7 < v; i7 ++) {
 			ArrayList<Integer> coinList = new ArrayList<Integer>(coinList0);
 			ArrayList<Integer> addList = new ArrayList<Integer>();
 			addList.add(i1);addList.add(i2);addList.add(i3);addList.add(i4);addList.add(i5);addList.add(i6);addList.add(i7);
 			if(getHoge(coinList, addList)) {
 				return "" + plus;
 			}
 		}}}}}}}
 		
 		plus++;
 		for (int i1 = 0; i1 <= v; i1 ++) {for (int i2 = i1+1; i2 <= v; i2 ++) {for (int i3 = i2+1; i3 <= v; i3 ++) {for (int i4 = i3+1; i4 <= v; i4 ++) {for (int i5 = i4+1; i5 <= v; i5 ++) {for (int i6 = i5+1; i6 < v; i6 ++) {for (int i7 = i6+1; i7 < v; i7 ++) {for (int i8 = i7+1; i8 < v; i8 ++) {
 			ArrayList<Integer> coinList = new ArrayList<Integer>(coinList0);
 			ArrayList<Integer> addList = new ArrayList<Integer>();
 			addList.add(i1);addList.add(i2);addList.add(i3);addList.add(i4);addList.add(i5);addList.add(i6);addList.add(i7);addList.add(i8);
 			if(getHoge(coinList, addList)) {
 				return "" + plus;
 			}
 		}}}}}}}}
 		
 		plus++;
 		for (int i1 = 0; i1 <= v; i1 ++) {for (int i2 = i1+1; i2 <= v; i2 ++) {for (int i3 = i2+1; i3 <= v; i3 ++) {for (int i4 = i3+1; i4 <= v; i4 ++) {for (int i5 = i4+1; i5 <= v; i5 ++) {for (int i6 = i5+1; i6 < v; i6 ++) {for (int i7 = i6+1; i7 < v; i7 ++) {for (int i8 = i7+1; i8 < v; i8 ++) {for (int i9 = i8+1; i9 < v; i9 ++) {
 			ArrayList<Integer> coinList = new ArrayList<Integer>(coinList0);
 			ArrayList<Integer> addList = new ArrayList<Integer>();
 			addList.add(i1);addList.add(i2);addList.add(i3);addList.add(i4);addList.add(i5);addList.add(i6);addList.add(i7);addList.add(i8);addList.add(i9);
 			if(getHoge(coinList, addList)) {
 				return "" + plus;
 			}
 		}}}}}}}}}
 		
 		plus++;
 		for (int i1 = 0; i1 <= v; i1 ++) {for (int i2 = i1+1; i2 <= v; i2 ++) {for (int i3 = i2+1; i3 <= v; i3 ++) {for (int i4 = i3+1; i4 <= v; i4 ++) {for (int i5 = i4+1; i5 <= v; i5 ++) {for (int i6 = i5+1; i6 < v; i6 ++) {for (int i7 = i6+1; i7 < v; i7 ++) {for (int i8 = i7+1; i8 < v; i8 ++) {for (int i9 = i8+1; i9 < v; i9 ++) {for (int i10 = i9+1; i10 < v; i10 ++) {for (int i11 = i9+1; i11 < v; i11 ++) {
 			ArrayList<Integer> coinList = new ArrayList<Integer>(coinList0);
 			ArrayList<Integer> addList = new ArrayList<Integer>();
 			addList.add(i1);addList.add(i2);addList.add(i3);addList.add(i4);addList.add(i5);addList.add(i6);addList.add(i7);addList.add(i8);addList.add(i9);addList.add(i10);addList.add(i11);
 			if(getHoge(coinList, addList)) {
 				return "" + plus;
 			}
 		}}}}}}}}}}}
 		
 		return "" + "xxx";
 	}
 	
 	private boolean getHoge(ArrayList<Integer> coinList, ArrayList<Integer> addList) {
 		for (Integer add : addList) {
 			if (coinList.contains(add)) {
 				return false;
 			}
 		}
 		coinList.addAll(addList);
 		
 		TreeSet<Integer> set = new TreeSet<Integer>();
 		long count = 0;
 		long maxCount = 1;
 		for (int i = 0; i < coinList.size(); i++) {
 			maxCount *= 2;
 		}
 		while (true) {
 			long tmp = count;
 			long pur = 0;
 			for (int i = 0; i < coinList.size(); i ++) {
 				// System.out.println("count=" + count + ", i=" + i + ", pur=" + pur + ", coin=" + coinList.get(i));
 				if (tmp % 2 == 1){
 					pur += coinList.get(i);
 				}
 				tmp /= 2;
 			}
 			if (pur <= v) {
 				set.add((int) pur);
 			}
 			count ++;
 			if (count == maxCount) {
 				break;
 			}
 		}
 		
 		String str = "";
 		for (Integer i : set) {
 			str += "," + i;
 		}
 		// System.out.println("str=" + str + "---" + maxCount + ", v=" + v);
 		
 		for (int i = 1; i <= v; i++) {
 			// System.out.println("aaa");
 			if (!set.contains(i)) {
 				// System.out.println("bbb");
 				break;
 			}
 			if (i == v) {
 				// System.out.println("ccc");
 				return true;
 			}
 		}
 		return false;
 	}
 	
 	public static void main(String[] args) throws Exception {
 		String directory = new File("src\\"
 			+ Test.class.getPackage().getName().replace(".", "/")).getAbsolutePath() +
 			"\\";
 		String inName = directory + TASK + ".in";
 		String outName = directory + TASK + ".out";
 
 		try (InputReader reader = new InputReader(inName);
 				OutputWriter writer = new OutputWriter(outName)) {
 			ExecutorService executorService = Executors.newFixedThreadPool(1); // TODO
 
 			int testCaseN = reader.nextInt();
 			final String[] result = new String[testCaseN];
 			for (int i = 0; i < testCaseN; i++) {
 				final Test test = new Test(reader);
 				final int ii = i;
 				executorService.submit(new Runnable() {
 					@Override
 					public void run() {
 						try {
 							result[ii] = test.solve();
 						} catch (Exception e) {
 							e.printStackTrace();
 							System.out.println("failure :: " + ii);
 							throw new RuntimeException("failure :: " + ii, e);
 						}
 					}
 				});
 			}
 			executorService.shutdown();
 			executorService.awaitTermination(10, TimeUnit.MINUTES);
 
 			for (int i = 0; i < testCaseN; i++) {
 				writer.println("Case #" + (i + 1) + ": " + result[i]);
 				if (result[i] == null) {
 					System.out.println("failure : " + i);
 					throw new RuntimeException("failure : " + i);
 				}
 			}
 		} catch (FileNotFoundException e) {
 			System.out.println("FileNotFound : " + e.getMessage());
 		}
 	}
 	
 	/** Utility **/
 	public static class InputReader implements AutoCloseable {
 		private final BufferedReader reader;
 		private StringTokenizer tokenizer = new StringTokenizer("");
 		public InputReader(String filename) throws FileNotFoundException {
 			this.reader = new BufferedReader(new FileReader(filename));
 		}
 		public String nextToken() throws IOException {
 			while (!tokenizer.hasMoreTokens()) {
 				tokenizer = new StringTokenizer(reader.readLine());
 			}
 			return tokenizer.nextToken();
 		}
 		public int nextInt() throws IOException {
 			return Integer.parseInt(nextToken());
 		}
 		public long nextLong() throws IOException {
 			return Long.parseLong(nextToken());
 		}
 		public double nextDouble() throws IOException {
 			return Double.parseDouble(nextToken());
 		}
 		public String nextString() throws IOException {
 			return nextToken();
 		}
 		@Override
 		public void close() throws Exception {
 			reader.close();
 		}
 	}
 	
 	public static class OutputWriter implements AutoCloseable {
 		private final PrintWriter writer;
 		public OutputWriter(String file) throws FileNotFoundException {
 			writer = new PrintWriter(file);
 		}
 		public void println(String str) {
 			System.out.println(str);
 			writer.println(str);
 		}
 		@Override
 		public void close() throws Exception {
 			writer.close();
 		}
 	}
 	
 }
