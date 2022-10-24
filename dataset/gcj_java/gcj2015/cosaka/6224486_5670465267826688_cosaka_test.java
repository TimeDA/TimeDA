package com.g0411.c;
 
 import java.io.*;
 import java.util.ArrayList;
 import java.util.Collections;
 import java.util.StringTokenizer;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 import java.util.concurrent.TimeUnit;
 
 public class Test {
 
 	// private static final String TASK = "sample";
 	private static final String TASK = "C-small-attempt0";
 	// private static final String TASK = "A-small-attempt2";
 	// private static final String TASK = "A-large";
 
 	private long l;
 	private long x;
 	private ArrayList<String> list = new ArrayList<String> (); 
 
 	public Test(InputReader reader) throws IOException {
 		l = reader.nextLong();
 		x = reader.nextLong();
 		if (20 < x) {
 			x %= 20;
 		}
 		String s = reader.nextString();
 		for (int i = 0; i < s.length(); i++) {
 			list.add(s.substring(i, i+1));
 		}
 	}
 
 	private String solve() throws Exception {
 		String s = "1";
 		String ret = "NO";
 		
 		String target = "i";
 		for (int k = 0; k < x; k++){
 			for (int i = 0; i < list.size(); i++) {
 				s = multi(s, list.get(i));
 				// System.out.println("s=" + s);
 				if (s.equals(target)) {
 					if (target.equals("i")) {
 						// System.out.println("get " + target);
 						target = "j";
 						s = "1";
 					} else if (target.equals("j")) {
 						// System.out.println("get " + target);
 						target = "z";
 						s = "1";
 					}
 				}
 			}
 		}
 		if (target.equals("z") && s.equals("k")) {
 			// System.out.println("get " + target);
 			ret = "YES";
 		}
 		// System.out.println("--- ret=" + ret + " ---");
 		return ret;
 	}
 	
 	private String multiSub (String s, int negative) {
 		if (negative == -1) {
 			return "-" + s;
 		} else {
 			return s;
 		}
 	}
 	
 	private String multi(String a, String b) throws Exception {
 		int negative = 1;
 		if (a.substring(0, 1).equals("-")) {
 			negative *= -1;
 			a = a.substring(1, 2);
 		}
 		if (b.substring(0, 1).equals("-")) {
 			negative *= -1;
 			b = b.substring(1, 2);
 		}
 		if (a.equals("1")) {
 			return multiSub(b, negative);
 		}
 		if (b.equals("1")) {
 			return multiSub(a, negative);
 		}
 		
 		if (a.equals("i")) {
 			if (b.equals("i")) {
 				return multiSub("1", -negative);
 			}
 			if (b.equals("j")) {
 				return multiSub("k", negative);
 			}
 			if (b.equals("k")) {
 				return multiSub("j", -negative);
 			}
 		}
 		if (a.equals("j")) {
 			if (b.equals("i")) {
 				return multiSub("k", -negative);
 			}
 			if (b.equals("j")) {
 				return multiSub("1", -negative);
 			}
 			if (b.equals("k")) {
 				return multiSub("i", negative);
 			}
 		}
 		if (a.equals("k")) {
 			if (b.equals("i")) {
 				return multiSub("j", negative);
 			}
 			if (b.equals("j")) {
 				return multiSub("i", -negative);
 			}
 			if (b.equals("k")) {
 				return multiSub("1", -negative);
 			}
 		}
 		
 		throw new Exception ("error");
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
