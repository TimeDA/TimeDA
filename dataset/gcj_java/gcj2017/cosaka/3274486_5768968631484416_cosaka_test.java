package com.g0430.a;
 
 import java.io.*;
 import java.util.ArrayList;
 import java.util.Collections;
 import java.util.StringTokenizer;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 import java.util.concurrent.TimeUnit;
 
 public class Test {
 
 	// private static final String TASK = "sample";
 	// private static final String TASK = "B-small-attempt0";
 	private static final String TASK = "A-small-attempt0";
 	// private static final String TASK = "A-large";
 	private static int testCase = 0;
 
 	private int k, n;
 	private ArrayList<Pan> panList;
 	
 	public Test(InputReader reader) throws IOException {
 		n = reader.nextInt();
 		k = reader.nextInt();
 		panList = new ArrayList<Pan>();
 		for (int i = 0; i < n; i ++){
 			panList.add(new Pan(reader.nextDouble(), reader.nextDouble()));
 		}
 		Collections.sort(panList);
 	}
 
 	private String solve() throws Exception {
 		testCase ++;
 		double maxArea = 0;
 		
 		/*
 		for (Pan pan : panList) {
 			System.out.println("area2=" + pan.area2);
 		}
 		System.out.println("----");
 		*/
 		
 		for (int i = 0 ; i < panList.size(); i++) {
 			double area = 0;
 			ArrayList<Pan> tmpList = new ArrayList<Pan>(panList);
 			Pan pan = tmpList.remove(i);
 			area += pan.area1 + pan.area2;
 			for (int j = 0; j < k - 1; j++) {
 				pan = tmpList.remove(0);
 				area += pan.area2;
 			}
 			if (maxArea < area) {
 				maxArea = area;
 			}
 		}
 		
 		return "" + maxArea;
 	}
 
 	private class Pan implements Comparable {
 		double r;
 		double h;
 		double area1;
 		double area2;
 		
 		private Pan(double r, double h) {
 			this.r = r;
 			this.h = h;
 			area1 = r * r * Math.PI;
 			area2 = 2 * Math.PI * r * h;
 		}
 
 		@Override
 		public int compareTo(Object arg0) {
 			Pan o = (Pan)arg0; 
 			if (this.area2 - o.area2 > 0) {
 				return -1;
 			} else if (this.area2 - o.area2 < 0){
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
