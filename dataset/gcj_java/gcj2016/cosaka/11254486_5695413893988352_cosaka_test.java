package com.g0501.b;
 
 import java.io.*;
 import java.util.StringTokenizer;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 import java.util.concurrent.TimeUnit;
 
 public class Test {
 
 	// private static final String TASK = "sample";
 	// private static final String TASK = "B-small-attempt0";
 	private static final String TASK = "B-small-attempt3";
 	// private static final String TASK = "B-large";
 
 	private String inputA, inputB;
 	
 	public Test(InputReader reader) throws IOException {
 		inputA = reader.nextString();
 		inputB = reader.nextString();
 	}
 
 	private String solve() throws Exception {
 		int length = inputA.length();
 		int win = 0; // plus=Bwin , minus=Awin
 		String q = "\\?";
 		boolean flagA = false;
 		boolean flagB = false;
 		int j = 0;
 		String AA = null;
 		String BB = null;
 		for (int i = 0; i < length; i ++) {
 			String A = inputA.substring(i,i+1);
 			String B = inputB.substring(i,i+1);
 			j = i;
 			if (!"?".equals(A) && !"?".equals(B)){
 				win = A.compareTo(B);
 				break;
 			} else if (!"?".equals(A) && "?".equals(B)){
 				inputB = inputB.replaceFirst(q, A);
 				flagA = false;
 				flagB = true;
 				// System.out.println("inputB=" + inputB);
 			} else if ("?".equals(A) && !"?".equals(B)){
 				inputA = inputA.replaceFirst(q, B);
 				flagA = true;
 				flagB = false;
 				// System.out.println("inputA=" + inputA);
 				// inputA = inputA.substring(i-1,i+1) + B + inputA.substring(i+2, inputA.length());
 			} else if ("?".equals(A) && "?".equals(B)){
 				inputA = inputA.replaceFirst(q, "0");
 				// System.out.println("!inputA=" + inputA);
 				inputB = inputB.replaceFirst(q, "0");
 				// System.out.println("!inputB=" + inputB);
 				flagA = true;
 				flagB = true;
 			}
 			AA = inputA.substring(i,i+1);
 			BB = inputB.substring(i,i+1);
 		}
 		// System.out.println("win=" + win + ", flagA=" + flagA + ", flagB=" + flagB + ", j=" + j);
 		if (win == 0){
 			inputA = inputA.replaceAll(q, "0");
 			inputB = inputB.replaceAll(q, "0");
 			return inputA + " " + inputB;
 		}
 		long diff = Long.MAX_VALUE;
 		String inputA3 = "";
 		String inputB3 = "";
 		
 		
 		if (flagB) { // B win
 			String inputAN = inputA.replaceAll(q, "9");
 			String inputBN = inputB.replaceAll(q, "0");
 			String inputB2 = "" + (Long.parseLong(inputBN) + get(inputBN.length() - j));
 			if (inputAN.length() < inputB2.length()) {
 			} else {
 				inputBN = inputB2;
 				while (inputBN.length() < inputAN.length()) {
 					inputBN = "0" + inputBN;
 				}
 			}
 			
 			long d = Long.parseLong(inputAN) - Long.parseLong(inputBN);
 			if (d < 0) {
 				d *= -1;
 			}
 			if (d < diff) {
 				diff = d;
 				inputA3 = inputAN;
 				inputB3 = inputBN;
 			} else  if (d == diff) {
 				if (Long.parseLong(inputA3) + Long.parseLong(inputB3) >
 					Long.parseLong(inputAN) + Long.parseLong(inputBN)) {
 					diff = d;
 					inputA3 = inputAN;
 					inputB3 = inputBN;
 				}
 			}
 		}
 		{
 			String inputAN = inputA.replaceAll(q, "0");
 			String inputBN = inputB.replaceAll(q, "9");
 			long d = Long.parseLong(inputAN) - Long.parseLong(inputBN);
 			if (d < 0) {
 				d *= -1;
 			}
 			if (d < diff) {
 				diff = d;
 				inputA3 = inputAN;
 				inputB3 = inputBN;
 			} else  if (d == diff) {
 				if (Long.parseLong(inputA3) + Long.parseLong(inputB3) >
 					Long.parseLong(inputAN) + Long.parseLong(inputBN)) {
 					diff = d;
 					inputA3 = inputAN;
 					inputB3 = inputBN;
 				}
 			}
 			
 		}
 		if (flagA) { // A win
 			String inputAN = inputA.replaceAll(q, "0");
 			String inputBN = inputB.replaceAll(q, "9");
 			String inputA2 = "" + (Long.parseLong(inputAN) + get(inputAN.length() - j));
 			if (inputBN.length() < inputA2.length()) {
 			} else {
 				inputAN = inputA2;
 				while (inputAN.length() < inputBN.length()) {
 					inputAN = "0" + inputAN;
 				}
 			}
 			long d = Long.parseLong(inputBN) - Long.parseLong(inputAN);
 			if (d < 0) {
 				d *= -1;
 			}
 			if (d < diff) {
 				diff = d;
 				inputA3 = inputAN;
 				inputB3 = inputBN;
 			} else  if (d == diff) {
 				if (Long.parseLong(inputA3) + Long.parseLong(inputB3) >
 					Long.parseLong(inputAN) + Long.parseLong(inputBN)) {
 					diff = d;
 					inputA3 = inputAN;
 					inputB3 = inputBN;
 				}
 			}
 		}
 		{ // B win
 			String inputAN = inputA.replaceAll(q, "9");
 			String inputBN = inputB.replaceAll(q, "0");
 			long d = Long.parseLong(inputAN) - Long.parseLong(inputBN);
 			if (d < 0) {
 				d *= -1;
 			}
 			if (d < diff) {
 				diff = d;
 				inputA3 = inputAN;
 				inputB3 = inputBN;
 			} else  if (d == diff) {
 				if (Long.parseLong(inputA3) + Long.parseLong(inputB3) >
 					Long.parseLong(inputAN) + Long.parseLong(inputBN)) {
 					diff = d;
 					inputA3 = inputAN;
 					inputB3 = inputBN;
 				}
 			}
 		}
 		/*
 		if (5 < win && j > 0 && flagB){
 			inputB = "" + (Long.parseLong(inputB) + get(inputB.length() - j));
 		}
 		if (win < -5 && j > 0 && flagA){
 			inputA = "" + (Long.parseLong(inputA) + get(inputA.length() - j));
 		}
 		*/
 		if (inputA.length() != inputB.length()) {
 			System.out.println("win=" + win + ", flagA=" + flagA + ", flagB=" + flagB + ", j=" + j);
 			System.out.println("NG inputA=" +inputA + ", inputB=" + inputB);
 		}
 		return inputA3 + " " + inputB3;
 	}
 
 	private long get(int j){
 		long l = 1;
 		for (int i = 0; i < j; i++) {
 			l *= 10;
 		}
 		return l;
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
