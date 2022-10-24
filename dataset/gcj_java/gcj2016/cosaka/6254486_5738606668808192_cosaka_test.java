package com.g0409.c;
 
 import java.io.*;
 import java.util.StringTokenizer;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 import java.util.concurrent.TimeUnit;
 
 public class Test {
 
 	// private static final String TASK = "sample";
 	private static final String TASK = "C-small-attempt0";
 	// private static final String TASK = "A-small-attempt2";
 	// private static final String TASK = "A-large";
 
 	private long n;
 	private int j;
 
 	public Test(InputReader reader) throws IOException {
 		int nn = reader.nextInt();
 		j = reader.nextInt();
 		
 		n = 1;
 		for (int i = 0; i < nn - 1; i++){
 			n *= 10;
 		}
 		n += 1;
 	}
 
 	private String solve() throws Exception {
 		int count = 0;
 		String str = "";
 		while (count < j) {
 			String str2 = n + "";
 			for (int i = 2; i < 11; i++) {
 				long aa = func(i, 10, n);
 				long prime = getPrime(aa);
 				System.out.println(aa + "/" + prime + ", n=" + i);
 				if (prime == 0) {
 					str2 = null;
 					break;
 				} else {
 					str2 += " " + prime;
 					// System.out.println("str2=" + str2);
 				}
 			}
 			n = func(10, 2, (func(2, 10, n) + 2));
 			if (str2 == null) {
 				continue;
 			}
 			count ++;
 			str += "\n" + str2;
 		}
 		return str;
 	}
 
 	
 	// from x-base to y-base 
 	private long func(long x, long y, long aa) {
 		long ret = 0;
 		long digit = 1;
 		while (aa > 0){
 			ret += aa % y * digit;
 			aa /= y;
 			digit *= x;
 		}
 		return ret;
 	}
 	
 	private long getPrime (long aa) {
 		long m = (long)Math.sqrt(aa) + 100;
 		if (aa % 2 == 0){
 			return 2;
 		}
 		for (long i = 3; i < m; i ++) {
 			if (aa % i == 0){
 				return i;
 			}
 		}
 		return 0;
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
