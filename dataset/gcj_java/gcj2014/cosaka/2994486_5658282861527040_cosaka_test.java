package com.g0504.b;
 
 import java.io.*;
 import java.util.StringTokenizer;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 import java.util.concurrent.TimeUnit;
 
 public class Test {
 
 	// private static final String TASK = "sample";
 	private static final String TASK = "B-small-attempt1";
 	// private static final String TASK = "A-small-attempt2";
 	// private static final String TASK = "A-large";
 
 	int a, b, k;
 	
 	public Test(InputReader reader) throws IOException {
 		a = reader.nextInt();
 		b = reader.nextInt();
 		k = reader.nextInt();
 	}
 
 	private String solve() throws Exception {
 		String ret = "";
 		
 		int count = 0;
 		for (int m = 0; m < k; m++) {
 			for (int i = 0; i < a; i++) {
 				for (int j = 0; j < b; j++) {
 					if (m == (i & j)) {
 						count ++;
 					}
 				}
 			}
 		}
 		ret += a + "," + b + "," + k;
 		return count +"";
 	}
 	
 	
 	private String replace (String s) {
 		s = replace(s, "a");
 		s = replace(s, "b");
 		s = replace(s, "c");
 		s = replace(s, "d");
 		s = replace(s, "e");
 		s = replace(s, "f");
 		s = replace(s, "g");
 		s = replace(s, "h");
 		s = replace(s, "i");
 		s = replace(s, "j");
 
 		s = replace(s, "k");
 		s = replace(s, "l");
 		s = replace(s, "m");
 		s = replace(s, "n");
 		s = replace(s, "o");
 		s = replace(s, "p");
 		s = replace(s, "q");
 		s = replace(s, "r");
 		s = replace(s, "s");
 		s = replace(s, "t");
 
 		s = replace(s, "u");
 		s = replace(s, "v");
 		s = replace(s, "w");
 		s = replace(s, "x");
 		s = replace(s, "y");
 		s = replace(s, "z");
 		return s;
 	}
 	
 	private String replace (String input, String oldChar) {
 		int i = input.length();
 		String output = input.replace(oldChar + oldChar, oldChar);
 		if (i == output.length()) {
 			return output;
 		} else {
 			return replace(output, oldChar);
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
