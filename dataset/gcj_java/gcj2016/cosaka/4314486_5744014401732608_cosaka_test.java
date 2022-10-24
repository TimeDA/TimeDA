package com.g0508.b;
 
 import java.io.*;
 import java.util.ArrayList;
 import java.util.StringTokenizer;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 import java.util.concurrent.TimeUnit;
 
 public class Test {
 
 	// private static final String TASK = "sample";
 	private static final String TASK = "B-small-attempt2";
 	// private static final String TASK = "A-large";
 
 	private int n, m;
 	private int[][]b;
 	private boolean debug = false;
 	
 	public Test(InputReader reader) throws IOException {
 		n = reader.nextInt();
 		m = reader.nextInt();
 		b = new int[n][n];
 	}
 
 	private String solve() throws Exception {
 		int count = 1;
 		while (true) {
 			reset();
 			int count2 = count;
 			boolean all1 = true;
 			for (int i = 0; i < n; i ++) {
 				for (int j = i + 2; j < n; j ++) {
 					b[i][j] = count2 % 2;
 					if (b[i][j] == 0) {
 						all1 = false;
 					}
 					count2 /= 2;
 				}
 			}
 			if (check()) {
 				break;
 			}
 			if (all1) {
 				return "IMPOSSIBLE";
 			}
 			count ++;
 		}
 		/*
 		reset();
 		b[0][2] = 1;
 		b[1][3] = 1;
 		b[2][4] = 1;
 		check();
 		*/
 		
 		// ans
 		String ret = "";
 		if (debug) {
 			ret += n + "," + m + ",";
 		}
 		ret += "POSSIBLE\n";
 		ret += print();
 		return ret;
 	}
 	
 	private void reset() {
 		for (int i = 0; i < n; i ++) {
 			for (int j = 0; j < n; j ++) {
 				if (i + 1 == j) {
 					b[i][j] = 1;
 				} else {
 					b[i][j] = 0;
 				}
 			}
 		}
 	}
 
 	private String print() {
 		String ret = "";
 		for (int i = 0; i < n; i ++) {
 			if (0 < i) {
 				ret += "\n";
 			}
 			for (int j = 0; j < n; j ++) {
 				if (debug) {
 					ret += b[i][j] + ","; //debug
 				} else {
 					if (b[i][j] == 0) {
 						ret += "0";
 					} else {
 						ret += "1";
 					}
 				}
 			}
 		}
 		return ret;
 	}
 	
 	private boolean check() {
 		for (int j = 0; j < n; j ++) {
 			for (int i = 0; i < n; i ++) {
 				if (i + 1 < j && b[i][j] == 1) {
 					for (int p = 0; p < n; p ++) {
 						for (int q = p + 2; q < i + 1; q ++) {
 							b[i][j] += b[p][q];
 						}
 					}
 				}
 			}
 		}
 		int count = 1;
 		for (int i = 0; i < n; i ++) {
 			for (int j = i + 2; j < n; j ++) {
 				count += b[i][j];
 			}
 		}
 		boolean flag = count == m;
 		
 		// System.out.println("flag=" + flag + "\n" + count + "?" + m + "\n" + print());
 		
 		return flag;
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
