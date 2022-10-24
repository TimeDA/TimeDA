package com.g0531.d;
 
 import java.io.*;
 import java.util.ArrayList;
 import java.util.Collections;
 import java.util.StringTokenizer;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 import java.util.concurrent.TimeUnit;
 
 public class Test {
 
 	// private static final String TASK = "sample";
 	private static final String TASK = "D-small-attempt0";
 	// private static final String TASK = "A-small-attempt2";
 	// private static final String TASK = "B-large";
 
 	int m, n;
 	ArrayList<String> slist = new ArrayList<String>();
 
 	public Test(InputReader reader) throws IOException {
 		m = reader.nextInt();
 		n = reader.nextInt();
 		for (int i = 0; i < m; i ++){
 			slist.add(reader.nextString());
 		}
 	}
 
 	private String solve() throws Exception {
 		ArrayList<Integer> list = new ArrayList<Integer>(); // ǂ̕ǂ̃T[oɓ邩B
 		for (int i = 0; i < m; i ++) {
 			list.add(0);
 		}
 
 		int maxCount = 0;
 		int nnn = 0;
 		while (true) {
 			ArrayList<ArrayList<String>> serverList = new ArrayList<ArrayList<String>>();
 			for (int i = 0; i < n; i ++) {
 				serverList.add (new ArrayList<String>());
 			}
 			for (int i = 0; i < m; i ++) {
 				serverList.get(list.get(i)).add(slist.get(i));
 			}
 			
 			int count = 0;
 			for (ArrayList<String> server : serverList) {
 				ArrayList<String> prefixList = new ArrayList<String>();
 				for (String s : server) {
 					for (int i = 0; i < s.length() + 1; i ++) {
 						String prefix = s.substring(0, i);
 						if (!prefixList.contains(prefix)) {
 							//System.out.println("s=" + s + ", prefix=" + prefix);
 							prefixList.add(prefix);
 						}
 					}
 				}
 				count += prefixList.size();
 			}
 			if (maxCount < count) {
 				maxCount = count;
 				nnn = 1;
 			} else if (maxCount == count){
 				nnn ++;
 			}
 			
 			boolean flag = false;
 			int b = 0;
 			while (true) {
 				int a = list.get(b);
 				if (a == n - 1) {
 					list.remove(b);
 					list.add(b, 0);
 					b++;
 					if (b == m) {
 						flag = true;
 						break;
 					}
 				} else {
 					int c = list.remove(b);
 					list.add(b, c + 1);
 					break;
 				}
 			}
 			/*
 			for (int i : list) {
 				System.out.print(" " + i);
 			}
 			*/
 			// System.out.println("  ,n=" + n + ",m=" + m);
 			if (flag) {
 				break;
 			}
 		}
 		
 		return "" + maxCount + " " + nnn;
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
