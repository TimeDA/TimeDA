package com.g0412.c;
 
 import java.io.*;
 import java.util.StringTokenizer;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 import java.util.concurrent.TimeUnit;
 
 public class Test {
 
 	// private static final String TASK = "sample";
 	private static final String TASK = "C-small-attempt1";
 	// private static final String TASK = "A-small-attempt2";
 	// private static final String TASK = "A-large";
 
 	private int r, c, m;
 
 	public Test(InputReader reader) throws IOException {
 		
 		r = reader.nextInt();
 		c = reader.nextInt();
 		m = reader.nextInt();
 	}
 
 	private String solve() throws Exception {
 		String ans = "\n";
 
 		// init
 		int oldM = m;
 		int[][] mass = new int[c][r];
 		for (int i = 0; i < c; i++) {
 			for (int j = 0; j < r; j++) {
 				mass[i][j] = -1;
 			}
 		}
 		
 		// place bomb
 		int cMax = c - 1;
 		int rMax = r - 1;
 		
 		int massC = -1;
 		int massR = -1;
 		boolean rFlag = true;
 		while (0 < m) {
 			if (cMax < rMax) {
 				for (int i = c - 1; 0 <= i; i--) {
 					if (mass[i][rMax] == -1) {
 						mass[i][rMax] = 11;
 						m --;
 						if (m == 0) {
 							if (i == 1) {
 								massC = i;
 								massR = rMax;
 								rFlag = true;
 							}
 							break;
 						}
 					}
 				}
 				rMax --;
 			} else {
 				for (int i = r - 1; 0 <= i; i--) {
 					if (mass[cMax][i] == -1) {
 						mass[cMax][i] = 11;
 						m --;
 						if (m == 0) {
 							if (i == 1) {
 								massC = cMax;
 								massR = i;
 								rFlag = false;
 							}
 							break;
 						}
 					}
 				}
 				cMax --;
 			}
 		}
 		
 		if (massC != -1) {
 			// System.out.println("hoge " + massC + "," + massR);
 			if (rFlag) {
 				mass[massC][massR] = -1;
 				if (3 < r && mass[cMax][1] == -1 && mass[cMax][2] == -1 && mass[cMax][3] == 11) {
 					mass[cMax][2] = 11;
 				} else {
 					mass[cMax][0] = 11;
 				}
 			} else {
 				mass[massC][massR] = -1;
 				if (3 < c && mass[1][rMax] == -1 && mass[2][rMax] == -1 && mass[3][rMax] == 11) {
 					mass[2][rMax] = 11;
 				} else {
 					mass[0][rMax] = 11;
 				}
 			}
 		}
 		int count = 0;
 		for (int i = 0; i < c; i++) {
 			for (int j = 0; j < r; j++) {
 				if (mass[i][j] == 11) {
 					count ++;
 				}
 			}
 		}
 		if (oldM != count) {
 			return "\nImpossible";
 		}
 		
 		reveal(mass, 0, 0);
 		/*
 		if (mass[0][0] != 0) {
 			return "\nImpossible";
 		}
 		*/
 		
 		// reveal
 		for (int i = 0; i < c; i++) {
 			for (int j = 0; j < r; j++) {
 				if (mass[i][j] == 0) {
 					reveal (mass, i-1, j-1);
 					reveal (mass, i-1, j);
 					reveal (mass, i-1, j+1);
 					reveal (mass, i, j-1);
 					reveal (mass, i, j+1);
 					reveal (mass, i+1, j-1);
 					reveal (mass, i+1, j);
 					reveal (mass, i+1, j+1);
 				}
 			}
 		}
 
 		// print
 		for (int j = 0; j < r; j++) {
 			for (int i = 0; i < c; i++) {
 				if (i + j == 0) {
 					ans += "c";
 				} else if (mass[i][j] == -1) {
 					ans += "?";
 					return "\nImpossible";
 				} else if (mass[i][j] == 11) {
 					ans += "*"; // bomb
 				} else {
 					// ans += mass[i][j];
 					ans += ".";
 				}
 			}
 			if (j != r-1) ans += "\n";
 		}
 		// System.out.println("=======");
 		return "" + ans;
 	}
 	
 	public void reveal(int mass[][], int a, int b) {
 		if (a < 0 || c <= a || b < 0 || r <= b) {
 			return;
 		}
 		
 		int n = 0;
 		if (0 <= b-1) {
 			if (0 <= a-1 && mass[a-1][b-1] == 11) {
 				n ++;
 			}
 			if (mass[a][b-1] == 11) {
 				n ++;
 			}
 			if (a+1 < c && mass[a+1][b-1] == 11) {
 				n ++;
 			}
 		}
 		
 		if (0 <= a-1 && mass[a-1][b] == 11) {
 			n ++;
 		}
 		if (a+1 < c && mass[a+1][b] == 11) {
 			n ++;
 		}
 		
 		if (b+1 < r) {
 			if (0 <= a-1 && mass[a-1][b+1] == 11) {
 				n ++;
 			}
 			if (mass[a][b+1] == 11) {
 				n ++;
 			}
 			if (a+1 < c && mass[a+1][b+1] == 11) {
 				n ++;
 			}
 		}
 		mass[a][b] = n;
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
