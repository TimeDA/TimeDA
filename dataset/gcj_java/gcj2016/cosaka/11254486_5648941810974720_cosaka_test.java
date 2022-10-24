package com.g0501.a;
 
 import java.io.*;
 import java.util.StringTokenizer;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 import java.util.concurrent.TimeUnit;
 
 public class Test {
 
 	// private static final String TASK = "sample";
 	private static final String TASK = "A-small-attempt0";
 	// private static final String TASK = "A-small-attempt2";
 	// private static final String TASK = "A-large";
 
 	private String str;
 	
 	public Test(InputReader reader) throws IOException {
 		str = reader.nextString();
 	}
 
 	private String solve() throws Exception {
 		int count[] = new int[10];
 		int length = str.length();
 		while (true) {
 			str = get(str, "ZERO", 'Z');
 			if (length != str.length()) {
 				count[0] ++;
 				length = str.length();
 			} else {
 				break;
 			}
 		}
 		
 		while (true) {
 			str = get(str, "TWO", 'W');
 			if (length != str.length()) {
 				count[2] ++;
 				length = str.length();
 			} else {
 				break;
 			}
 		}
 		
 		while (true) {
 			str = get(str, "FOUR", 'U');
 			if (length != str.length()) {
 				count[4] ++;
 				length = str.length();
 			} else {
 				break;
 			}
 		}
 		
 		while (true) {
 			str = get(str, "SIX", 'X');
 			if (length != str.length()) {
 				count[6] ++;
 				length = str.length();
 			} else {
 				break;
 			}
 		}
 		
 		while (true) {
 			str = get(str, "EIGHT", 'G');
 			if (length != str.length()) {
 				count[8] ++;
 				length = str.length();
 			} else {
 				break;
 			}
 		}
 		
 		while (true) {
 			str = get(str, "THREE", 'R');
 			if (length != str.length()) {
 				count[3] ++;
 				length = str.length();
 			} else {
 				break;
 			}
 		}
 		
 		while (true) {
 			str = get(str, "FIVE", 'F');
 			if (length != str.length()) {
 				count[5] ++;
 				length = str.length();
 			} else {
 				break;
 			}
 		}
 		
 		while (true) {
 			str = get(str, "SEVEN", 'V');
 			if (length != str.length()) {
 				count[7] ++;
 				length = str.length();
 			} else {
 				break;
 			}
 		}
 		
 		while (true) {
 			str = get(str, "NINE", 'I');
 			if (length != str.length()) {
 				count[9] ++;
 				length = str.length();
 			} else {
 				break;
 			}
 		}
 		
 		while (true) {
 			str = get(str, "ONE", 'N');
 			if (length != str.length()) {
 				count[1] ++;
 				length = str.length();
 			} else {
 				break;
 			}
 		}
 		System.out.println("length=" + str.length());
 		
 		String ans = "";
 		for (int i = 0 ; i < 10; i ++) {
 			while (0 < count[i]) {
 				ans += i;
 				count[i] --;
 			}
 		}
 		return ans;
 	}
 	
 	private String get(String str2, String key, int ch) {
 		int z = 0;
 		z = str2.indexOf(ch);
 		if (z == -1) {
 			return str2;
 		}
 		for (char c : key.toCharArray()) {
 			// System.out.println("ch=" + c);
 			z = str2.indexOf(c);
 			str2 = str2.substring(0, z) + str2.substring(z + 1, str2.length());
 		}
 		return str2;
 	}
 	
 	/*
 	if (0 == z){
 		str2 = str2.substring(1, str2.length());
 	} else if (0 < z) {
 		str2 = str2.substring(0, z) + str2.substring(z + 1, str2.length());
 	} else if (str2.length() == z - 1 ){
 		str2 = str2.substring(0, z - 2);
 	}
 	*/
 
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
