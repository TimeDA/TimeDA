package com.g0413.b;
 
 import java.io.BufferedReader;
 import java.io.File;
 import java.io.FileReader;
 import java.io.FileWriter;
 import java.io.IOException;
 import java.util.ArrayList;
 
 public class Problem {
 	public final String FILE_PATH = "C:/data/workspace/googleCodeJam2013/src/" + "com/g0413/b/";
 	public final String FILE_BASE = "B-small-attempt0";
 	// public final String FILE_BASE = "sample";
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
 			long testN = -1;
 			testN = Long.parseLong(br.readLine());
 			for (int i = 0; i < testN ; i++) {
 				String line = br.readLine();
 				System.out.println("hoge " + line);
 				String[] line2 = line.split(" ");
 				int a = Integer.parseInt(line2[0]);
 				int b = Integer.parseInt(line2[1]);
 				long mass[][] = new long[a][b];
 				for (int n = 0; n < a; n++) {
 					line = br.readLine();
 					line2 = line.split(" ");
 					for (int m = 0; m < b; m++) {
 						mass[n][m] = Integer.parseInt(line2[m]);
 					}
 				}
 				Test test = new Test(mass);
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
 		
 		private long mass[][];
 		
 		public Test (long mass[][]) {
 			this.mass = mass;
 		}
 		
 		public String check () {
 			for (int j = 0; j < mass.length; j++) {
 				for (int i = 0; i < mass[0].length; i++) {
 					long h =  mass[j][i];
 					boolean rowFlag = true;
 					for (int n = 0; n < mass.length; n++) {
 						if (h < mass[n][i]) {
 							rowFlag = false;
 						}
 					}
 					boolean columnFlag = true;
 					for (int n = 0; n < mass[0].length; n++) {
 						if (h < mass[j][n]) {
 							columnFlag = false;
 						}
 					}
 					if (!rowFlag && !columnFlag) {
 						return "NO";
 					}
 				}
 			}
 			return "YES";
 			// return "" + this.toString();
 		}
 		
 		
 		@Override
 		public String toString() {
 			String list = "\n";
 			for (int j = 0; j < mass.length; j++) {
 				for (int i = 0; i < mass[0].length; i++) {
 					list += mass[j][i] + ",";
 				}
 				list += "\n";
 			}
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
