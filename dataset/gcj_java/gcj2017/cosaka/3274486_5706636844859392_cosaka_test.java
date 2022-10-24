package com.g0430.b;
 
 import java.io.*;
 import java.util.StringTokenizer;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 import java.util.concurrent.TimeUnit;
 
 public class Test {
 
 	// private static final String TASK = "sample";
 	private static final String TASK = "B-small-attempt2";
 	// private static final String TASK = "A-small-attempt0";
 	// private static final String TASK = "A-large";
 	private static int testCase = 0;
 
 	private int acn, ajn;
 	private int[] ac0, ac1, aj0, aj1;
 	
 	public Test(InputReader reader) throws IOException {
 		acn = reader.nextInt();
 		ajn = reader.nextInt();
 		
 		ac0 = new int[acn];
 		ac1 = new int[acn];
 		for (int i = 0; i < acn; i ++){
 			ac0[i] = reader.nextInt();
 			ac1[i] = reader.nextInt();
 		}
 		aj0 = new int[ajn];
 		aj1 = new int[ajn];
 		for (int i = 0; i < ajn; i ++){
 			aj0[i] = reader.nextInt();
 			aj1[i] = reader.nextInt();
 		}
 	}
 
 	private String solve() throws Exception {
 		testCase ++;
 		int change = 0;
 		
 		if (acn + ajn == 1) {
 			return "2";
 		}
 		
 		if (acn == 1 && ajn == 1) {
 			return "2";
 		}
 		
 		if (acn == 2 && ajn == 0) {
 			return "" + calc(ac0, ac1);
 		}
 
 		if (acn == 0 && ajn == 2) {
 			return "" + calc(aj0, aj1);
 		}
 		return "" + change;
 	}
 
 	private int calc(int[] a0, int[] a1) {
 		
 		int small, large;
 		
 		small = Integer.MAX_VALUE;
 		large = 0;
 		for (int i = 0; i < 2; i ++) {
 			if (a0[i] < small) {
 				small = a0[i];
 			}
 			if (large < a0[i]) {
 				large = a0[i];
 			}
 			if (a1[i] < small) {
 				small = a1[i];
 			}
 			if (large < a1[i]) {
 				large = a1[i];
 			}
 		}
 		if (large - small <= 720) {
 			return 2;
 		}
 		
 		a0[0] += 1440;
 		a1[0] += 1440;
 		small = Integer.MAX_VALUE;
 		large = 0;
 		for (int i = 0; i < 2; i ++) {
 			if (a0[i] < small) {
 				small = a0[i];
 			}
 			if (large < a0[i]) {
 				large = a0[i];
 			}
 			if (a1[i] < small) {
 				small = a1[i];
 			}
 			if (large < a1[i]) {
 				large = a1[i];
 			}
 		}
 		if (large - small <= 720) {
 			return 2;
 		}
 		a0[0] -= 1440;
 		a1[0] -= 1440;
 		
 		a0[1] += 1440;
 		a1[1] += 1440;
 		small = Integer.MAX_VALUE;
 		large = 0;
 		for (int i = 0; i < 2; i ++) {
 			if (a0[i] < small) {
 				small = a0[i];
 			}
 			if (large < a0[i]) {
 				large = a0[i];
 			}
 			if (a1[i] < small) {
 				small = a1[i];
 			}
 			if (large < a1[i]) {
 				large = a1[i];
 			}
 		}
 		if (large - small <= 720) {
 			return 2;
 		}
 		a0[1] -= 1440;
 		a1[1] -= 1440;
 		
 		return 4;
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
