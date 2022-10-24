package com.g0423.a;
 
 import java.io.*;
 import java.util.ArrayList;
 import java.util.Collections;
 import java.util.StringTokenizer;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 import java.util.concurrent.TimeUnit;
 
 public class Test {
 
 	// private static final String TASK = "sample";
 	private static final String TASK = "A-small-attempt1";
 	// private static final String TASK = "A-small-attempt2";
 	// private static final String TASK = "A-large";
 
 	private static int testCase = 0;
 	private long d,n;
 	private ArrayList<Horse> horseList = new ArrayList<>();
 	
 	public Test(InputReader reader) throws IOException {
 		d = reader.nextLong();
 		n = reader.nextLong();
 		
 		horseList.add(new Horse(d, 0L));
 		for (int i = 0; i < n; i++) {
 			horseList.add(new Horse(reader.nextLong(), reader.nextLong()));
 		}
 		Collections.sort(horseList);
 		
 //		for (Horse h : horseList) {
 //		System.out.println("k=" + h.k + ", s=" + h.s);
 //	}
 	}
 
 	private String solve() throws Exception {
 		testCase ++;
 		double totalTime = 0;
 //		System.out.println("====");
 		while (1 < horseList.size()) {
 			boolean flag = true;
 			while (flag) {
 				flag = false;
 				for (int i = 0; i < horseList.size() - 1; i++) {
 					Horse h1 = horseList.get(i);
 					Horse h2 = horseList.get(i+1);
 					
 					// System.out.println("!h1=" + h1.s + ", h2=" + h2.s + ", size=" + horseList.size());
 					if (h1.s >= h2.s) {
 						boolean a = horseList.remove(h1);
 						// System.out.println("a=" + a);
 						flag = true;
 						break;
 					}
 				}
 			}
 
 			double time = Long.MAX_VALUE;
 			Horse deleteHorse = null;
 			for (int i = 0; i < horseList.size() - 1; i++) {
 				Horse h1 = horseList.get(i);
 				Horse h2 = horseList.get(i+1); // fast
 				double timeTmp = (h1.k - h2.k) * 1.0d / (h2.s - h1.s);
 
 				if (testCase == 95) {
 					System.out.println("testCase=" + testCase + ", timeTmp=" + timeTmp);
 					System.out.println(h1.k + "," + h1.s + ",  " + h2.k + "," + h2.s);
 				}
 				if (timeTmp < time) {
 					time = timeTmp;
 					deleteHorse = h2;
 				}
 			}
 			totalTime += time;
 			
 			if (testCase == 95) {
 				System.out.println("--- totalTime=" + totalTime + ", time=" + time);
 			}
 			for (Horse h : horseList) {
 				h.k += time * h.s;
 			}
 			horseList.remove(deleteHorse);
 		}
 		// System.out.println("testCase=" + testCase + ",d=" + d + ", totalTime=" + totalTime);
 		return "" + (String.format("%15.7f", d * 1.0d / totalTime)).trim();
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
