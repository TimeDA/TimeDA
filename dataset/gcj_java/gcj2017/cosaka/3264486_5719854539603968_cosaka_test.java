package com.g0408.d;
 
 import java.io.*;
 import java.util.StringTokenizer;
 import java.util.concurrent.ExecutorService;
 import java.util.concurrent.Executors;
 import java.util.concurrent.TimeUnit;
 
 public class Test {
 
 	// private static final String TASK = "sample";
 	private static final String TASK = "D-small-attempt1";
 	// private static final String TASK = "A-small-attempt2";
 	// private static final String TASK = "C-large";
 
 	private int n; // n-grid
 	private long m; // already models
 	private int[][] gridOld;// grid
 	private int[][] grid;// grid
 	// ans : (point) (add or substitute) 
 	
 	public Test(InputReader reader) throws IOException {
 		n = reader.nextInt();
 		m = reader.nextLong();
 		gridOld = new int[n][n];
 		grid = new int[n][n];
 		for (int i = 0; i < n; i ++) {
 			for (int j = 0; j < n; j ++) {
 				gridOld[i][j] = 0;
 				grid[i][j] = 0;
 			}
 		}
 		for (int i = 0; i < m; i ++) {
 			String type = reader.nextString();
 
 			int x = reader.nextInt() - 1;
 			int y = reader.nextInt() - 1;
 			if (type.equals("+")) {
 				grid[x][y] = 1;
 				gridOld[x][y] = 1;
 			} else if (type.equals("x")) {
 				grid[x][y] = -1;
 				gridOld[x][y] = -1;
 			} else if (type.equals("o")) {
 				grid[x][y] = 2;
 				gridOld[x][y] = 2;
 			} else {
 				System.out.println("error");
 			}
 		}
 	}
 
 	private String solve() throws Exception {
 		// print();
 		for (int i = 0; i < n; i ++) {
 			for (int j = 0; j < n; j ++) {
 				if (grid[i][j] != 0) {
 					continue;
 				}
 				grid[i][j] = -1;
 				for (int x = 0; x < n; x ++) {
 					if (x != i){
 						if (grid[x][j] != 1 && grid[x][j] != 0) {
 							grid[i][j] = 0;
 							break;
 						}
 					}
 					if (x != j) {
 						if (grid[i][x] != 1 && grid[i][x] != 0) {
 							grid[i][j] = 0;
 							break;
 						}
 					}
 				}
 				
 				if (grid[i][j] != 0) {
 					continue;
 				}
 				grid[i][j] = 1;
 				for (int x = -n + 1; x < n; x ++) {
 					if (x == 0) {
 						continue;
 					}
 					if (0 <= i+x && i+x < n && 0 <= j+x && j+x < n) {
 						if (grid[i + x][j + x] != -1 && grid[i + x][j + x] != 0) {
 							grid[i][j] = 0;
 							break;
 						}
 					}
 					if (0 <= i+x && i+x < n && 0 <= j-x && j-x < n) {
 						if (grid[i + x][j - x] != -1 && grid[i + x][j - x] != 0) {
 							grid[i][j] = 0;
 							break;
 						}
 					}
 				}
 				if (grid[i][j] != 0) {
 					continue;
 				}
 			}
 		}
 		
 		for (int i = 0; i < n; i ++) {
 			for (int j = 0; j < n; j ++) {
 				if (grid[i][j] == 0) {
 					continue;
 				}
 				int tmp = grid[i][j];
 				grid[i][j] = 2;
 				for (int x = 0; x < n; x ++) {
 					if (x != i){
 						if (grid[x][j] != 1 && grid[x][j] != 0) {
 							grid[i][j] = tmp;
 							break;
 						}
 					}
 					if (x != j) {
 						if (grid[i][x] != 1 && grid[i][x] != 0) {
 							grid[i][j] = tmp;
 							break;
 						}
 					}
 				}
 				for (int x = -n + 1; x < n; x ++) {
 					if (x == 0) {
 						continue;
 					}
 					if (0 <= i+x && i+x < n && 0 <= j+x && j+x < n) {
 						if (grid[i + x][j + x] != -1 && grid[i + x][j + x] != 0) {
 							grid[i][j] = tmp;
 							break;
 						}
 					}
 					if (0 <= i+x && i+x < n && 0 <= j-x && j-x < n) {
 						if (grid[i + x][j - x] != -1 && grid[i + x][j - x] != 0) {
 							grid[i][j] = tmp;
 							break;
 						}
 					}
 				}
 			}
 		}
 		
 		int point = 0;
 		int add = 0;
 		String zLine = "";
 		for (int i = 0; i < n; i ++) {
 			for (int j = 0; j < n; j ++) {
 				if (grid[i][j] != gridOld[i][j]) {
 					zLine += "\r\n" + type(grid[i][j]) + " " + (i + 1) + " " + (j + 1);
 					add ++;
 				}
 				if (grid[i][j] == 1 || grid[i][j] == -1) {
 					point ++;
 				} else if (grid[i][j] == 2) {
 					point += 2;
 				}
 			}
 		}
 		// print();
 		return "" + point + " " + add + zLine;
 	}
 	
 	private String type(int t) {
 		if (t == 1) {
 			return "+";
 		} else if (t == -1) {
 			return "x";
 		} else if (t == 2) {
 			return "o";
 		} else {
 			return ".";
 		}
 	}
 	
 	private void print() {
 		System.out.println("============");
 		for (int i = 0; i < n; i++) {
 			String str = "";
 			for (int j = 0; j < n; j++) {
 				str += type (grid[i][j]);
 			}
 			System.out.println(str);
 		}
 		System.out.println("============");
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
