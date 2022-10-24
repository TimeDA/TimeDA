package com.g0511.a;
 
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
 	// private static final String TASK = "A-large";
 
 	long p, q;
 	
 	public Test(InputReader reader) throws IOException {
 		String pq = reader.nextString();
 		String pStr = pq.split("/")[0];
 		p = Long.parseLong(pStr);
 		String qStr = pq.split("/")[1];
 		q = Long.parseLong(qStr);
 	}
 
 	private String solve() throws Exception {
 		String ret = "";
 		
 		{
 			long pp = p;
 			long qq = q;
 			while (pp != 0 && qq != 0) {
 				if (pp > qq) {
 					pp = pp % qq;
 				} else {
 					qq = qq % pp;
 				}
 				if (pp == 0) {
 					p /= qq;
 					q /= qq;
 					break;
 				}
 				if (qq == 0) {
 					p /= pp;
 					q /= pp;
 					break;
 				}
 			}
 		}
 		
 		ret += p + "," + q;
 		{
 			long qq = q;
 			while (qq > 0) {
 				if (qq != 1 && qq % 2 == 1) {
 					return "impossible";
 				} else {
 					qq /= 2;
 				}
 			}
 		}
 		
 		int count = 1;
 		{
 			while (true) {
 				if (p * 2>= q) {
 					break;
 				}
 				count ++;
 				q /= 2;
 			}
 		}
 		
 		return count + "";
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
