package com.g0430.c;
 
 import java.io.*;
 import java.util.Arrays;
 import java.util.StringTokenizer;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 import java.util.concurrent.TimeUnit;
 
 public class Test {
 
 	// private static final String TASK = "sample";
 	private static final String TASK = "C-small-1-attempt3";
 	// private static final String TASK = "A-small-attempt0";
 	// private static final String TASK = "A-large";
 	private static int testCase = 0;
 
 	private int n, k;
 	private double u;
 	private double[] pList;
 	
 	public Test(InputReader reader) throws IOException {
 		n = reader.nextInt();
 		k = reader.nextInt();
 		u = reader.nextDouble();
 		
 		pList = new double[n];
 		for (int i = 0; i < n; i ++){
 			pList[i] = reader.nextDouble();
 		}
 		Arrays.sort(pList);
 	}
 
 	private String solve() throws Exception {
 		testCase ++;
 		String ret = "";
 		
 		for (int i = 1; i<n; i++) {
 			print();
 			double diff = pList[i] - pList[0];
 			diff *= i;
 			if (diff <= u) {
 				for (int j = 0; j < i; j++) {
 					pList[j] += diff / i;
 				}
 				u -= diff;
 			} else if (u <= diff) {
 				if (testCase == 20) {
 					// System.out.println("aaaaa ");
 				}
 				for (int j = 0; j < i; j++) {
 					pList[j] += u / i;
 				}
 				u = 0;
 			}
 			if (u == 0) {
 				break;
 			}
 		}
 		for (int i = 0; i < n; i++){
 			pList[i] += u / n;
 		}
 		u = 0;
 		print();
 		
 		// System.out.println("aaaaa");
 		double p = 1.0;
 		for (int i = 0; i < n; i++){
 			p *= pList[i];
 		}
 		
 		return ret + String.format("%1.10f", p);
 	}
 
 	private void print() {
 		String ret = "";
 		ret += u + ",,";
 		for (int ii = 0; ii<n; ii++) {
 			ret += ", " + pList[ii];
 		}
 		if(testCase == 20) {
 			System.out.println(ret);
 		}
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
