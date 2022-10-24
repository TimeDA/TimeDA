package com.g0423.b;
 
 import java.io.*;
 import java.util.ArrayList;
 import java.util.Collections;
 import java.util.StringTokenizer;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 import java.util.concurrent.TimeUnit;
 
 public class Test {
 
 	// private static final String TASK = "sample";
 	private static final String TASK = "B-small-attempt0";
 	// private static final String TASK = "A-small-attempt2";
 	// private static final String TASK = "A-large";
 	private static int testCase = 0;
 
 	private long n,r,o,y,g,b,v;
 	
 	public Test(InputReader reader) throws IOException {
 		n = reader.nextInt();
 		r = reader.nextInt();
 		o = reader.nextInt();
 		y = reader.nextInt();
 		g = reader.nextInt();
 		b = reader.nextInt();
 		v = reader.nextInt();
 	}
 
 	private String solve() throws Exception {
 		testCase ++;
 		String ret = "";
 		
 		if (r > 0) {
 			ret += "R";
 			r --;
 		} else if (y > 0) {
 			ret += "Y";
 			y --;
 		} else {
 			ret += "B";
 			b --;
 		}
 
 		while (r > 0 || y > 0 || b > 0) {
 			String last = ret.substring(ret.length() - 1);
 			if (last.equals("R")) {
 				if (y >= b && y != 0) {
 					ret += "Y";
 					y --;
 				} else if (b > 0){
 					ret += "B";
 					b --;
 				} else {
 					ret = "IMPOSSIBLE";
 					break;
 				}
 			} else if(last.equals("Y")) {
 				if (r >= b && r != 0) {
 					ret += "R";
 					r --;
 				} else if (b > 0){
 					ret += "B";
 					b --;
 				} else {
 					ret = "IMPOSSIBLE";
 					break;
 				}
 			} else if(last.equals("B")) {
 				if (r >= y && r != 0) {
 					ret += "R";
 					r --;
 				} else if (y > 0){
 					ret += "Y";
 					y --;
 				} else {
 					ret = "IMPOSSIBLE";
 					break;
 				}
 			}
 		}
 		
 		String first = ret.substring(0, 1);
 		String last = ret.substring(ret.length() - 1);
 		System.out.println(first + "," + last);
 		if (last.equals(first)) {
 			ret = "IMPOSSIBLE";
 		}
 		return ret;
 	}
 
 	private class Horse implements Comparable<Horse> {
 		double k;
 		Long s;
 		
 		private Horse(Long k, Long s) {
 			this.k = k;
 			this.s = s;
 		}
 
 		@Override
 		public int compareTo(Horse arg0) {
 			double ret = - k + arg0.k;
 			if (ret < 0) {
 				return -1;
 			} else if (0 < ret) {
 				return 1;
 			} else {
 				return 0;
 			}
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
