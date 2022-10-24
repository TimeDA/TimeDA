package com.g0510.b;
 
 import java.io.*;
 import java.util.StringTokenizer;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 import java.util.concurrent.TimeUnit;
 
 public class Test {
 
 	// private static final String TASK = "sample";
 	private static final String TASK = "B-small-attempt0";
 	// private static final String TASK = "A-large";
 
 	private int k; // L[{[h̕
 	private int l; // ^[Qbg̕
 	private int s; // ͕
 	private String keyS;
 	private String targetS;
 	
 	public Test(InputReader reader) throws IOException {
 		k = reader.nextInt();
 		l = reader.nextInt();
 		s = reader.nextInt();
 		keyS = reader.nextString();
 		targetS = reader.nextString();
 	}
 
 	private String solve() throws Exception {
 		double ret = 0;
 		
 		int[] key = new int[k];
 		for (int i = 0; i < k; i++) {
 			key[i] = keyS.codePointAt(i);
 		}
 		int[] target = new int[l];
 		for (int i = 0; i < l; i++) {
 			target[i] = targetS.codePointAt(i);
 		}
 		
 		int[] goal = new int[s];
 		
 		long count = 0;
 		long maxCount = 1;
 		for (int i = 0; i < s; i ++) {
 			maxCount *= k;
 		}
 		int banana = 0;
 		int maxBanana = 0;
 		while (true) {
 			long tmp = count;
 			for (int i = 0; i < s; i ++) {
 				goal[i] = key[(int)(tmp % k)];
 				tmp /= k;
 			}
 			int tmpBanana = 0;
 			for (int i = 0; i < (s - l + 1); i ++) {
 				for (int j = 0; j < l; j ++) {
 					if(goal[i + j] != target[j]) {
 						break;
 					}
 					if (j == l - 1) {
 						tmpBanana ++;
 					}
 				}
 			}
 			// System.out.println("count=" + count + ", tmpBanana=" + tmpBanana);
 			banana += tmpBanana;
 			if (maxBanana < tmpBanana) {
 				maxBanana = tmpBanana;
 			}
 			count ++;
 			if (count == maxCount) {
 				break;
 			}
 		}
 		System.out.println("maxBanana=" + maxBanana + ", banana=" + banana + ", maxCount=" + maxCount);
 		ret = maxBanana - (banana * 1.0f / maxCount);
 		return "" + ret;
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
