package com.g0427.a;
 
 import java.io.BufferedReader;
 import java.io.File;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.io.IOException;
 import java.util.ArrayList;
 
 public class Problem {
 	public final String FILE_PATH = "C:/data/workspace/googleCodeJam2013/src/" + "com/g0427/a/";
 	// public final String FILE_BASE = "A-large";
 	public final String FILE_BASE = "A-small-attempt0";
 	public final String INPUT_FILE = FILE_PATH + FILE_BASE + ".in";
 	public final String OUTPUT_FILE = FILE_PATH + FILE_BASE + ".out";
 	
 	ArrayList<Test> testList = new ArrayList<Test>();
 	
 	public static void main(String[] args) {
 		try {
 			Problem p = new Problem();
 			p.init();
 			p.printResult();
 			p.end();
 		} catch (Exception e) {
 			e.printStackTrace();
 		}
 	}
 	
 	public void printResult() throws ProblemException {
 		long i = 1;
 		for (Test p : testList) {
 			prlong("Case #" + i + ": " + p.check());
 			i++;
 		}
 	}
 	
 	public static boolean flag = true;
 	FileWriter outputFile = null;
 	public void prlong(String str) throws ProblemException {
 		try {
 			// t@C̍폜At@C̐VKI[v
 			if (flag) {
 				flag = false;
 				File fw01 = new File(OUTPUT_FILE);
 				fw01.delete();
 				outputFile = new FileWriter(OUTPUT_FILE, true);
 			}
 			outputFile.write(str + "\r\n");
 			System.out.println(str);
 		} catch (IOException e) {
 				throw new ProblemException(e.getMessage(),e);
 		}
 	}
 	
 	public void end() throws ProblemException {
 		try {
 			outputFile.close();
 		} catch (IOException e) {
 			throw new ProblemException(e.getMessage(),e);
 		}
 	}
 	
 	public static final long X = 1l;
 	public static final long O = -1l;
 	public static final long T = 0l;
 	public static final long N = 100;
 	
 	public void init() throws ProblemException {
 		try {
 			FileReader in = new FileReader(INPUT_FILE);
 			BufferedReader br = new BufferedReader(in);
 			String line;
 			long testN = -1;
 			testN = Long.parseLong(br.readLine());
 			for (int i = 0; i < testN ; i++) {
 				line = br.readLine();
 				String r = line.split(" ")[0];
 				String t = line.split(" ")[1];
 				Test test = new Test(Long.parseLong(r), Long.parseLong(t));
 				testList.add(test);
 			}
 			br.close();
 			in.close();
 		} catch (IOException e) {
 			System.out.println(e);
 			throw new ProblemException(e.getMessage(),e);
 		}
 	}
 	
 	
 	public class Test {
 		
 		long r = 0;
 		double t = 0;
 		
 		public Test (long r, long t) {
 			this.r = r;
 			this.t = t;
 		}
 		
 		public String check () {
 			long n = 1;
 			double diff = 0;
 			for (int i = 0; i < 10000; i ++){
 				diff = 2 * r * n + 2 * n * n - n - t;
 				if (diff < 0) {
 					n *= 2;
 				}
 				if (diff > 0) {
 					n /= 2;
 				}
 			}
 			for (int i = 0; i < 10000; i ++){
 				diff = 2 * r * n + 2 * n * n - n - t;
 				if (diff < 0) {
 					n *= 1.1;
 				}
 				if (diff > 0) {
 					n /= 1.1;
 				}
 			}
 			for (int i = 0; i < 1000; i ++){
 				diff = 2 * r * n + 2 * n * n - n - t;
 				if (diff < 0) {
 					n *= 1.001;
 				}
 				if (diff > 0) {
 					n /= 1.001;
 				}
 			}
 			for (int i = 0; i < 1000; i ++){
 				diff = 2 * r * n + 2 * n * n - n - t;
 				if (diff < 0) {
 					n *= 1.00001;
 				}
 				if (diff > 0) {
 					n /= 1.00001;
 				}
 			}
 			for (int i = 0; i < 1000; i ++){
 				diff = 2 * r * n + 2 * n * n - n - t;
 				if (diff < 0) {
 					n *= 1.0000001;
 				}
 				if (diff > 0) {
 					n /= 1.0000001;
 				}
 			}
 			for (int i = 0; i < 1000; i ++){
 				diff = 2 * r * n + 2 * n * n - n - t;
 				if (diff < 0) {
 					n *= 1.000000001;
 				}
 				if (diff > 0) {
 					n /= 1.000000001;
 				}
 			}
 			for (int i = 0; i < 1000; i ++){
 				diff = 2 * r * n + 2 * n * n - n - t;
 				if (diff < 0) {
 					n *= 1.00000000001;
 				}
 				if (diff > 0) {
 					n /= 1.00000000001;
 				}
 			}
 			for (int i = 0; i < 1000; i ++){
 				diff = 2 * r * n + 2 * n * n - n - t;
 				if (diff < 0) {
 					n *= 1.0000000000001;
 				}
 				if (diff > 0) {
 					n /= 1.0000000000001;
 				}
 			}
 			for (int i = 0; i < 10000; i ++){
 				diff = 2 * r * n + 2 * n * n - n - t;
 				if (diff < 0) {
 					n += 1;
 				}
 				if (diff > 0) {
 					n -= 1;
 				}
 			}
 			long lastN = n;
 			for (int i = 0; i < 10000; i ++){
 				diff = 2 * r * n + 2 * n * n - n - t;
 				if (diff < 0) {
 					n += 1;
 				}
 				if (diff > 0) {
 					n -= 1;
 					lastN = n;
 				}
 			}
 			
 			return "" + lastN;
 		}
 		
 		
 		@Override
 		public String toString() {
 			String list = " " + r + "," + t;
 			return list;
 		}
 	}
 	
 	public class ProblemException extends Exception {
 		private static final long serialVersionUID = 2080823058826051635L;
 		public ProblemException(String message) {
 			super(message);
 		}
 		public ProblemException(String message, Throwable e) {
 			super (message, e);
 		}
 	}
 	
 	/*
 	 * 
 Case #1: 1
 Case #2: 256
 Case #3: 4
 Case #4: 674
 Case #5: 461
 	 * 
 	 */
 }
