package com.g0411.b;
 
 import java.io.*;
 import java.util.ArrayList;
 import java.util.Collections;
 import java.util.StringTokenizer;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 import java.util.concurrent.TimeUnit;
 
 public class Test {
 
 	// private static final String TASK = "sample";
 	private static final String TASK = "B-small-attempt2";
 	// private static final String TASK = "A-small-attempt2";
 	// private static final String TASK = "A-large";
 
 	private int d;
 	private ArrayList<Integer> pp = new ArrayList<Integer>();
 
 	public Test(InputReader reader) throws IOException {
 		d = reader.nextInt();
 		for (int i = 0; i < d; i++) {
 			pp.add(reader.nextInt());
 		}
 	}
 
 	private String solve() throws Exception {
 		int count = 0;
 		
 		int three = 0;
 		
 		ArrayList<Plate> plateList = new ArrayList<Plate>();
 		for (Integer p : pp) {
 			if (p < 4) {
 				if (three < p) {
 					three = p;
 				}
 			} else {
 				plateList.add(new Plate(p, 1));
 			}
 		}
 		if (three != 0) {
 			plateList.add(new Plate(three, 1));
 		}
 
 		int best = Integer.MAX_VALUE;
 		while (true) {
 			int maxN = three;
 			Plate maxPlate = null;
 			for (int i = 0; i < plateList.size(); i ++) {
 				if (maxN < plateList.get(i).getMaxN()) {
 					maxPlate = plateList.get(i);
 					maxN = maxPlate.getMaxN();
 				}
 			}
 			if (maxN + count < best) {
 				best = maxN + count;
 			}
 			
 			{
 				String s = "";
 				for (Plate p : plateList) {
 					s += "," + p;
 				}
 				System.out.println("best=" + best + ",, " + s);
 			}
 			
 			if (maxPlate == null){
 				break;
 			}
 			
 			maxPlate.countUp();
 			count ++;
 			
 			if (maxPlate.getMaxN() < 4) {
 				if (three < maxPlate.getMaxN()) {
 					three = maxPlate.getMaxN();
 				}
 				plateList.remove(maxPlate);
 			}
 
 		}
 		
 		return best + "";
 	}
 	
 	class Plate {
 		int startN;
 		int people;
 		int maxN;
 		public Plate(int startN, int people) {
 			this.startN = startN;
 			this.people = people;
 			this.maxN = startN;
 		}
 		
 		public void countUp() {
 			people++;
 			maxN = startN / people;
 			if (startN % people != 0){
 				maxN ++;
 			}
 		}
 		
 		public int getMaxN() {
 			return maxN;
 		}
 		
 		public String toString() {
 			return "(" + maxN + "," + people + ")";
 			
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
