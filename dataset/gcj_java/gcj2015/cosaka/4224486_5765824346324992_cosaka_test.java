package com.g0418.b;
 
 import java.io.*;
 import java.util.ArrayList;
 import java.util.StringTokenizer;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 import java.util.concurrent.TimeUnit;
 
 public class Test {
 
 	// private static final String TASK = "sample";
 	private static final String TASK = "B-small-attempt0";
 	// private static final String TASK = "A-large";
 
 	private long b;
 	private long n;
 	private ArrayList<Long> mList = new ArrayList<Long>();
 
 	public Test(InputReader reader) throws IOException {
 		
 		b = reader.nextLong();
 		n = reader.nextLong();
 		for (int i = 0; i < b; i ++) {
 			mList.add(reader.nextLong());
 		}
 	}
 
 	private String solve() throws Exception {
 		double spec = 0;
 		for (Long m : mList){
 			spec += 1.0 / m;
 		}
 		
 		long bestTime = (long)((n - b) / spec);
 		bestTime --;
 		
 		ArrayList<Barber> barberList = new ArrayList<Barber>();
 		for (Long m : mList) {
 			Barber barber = new Barber(m);
 			barber.setTime(bestTime);
 			barberList.add(barber);
 		}
 		
 		long person = b;
 		for (Barber barber : barberList) {
 			person += barber.getPerson();
 		}
 		
 		// System.out.println("time=" + bestTime + ", person=" + person);
 		
 		while (true){
 			bestTime ++;
 			for (int i = 0; i < b; i ++) {
 				Barber barber = barberList.get(i);
 				if (barber.countup()) {
 					person ++;
 					if (person == n) {
 						// System.out.println("  time=" + bestTime + ", person=" + person);
 						
 						return "" + (i + 1);
 					}
 				}
 			}
 		}
 	}
 	
 	class Barber {
 		private long m = 0;
 		private long time = 0;
 		private long person = 0;
 		
 		private Barber (long m) {
 			this.m = m;
 		}
 		private void setTime (long time){
 			this.time = time;
 			person = time / m;
 		}
 		private boolean countup () {
 			boolean ret = false;
 			time ++;
 			long person2 = time / m;
 			if (person != person2) {
 				ret = true;
 			}
 			person = person2;
 			return ret;
 		}
 		
 		private long getPerson () {
 			return person;
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
