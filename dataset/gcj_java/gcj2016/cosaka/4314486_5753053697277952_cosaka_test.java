package com.g0508.a;
 
 import java.io.*;
 import java.util.ArrayList;
 import java.util.StringTokenizer;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 import java.util.concurrent.TimeUnit;
 
 public class Test {
 
 	// private static final String TASK = "sample";
 	private static final String TASK = "A-small-attempt1";
 	// private static final String TASK = "B-small-attempt3";
 	// private static final String TASK = "B-large";
 
 	private int n;
 	private int[] party;
 	
 	public Test(InputReader reader) throws IOException {
 		n = reader.nextInt();
 		party = new int[n];
 		for (int i = 0; i < n; i++) {
 			Integer j = (Integer)(reader.nextInt());
 			party[i] = j;
 		}
 	}
 
 	private String solve() throws Exception {
 		String ret = "";
 		while (true) {
 			if (0 < ret.length()) {
 				ret += " ";
 			}
 			int max = -1;
 			int maxN = 0;
 			for (int i = 0; i < n; i ++) {
 				int j = party[i];
 				if (max < j) {
 					max = j;
 					maxN = i;
 				}
 			}
 			if (max == 0) {
 				break;
 			}
 			if (1 < max){
 				party[maxN] -= 2;
 				if (checkNG()) {
 					ret += String.valueOf((char)('A' + maxN)) + String.valueOf((char)('A' + maxN)); 
 					continue;
 				}
 				party[maxN] += 2;
 			}
 			{
 				party[maxN] -= 1;
 				if (checkNG()) {
 					ret += String.valueOf((char)('A' + maxN)); 
 					continue;
 				}
 				party[maxN] += 1;
 			}
 			{
 				party[maxN] -= 1;
 				int max2 = -1;
 				int maxN2 = 0;
 				for (int i = 0; i < n; i ++) {
 					int j = party[i];
 					if (max2 < j) {
 						max2 = j;
 						maxN2 = i;
 					}
 				}
 				party[maxN2] -= 1;
 				if (checkNG()) {
 					ret += String.valueOf((char)('A' + maxN)) + String.valueOf((char)('A' + maxN2)); 
 					continue;
 				} else {
 					System.out.println("!!!!!!!!!!");
 				}
 			}
 		}
 		return ret;
 	}
 
 	
 	public boolean checkNG () {
 		int sum = 0;
 		int max = -1;
 		for (int i = 0; i < n; i ++) {
 			int j = party[i];
 			if (max < j) {
 				max = j;
 			}
 			sum += j;
 		}
 		return sum - max >= max;
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
