package com.g0504.a;
 
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
 
 	ArrayList<String> stringList = new ArrayList<String>();
 
 	public Test(InputReader reader) throws IOException {
 		int ii = reader.nextInt();
 		for (int i = 0; i < ii; i++) {
 			String str = reader.nextString();
 			stringList.add(str);
 		}
 	}
 
 	private String solve() throws Exception {
 		String ret = "";
 		String simple = replace(stringList.get(0));
 		for (String s : stringList) {
 			if (!simple.equals(replace(s))) {
 				return "Fegla Won";
 			}
 			// ret += ", " + s;
 		}
 		
 		ArrayList<ArrayList<Integer>> intList = new ArrayList<ArrayList<Integer>>();
 		for (int i = 0; i < stringList.size(); i++) {
 			intList.add(new ArrayList<Integer>());
 		}
 		
 		for (int i = 0; i < simple.length(); i++) {
 			String substring = simple.substring(i, i + 1);
 			ArrayList<String> newArrayList = new ArrayList<String>();
 			for (int j = 0; j < stringList.size(); j ++) {
 				String s = stringList.get(j);
 				for (int k = 0; k < s.length(); k++) {
 					if (!substring.equals(s.substring(k, k+1)) || k == s.length() - 1) {
 						if (!substring.equals(s.substring(k, k+1))) {
 							intList.get(j).add(k - 1);
 						} else {
 							intList.get(j).add(k);
 						}
 						String newString = s.substring(k, s.length());
 						newArrayList.add(newString);
 						break;
 					}
 				}
 			}
 			stringList = newArrayList;
 		}
 		
 		ArrayList<Integer> goalString = new ArrayList<Integer>();
 		
 		int size = intList.get(0).size();
 		for (int i = 0; i < size; i++) {
 			int iSum = 0;
 			for (int j = 0; j < intList.size(); j++) {
 				iSum += intList.get(j).get(i);
 			}
 			iSum = (int)((iSum * 1.0f / intList.size()) + 0.5f);
 			goalString.add(iSum);
 		}
 		
 		int intRet = 0;
 		for (ArrayList<Integer> ii : intList) {
 			for (int i = 0; i < ii.size(); i++) {
 				intRet += Math.abs(ii.get(i) - goalString.get(i));
 			}
 		}
 		
 		return intRet + "";
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
