package com.g0412.a;
 
 import java.io.*;
 import java.util.ArrayList;
 import java.util.StringTokenizer;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 import java.util.concurrent.TimeUnit;
 
 public class Test {
 
 	// private static final String TASK = "sample";
 	private static final String TASK = "A-small-attempt0";
 	// private static final String TASK = "A-small-attempt2";
 	// private static final String TASK = "B-large";
 
 	int a, b;
 	private int massA[][] = new int[4][4];
 	private int massB[][] = new int[4][4];
 
 	public Test(InputReader reader) throws IOException {
 		a = reader.nextInt();
 		for (int i = 0; i < 4; i++) {
 			for (int j = 0; j < 4; j++) {
 				massA[i][j] = reader.nextInt();
 			}
 		}
 		b = reader.nextInt();
 		for (int i = 0; i < 4; i++) {
 			for (int j = 0; j < 4; j++) {
 				massB[i][j] = reader.nextInt();
 			}
 		}
 	}
 
 	private String solve() throws Exception {
 		ArrayList<Integer> list = new ArrayList<Integer>();
 		for (int i = 0; i < 4; i++) {
 			list.add(massA[a - 1][i]);
 		}
 		
 		ArrayList<Integer> ans = new ArrayList<Integer>();
 		for (int i = 0; i < 4; i++) {
 			if (list.contains(massB[b - 1][i])) {
 				ans.add(massB[b - 1][i]);
 			}
 		}
 		
 		if (ans.size() == 0) {
 			return "Volunteer cheated!";
 		} else if (ans.size() == 1) {
 			return "" + ans.get(0);
 		} else {
 			return "Bad magician!";
 		}
 		
 		/*
 		ans += a + "\n";
 		for (int i = 0; i < 4; i++) {
 			for (int j = 0; j < 4; j++) {
 				ans += massA[i][j] + " ";
 			}
 			ans += "\n";
 		}
 		ans += b + "\n";
 		for (int i = 0; i < 4; i++) {
 			for (int j = 0; j < 4; j++) {
 				ans += massB[i][j] + " ";
 			}
 			ans += "\n";
 		}
 		*/
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
